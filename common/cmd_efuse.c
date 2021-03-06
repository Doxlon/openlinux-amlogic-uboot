#include <config.h>
#include <common.h>
#include <asm/arch/io.h>
#include <command.h>
#include <malloc.h>
#include <amlogic/efuse.h>

#define EFUSE_WRITE 0
#define EFUSE_READ 1
#define EFUSE_DUMP 2
//#define EFUSE_VERSION 3
#define EFUSE_SECURE_BOOT_SET 6

int __aml_sec_boot_check_efuse(unsigned char *pSRC)
{	
	return -1;
}

//Note: each Meson chip should make its own implementation
//         aml_sec_boot_check_efuse() for EFUSE programming with
//         secure boot.
int aml_sec_boot_check_efuse(unsigned char *pSRC)
	__attribute__((weak, alias("__aml_sec_boot_check_efuse")));


int cmd_efuse(int argc, char * const argv[], char *buf)
{
	int i, action = -1;
	efuseinfo_item_t info;
	char *title;
	char *s;
	char *end;
	
	if(strncmp(argv[1], "read", 4) == 0)
		action=EFUSE_READ;
	else if(strncmp(argv[1], "write", 5) == 0)
		action=EFUSE_WRITE;
#ifndef CONFIG_MESON_TRUSTZONE		
	else if(strcmp(argv[1], "dump") == 0)
		action=EFUSE_DUMP;
#endif		
	/*else if(strcmp(argv[1], "version") == 0)
		action = EFUSE_VERSION;*/
	else if(strcmp(argv[1], "secure_boot_set") == 0)
		action=EFUSE_SECURE_BOOT_SET;
	else{
		printf("%s arg error\n", argv[1]);
		return -1;
	}
				
	// efuse dump
	if(action == EFUSE_DUMP){
		memcpy(buf, efuse_dump(), EFUSE_BYTES);
		printf("Raw efuse data: \n");
		for(i=0; i<EFUSE_BYTES; i++){
			if(i%16 == 0)
				printf("%03x:  ", i);
			printf("%02x ", buf[i]);
			if(i%16 == 15)
				printf("\n");
		}	
		printf("efuse raw data dump finish \n");
		return 0;
	}
	
	// efuse version
	/*else if(action == EFUSE_VERSION){
		if(argc<3){
				printf("arg count error\n");
				return -1;
		}
		efuse_getinfo_version(&info);
		memset(buf, 0, info.data_len);	
		s=argv[2];
		for(i=0; i<info.data_len; i++){
			buf[i] = s ? simple_strtoul(s, &end, 16) : 0;
			if (s)
				s = (*end) ? end+1 : end;
		}
			
		if(efuse_write_usr(&info, buf)){
			printf("error: efuse version has been selected.\n");
			return -1;
		}
		else
			printf("efuse version select done.\n");		
	}*/
		

	// efuse read
	else if(action == EFUSE_READ){
		title = argv[2];
		if(efuse_getinfo(title, &info) < 0)		
			return -1;
		
		memset(buf, 0, EFUSE_BYTES);
		efuse_read_usr(buf, info.data_len, (loff_t *)&info.offset);		
		printf("%s is: ", title);
		for(i=0; i<(info.data_len); i++)
			printf(":%02x", buf[i]);
		printf("\n");
	}
	
	// efuse write
	else if(action==EFUSE_WRITE){		
		if(argc<4){
			printf("arg count error\n");
			return -1;
		}
		title = argv[2];
		if(efuse_getinfo(title, &info) < 0)
			return -1;		
		if(!(info.we)){
			printf("%s write unsupport now. \n", title);
			return -1;
		}
		
		memset(buf, 0, info.data_len);	
		s=argv[3];

#ifdef WRITE_TO_EFUSE_ENABLE
		//usb_burning
		if( !strncmp(title,"usid",sizeof("usid")) )				 	//efuse write usid data(data is string)
			memcpy(buf, s, strlen(s));
		else if( !strncmp(title,"hdcp",sizeof("hdcp")) )  			 //efuse write hdcp data(data is not string)
			memcpy(buf, s, 288);
		else if( !strncmp(title,"version",sizeof("version"))){
			unsigned int ver;
			ver = simple_strtoul(s, &end, 16);
			buf[0]=(char)ver;
		}
		else													//efuse write version, mac, mac_bt, mac_wifi is data
		{
			for(i=0; i<info.data_len; i++){						
				buf[i] = s ? simple_strtoul(s, &end, 16) : 0;
				if (s)
					s = (*end) ? end+1 : end;
			}

			if(*s){
				printf("error: The wriiten data length is too large.\n");
				return -1;
			}
		}
		
#else

		if( !strncmp(title,"version",sizeof("version"))){
			unsigned int ver;
			ver = simple_strtoul(s, &end, 16);
			buf[0]=(char)ver;
		}
		else{
			for(i=0; i<info.data_len; i++){
				buf[i] = s ? simple_strtoul(s, &end, 16) : 0;
				if (s)
					s = (*end) ? end+1 : end;
			}

			if(*s){
				printf("error: The wriiten data length is too large.\n");
				return -1;
			}
		}
#endif
		
		if(efuse_write_usr(buf, info.data_len, (loff_t*)&info.offset)<0){
			printf("error: efuse write fail.\n");
			return -1;
		}
		else
			printf("%s written done.\n", info.title);					
	}
	else if ((EFUSE_SECURE_BOOT_SET == action) && (3 == argc))
	{
		s = argv[2];
		unsigned int nAddr = simple_strtoul(s, &end, 16);
		int nChkVal,nChkAddr;
		nChkVal = nChkAddr = 0;
		efuse_read(&nChkVal,sizeof(nChkVal),(loff_t*)&nChkAddr);
		if(((nChkVal >> 7) & 1) && ((nChkVal >> 6) & 1))
		{
			printf("aml log : boot key can not write twice!\n");
			return -1;
		}		
		if(aml_sec_boot_check_efuse(nAddr))
			printf("aml log : efuse pattern check fail!\n");
		else
		{	unsigned int pos = 0;
			efuse_write(nAddr, EFUSE_BYTES, (loff_t*)&pos);
		}
	}
	else{
		printf("arg error\n");
		return -1;	
	}
	
	return 0;
}


int do_efuse(cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[])
{
//	int ret = 0 ;
	char buf[EFUSE_BYTES];

	memset(buf, 0, sizeof(buf));
	
	if(argc < 2){
		cmd_usage(cmdtp);
		return -1;
	}

	return cmd_efuse(argc, argv, buf);
	
}

U_BOOT_CMD(
	efuse,	4,	1,	do_efuse,
	"efuse version/licence/mac/hdcp/usid read/write or dump raw efuse data commands",
	"[read/write] [licence/mac/hdc/usid/machineid] [mem_addr]\n"
	"	   [read/wirte] para read ; write ;\n"
	"				read need not mem_addr;write need\n"
	"				read to get efuse context\n"
	"				write to write efuse\n"
	"	   [mem_addr] usr do \n"
	"efuse [dump]\n"
	"	   dump raw efuse data\n"
	"efuse [secure_boot_set] [mem_addr]\n"
	"	   decrypt the EFUSE pattern from address mem_addr which contain setting\n"	
	"	   for secure boot, if pass then the setting will be programmed to the chip\n"
	"	   DO NOT TRY THIS FEATURE IF NO CONFIRMATION FROM AMLOGIC IN WRITING\n" 
	"	   OTHERWISE IT WILL CAUSE UNCORRECTABLE DAMAGE TO AMLOGIC CHIPS\n"
);

/****************************************************/
