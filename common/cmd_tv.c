/*
 * Command for control tv out.
 *
 * Copyright (C) 2011 Amlogic.
 */
#include <common.h>


/********************************************************************************************
*
*										TVOUT
*
*********************************************************************************************/

#include <asm/arch-m1/tv_out.h>

static int to_mode(char *mode_name)
{
	if(strcmp(mode_name, "1080P")==0)
		return TVOUT_1080P;
	if(strcmp(mode_name, "1080I")==0)
		return TVOUT_1080I;
	if(strcmp(mode_name, "720P")==0)
		return TVOUT_720P;
	if(strcmp(mode_name, "576P")==0)
		return TVOUT_576P;
	if(strcmp(mode_name, "480P")==0)
		return TVOUT_480P;
	if(strcmp(mode_name, "576I")==0)
		return TVOUT_576I;
	if(strcmp(mode_name, "480I")==0)
		return TVOUT_480I;

	return TVOUT_MAX;
}

static char * to_modestr(int mode)
{
#define CASE_RET(_x_)	case TVOUT_##_x_: return #_x_

	switch(mode)
	{
		CASE_RET(1080P);
		CASE_RET(1080I);
		CASE_RET(720P);
		CASE_RET(576P);
		CASE_RET(480P);
		CASE_RET(576I);
		CASE_RET(480I);
	}
	return "UNKNOWN";
}

static int do_tv_out_open(int argc, char *argv[])
{
	int mode;
	int ret;

	if (argc < 2)
		goto usage;

	mode = to_mode(argv[1]);
	if(mode == TVOUT_MAX)
		goto usage;
	
	ret = tv_out_open(mode);
	if (ret!=0) {
		printf("tv %s %s failed\n",argv[0], argv[1]);
		return 1;
	}

	return 0;

usage:
	puts("Usage: tv open mode(1080P/1080I/720P/576P/480P/576I/480I)\n");
	return 1;
}

static int do_tv_out_close(int argc, char *argv[])
{
	int ret;

	ret = tv_out_close();
	if (ret!=0) {
		printf("tv %s failed\n", argv[0]);
		return 1;
	}

	return 0;
}

static int do_tv_out_get_info(int argc, char *argv[])
{
	int mode;
	unsigned w,h;
	int ret;

	if (argc < 1)
		goto usage;

	mode = to_mode(argv[1]);
	if(mode == TVOUT_MAX)
		goto usage;

	ret = tv_out_get_info(mode, &w, &h);
	if (ret!=0) {
		printf("tv %s %s failed\n", argv[0], argv[1]);
		return 1;
	}

	printf("[%s]: %u x %u\n", argv[1], w, h);
	return 0;

usage:
	puts("Usage: tv minfo(1080P/1080I/720P/576P/480P/576I/480I)\n");
	return 1;
}

static int do_tv_out_cur_mode(int argc, char *argv[])
{
	int mode;

	mode = tv_out_cur_mode();
	printf("Current mode: %s\n", to_modestr(mode));
	
	return 0;
}

static int do_tv_out_tst(int argc, char *argv[])
{
	int mode;
	int ret;
	char *endp;

	if (argc < 2)
		goto usage;

	mode = simple_strtoul(argv[1], &endp, 0);
	if (*argv[1] == 0 || *endp != 0)
		goto usage;

	ret = tv_out_test(mode);
	if (ret!=0) {
		printf("tv %s %s failed\n",argv[0], argv[1]);
		return 1;
	}

	return 0;

usage:
	puts("Usage: tv tst mode(0-fix,1-colorbar,2-thinline,3-dotgrid)\n");
	return 1;
}

static int do_tv(cmd_tbl_t *cmdtp, int flag, int argc, char *argv[])
{
	const char *cmd;

	cmd = argv[1];

	if (strcmp(cmd, "open") == 0)
		return do_tv_out_open(argc - 1, argv + 1);
	if (strcmp(cmd, "close") == 0)
		return do_tv_out_close(argc - 1, argv + 1);
	if (strcmp(cmd, "minfo") == 0)
		return do_tv_out_get_info(argc - 1, argv + 1);
	if (strcmp(cmd, "mode") == 0)
		return do_tv_out_cur_mode(argc - 1, argv + 1);
	if (strcmp(cmd, "tst") == 0)
		return do_tv_out_tst(argc - 1, argv + 1);

	cmd_usage(cmdtp);
	return 1;
}

U_BOOT_CMD(
	tv,	3,	0,	do_tv,
	"tv sub-system",
	"open mode(1080P/1080I/720P/576P/480P/576I/480I)\n"
	"			- open the tv out\n"
	"tv close		- close the tv out\n"
	"tv minfo(1080P/1080I/720P/576P/480P/576I/480I)\n"
	"			- get mode info \n"
	"tv mode		- get current mode"
	"tv tst mode(0-fix,1-colorbar,2-thinline,3-dotgrid)\n"
	"                    - test tv output");

