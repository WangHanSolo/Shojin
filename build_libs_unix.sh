#! /bin/bash

ROOT=$(pwd)
echo $ROOT

git submodule update --init --recursive

mkdir build_cmake && cd build_cmake
mkdir third_party && cd third_party

mkdir gflags      && cd gflags
cmake  -DCMAKE_DEBUG_POSTFIX="" -DBUILD_SHARED_LIBS=ON -DINSTALL_LIBS=ON -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX:PATH=$ROOT/build_cmake/third_party/gflags $ROOT/third_party/gflags
make -j4
make install
cd $ROOT/build_cmake

cmake ..
make -j4

# TODO: should I also add glog and gtest here?
