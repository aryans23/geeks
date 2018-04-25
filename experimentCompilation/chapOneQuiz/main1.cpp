#include <iostream>
using namespace std;

void readNumber(int &a) {
  cout << "Enter: " ;
  cin >> a;
}

void writeAnswer(int sum) {
  cout << "Sum = " << sum << endl;
}

int main() {
  int a,b;
  readNumber(a);
  readNumber(b);
  writeAnswer(a+b);
  return 0;
}

