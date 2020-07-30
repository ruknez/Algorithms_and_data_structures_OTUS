#!/bin/bash

rm -rf build
mkdir build
cd build
cmake ..
make
cp tickets_cli ..
cd ..
./tickets_cli
