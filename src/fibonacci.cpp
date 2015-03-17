#include <iostream>
#include <vector>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/lexical_cast.hpp>

using namespace std;

typedef boost::multiprecision::cpp_int BigInteger;
typedef vector<BigInteger> vec;
typedef vector< vec > mat;

mat mult(mat& A, mat & B){
    mat C(A.size(), vec(B[0].size()));
    for(unsigned int i=0;i<A.size();++i){
        for(unsigned int j=0;j<B.size();++j){
            for(unsigned int k=0;k<B[0].size();++k){
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}

mat pow(mat A, int n){
    mat B(A.size(), vec(A.size(),0));
    for(unsigned int i=0;i<A.size();++i)B[i][i] = 1;
    while(n){
        if(n & 1) B= mult(A, B);
        A = mult(A, A);
        n >>= 1;
    }
    return B;
}

int main(int argc, char *argv[]){
    int N = 0;
    if(argc==2){
        N = boost::lexical_cast<int>(argv[1]);
    } else {
        cout << "fibo <number>" << endl;
    }
    mat Fibo(2,vec(2, 1));
    Fibo[1][1] = 0;
    Fibo = pow(Fibo, N);
    cout << "fibonacci number:" << endl;
    cout << Fibo[1][0] << endl;
}
