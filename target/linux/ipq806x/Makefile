# Copyright (c) 2013 The Linux Foundation. All rights reserved.
#
include $(TOPDIR)/rules.mk

ARCH:=arm
BOARD:=ipq806x
BOARDNAME:=Qualcomm Atheros IPQ806X
FEATURES:=squashfs nand fpu ramdisk
CPU_TYPE:=cortex-a15
CPU_SUBTYPE:=neon-vfpv4
MAINTAINER:=John Crispin <john@phrozen.org>
SUBTARGETS:=generic

<<<<<<< HEAD
KERNEL_PATCHVER:=4.14
=======
KERNEL_PATCHVER:=4.19
KERNEL_TESTING_PATCHVER:=5.4
>>>>>>> 2a18840cc773425668fdfd99429d74ef0ab3a8ef

KERNELNAME:=zImage Image dtbs

include $(INCLUDE_DIR)/target.mk
DEFAULT_PACKAGES += \
	kmod-leds-gpio kmod-gpio-button-hotplug swconfig \
	kmod-ata-ahci kmod-ata-ahci-platform \
	kmod-usb-ohci kmod-usb2 kmod-usb-ledtrig-usbport \
	kmod-usb-phy-qcom-dwc3 kmod-usb3 kmod-usb-dwc3-qcom \
	kmod-ath10k-ct wpad-basic \
	uboot-envtools

$(eval $(call BuildTarget))
