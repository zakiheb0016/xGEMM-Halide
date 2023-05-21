# Overview
This repository contains an implementation of the Matrix to Matrix of integer elements Multiplication (xGEMM) routine using C and Halide. The xGEMM routine is part of the Basic Linear Algebra Subprograms Level 3 (BLAS3) library and is widely used for efficient matrix multiplication.
# Contents
* xGEMM.c : C implementation of Matrix to Matrix to multiplication
* xGEMM.cpp : Halide implemenation of Matrix to Matrix multiplication 
* logs_files/LLVM_build.txt : LLVM build logs 
* logs_files/LLVM_install.txt : LLVM installation logs
* logs_files/Halide_build.txt : Halide build logs
* data/matrices.txt : a text file containing matrices to peform multiplication with
* data/CResult.txt : a text file storing the result returned from the C program
* data/HalideResult.txt : a text file storing the result returned from Halide

# How to use ?
To run the project, follow these steps:

1. Clone the repository:

   ```bash
   git clone https://github.com/zakiheb0016/xGEMM-Halide.git

1. Navigate to the project directory:

    ```bash
    cd xGEMM-Halide
    
1. Give the script the execution permission

    ```bash
    sudo chmod +x script.sh
    
1. Write down the matrices you want calculate their product to data/matrices.txt file following this syntax
    
     ```plaintext
     N1 M1
     Matrix A
     N2 M2
     Matrix B
     // Where N1,M1 are the dimensions of matrix A and N2,M2 are the dimensions of matrix B

1. Now run the script following the next syntax

    ```bash
    ./script.sh /path/to/halide_build #replace /path/to/halide_build by the path of your halide build
    
1. If no error appears then the script completed execution successfully and you are now able to visualize the results in the data folder,Otherwise the appeared error will indicate the issue to fix
