#
# Copyright (C) 2016 LEDE
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk
include $(INCLUDE_DIR)/kernel.mk

PKG_NAME:=sched-cake
PKG_RELEASE:=1

PKG_SOURCE_PROTO:=git
PKG_SOURCE_URL:=https://github.com/dtaht/sch_cake.git
<<<<<<< HEAD
PKG_SOURCE_DATE:=2019-01-08
PKG_SOURCE_VERSION:=331ac70c8580544cd08a556579dc8807d9941d2e
PKG_MIRROR_HASH:=e2174531a92d1e9c48bcb74757399255aa205cb64f9863f307e357c5e23c3449
=======
PKG_SOURCE_DATE:=2020-01-10
PKG_SOURCE_VERSION:=aeff7a3e61ffa3159a8a95384d33e47a006211f4
PKG_MIRROR_HASH:=5bf06a804824db36ae393fc174aeec7b12633176e05a765c0931b39df5bd34df
>>>>>>> 2a18840cc773425668fdfd99429d74ef0ab3a8ef
PKG_MAINTAINER:=Kevin Darbyshire-Bryant <ldir@darbyshire-bryant.me.uk>

include $(INCLUDE_DIR)/package.mk

define KernelPackage/sched-cake
  SUBMENU:=Network Support
  TITLE:=Cake fq_codel/blue derived shaper
  URL:=https://github.com/dtaht/sch_cake
  FILES:=$(PKG_BUILD_DIR)/sch_cake.ko
  AUTOLOAD:=$(call AutoLoad,75,sch_cake)
  DEPENDS:=+kmod-ipt-conntrack
endef

include $(INCLUDE_DIR)/kernel-defaults.mk

define KernelPackage/sched-cake/description
  Common Applications Kept Enhanced fq_codel/blue derived shaper
endef

define Build/Compile
	$(KERNEL_MAKE) M="$(PKG_BUILD_DIR)" modules
endef

$(eval $(call KernelPackage,sched-cake))
