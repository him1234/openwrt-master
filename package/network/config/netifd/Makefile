include $(TOPDIR)/rules.mk

PKG_NAME:=netifd
PKG_RELEASE:=2.1

PKG_SOURCE_PROTO:=git
PKG_SOURCE_URL=$(PROJECT_GIT)/project/netifd.git
<<<<<<< HEAD
PKG_SOURCE_DATE:=2019-01-31
PKG_SOURCE_VERSION:=a2aba5c7ae574452a9f81e9d788afecdd8ec07b2
PKG_MIRROR_HASH:=c5ff34aa401549e377c9e4ee5ce7443796a02bea743ecdc73f439cd942914c8d
=======
PKG_SOURCE_DATE:=2020-01-18
PKG_SOURCE_VERSION:=1321c1bd8fe921986c4eb39c3783ddd827b79543
PKG_MIRROR_HASH:=7e93ba79727e84cc391121be8a190cfa373dee8e2511f75d6f2fcb179928f5fa
>>>>>>> 2a18840cc773425668fdfd99429d74ef0ab3a8ef
PKG_MAINTAINER:=Felix Fietkau <nbd@nbd.name>

PKG_LICENSE:=GPL-2.0
PKG_LICENSE_FILES:=

PKG_BUILD_PARALLEL:=1

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/cmake.mk

define Package/netifd
  SECTION:=base
  CATEGORY:=Base system
  DEPENDS:=+libuci +libnl-tiny +libubus +ubus +ubusd +jshn +libubox
  TITLE:=OpenWrt Network Interface Configuration Daemon
endef

TARGET_CFLAGS += \
	-I$(STAGING_DIR)/usr/include/libnl-tiny \
	-I$(STAGING_DIR)/usr/include \
	-flto

TARGET_LDFLAGS += -flto -fuse-linker-plugin

CMAKE_OPTIONS += \
	-DLIBNL_LIBS=-lnl-tiny \
	-DDEBUG=1

define Package/netifd/install
	$(INSTALL_DIR) $(1)/sbin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/netifd $(1)/sbin/
	$(CP) ./files/* $(1)/
	$(CP) $(PKG_BUILD_DIR)/scripts/* $(1)/lib/netifd/
endef

$(eval $(call BuildPackage,netifd))
