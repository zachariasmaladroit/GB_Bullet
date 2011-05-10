#!/bin/bash
# set environment
RAMDISK="../ramdisk"
CCTC="/home/curtis/VIBEDEV/arm-2009q3/bin/arm-none-linux-gnueabi-"
# start off clean
make ARCH=arm clean
# prepare source to allow us building of modules first
export LOCALVERSION="-I9000XWJVB-CL118186"
make -j8 ARCH=arm CROSS_COMPILE=$CCTC prepare
# build modules before kernel
make -j8 ARCH=arm CROSS_COMPILE=$CCTC modules
# copy ready modules into ramdisk
# find -name *.ko -exec cp -v {} $RAMDISK/lib/modules/ \;
# build kernel
make -j8 ARCH=arm CROSS_COMPILE=$CCTC
# verify kernel is ready and of good size
ls -alh arch/arm/boot/zImage
