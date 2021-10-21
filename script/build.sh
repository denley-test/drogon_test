#!/usr/bin/env bash

set -e

CUR_PATH=$(cd $(dirname $0); pwd)
WORK_PATH=${CUR_PATH}/..
BUILD_PATH=${WORK_PATH}/build
source ${WORK_PATH}/script/common.sh

mkdir -p ${BUILD_PATH}
cd ${BUILD_PATH}
cmake -DCMAKE_INSTALL_PREFIX=../install .. && make -j${USE_KERNEL_NUM} && make test CTEST_OUTPUT_ON_FAILURE=TRUE

cd ${CUR_PATH}
