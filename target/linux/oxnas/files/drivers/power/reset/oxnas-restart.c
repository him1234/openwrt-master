// SPDX-License-Identifier: (GPL-2.0)
/*
 * oxnas SoC reset driver
 * based on:
 * Microsemi MIPS SoC reset driver
 * and ox820_assert_system_reset() written by Ma Hajun <mahaijuns@gmail.com>
 *
 * License: GPL
 * Copyright (c) 2013 Ma Hajun <mahaijuns@gmail.com>
 * Copyright (c) 2017 Microsemi Corporation
 * Copyright (c) 2019 Daniel Golle <daniel@makrotopia.org>
 */
#include <linux/delay.h>
#include <linux/io.h>
#include <linux/notifier.h>
#include <linux/mfd/syscon.h>
#include <linux/of_address.h>
#include <linux/of_device.h>
#include <linux/platform_device.h>
#include <linux/reboot.h>
#include <linux/regmap.h>

/* bit numbers of reset control register */
<<<<<<< HEAD
#define SYS_CTRL_RST_SCU                0
#define SYS_CTRL_RST_COPRO              1
#define SYS_CTRL_RST_ARM0               2
#define SYS_CTRL_RST_ARM1               3
#define SYS_CTRL_RST_USBHS              4
#define SYS_CTRL_RST_USBHSPHYA          5
#define SYS_CTRL_RST_MACA               6
#define SYS_CTRL_RST_MAC                SYS_CTRL_RST_MACA
#define SYS_CTRL_RST_PCIEA              7
#define SYS_CTRL_RST_SGDMA              8
#define SYS_CTRL_RST_CIPHER             9
#define SYS_CTRL_RST_DDR                10
#define SYS_CTRL_RST_SATA               11
#define SYS_CTRL_RST_SATA_LINK          12
#define SYS_CTRL_RST_SATA_PHY           13
#define SYS_CTRL_RST_PCIEPHY            14
#define SYS_CTRL_RST_STATIC             15
#define SYS_CTRL_RST_GPIO               16
#define SYS_CTRL_RST_UART1              17
#define SYS_CTRL_RST_UART2              18
#define SYS_CTRL_RST_MISC               19
#define SYS_CTRL_RST_I2S                20
#define SYS_CTRL_RST_SD                 21
#define SYS_CTRL_RST_MACB               22
#define SYS_CTRL_RST_PCIEB              23
#define SYS_CTRL_RST_VIDEO              24
#define SYS_CTRL_RST_DDR_PHY            25
#define SYS_CTRL_RST_USBHSPHYB          26
#define SYS_CTRL_RST_USBDEV             27
#define SYS_CTRL_RST_ARMDBG             29
#define SYS_CTRL_RST_PLLA               30
#define SYS_CTRL_RST_PLLB               31

/* bit numbers of clock control register */
#define SYS_CTRL_CLK_COPRO              0
#define SYS_CTRL_CLK_DMA                1
#define SYS_CTRL_CLK_CIPHER             2
#define SYS_CTRL_CLK_SD                 3
#define SYS_CTRL_CLK_SATA               4
#define SYS_CTRL_CLK_I2S                5
#define SYS_CTRL_CLK_USBHS              6
#define SYS_CTRL_CLK_MACA               7
#define SYS_CTRL_CLK_MAC                SYS_CTRL_CLK_MACA
#define SYS_CTRL_CLK_PCIEA              8
#define SYS_CTRL_CLK_STATIC             9
#define SYS_CTRL_CLK_MACB               10
#define SYS_CTRL_CLK_PCIEB              11
#define SYS_CTRL_CLK_REF600             12
#define SYS_CTRL_CLK_USBDEV             13
#define SYS_CTRL_CLK_DDR                14
#define SYS_CTRL_CLK_DDRPHY             15
#define SYS_CTRL_CLK_DDRCK              16

