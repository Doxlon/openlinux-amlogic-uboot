#include <amlogic/aml_tv.h>
#include <amlogic/enc_clk_config.h>
#include <asm/arch-m8/reg_addr.h>
#include <asm/arch-m8/io.h>
#include <asm/io.h>
#include "hdmi_tx_reg.h"

#define check_div() \
    if(div == -1)\
        return ;\
    switch(div){\
        case 1:\
            div = 0; break;\
        case 2:\
            div = 1; break;\
        case 4:\
            div = 2; break;\
        case 6:\
            div = 3; break;\
        case 12:\
            div = 4; break;\
        default:\
            break;\
    }

static void set_hpll_clk_out(unsigned clk)
{
    printf("config HPLL\n");
    aml_write_reg32_op(P_HHI_VID_PLL_CNTL2, 0x69c88000);
    aml_write_reg32_op(P_HHI_VID_PLL_CNTL3, 0xca563823);
    aml_write_reg32_op(P_HHI_VID_PLL_CNTL4, 0x00238100);
    aml_write_reg32_op(P_HHI_VID_PLL_CNTL5, 0x00012286);
    switch(clk){
        case 2970:
            aml_write_reg32_op(P_HHI_VID_PLL_CNTL2, 0x59c84e00);
            aml_write_reg32_op(P_HHI_VID_PLL_CNTL3, 0xce59c822);   // optimise HPLL VCO 2.97GHz performance
            aml_write_reg32_op(P_HHI_VID_PLL_CNTL4, 0x0123b100);
            aml_write_reg32_op(P_HHI_VID_PLL_CNTL5, 0x00012385);
            
            aml_write_reg32_op(P_HHI_VID_PLL_CNTL,  0x6000043d);
            aml_write_reg32_op(P_HHI_VID_PLL_CNTL,  0x4000043d);
            while(!(aml_read_reg32_op(P_HHI_VID_PLL_CNTL) & (1 << 31))) {
                ;
            }
            break;
        case 1488:
            aml_write_reg32_op(P_HHI_VID_PLL_CNTL,  0x6000043d);
            aml_write_reg32_op(P_HHI_VID_PLL_CNTL,  0x4000043d);
            while(!(aml_read_reg32_op(P_HHI_VID_PLL_CNTL) & (1 << 31))) {
                ;
            }
            aml_write_reg32_op(P_HHI_VID_PLL_CNTL2, 0x69c8ce00);
            break;
        case 1080:
            aml_write_reg32_op(P_HHI_VID_PLL_CNTL,  0x6000042d);
            aml_write_reg32_op(P_HHI_VID_PLL_CNTL,  0x4000042d);
            break;
        case 1066:
            aml_write_reg32_op(P_HHI_VID_PLL_CNTL, 0x42a);
            break;
        case 1058:
            aml_write_reg32_op(P_HHI_VID_PLL_CNTL, 0x422);
            break;
        case 1086:
            aml_write_reg32_op(P_HHI_VID_PLL_CNTL, 0x43e);
            break;
        default:
            break;
    }
}

static void set_hpll_hdmi_od(unsigned div)
{
    switch(div){
        case 1:
            aml_set_reg32_bits_op(P_HHI_VID_PLL_CNTL, 0, 18, 2);
            break;
        case 2:
            aml_set_reg32_bits_op(P_HHI_VID_PLL_CNTL, 1, 18, 2);
            break;
        case 3:
            aml_set_reg32_bits_op(P_HHI_VID_PLL_CNTL, 1, 16, 2);
            break;
        case 4:
            aml_set_reg32_bits_op(P_HHI_VID_PLL_CNTL, 3, 18, 2);
            break;
        default:
            break;
    }
}

static void set_hpll_lvds_od(unsigned div)
{
    switch(div) {
        case 1:
            aml_set_reg32_bits_op(P_HHI_VID_PLL_CNTL, 0, 16, 2);
            break;
        case 2:
            aml_set_reg32_bits_op(P_HHI_VID_PLL_CNTL, 1, 16, 2);
            break;
        case 4:
            aml_set_reg32_bits_op(P_HHI_VID_PLL_CNTL, 2, 16, 2);
            break;
        case 8:     // note: need test
            aml_set_reg32_bits_op(P_HHI_VID_PLL_CNTL, 3, 16, 2);
            break;
        default:
            break;
    }
}

