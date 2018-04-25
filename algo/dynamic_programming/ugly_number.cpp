#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int min3(int a, int b, int c) {
  return min(min(a,b),c);
}

int main() 
{
  int i2 = 0,i3 = 0 ,i5 = 0;
  int ugly[150] = {[0 ... 149] = 1};
  
  for (int i = 1; i < 150; i++) {
    ugly[i] = min3(ugly[i2]*2, ugly[i3]*3, ugly[i5]*5);
    bool is2 = min3(ugly[i2]*2, ugly[i3]*3, ugly[i5]*5) == ugly[i2]*2;
    bool is3 = min3(ugly[i2]*2, ugly[i3]*3, ugly[i5]*5) == ugly[i3]*3;
    bool is5 = min3(ugly[i2]*2, ugly[i3]*3, ugly[i5]*5) == ugly[i5]*5;

    i2 = is2 ? i2+1:i2;
    i3 = is3 ? i3+1:i3;
    i5 = is5 ? i5+1:i5;
  }
  cout << ugly[149] << endl;
}
