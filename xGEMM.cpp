#include <Halide.h>
#include <iostream>
#include <fstream>
using namespace Halide;

int main() {
    std::ifstream input_file("data/matrices.txt");
      if (!input_file) {
        std::cout << "Failed to open the matrices.txt file" << std::endl;
        return -1;
    }  
    int N1,M1,N2,M2;
    input_file >> N1;
    input_file >> M1;
    Buffer<int> A(N1, M1);
    for(int i=0;i<N1;i++){
    	for(int j=0;j<M1;j++){
    		input_file>>A(i,j);
    	}
    }
    input_file >> N2;
    input_file >> M2;
    Buffer<int> B(N2, M2);
    for(int i=0;i<N2;i++){
    	for(int j=0;j<M2;j++){
    		input_file>>B(i,j);
    	}
    }
    input_file.close();
    if(M1!=N2) {
    	std::cout << "Can't perform multiplication due to dimensions" << std::endl;
    	return -1;
    }
    Var x, y;
    Func matrix_mul("matrix_mul");
    RDom r(0, M1);
    matrix_mul(x, y) = sum(A(x, r) * B(r, y));
    Buffer<int> C = matrix_mul.realize({N1, M2});
    std::ofstream output_file("data/HalideResult.txt");
      if (!output_file) {
        std::cout << "Failed to open HalideResult.txt." << std::endl;
        return -1;
    }
    output_file << N1 << " " << M2 << "\n";
    for (int i = 0; i < N1; i++) {
        for (int j = 0; j < M2; j++) {
            output_file << C(i, j) << " ";
        }
        output_file << "\n";
    }
    output_file.close();
    return 0;
}
