# Copyright (c) 2015 OpenWrt.org
#
include $(TOPDIR)/rules.mk

ARCH:=arm
BOARD:=mediatek
BOARDNAME:=MediaTek Ralink ARM
<<<<<<< HEAD
SUBTARGETS:=mt7622 mt7623
FEATURES:=squashfs nand ramdisk fpu
MAINTAINER:=John Crispin <john@phrozen.org>

KERNEL_PATCHVER:=4.14
=======
SUBTARGETS:=mt7622 mt7623 mt7629
FEATURES:=squashfs nand ramdisk fpu
MAINTAINER:=John Crispin <john@phrozen.org>

KERNEL_PATCHVER:=4.19
KERNEL_TESTING_PATCHVER:=5.4
>>>>>>> 2a18840cc773425668fdfd99429d74ef0ab3a8ef

include $(INCLUDE_DIR)/target.mk
DEFAULT_PACKAGES += \
	kmod-mt76 kmod-leds-gpio kmod-gpio-button-hotplug \
	wpad-basic

$(eval $(call BuildTarget))
