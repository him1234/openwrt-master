#
<<<<<<< HEAD
# Copyright (C) 2016-2018 Jason A. Donenfeld <Jason@zx2c4.com>
=======
# Copyright (C) 2016-2019 Jason A. Donenfeld <Jason@zx2c4.com>
>>>>>>> 2a18840cc773425668fdfd99429d74ef0ab3a8ef
# Copyright (C) 2016 Baptiste Jonglez <openwrt@bitsofnetworks.org>
# Copyright (C) 2016-2017 Dan Luedtke <mail@danrl.com>
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.

include $(TOPDIR)/rules.mk
include $(INCLUDE_DIR)/kernel.mk

PKG_NAME:=wireguard

<<<<<<< HEAD
PKG_VERSION:=0.0.20190601
PKG_RELEASE:=1

PKG_SOURCE:=WireGuard-$(PKG_VERSION).tar.xz
PKG_SOURCE_URL:=https://git.zx2c4.com/WireGuard/snapshot/
PKG_HASH:=7528461824a0174bd7d4f15e68d8f0ce9a8ea318411502b80759438e8ef65568
=======
PKG_VERSION:=0.0.20200215
PKG_RELEASE:=1

PKG_SOURCE:=wireguard-linux-compat-$(PKG_VERSION).tar.xz
PKG_SOURCE_URL:=https://git.zx2c4.com/wireguard-linux-compat/snapshot/
PKG_HASH:=0def6f3608ec06f6dfc454aa5281a7c38b06ff27096cb341448d20602da4e923
>>>>>>> 2a18840cc773425668fdfd99429d74ef0ab3a8ef

PKG_LICENSE:=GPL-2.0
PKG_LICENSE_FILES:=COPYING

PKG_BUILD_DIR:=$(KERNEL_BUILD_DIR)/wireguard-linux-compat-$(PKG_VERSION)
PKG_BUILD_PARALLEL:=1
PKG_USE_MIPS16:=0

# WireGuard's makefile needs this to know where to build the kernel module
export KERNELDIR:=$(LINUX_DIR)

include $(INCLUDE_DIR)/package.mk

define Package/wireguard/Default
  SECTION:=net
  CATEGORY:=Network
  SUBMENU:=VPN
  URL:=https://www.wireguard.com
<<<<<<< HEAD
  MAINTAINER:=Jason A. Donenfeld <Jason@zx2c4.com> \
              Kevin Darbyshire-Bryant <ldir@darbyshire-bryant.me.uk>
=======
  MAINTAINER:=Jason A. Donenfeld <Jason@zx2c4.com>
>>>>>>> 2a18840cc773425668fdfd99429d74ef0ab3a8ef
endef

define Package/wireguard/Default/description
  WireGuard is a novel VPN that runs inside the Linux Kernel and utilizes
  state-of-the-art cryptography. It aims to be faster, simpler, leaner, and
  more useful than IPSec, while avoiding the massive headache. It intends to
  be considerably more performant than OpenVPN.  WireGuard is designed as a
  general purpose VPN for running on embedded interfaces and super computers
  alike, fit for many different circumstances. It uses UDP.
endef

define Package/wireguard
  $(call Package/wireguard/Default)
  TITLE:=WireGuard meta-package
  DEPENDS:=+wireguard-tools +kmod-wireguard
endef

include $(INCLUDE_DIR)/kernel-defaults.mk
include $(INCLUDE_DIR)/package-defaults.mk

<<<<<<< HEAD
# Used by Build/Compile/Default
MAKE_PATH:=src/tools
MAKE_VARS += PLATFORM=linux

=======
>>>>>>> 2a18840cc773425668fdfd99429d74ef0ab3a8ef
define Build/Compile
	$(MAKE) $(KERNEL_MAKEOPTS) M="$(PKG_BUILD_DIR)/src" modules
endef

define Package/wireguard/install
  true
endef

define Package/wireguard/description
  $(call Package/wireguard/Default/description)
endef

<<<<<<< HEAD
define Package/wireguard-tools
  $(call Package/wireguard/Default)
  TITLE:=WireGuard userspace control program (wg)
  DEPENDS:=+libmnl +ip
endef

define Package/wireguard-tools/description
  $(call Package/wireguard/Default/description)

  This package provides the userspace control program for WireGuard,
  `wg(8)`, a netifd protocol helper, and a re-resolve watchdog script.
endef

define Package/wireguard-tools/install
	$(INSTALL_DIR) $(1)/usr/bin/
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/src/tools/wg $(1)/usr/bin/
	$(INSTALL_BIN) ./files/wireguard_watchdog $(1)/usr/bin/
	$(INSTALL_DIR) $(1)/lib/netifd/proto/
	$(INSTALL_BIN) ./files/wireguard.sh $(1)/lib/netifd/proto/
endef

=======
>>>>>>> 2a18840cc773425668fdfd99429d74ef0ab3a8ef
define KernelPackage/wireguard
  SECTION:=kernel
  CATEGORY:=Kernel modules
  SUBMENU:=Network Support
  TITLE:=WireGuard kernel module
  DEPENDS:=+IPV6:kmod-udptunnel6 +kmod-udptunnel4
  FILES:= $(PKG_BUILD_DIR)/src/wireguard.$(LINUX_KMOD_SUFFIX)
  AUTOLOAD:=$(call AutoProbe,wireguard)
endef

define KernelPackage/wireguard/description
  $(call Package/wireguard/Default/description)

  This package provides the kernel module for WireGuard.
endef

$(eval $(call BuildPackage,wireguard))
$(eval $(call KernelPackage,wireguard))
