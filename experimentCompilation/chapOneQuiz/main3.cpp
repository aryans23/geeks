#include <iostream>
#include "io.h"
using namespace std;

int main() {
  int a,b;
  readNumber(a);
  readNumber(b);
  writeAnswer(a+b);
  return 0;
}

