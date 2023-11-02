#! /bin/bash

ROOT=$(pwd)
echo $ROOT

git submodule update --init --recursive

mkdir -p build_cmake/third_party/gflags
cd build_cmake/third_party/gflags

cmake  -DCMAKE_DEBUG_POSTFIX="" -DBUILD_SHARED_LIBS=ON -DINSTALL_LIBS=ON -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX:PATH=$ROOT/build_cmake/third_party/gflags $ROOT/third_party/gflags
make -j4
make install
popd


# mkdir googletest
# pushd googletest
# cmake -DCMAKE_INSTALL_PREFIX:PATh=$ROOT/build_cmake/third_party/googletest $ROOT/third_party/googletest
# make -j4
# make install
# popd

cd $ROOT/build_cmake

cmake ..
make -j4

cd build_cmake/test
ctest
