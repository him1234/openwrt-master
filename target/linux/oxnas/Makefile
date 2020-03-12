include $(TOPDIR)/rules.mk

ARCH:=arm
BOARD:=oxnas
BOARDNAME:=PLXTECH/Oxford NAS782x/OX8xx
SUBTARGETS:=ox810se ox820
FEATURES:=gpio ramdisk rtc squashfs
DEVICE_TYPE:=nas

MAINTAINER:=Daniel Golle <daniel@makrotopia.org>

<<<<<<< HEAD
KERNEL_PATCHVER:=4.14
<<<<<<< HEAD
=======
KERNEL_TESTING_PATCHVER:=5.4
>>>>>>> 2a18840cc773425668fdfd99429d74ef0ab3a8ef
=======
KERNEL_PATCHVER:=5.4
>>>>>>> 763de7bd51f38f0b9e155bd6160d552d9a0fd2ae

include $(INCLUDE_DIR)/target.mk

DEFAULT_PACKAGES += \
	kmod-button-hotplug kmod-input-gpio-keys-polled \
	kmod-ledtrig-timer kmod-leds-gpio uboot-envtools

KERNELNAME:=zImage dtbs

$(eval $(call BuildTarget))
