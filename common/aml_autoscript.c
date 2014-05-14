#include <common.h>
#include <command.h>

int aml_autoscript(void)
{
	int	i = 0;
	char	str[128];
	if(run_command ("mmcinfo", 0))
	{
		printf("##aml_autoscript---ERROR: SD card not find!!!\n");
	}
	else
	{
		for(i = 0; i < SCAN_MMC_PARTITION; i++)
		{
			sprintf(str, "fatexist mmc 0:%d %s", (i + 1), AML_AUTOSCRIPT);
			if(!run_command (str, 0))
			{
				sprintf(str, "fatload mmc 0:%d ${loadaddr} %s", (i + 1), AML_AUTOSCRIPT);
				run_command (str, 0);
				run_command ("autoscr ${loadaddr}", 0);
				return	0;
			}
		}
	}
	return -1;
}