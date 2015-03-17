#include <iostream>
#include <cmath>
#include <boost/lexical_cast.hpp>
using namespace std;

typedef long double ld;
int main(int argc, char *argv[]){
  if(argc!=2){
    cout << "Usage: logarithm <Number>" << endl;
    return 0;
  }

  ld N = boost::lexical_cast<ld>(argv[1]);
  cout << log(N) / log(2.0) << endl;
}
