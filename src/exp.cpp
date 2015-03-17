#include <iostream>
#include <algorithm>
#include <boost/lexical_cast.hpp>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>

using namespace boost::multiprecision;
using namespace std;

void pow(cpp_dec_float_100 A, int1024_t B){
  cpp_dec_float_100 ret = 1;
  while(B > 0){
    if(B & 1) ret *= A;
    A *= A;
    B >>= 1;
  }
  cout << ret << endl;
}

int main(int argc, char *argv[]){
  if(argc != 3){
    cout << "Usage: exp <num> <base>" << endl;
    return 0;
  }
  cpp_dec_float_100 A = boost::lexical_cast<cpp_dec_float_100>(argv[1]);
  int1024_t B = boost::lexical_cast<int1024_t>(argv[2]);
  pow(A, B);
  return 0;
}
