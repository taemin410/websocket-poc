#!/bin/sh

echo "mkdir -p build"
mkdir -p build

cd build && cmake .. && make -j$(nproc)