/* Regmap offsets */
#define CLK_SET_REGOFFSET               0x2c
#define CLK_CLR_REGOFFSET               0x30
#define RST_SET_REGOFFSET               0x34
#define RST_CLR_REGOFFSET               0x38
#define SECONDARY_SEL_REGOFFSET         0x14
#define TERTIARY_SEL_REGOFFSET          0x8c
#define QUATERNARY_SEL_REGOFFSET        0x94
#define DEBUG_SEL_REGOFFSET             0x9c
#define ALTERNATIVE_SEL_REGOFFSET       0xa4
#define PULLUP_SEL_REGOFFSET            0xac
#define SEC_SECONDARY_SEL_REGOFFSET     0x100014
#define SEC_TERTIARY_SEL_REGOFFSET      0x10008c
#define SEC_QUATERNARY_SEL_REGOFFSET    0x100094
#define SEC_DEBUG_SEL_REGOFFSET         0x10009c
#define SEC_ALTERNATIVE_SEL_REGOFFSET   0x1000a4
#define SEC_PULLUP_SEL_REGOFFSET        0x1000ac
=======
#define OX820_SYS_CTRL_RST_SCU                0
#define OX820_SYS_CTRL_RST_COPRO              1
#define OX820_SYS_CTRL_RST_ARM0               2
#define OX820_SYS_CTRL_RST_ARM1               3
#define OX820_SYS_CTRL_RST_USBHS              4
#define OX820_SYS_CTRL_RST_USBHSPHYA          5
#define OX820_SYS_CTRL_RST_MACA               6
#define OX820_SYS_CTRL_RST_MAC                OX820_SYS_CTRL_RST_MACA
#define OX820_SYS_CTRL_RST_PCIEA              7
#define OX820_SYS_CTRL_RST_SGDMA              8
#define OX820_SYS_CTRL_RST_CIPHER             9
#define OX820_SYS_CTRL_RST_DDR                10
#define OX820_SYS_CTRL_RST_SATA               11
#define OX820_SYS_CTRL_RST_SATA_LINK          12
#define OX820_SYS_CTRL_RST_SATA_PHY           13
#define OX820_SYS_CTRL_RST_PCIEPHY            14
#define OX820_SYS_CTRL_RST_STATIC             15
#define OX820_SYS_CTRL_RST_GPIO               16
#define OX820_SYS_CTRL_RST_UART1              17
#define OX820_SYS_CTRL_RST_UART2              18
#define OX820_SYS_CTRL_RST_MISC               19
#define OX820_SYS_CTRL_RST_I2S                20
#define OX820_SYS_CTRL_RST_SD                 21
#define OX820_SYS_CTRL_RST_MACB               22
#define OX820_SYS_CTRL_RST_PCIEB              23
#define OX820_SYS_CTRL_RST_VIDEO              24
#define OX820_SYS_CTRL_RST_DDR_PHY            25
#define OX820_SYS_CTRL_RST_USBHSPHYB          26
#define OX820_SYS_CTRL_RST_USBDEV             27
#define OX820_SYS_CTRL_RST_ARMDBG             29
#define OX820_SYS_CTRL_RST_PLLA               30
#define OX820_SYS_CTRL_RST_PLLB               31

/* bit numbers of clock control register */
#define OX820_SYS_CTRL_CLK_COPRO              0
#define OX820_SYS_CTRL_CLK_DMA                1
#define OX820_SYS_CTRL_CLK_CIPHER             2
#define OX820_SYS_CTRL_CLK_SD                 3
#define OX820_SYS_CTRL_CLK_SATA               4
#define OX820_SYS_CTRL_CLK_I2S                5
#define OX820_SYS_CTRL_CLK_USBHS              6
#define OX820_SYS_CTRL_CLK_MACA               7
#define OX820_SYS_CTRL_CLK_MAC                OX820_SYS_CTRL_CLK_MACA
#define OX820_SYS_CTRL_CLK_PCIEA              8
#define OX820_SYS_CTRL_CLK_STATIC             9
#define OX820_SYS_CTRL_CLK_MACB               10
#define OX820_SYS_CTRL_CLK_PCIEB              11
#define OX820_SYS_CTRL_CLK_REF600             12
#define OX820_SYS_CTRL_CLK_USBDEV             13
#define OX820_SYS_CTRL_CLK_DDR                14
#define OX820_SYS_CTRL_CLK_DDRPHY             15
#define OX820_SYS_CTRL_CLK_DDRCK              16

