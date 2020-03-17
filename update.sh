opkg update
opkg install libustream-mbedtls
wget -O /tmp/update.bin https://github.com/him1234/openwrt-master/releases/download/latest/openwrt-ramips-mt7620-phicomm_psg1218a-squashfs-sysupgrade.bin
sysupgrade /tmp/update.bin
