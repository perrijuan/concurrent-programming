#include <iostream>

using namespace std;
// usar therad para melhorar

int main() {
  long int a = 0;
  long long b = 0;
  long int z = 0;

  while (a < 400000) {
    b++;
  }

  while (z < 400000) {
    b++;
  }

  cout << b;
}
