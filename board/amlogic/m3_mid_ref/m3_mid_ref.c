
#include <common.h>
#include <asm/mach-types.h>
#include <asm/arch/memory.h>
#include <asm/arch/am_reg_addr.h>
#include <asm/arch/aml_card_sd.h>
#include <asm/arch/pinmux.h>
#include <asm/arch/am_eth_reg.h>
#include <asm/arch/clk_set.h>
#include <share_kernel.h>
#include <asm/arch/gpio.h>
#include <asm/arch/nand.h>
#include <linux/mtd/nand.h>
#include <linux/mtd/mtd.h>

#include <asm/arch/i2c.h>
#include <aml_i2c.h>

/**
 * Routine: board_init
 * Description: Early hardware init.
 */
//just compile pass 
struct aml_nand_platform aml_nand_mid_platform[] = {
    {
        .name = NAND_BOOT_NAME,
        .chip_enable_pad = AML_NAND_CE0,
        .ready_busy_pad = AML_NAND_CE0,
        .platform_nand_data = {
            .chip =  {
                .nr_chips = 1,
                .options = (NAND_TIMING_MODE5 | NAND_ECC_SHORT_MODE),
            },
        },
        .rbpin_mode=1,
        .short_pgsz=384,
        .ran_mode=0,
        .T_REA = 20,
        .T_RHOH = 15,
    },
    {
        .name = NAND_NORMAL_NAME,
        .chip_enable_pad = (AML_NAND_CE0) ,  //| (AML_NAND_CE1 << 4) | (AML_NAND_CE2 << 8) | (AML_NAND_CE3 << 12)),
        .ready_busy_pad = (AML_NAND_CE0) ,  //| (AML_NAND_CE0 << 4) | (AML_NAND_CE1 << 8) | (AML_NAND_CE1 << 12)),
        .platform_nand_data = {
            .chip =  {
                .nr_chips = 1,
                .options = (NAND_TIMING_MODE5 | NAND_ECC_BCH30_MODE),
            },
        },
        .rbpin_mode = 1,
        .short_pgsz = 0,
        .ran_mode = 0,
        .T_REA = 20,
        .T_RHOH = 15,
    }
    
};

struct aml_nand_device aml_nand_mid_device = {
    .aml_nand_platform = aml_nand_mid_platform,
    .dev_num = ARRAY_SIZE(aml_nand_mid_platform),
};

int board_init(void)
{
    /*
    @todo implement this function
    */
	DECLARE_GLOBAL_DATA_PTR;
	gd->bd->bi_arch_number=2958;
	gd->bd->bi_boot_params=BOOT_PARAMS_OFFSET;

#ifdef CONFIG_CMD_KGDB

	kgdb_init();
#endif

	return 0;
}

/*
 * Routine: misc_init_r
 * Description: Init ethernet (done here so udelay works)
 */
int misc_init_r(void)
{
/*
    @todo implement this function
    */

	return 0;
}

/*
 * Routine: set_muxconf_regs
 * Description: Setting up the configuration Mux registers specific to the
 *		hardware. Many pins need to be moved from protect to primary
 *		mode.
 */
void set_muxconf_regs(void)
{
    /*
    @todo implement this function
    */
}

#if defined(CONFIG_CMD_NET)
/*
 * Routine: setup_net_chip
 * Description: Setting up the configuration GPMC registers specific to the
 *		Ethernet hardware.
 */
static void setup_net_chip(void)
{
    /*
    @todo implement this function
    */
	
}

