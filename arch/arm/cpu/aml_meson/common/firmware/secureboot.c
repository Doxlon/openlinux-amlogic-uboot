/*
 *  Copyright (C) 2002 ARM Ltd.
 *  All Rights Reserved
 *  Copyright (c) 2010, Code Aurora Forum. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

/*
 * Secure loader
 *
 * Copyright (C) 2012 Amlogic, Inc.
 *
 * Author: Platform-SH@amlogic.com
 *
 */
 
#include <config.h>
#include <asm/arch/cpu.h>
#include <asm/arch/romboot.h>

extern int uclDecompress(char* op, unsigned* o_len, char* ip);

int load_secureos(void)
{
 	int rc=0;
 	unsigned len;    

 	// verify secureOS validation 		
/*
#ifndef CONFIG_MESON_SECUREBOOT_WITHOUT_DECRYPT	
	rc=spldecrypt(SECURE_OS_COMPRESS_ADDR);
	if(rc)
		goto exit;	
#endif		
*/ 	

	unsigned* psecureargs = (unsigned*)(AHB_SRAM_BASE + READ_SIZE-SECUREARGS_ADDRESS_IN_SRAM);
	*psecureargs = 0;
#ifdef CONFIG_MESON_SECUREARGS
	*psecureargs = __secureargs;	
#endif
	
 	// UCL decompress 	 	
#ifdef CONFIG_MESON_TRUSTZONE
	rc=uclDecompress((char*)(SECURE_OS_DECOMPRESS_ADDR), &len,(char*)(SECURE_OS_COMPRESS_ADDR)); 	
//#else 	
// 	rc=uclDecompress((char*)(SECURE_OS_DECOMPRESS_ADDR), &len,(char*)(SECURE_OS_COMPRESS_ADDR+SECUREOS_HEAD_SIZE)); 	
#endif 	 	
exit:
	return rc; 	 	
 }
 
 