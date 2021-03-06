/* drivers/video/msm/mipi_sharp_cmd_flute_fwvga_pt.c  (Display Driver)
 *
 * Copyright (C) 2011-2012 SHARP CORPORATION
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#include "msm_fb.h"
#include "mipi_dsi.h"
#include "mipi_sharp_flute.h"
#include <sharp/shdisp_kerl.h>

static struct msm_panel_info pinfo;

static struct mipi_dsi_phy_ctrl dsi_cmd_mode_phy_db = {
	/* regulator */
	{0x03, 0x01, 0x01, 0x00, 0x20},
	/* timing    */
	{0x55, 0x1D, 0x15, 0x00, 0x58, 0x2D, 0x19, 0x1F, 0x18, 0x03, 0x04, 0x00},
	/* phy ctrl  */
	{0x7F, 0x00, 0x00, 0x10},
	/* strength  */
	{0xEE, 0x02, 0x86, 0x00},
	/* pll control */
	{0x00, 0x38, 0x31, 0xD8, 0x00, 0x50, 0x48, 0x63,
	 0x31, 0x0F, 0x07, /*  --> Four lane configuration */
	 0x05, 0x14, 0x03, 0x00, 0x02, 0x54, 0x06, 0x10, 0x04, 0x00},
};

static int __init mipi_cmd_sharp_flute_fwvga_pt_init(void)
{
	int ret;

#ifdef CONFIG_FB_MSM_MIPI_PANEL_DETECT
	if (msm_fb_detect_client("mipi_cmd_sharp_flute_fwvga"))
		return 0;
#endif

#if defined(CONFIG_SHDISP_PANEL_SWITCH)
	printk(KERN_INFO "[SHDISP]%s\n", __func__);
#endif

	pinfo.xres = 480;
	pinfo.yres = 854;
	pinfo.type = MIPI_CMD_PANEL;
	pinfo.pdest = DISPLAY_1;
	pinfo.wait_cycle = 0;
	pinfo.bpp = 24;
	pinfo.bl_max = 255;
	pinfo.bl_min = 1;
	pinfo.fb_num = 2;
    pinfo.clk_rate = 338040000;
    pinfo.clk_min  = 338040000;
    pinfo.clk_max  = 338040000;
	pinfo.is_3d_panel = 0;
	pinfo.lcd.vsync_enable = TRUE;
	pinfo.lcd.refx100 = 6000;
	pinfo.lcd.hw_vsync_mode = TRUE;
	pinfo.lcdc.h_back_porch = 20;
	pinfo.lcdc.h_front_porch = 8;
	pinfo.lcdc.h_pulse_width = 8;
	pinfo.lcdc.v_back_porch = 20;	/* v timing adjusted for internal CR clock */
	pinfo.lcdc.v_front_porch = 30;	/* v timing adjusted for internal CR clock */
	pinfo.lcdc.v_pulse_width = 2;
	pinfo.lcdc.border_clr = 0;
	pinfo.lcdc.underflow_clr = 0;
	pinfo.lcdc.hsync_skew = 0;
	pinfo.mipi.mode = DSI_CMD_MODE;
	pinfo.mipi.dst_format = DSI_CMD_DST_FORMAT_RGB888;
	pinfo.mipi.data_lane0 = TRUE;
	pinfo.mipi.data_lane1 = TRUE;
	pinfo.mipi.data_lane2 = FALSE;
	pinfo.mipi.data_lane3 = FALSE;
	pinfo.mipi.esc_byte_ratio = 3;
	pinfo.mipi.rgb_swap = DSI_RGB_SWAP_RGB;
	pinfo.mipi.tx_eot_append = TRUE;
	pinfo.mipi.t_clk_post = 0x00;
	pinfo.mipi.t_clk_pre = 0x12;
	pinfo.mipi.vc = 0;
	pinfo.mipi.dsi_phy_db = &dsi_cmd_mode_phy_db;
	pinfo.mipi.pulse_mode_hsa_he = FALSE;
	pinfo.mipi.hfp_power_stop = FALSE;
	pinfo.mipi.hbp_power_stop = FALSE;
	pinfo.mipi.hsa_power_stop = FALSE;
	pinfo.mipi.eof_bllp_power_stop = TRUE;
	pinfo.mipi.bllp_power_stop = TRUE;
	pinfo.mipi.traffic_mode = DSI_NON_BURST_SYNCH_EVENT;
	pinfo.mipi.frame_rate = 60;
	pinfo.mipi.interleave_max = 1;
	pinfo.mipi.insert_dcs_cmd = TRUE;
	pinfo.mipi.wr_mem_continue = 0x3c;
	pinfo.mipi.wr_mem_start = 0x2c;
	pinfo.mipi.te_sel = 1;
	pinfo.mipi.stream = 0;
	pinfo.mipi.mdp_trigger = DSI_CMD_TRIGGER_NONE;
	pinfo.mipi.dma_trigger = DSI_CMD_TRIGGER_SW;
	pinfo.mipi.force_clk_lane_hs = TRUE;

	ret = mipi_sharp_flute_device_register(&pinfo, MIPI_DSI_PRIM,
						MIPI_DSI_PANEL_FWVGA_PT);
	if (ret)
		pr_err("%s: failed to register device!\n", __func__);

	return ret;
}

module_init(mipi_cmd_sharp_flute_fwvga_pt_init);
