#!/bin/bash

set -eou pipefail

build_dir=Build

rm -rf $build_dir/
mkdir -p $build_dir/
cmake -S . -B $build_dir/
cmake --build $build_dir/