// viu_channel_sel: 1 or 2
// viu_type_sel: 0: 0=ENCL, 1=ENCI, 2=ENCP, 3=ENCT.
int set_viu_path(unsigned viu_channel_sel, viu_type_e viu_type_sel)
{
    if((viu_channel_sel > 2) || (viu_channel_sel == 0))
        return -1;

    if(viu_channel_sel == 1){
        aml_set_reg32_bits_op(P_VPU_VIU_VENC_MUX_CTRL, viu_type_sel, 0, 2);
        printf("viu chan = 1\n");
    }
    else{
        //viu_channel_sel ==2
        aml_set_reg32_bits_op(P_VPU_VIU_VENC_MUX_CTRL, viu_type_sel, 2, 2);
        printf("viu chan = 2\n");
    }
    return 0;
}

static void set_vid_pll_div(unsigned div)
{
    // Gate disable
    aml_set_reg32_bits_op(P_HHI_VID_DIVIDER_CNTL, 0, 16, 1);
    switch(div){
        case 10:
            aml_set_reg32_bits_op(P_HHI_VID_DIVIDER_CNTL, 4, 4, 3);
            aml_set_reg32_bits_op(P_HHI_VID_DIVIDER_CNTL, 1, 8, 2);
            aml_set_reg32_bits_op(P_HHI_VID_DIVIDER_CNTL, 1, 12, 3);
            break;
        case 5:
            aml_set_reg32_bits_op(P_HHI_VID_DIVIDER_CNTL, 4, 4, 3);
            aml_set_reg32_bits_op(P_HHI_VID_DIVIDER_CNTL, 0, 8, 2);
            aml_set_reg32_bits_op(P_HHI_VID_DIVIDER_CNTL, 0, 12, 3);
            break;
        default:
            break;
    }
    // Soft Reset div_post/div_pre
    aml_set_reg32_bits_op(P_HHI_VID_DIVIDER_CNTL, 0, 0, 2);
    aml_set_reg32_bits_op(P_HHI_VID_DIVIDER_CNTL, 1, 3, 1);
    aml_set_reg32_bits_op(P_HHI_VID_DIVIDER_CNTL, 1, 7, 1);
    aml_set_reg32_bits_op(P_HHI_VID_DIVIDER_CNTL, 3, 0, 2);
    aml_set_reg32_bits_op(P_HHI_VID_DIVIDER_CNTL, 0, 3, 1);
    aml_set_reg32_bits_op(P_HHI_VID_DIVIDER_CNTL, 0, 7, 1);
    // Gate enable
    aml_set_reg32_bits_op(P_HHI_VID_DIVIDER_CNTL, 1, 16, 1);
}

static void set_clk_final_div(unsigned div)
{
    if(div == 0)
        div = 1;
    aml_set_reg32_bits_op(P_HHI_VID_CLK_CNTL, 1, 19, 1);
    aml_set_reg32_bits_op(P_HHI_VID_CLK_CNTL, 0, 16, 3);
    aml_set_reg32_bits_op(P_HHI_VID_CLK_DIV, div-1, 0, 8);
    aml_set_reg32_bits_op(P_HHI_VID_CLK_CNTL, 7, 0, 3);
}

static void set_hdmi_tx_pixel_div(unsigned div)
{
    check_div();
    aml_set_reg32_bits_op(P_HHI_HDMI_CLK_CNTL, div, 16, 4);
}
static void set_encp_div(unsigned div)
{
    check_div();
    aml_set_reg32_bits_op(P_HHI_VID_CLK_DIV, div, 24, 4);
}

static void set_enci_div(unsigned div)
{
    check_div();
    aml_set_reg32_bits_op(P_HHI_VID_CLK_DIV, div, 28, 4);
}

static void set_enct_div(unsigned div)
{
    check_div();
    aml_set_reg32_bits_op(P_HHI_VID_CLK_DIV, div, 20, 4);
}

static void set_encl_div(unsigned div)
{
    check_div();
    aml_set_reg32_bits_op(P_HHI_VIID_CLK_DIV, div, 12, 4);
}

static void set_vdac0_div(unsigned div)
{
    check_div();
    aml_set_reg32_bits_op(P_HHI_VIID_CLK_DIV, div, 28, 4);
}

static void set_vdac1_div(unsigned div)
{
    check_div();
    aml_set_reg32_bits_op(P_HHI_VIID_CLK_DIV, div, 24, 4);
}

