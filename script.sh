#!/bin/bash

echo "Compiling C code"
gcc -o xGEMM xGEMM.c
return_value=$?
if [ "$return_value" != 0 ]; then
    echo "C Compilation failed"
    exit 1  
fi
echo "C code compiled successfully"
./xGEMM
return_value=$?
if [ "$return_value" != 0 ]; then
    echo "Something went wrong while executing C program, Execution will be stopped"
    exit 1
fi
echo "C program executed successfully. You can see the result in CResult.txt"

path="$1"
include_path="$path/include"
lib_path="$path/lib"
echo "Compiling Halide code"
g++ xGEMM.cpp -g -I "$include_path" -L "$lib_path" -lHalide -lpthread -ldl -o xGEMM -std=c++17
return_value=$?
if [ "$return_value" != 0 ]; then
    echo "Halide Compilation failed"
    exit 1
fi
echo "Halide code compiled successfully"
./xGEMM
return_value=$?
if [ "$return_value" != 0 ]; then
    echo "Something went wrong while executing Halide program, Execution will be stopped"
    exit 1
fi
echo "Halide program executed successfully. You can see the result in HalideResult.txt"

file1="data/CResult.txt"
file2="data/HalideResult.txt"
if diff -q "$file1" "$file2" >/dev/null; then
    echo "The results are the same"
else
    echo "The results are not the same. Something went wrong!"
fi

