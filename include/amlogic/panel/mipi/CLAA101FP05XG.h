#ifndef PANEL_TYPICAL_TIMING_H
#define PANEL_TYPICAL_TIMING_H

//*****************************************
// Define LCD Typical Timing Parameters
//*****************************************
#define MODEL_NAME			"CLAA101FP05XG"	/** lcd model name */

#define ACITVE_AREA_WIDTH	216	/** lcd active_area or display_area horizontal size(unit in mm, you can find it on the home page of lcd spec) */
#define ACITVE_AREA_HEIGHT	135	/** lcd active_area or display_area vertical size(unit in mm, you can find it on the home page of lcd spec) */
#define LCD_TYPE			LCD_DIGITAL_MIPI   /** lcd interface(LCD_DIGITAL_MIPI, LCD_DIGITAL_LVDS, LCD_DIGITAL_EDP, LCD_DIGITAL_TTL) */
#define LCD_BITS			8	/** lcd bits(6, 8) */
#define BITS_OPTION			0	/** bits_option(0=only support one mode as LCD_BITS define, 1=both support 6/8bit) */

#define H_ACTIVE			1920	/** horizontal resolution */
#define V_ACTIVE			1200	/** vertical resolution */
#define H_PERIOD			2080	/** horizontal period(htotal) */
#define V_PERIOD			1235	/** vertical period(vtotal) */

#define	LCD_CLK				154128000	/** clock(unit in Hz, both support clk and frame_rate, >200 regard as clk, <200 regard as frame_rate) */
#define CLK_POL				1			/** clk_polarity(only valid for TTL) */
#define HS_WIDTH			32	/** hsync_width */
#define HS_BACK_PORCH		112	/** hsync_backporch(include hsync_width) */
#define HS_POL				0	/** hsync_polarity(0=negative, 1=positive) */
#define VS_WIDTH			6	/** vsync_width */
#define VS_BACK_PORCH		26	/** vsync_backporch(include vsync_width) */
#define VS_POL				0	/** vsync_polarity(0=negative, 1=positive) */
#define VSYNC_H_ADJUST_SIGN 0  /** 0=positive,1=negative */
#define VSYNC_H_ADJUST      0  /** adj_sign(0=positive, 1=negative), adj_value. default is 0 */
//************************************************
/** special power on command, 2 data is a pair(reg, value). if the first valu is 0xff, second value is delay time(unit: ms). ending flag is 0xff,0xff. */
static unsigned short dsi_power_on_cmd[] = {0xFF,0xFF};

#endif