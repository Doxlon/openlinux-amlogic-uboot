#include "platform.h"
#include "usb_pcd.h"

#include "usb_pcd.c"
#include "platform.c"
#include "dwc_pcd.c"
#include "dwc_pcd_irq.c"

int v2_usbburning(unsigned timeout)
{
	int cfg = EXT_CLOCK;

    printf("Enter v2 usbburning mode\n");
	set_usb_phy_config(cfg);

	usb_parameter_init(timeout);
		
	if(usb_pcd_init()) {
        printf("!!!!Fail in usb_pcd_init\n");
        return __LINE__;
    }

#ifdef CONFIG_M8
	writel(0, P_WATCHDOG_TC);//disable watch dog
#endif//#ifdef CONFIG_M8

	while(1)
	{
		//watchdog_clear();		//Elvis Fool
		if(usb_pcd_irq())
			break;
	}
	return 0;
}

int do_v2_usbtool (cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[])
{
    int rc = 0;
    unsigned timeout = simple_strtoul(argv[1], NULL, 0);

    optimus_work_mode_set(OPTIMUS_WORK_MODE_USB_UPDATE);

	rc = v2_usbburning(timeout);
    close_usb_phy_clock(0);

    return rc;
}


U_BOOT_CMD(
	update,	2,	0,	do_v2_usbtool,
	"Enter v2 usbburning mode",
	"usbburning timeout"
);