/* Regmap offsets */
#define OX820_CLK_SET_REGOFFSET               0x2c
#define OX820_CLK_CLR_REGOFFSET               0x30
#define OX820_RST_SET_REGOFFSET               0x34
#define OX820_RST_CLR_REGOFFSET               0x38
#define OX820_SECONDARY_SEL_REGOFFSET         0x14
#define OX820_TERTIARY_SEL_REGOFFSET          0x8c
#define OX820_QUATERNARY_SEL_REGOFFSET        0x94
#define OX820_DEBUG_SEL_REGOFFSET             0x9c
#define OX820_ALTERNATIVE_SEL_REGOFFSET       0xa4
#define OX820_PULLUP_SEL_REGOFFSET            0xac
#define OX820_SEC_SECONDARY_SEL_REGOFFSET     0x100014
#define OX820_SEC_TERTIARY_SEL_REGOFFSET      0x10008c
#define OX820_SEC_QUATERNARY_SEL_REGOFFSET    0x100094
#define OX820_SEC_DEBUG_SEL_REGOFFSET         0x10009c
#define OX820_SEC_ALTERNATIVE_SEL_REGOFFSET   0x1000a4
#define OX820_SEC_PULLUP_SEL_REGOFFSET        0x1000ac
>>>>>>> 2a18840cc773425668fdfd99429d74ef0ab3a8ef


struct oxnas_restart_context {
	struct regmap *sys_ctrl;
	struct notifier_block restart_handler;
};

