#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/lexical_cast.hpp>
using namespace std;

typedef boost::multiprecision::cpp_int BigInteger;
BigInteger zero_cnt = 0;

BigInteger fact( BigInteger n){
  BigInteger ret = 1;
  for(BigInteger i=2;i<=n;++i){
    ret *= i;
    while(ret % 10 == 0){
      zero_cnt++;
      ret /= 10;
    }
  }
  return ret;
}

int main(int argc, char *argv[]){
  if(argc!=2){
    cout << "Usage: factorial <number>" << endl;
  }

  cout << fact(boost::lexical_cast<BigInteger>(argv[1]));
  for(int i=0;i<zero_cnt;++i)
      cout << 0;cout << endl;
}
