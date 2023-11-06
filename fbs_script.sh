#! /bin/bash
ROOT=$(pwd)
echo $ROOT

mkdir -p build_cmake/third_party/flatbuffers
cd build_cmake/third_party/flatbuffers


cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX:PATH=$ROOT/build_cmake/third_party/flatbuffers $ROOT/third_party/flatbuffers
make -j4 all

cd $ROOT/core/fbs/schemas
pwd
$ROOT/build_cmake/third_party/flatbuffers/flatc --cpp -o ../  *