extern int aml_eth_init(bd_t *bis);
int board_eth_init(bd_t *bis)
{
	/* Use Misc PLL for the source of ethernet */
	eth_clk_set(ETH_CLKSRC_MISC_CLK, get_misc_pll_clk(), (50 * CLK_1M));
	/* Use Internal clock output from GPIOY0*/
	eth_set_pinmux(ETH_BANK0_GPIOY1_Y9, ETH_CLK_OUT_GPIOY0_REG6_17, 0);
	
	/*disalbe*/
	//reset:LCD_G5
	writel(readl(ETH_PLL_CNTL) & ~(1 << 0), ETH_PLL_CNTL); // Disable the Ethernet clocks     
	// ---------------------------------------------
	// Test 50Mhz Input Divide by 2
	// ---------------------------------------------
	// Select divide by 2
	writel(readl(ETH_PLL_CNTL) | (0 << 3), ETH_PLL_CNTL); // desc endianess "same order"   
	writel(readl(ETH_PLL_CNTL) | (0 << 2), ETH_PLL_CNTL); // data endianess "little"    
	writel(readl(ETH_PLL_CNTL) | (1 << 1), ETH_PLL_CNTL); // divide by 2 for 100M     
	writel(readl(ETH_PLL_CNTL) | (1 << 0), ETH_PLL_CNTL);  // enable Ethernet clocks   
	udelay(100);

	/* reset phy with GPIOA_23*/
	set_gpio_mode(GPIOA_bank_bit0_27(23), GPIOA_bit_bit0_27(23), GPIO_OUTPUT_MODE);
	set_gpio_val(GPIOA_bank_bit0_27(23), GPIOA_bit_bit0_27(23), 0);
	udelay(100);    //GPIOE_bank_bit16_21(16) reset end;
	set_gpio_val(GPIOA_bank_bit0_27(23), GPIOA_bit_bit0_27(23), 1);
	udelay(100);	//waiting reset end;
    aml_eth_init(bis);
    return 0;
}
#endif /* (CONFIG_CMD_NET) */

u32 get_board_rev(void)
{
    /*
    @todo implement this function
    */
	return 0x20;
}
static int  sdio_init(unsigned port)
{
	//setbits_le32(P_PREG_CGPIO_EN_N,1<<5);
    //todo add card detect 	
	setbits_le32(P_PREG_PAD_GPIO5_EN_N,1<<29);//CARD_6

    return cpu_sdio_init(port);
}
static int  sdio_detect(unsigned port)
{
	setbits_le32(P_PREG_PAD_GPIO5_EN_N,1<<29);//CARD_6
	return readl(P_PREG_PAD_GPIO5_I)&(1<<29)?1:0;
}
static void sdio_pwr_prepare(unsigned port)
{
    /// @todo NOT FINISH
	///do nothing here
}
static void sdio_pwr_on(unsigned port)
{
	clrbits_le32(P_PREG_PAD_GPIO5_O,(1<<31));
	clrbits_le32(P_PREG_PAD_GPIO5_EN_N,(1<<31));
    /// @todo NOT FINISH
}
static void sdio_pwr_off(unsigned port)
{
//	setbits_le32(P_PREG_CGPIO_O,(1<<5));
//	clrbits_le32(P_PREG_CGPIO_EN_N,(1<<5));//test_n
	setbits_le32(P_PREG_PAD_GPIO5_O,(1<<31));
	clrbits_le32(P_PREG_PAD_GPIO5_EN_N,(1<<31));//GPIOD13
	/// @todo NOT FINISH
}
static void board_mmc_register(unsigned port)
{
    AML_CARD_SD_INFO_t *aml_priv=cpu_sdio_get(port);
    if(aml_priv==NULL)
        return;
    struct mmc *mmc = (struct mmc *)malloc(sizeof(struct mmc));
    strncpy(mmc->name,aml_priv->name,31);
    mmc->priv = aml_priv;
	aml_priv->removed_flag = 1;
	aml_priv->inited_flag = 0;
	aml_priv->sdio_init=sdio_init;
	aml_priv->sdio_detect=sdio_detect;
	aml_priv->sdio_pwr_off=sdio_pwr_off;
	aml_priv->sdio_pwr_on=sdio_pwr_on;
	aml_priv->sdio_pwr_prepare=sdio_pwr_prepare;
	mmc->send_cmd = aml_sd_send_cmd;
	mmc->set_ios = aml_sd_cfg_swth;
	mmc->init = aml_sd_init;
	mmc->rca = 1;
	mmc->voltages = MMC_VDD_33_34;
	mmc->host_caps = MMC_MODE_4BIT | MMC_MODE_HS;
	//mmc->host_caps = MMC_MODE_4BIT;
	mmc->bus_width = 1;
	mmc->clock = 300000;
	mmc->f_min = 200000;
	mmc->f_max = 50000000;
	mmc_register(mmc);
}
int board_mmc_init(bd_t	*bis)
{
//	board_mmc_register(SDIO_PORT_A);
	board_mmc_register(SDIO_PORT_B);
//	board_mmc_register(SDIO_PORT_C);
//	board_mmc_register(SDIO_PORT_B1);
	return 0;
}

