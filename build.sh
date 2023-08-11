#!/bin/bash
export CMAKE_PREFIX_PATH=/opt/Qt/6.3.0/gcc_64
mkdir build
cd build
cmake -DCMAKE_PREFIX_PATH=$CMAKE_PREFIX_PATH ..
cmake --build . --config Release