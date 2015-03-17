#include <iostream>
#include <map>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/lexical_cast.hpp>

using namespace boost::multiprecision;
using namespace std;


class Calc{
private:
  typedef int1024_t BigInt;
  int1024_t A;
  map<BigInt, BigInt> factors;
public:
  Calc(){};
  void decompositPrime(int1024_t a);
  void show();
};

void Calc::decompositPrime(int1024_t N){
  A = 2;
  while(N >= A * A){
    if(N % A ==0){
      //cout << A << " * ";
      factors[A]++;
      N /= A;
    } else {
      A++;
    }
  }
  factors[N]++;
  //cout << N << endl;
}

void Calc::show(){
  map<BigInt, BigInt>::iterator it = factors.begin(), end = factors.end();
  for(;it != end;++it){
    if(it!=factors.begin())cout << " * ";
    if(it->second==1){
      cout << it->first;
    } else {
      cout << it->first << " ^ " << it->second;
    }
  }
  cout << endl;
}

int main(int argc, char *argv[]){
  if(argc != 2){
    cout << "factorization <number>" << endl;
  }
  int1024_t N = boost::lexical_cast<int1024_t>(argv[1]);
  Calc c;
  c.decompositPrime(N);
  c.show();
  return 0;
}