<<<<<<< HEAD
static int oxnas_restart_handle(struct notifier_block *this,
=======
static int ox820_restart_handle(struct notifier_block *this,
>>>>>>> 2a18840cc773425668fdfd99429d74ef0ab3a8ef
				 unsigned long mode, void *cmd)
{
	struct oxnas_restart_context *ctx = container_of(this, struct
							oxnas_restart_context,
							restart_handler);
	u32 value;

	/* Assert reset to cores as per power on defaults
	 * Don't touch the DDR interface as things will come to an impromptu stop
	 * NB Possibly should be asserting reset for PLLB, but there are timing
	 *    concerns here according to the docs */
<<<<<<< HEAD
	value = BIT(SYS_CTRL_RST_COPRO)		|
		BIT(SYS_CTRL_RST_USBHS)		|
		BIT(SYS_CTRL_RST_USBHSPHYA)	|
		BIT(SYS_CTRL_RST_MACA)		|
		BIT(SYS_CTRL_RST_PCIEA)		|
		BIT(SYS_CTRL_RST_SGDMA)		|
		BIT(SYS_CTRL_RST_CIPHER)	|
		BIT(SYS_CTRL_RST_SATA)		|
		BIT(SYS_CTRL_RST_SATA_LINK)	|
		BIT(SYS_CTRL_RST_SATA_PHY)	|
		BIT(SYS_CTRL_RST_PCIEPHY)	|
		BIT(SYS_CTRL_RST_STATIC)	|
		BIT(SYS_CTRL_RST_UART1)		|
		BIT(SYS_CTRL_RST_UART2)		|
		BIT(SYS_CTRL_RST_MISC)		|
		BIT(SYS_CTRL_RST_I2S)		|
		BIT(SYS_CTRL_RST_SD)		|
		BIT(SYS_CTRL_RST_MACB)		|
		BIT(SYS_CTRL_RST_PCIEB)		|
		BIT(SYS_CTRL_RST_VIDEO)		|
		BIT(SYS_CTRL_RST_USBHSPHYB)	|
		BIT(SYS_CTRL_RST_USBDEV);

	regmap_write(ctx->sys_ctrl, RST_SET_REGOFFSET, value);

	/* Release reset to cores as per power on defaults */
	regmap_write(ctx->sys_ctrl, RST_CLR_REGOFFSET, BIT(SYS_CTRL_RST_GPIO));
=======
	value = BIT(OX820_SYS_CTRL_RST_COPRO)		|
		BIT(OX820_SYS_CTRL_RST_USBHS)		|
		BIT(OX820_SYS_CTRL_RST_USBHSPHYA)	|
		BIT(OX820_SYS_CTRL_RST_MACA)		|
		BIT(OX820_SYS_CTRL_RST_PCIEA)		|
		BIT(OX820_SYS_CTRL_RST_SGDMA)		|
		BIT(OX820_SYS_CTRL_RST_CIPHER)		|
		BIT(OX820_SYS_CTRL_RST_SATA)		|
		BIT(OX820_SYS_CTRL_RST_SATA_LINK)	|
		BIT(OX820_SYS_CTRL_RST_SATA_PHY)	|
		BIT(OX820_SYS_CTRL_RST_PCIEPHY)		|
		BIT(OX820_SYS_CTRL_RST_STATIC)		|
		BIT(OX820_SYS_CTRL_RST_UART1)		|
		BIT(OX820_SYS_CTRL_RST_UART2)		|
		BIT(OX820_SYS_CTRL_RST_MISC)		|
		BIT(OX820_SYS_CTRL_RST_I2S)		|
		BIT(OX820_SYS_CTRL_RST_SD)		|
		BIT(OX820_SYS_CTRL_RST_MACB)		|
		BIT(OX820_SYS_CTRL_RST_PCIEB)		|
		BIT(OX820_SYS_CTRL_RST_VIDEO)		|
		BIT(OX820_SYS_CTRL_RST_USBHSPHYB)	|
		BIT(OX820_SYS_CTRL_RST_USBDEV);

	regmap_write(ctx->sys_ctrl, OX820_RST_SET_REGOFFSET, value);

	/* Release reset to cores as per power on defaults */
	regmap_write(ctx->sys_ctrl, OX820_RST_CLR_REGOFFSET, BIT(OX820_SYS_CTRL_RST_GPIO));
>>>>>>> 2a18840cc773425668fdfd99429d74ef0ab3a8ef

	/* Disable clocks to cores as per power-on defaults - must leave DDR
	 * related clocks enabled otherwise we'll stop rather abruptly. */
	value =
<<<<<<< HEAD
		BIT(SYS_CTRL_CLK_COPRO)		|
		BIT(SYS_CTRL_CLK_DMA)		|
		BIT(SYS_CTRL_CLK_CIPHER)	|
		BIT(SYS_CTRL_CLK_SD)		|
		BIT(SYS_CTRL_CLK_SATA)		|
		BIT(SYS_CTRL_CLK_I2S)		|
		BIT(SYS_CTRL_CLK_USBHS)		|
		BIT(SYS_CTRL_CLK_MAC)		|
		BIT(SYS_CTRL_CLK_PCIEA)		|
		BIT(SYS_CTRL_CLK_STATIC)	|
		BIT(SYS_CTRL_CLK_MACB)		|
		BIT(SYS_CTRL_CLK_PCIEB)		|
		BIT(SYS_CTRL_CLK_REF600)	|
		BIT(SYS_CTRL_CLK_USBDEV);

	regmap_write(ctx->sys_ctrl, CLK_CLR_REGOFFSET, value);
=======
		BIT(OX820_SYS_CTRL_CLK_COPRO)		|
		BIT(OX820_SYS_CTRL_CLK_DMA)		|
		BIT(OX820_SYS_CTRL_CLK_CIPHER)		|
		BIT(OX820_SYS_CTRL_CLK_SD)		|
		BIT(OX820_SYS_CTRL_CLK_SATA)		|
		BIT(OX820_SYS_CTRL_CLK_I2S)		|
		BIT(OX820_SYS_CTRL_CLK_USBHS)		|
		BIT(OX820_SYS_CTRL_CLK_MAC)		|
		BIT(OX820_SYS_CTRL_CLK_PCIEA)		|
		BIT(OX820_SYS_CTRL_CLK_STATIC)		|
		BIT(OX820_SYS_CTRL_CLK_MACB)		|
		BIT(OX820_SYS_CTRL_CLK_PCIEB)		|
		BIT(OX820_SYS_CTRL_CLK_REF600)		|
		BIT(OX820_SYS_CTRL_CLK_USBDEV);

	regmap_write(ctx->sys_ctrl, OX820_CLK_CLR_REGOFFSET, value);
>>>>>>> 2a18840cc773425668fdfd99429d74ef0ab3a8ef

	/* Enable clocks to cores as per power-on defaults */

	/* Set sys-control pin mux'ing as per power-on defaults */
<<<<<<< HEAD
	regmap_write(ctx->sys_ctrl, SECONDARY_SEL_REGOFFSET, 0);
	regmap_write(ctx->sys_ctrl, TERTIARY_SEL_REGOFFSET, 0);
	regmap_write(ctx->sys_ctrl, QUATERNARY_SEL_REGOFFSET, 0);
	regmap_write(ctx->sys_ctrl, DEBUG_SEL_REGOFFSET, 0);
	regmap_write(ctx->sys_ctrl, ALTERNATIVE_SEL_REGOFFSET, 0);
	regmap_write(ctx->sys_ctrl, PULLUP_SEL_REGOFFSET, 0);

	regmap_write(ctx->sys_ctrl, SEC_SECONDARY_SEL_REGOFFSET, 0);
	regmap_write(ctx->sys_ctrl, SEC_TERTIARY_SEL_REGOFFSET, 0);
	regmap_write(ctx->sys_ctrl, SEC_QUATERNARY_SEL_REGOFFSET, 0);
	regmap_write(ctx->sys_ctrl, SEC_DEBUG_SEL_REGOFFSET, 0);
	regmap_write(ctx->sys_ctrl, SEC_ALTERNATIVE_SEL_REGOFFSET, 0);
	regmap_write(ctx->sys_ctrl, SEC_PULLUP_SEL_REGOFFSET, 0);
=======
	regmap_write(ctx->sys_ctrl, OX820_SECONDARY_SEL_REGOFFSET, 0);
	regmap_write(ctx->sys_ctrl, OX820_TERTIARY_SEL_REGOFFSET, 0);
	regmap_write(ctx->sys_ctrl, OX820_QUATERNARY_SEL_REGOFFSET, 0);
	regmap_write(ctx->sys_ctrl, OX820_DEBUG_SEL_REGOFFSET, 0);
	regmap_write(ctx->sys_ctrl, OX820_ALTERNATIVE_SEL_REGOFFSET, 0);
	regmap_write(ctx->sys_ctrl, OX820_PULLUP_SEL_REGOFFSET, 0);

	regmap_write(ctx->sys_ctrl, OX820_SEC_SECONDARY_SEL_REGOFFSET, 0);
	regmap_write(ctx->sys_ctrl, OX820_SEC_TERTIARY_SEL_REGOFFSET, 0);
	regmap_write(ctx->sys_ctrl, OX820_SEC_QUATERNARY_SEL_REGOFFSET, 0);
	regmap_write(ctx->sys_ctrl, OX820_SEC_DEBUG_SEL_REGOFFSET, 0);
	regmap_write(ctx->sys_ctrl, OX820_SEC_ALTERNATIVE_SEL_REGOFFSET, 0);
	regmap_write(ctx->sys_ctrl, OX820_SEC_PULLUP_SEL_REGOFFSET, 0);
>>>>>>> 2a18840cc773425668fdfd99429d74ef0ab3a8ef

	/* No need to save any state, as the ROM loader can determine whether
	 * reset is due to power cycling or programatic action, just hit the
	 * (self-clearing) CPU reset bit of the block reset register */
	value =
<<<<<<< HEAD
		BIT(SYS_CTRL_RST_SCU) |
		BIT(SYS_CTRL_RST_ARM0) |
		BIT(SYS_CTRL_RST_ARM1);

	regmap_write(ctx->sys_ctrl, RST_SET_REGOFFSET, value);
=======
		BIT(OX820_SYS_CTRL_RST_SCU) |
		BIT(OX820_SYS_CTRL_RST_ARM0) |
		BIT(OX820_SYS_CTRL_RST_ARM1);

	regmap_write(ctx->sys_ctrl, OX820_RST_SET_REGOFFSET, value);
>>>>>>> 2a18840cc773425668fdfd99429d74ef0ab3a8ef

	pr_emerg("Unable to restart system\n");
	return NOTIFY_DONE;
}

<<<<<<< HEAD
static int oxnas_restart_probe(struct platform_device *pdev)
=======
static int ox820_restart_probe(struct platform_device *pdev)
>>>>>>> 2a18840cc773425668fdfd99429d74ef0ab3a8ef
{
	struct oxnas_restart_context *ctx;
	struct regmap *sys_ctrl;
	struct device *dev = &pdev->dev;
	int err = 0;

<<<<<<< HEAD
	sys_ctrl = syscon_regmap_lookup_by_compatible("oxsemi,ox820-sys-ctrl");
=======
	sys_ctrl = syscon_node_to_regmap(pdev->dev.of_node);
>>>>>>> 2a18840cc773425668fdfd99429d74ef0ab3a8ef
	if (IS_ERR(sys_ctrl))
		return PTR_ERR(sys_ctrl);

	ctx = devm_kzalloc(&pdev->dev, sizeof(*ctx), GFP_KERNEL);
	if (!ctx)
		return -ENOMEM;

	ctx->sys_ctrl = sys_ctrl;
<<<<<<< HEAD
	ctx->restart_handler.notifier_call = oxnas_restart_handle;
=======
	ctx->restart_handler.notifier_call = ox820_restart_handle;
>>>>>>> 2a18840cc773425668fdfd99429d74ef0ab3a8ef
	ctx->restart_handler.priority = 192;
	err = register_restart_handler(&ctx->restart_handler);
	if (err)
		dev_err(dev, "can't register restart notifier (err=%d)\n", err);

	return err;
}

<<<<<<< HEAD
static const struct of_device_id oxnas_restart_of_match[] = {
=======
static const struct of_device_id ox820_restart_of_match[] = {
>>>>>>> 2a18840cc773425668fdfd99429d74ef0ab3a8ef
	{ .compatible = "oxsemi,ox820-sys-ctrl" },
	{}
};

<<<<<<< HEAD
static struct platform_driver oxnas_restart_driver = {
	.probe = oxnas_restart_probe,
	.driver = {
		.name = "oxnas-chip-reset",
		.of_match_table = oxnas_restart_of_match,
	},
};
builtin_platform_driver(oxnas_restart_driver);
=======
static struct platform_driver ox820_restart_driver = {
	.probe = ox820_restart_probe,
	.driver = {
		.name = "ox820-chip-reset",
		.of_match_table = ox820_restart_of_match,
	},
};
builtin_platform_driver(ox820_restart_driver);
>>>>>>> 2a18840cc773425668fdfd99429d74ef0ab3a8ef
