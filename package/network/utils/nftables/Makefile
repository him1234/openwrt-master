# Copyright (C) 2015 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=nftables
<<<<<<< HEAD
PKG_VERSION:=0.9.0
PKG_RELEASE:=2

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_URL:=https://netfilter.org/projects/$(PKG_NAME)/files
PKG_HASH:=ad8181b5fcb9ca572f444bed54018749588522ee97e4c21922648bb78d7e7e91
=======
PKG_VERSION:=0.9.2
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_URL:=https://netfilter.org/projects/$(PKG_NAME)/files
PKG_HASH:=5cb66180143e6bfc774f4eb316206d40ac1cb6df269a90882404cbf7165513f5
>>>>>>> 2a18840cc773425668fdfd99429d74ef0ab3a8ef
PKG_MAINTAINER:=Steven Barth <steven@midlink.org>
PKG_LICENSE:=GPL-2.0

PKG_FIXUP:=autoreconf
PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

DISABLE_NLS:=

CONFIGURE_ARGS += \
        --disable-debug \
        --disable-man-doc \
        --with-mini-gmp \
        --without-cli \
        --disable-python \

define Package/nftables
  SECTION:=net
  CATEGORY:=Network
  SUBMENU:=Firewall
  TITLE:=nftables packet filtering userspace utility
  DEPENDS:=+kmod-nft-core +libnftnl +PACKAGE_NFT_WITH_JSON:jansson
  URL:=http://netfilter.org/projects/nftables/
endef

define Package/nftables/config
	config PACKAGE_NFT_WITH_JSON
		bool "Build nftables with json support"
		depends on PACKAGE_nftables
		default n
endef

ifeq ($(CONFIG_PACKAGE_NFT_WITH_JSON),y)
CONFIGURE_ARGS += --with-json
endif

define Package/nftables/install
	$(INSTALL_DIR) $(1)/usr/sbin
	$(CP) $(PKG_INSTALL_DIR)/usr/sbin/nft $(1)/usr/sbin/
	$(INSTALL_DIR) $(1)/usr/lib
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/*.so* $(1)/usr/lib/
endef

$(eval $(call BuildPackage,nftables))
