#! /bin/bash
ROOT=$(pwd)
echo $ROOT

cd $ROOT/core/fbs/schemas
$ROOT/build_cmake/third_party/flatbuffers/flatc --cpp --gen-mutable -o ../  *
