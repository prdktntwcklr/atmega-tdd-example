#!/bin/bash

set -eou pipefail

BUILD_DIR="Build"

rm -rf ${BUILD_DIR:?}
mkdir -p ${BUILD_DIR:?}
cmake -DTARGET_GROUP=test -S . -B ${BUILD_DIR:?}
cmake --build ${BUILD_DIR:?} --target coverage
