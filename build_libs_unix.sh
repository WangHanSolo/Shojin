#! /bin/bash

ROOT=$(pwd)
echo $ROOT

TYPE=Debug

git submodule update --init --recursive

mkdir -p build_cmake/third_party/gflags
cd build_cmake/third_party/gflags

cmake  -DCMAKE_DEBUG_POSTFIX="" -DBUILD_SHARED_LIBS=ON -DINSTALL_LIBS=ON -DCMAKE_BUILD_TYPE=$TYPE -DCMAKE_INSTALL_PREFIX:PATH=$ROOT/build_cmake/third_party/gflags $ROOT/third_party/gflags
make -j4
make install
popd

mkdir -p build_cmake/third_party/flatbuffers
cd build_cmake/third_party/flatbuffers

cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=$TYPE -DCMAKE_INSTALL_PREFIX:PATH=$ROOT/build_cmake/third_party/flatbuffers $ROOT/third_party/flatbuffers
make -j4 all
popd
 
cd $ROOT/core/fbs/schemas
$ROOT/build_cmake/third_party/flatbuffers/flatc --cpp --gen-mutable -o ../  *


# mkdir googletest
# pushd googletest
# cmake -DCMAKE_INSTALL_PREFIX:PATh=$ROOT/build_cmake/third_party/googletest $ROOT/third_party/googletest
# make -j4
# make install
# popd

cd $ROOT/build_cmake

cmake -DCMAKE_BUILD_TYPE=$TYPE ..
make -j4

cd build_cmake/test
ctest