// mode hpll_clk_out hpll_hdmi_od viu_path viu_type vid_pll_div clk_final_div
// hdmi_tx_pixel_div unsigned encp_div unsigned enci_div unsigned enct_div unsigned ecnl_div;
static enc_clk_val_t setting_enc_clk_val[] = {
    {VMODE_480I,       1080, 4, 1, 1, VIU_ENCI,  5, 4, 2,-1,  2, -1, -1,  2,  -1},
    {VMODE_480CVBS,    1080, 4, 1, 1, VIU_ENCI,  5, 4, 2,-1,  2, -1, -1,  2,  -1},
    {VMODE_480P,       1080, 4, 1, 1, VIU_ENCP,  5, 4, 2, 1, -1, -1, -1,  1,  -1},
    {VMODE_576I,       1080, 4, 1, 1, VIU_ENCI,  5, 4, 2,-1,  2, -1, -1,  2,  -1},
    {VMODE_576CVBS,    1080, 4, 1, 1, VIU_ENCI,  5, 4, 2,-1,  2, -1, -1,  2,  -1},
    {VMODE_576P,       1080, 4, 1, 1, VIU_ENCP,  5, 4, 2, 1, -1, -1, -1,  1,  -1},
    {VMODE_720P,       1488, 2, 1, 1, VIU_ENCP, 10, 1, 2, 1, -1, -1, -1,  1,  -1},
    {VMODE_1080I,      1488, 2, 1, 1, VIU_ENCP, 10, 1, 2, 1, -1, -1, -1,  1,  -1},
    {VMODE_1080P,      1488, 1, 1, 1, VIU_ENCP, 10, 1, 1, 1, -1, -1, -1,  1,  -1},
    {VMODE_1080P,      1488, 1, 1, 1, VIU_ENCP, 10, 1, 1, 1, -1, -1, -1,  1,  -1},
    {VMODE_720P_50HZ,  1488, 2, 1, 1, VIU_ENCP, 10, 1, 2, 1, -1, -1, -1,  1,  -1},
    {VMODE_1080I_50HZ, 1488, 2, 1, 1, VIU_ENCP, 10, 1, 2, 1, -1, -1, -1,  1,  -1},
    {VMODE_1080P_50HZ, 1488, 1, 1, 1, VIU_ENCP, 10, 1, 1, 1, -1, -1, -1,  1,  -1},
    {VMODE_1080P_24HZ, 1488, 2, 1, 1, VIU_ENCP, 10, 2, 1, 1, -1, -1, -1,  1,  -1},
    {VMODE_4K2K_30HZ,  2970, 1, 2, 1, VIU_ENCP,  5, 1, 1, 1, -1, -1, -1,  1,  -1},
    {VMODE_4K2K_25HZ,  2970, 1, 2, 1, VIU_ENCP,  5, 1, 1, 1, -1, -1, -1,  1,  -1},
    {VMODE_4K2K_24HZ,  2970, 1, 2, 1, VIU_ENCP,  5, 1, 1, 1, -1, -1, -1,  1,  -1},
    {VMODE_4K2K_SMPTE, 2970, 1, 2, 1, VIU_ENCP,  5, 1, 1, 1, -1, -1, -1,  1,  -1},
//    {VMODE_VGA,  1066, 3, 1, 1, VIU_ENCP, 10, 1, 2, 1, -1, -1, -1,  1,  1},
//    {VMODE_SVGA, 1058, 2, 1, 1, VIU_ENCP, 10, 1, 2, 1, -1, -1, -1,  1,  1},
//    {VMODE_XGA, 1085, 1, 1, 1, VIU_ENCP, 5, 1, 1, 1, -1, -1, -1,  1,  1},
};

void set_vmode_clk(vmode_t mode)
{
    enc_clk_val_t *p_enc = &setting_enc_clk_val[0];
    int i = sizeof(setting_enc_clk_val) / sizeof(enc_clk_val_t);
    int j = 0;
    
    printf("mode is: %d\n", mode);
    for (j = 0; j < i; j++){
        if(mode == p_enc[j].mode)
            break;
    }
    set_viu_path(p_enc[j].viu_path, p_enc[j].viu_type);
    set_hpll_clk_out(p_enc[j].hpll_clk_out);
    set_hpll_lvds_od(p_enc[j].hpll_lvds_od);
    set_hpll_hdmi_od(p_enc[j].hpll_hdmi_od);
    set_vid_pll_div(p_enc[j].vid_pll_div);
    set_clk_final_div(p_enc[j].clk_final_div);
    set_hdmi_tx_pixel_div(p_enc[j].hdmi_tx_pixel_div);
    set_encp_div(p_enc[j].encp_div);
    set_enci_div(p_enc[j].enci_div);
    set_enct_div(p_enc[j].enct_div);
    set_encl_div(p_enc[j].encl_div);
    set_vdac0_div(p_enc[j].vdac0_div);
    set_vdac1_div(p_enc[j].vdac1_div);
}
 
