#include <iostream>
using namespace std;

void readNumber(int &a);
void writeAnswer(int sum);

int main() {
  int a,b;
  readNumber(a);
  readNumber(b);
  writeAnswer(a+b);
  return 0;
}

