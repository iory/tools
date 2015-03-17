#include <iostream>
#include <algorithm>
#include <boost/lexical_cast.hpp>
#include <boost/math/common_factor.hpp>
#include <boost/multiprecision/cpp_int.hpp>

using namespace boost::multiprecision;
using namespace std;

int main(int argc, char *argv[]){
  if(argc != 3){
    cout << "Usage: gcd <num1> <num2>" << endl;
    return 0;
  }
  int1024_t A = boost::lexical_cast<int1024_t>(argv[1]);
  int1024_t B = boost::lexical_cast<int1024_t>(argv[2]);
  cout << "GCD = " <<  boost::math::gcd(A, B) << endl;
  cout << "LCM = " << boost::math::lcm(A, B) << endl;
  return 0;
}
