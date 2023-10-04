#! /bin/bash

ROOT=$(pwd)
echo $ROOT

git submodule update --init --recursive

pushd third_party/gflags
mkdir build_cmake
cd build_cmake
cmake     -DCMAKE_DEBUG_POSTFIX="" -DBUILD_SHARED_LIBS=ON -DINSTALL_LIBS=ON -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX:PATH=$ROOT/third_party/gflags/build_cmake/local_install ..
make -j4
make install
popd
cd $ROOT


# TODO: should I also add glog and gtest here?