struct aml_i2c_platform aml_i2c_plat = {
    .wait_count     = 1000000,
    .wait_ack_interval  = 5,
    .wait_read_interval = 5,
    .wait_xfer_interval = 5,
    .master_no      = MASTER_AO,
    .use_pio            = 0,
    .master_i2c_speed   = AML_I2C_SPPED_400K,

    .master_ao_pinmux = {
        .scl_reg    = P_AO_RTI_PIN_MUX_REG,
        .scl_bit    = (1<<6),
        .sda_reg    = P_AO_RTI_PIN_MUX_REG,
        .sda_bit    = (1<<5),
    }
};



#ifdef CONFIG_SWITCH_BOOT_MODE

inline int get_key()
{
    int adc_val = get_adc_sample(4);
    printf("get_adc_sample(4): 0x%x\n", adc_val);
    return(((adc_val >= 0x320) && (adc_val < 0x370)) ? 1 : 0);
}

int switch_boot_mode(void)
{
    unsigned long hold_time = 50000, polling_time = 10000, tmp;
    unsigned long tag;

	

	act8942_init();
	act8942_dump();

	return	0;

	#ifdef CONFIG_EFUSE
		char *barg_addr;
		char *r_efus;
		char addr[20];
		char bootargs[384];
	#endif
	
    tag = simple_strtoul (getenv ("tag"), NULL, 16);
    printf("tag = %d    !!!!!!!!!!!!!!!!!!\n", tag);

    if(tag == 3)
    {
        switch(get_kernel_cmd())
        {
            case SYSTEM_REBOOT:
            {
                printf("SYSTEM_REBOOT...\n");
                return  1;
            }
            default:
            {
                printf("NORMAL_BOOT...\n");
                break;
            }
        }
    }
    else
    {
        printf("Upgrade step %d...\n", tag);
    }

    if(tag == 0)
    {
        if(upgrade_bootloader())
        {
            run_command ("set tag 1", 0);
            run_command ("save", 0);
            run_command ("reset", 0);
            hang();
        }
        else
        {
            printf("### ERROR:  u-boot write failed!!!\n");
            return  -1;
        }
    }
    else if((tag >0) && (tag < 3))
    {
        if(tag == 1)
        {
            if(upgrade_env())
            {
                run_command ("set tag 2", 0);
                run_command ("save", 0);
                run_command ("reset", 0);
                hang();
            }
            else
            {
                run_command ("defenv", 0);
                run_command ("save", 0);
            }
        }
        run_command ("set tag 3", 0);
        
        #ifdef CONFIG_EFUSE
			//r_addr = getenv ("ethaddr");
			if(efuse_chk_written(2)){
				r_efus = efuse_read_usr(2);
				memset(addr,0,sizeof(addr));
				sprintf(addr,"%02x:%02x:%02x:%02x:%02x:%02x",r_efus[0],r_efus[1],r_efus[2],r_efus[3],r_efus[4],r_efus[5]);
				printf("efuse mac is : %s \n", addr);
				//setenv ("ethaddr", addr);
				barg_addr = getenv ("bootargs");
				sprintf(bootargs,"set bootargs '%s mac=%s'",barg_addr,addr);
				run_command (bootargs, 0);
			}
		#endif
        run_command ("save", 0);
        
        upgrade_partition();
        return  1;
    }

    saradc_enable();

    //added by Elvis for added fool idle
    get_key();
    get_key();
    
    while(hold_time > 0)
    {
        udelay(polling_time);
        tmp = get_key();
        printf("get_key(): %d\n", tmp);
        if(!tmp)  break;
        hold_time -= polling_time;
    }

    if(hold_time > 0)
    {
        printf("Normal Start...\n");
        return  1;
    }
    else
    {
        if(upgrade_bootloader())
        {
            run_command ("set tag 1", 0);
            run_command ("save", 0);
            run_command ("reset", 0);
            hang();
        }
        if(upgrade_env())
        {
            run_command ("set tag 2", 0);
            run_command ("save", 0);
            run_command ("reset", 0);
            hang();
        }
        run_command ("set tag 3", 0);
        run_command ("save", 0);
        upgrade_partition();
    }
}
#endif