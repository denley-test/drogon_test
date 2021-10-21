#!/usr/bin/env bash

set -e

IS_LINUX=false
IS_LINUX_RPI=false
IS_MAC=false
IS_WIN=false
USE_KERNEL_NUM=$(nproc --all)

NAME=$(uname -s)
if [ "${NAME}" = "Linux" ]; then
  if [ "$(arch)" = "armv7l" ]; then
    PLATFORM_NAME="linux_rpi"
    IS_LINUX_RPI=true
    USE_KERNEL_NUM=1
  else
    PLATFORM_NAME="linux"
    IS_LINUX=true
  fi
elif [ "${NAME}" = "Darwin" ]; then
  PLATFORM_NAME="mac"
  IS_MAC=true
elif [ "${NAME}" = "Windows" ]; then
  PLATFORM_NAME="win"
  IS_WIN=true
else
  PLATFORM_NAME="Unknown platform name"
fi

PLATFORM_BITS=$(getconf LONG_BIT)
