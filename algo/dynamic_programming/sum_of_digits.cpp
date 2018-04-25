// Wrong 
#include <iostream>
using namespace std;

int sumDig(int n)
{
  if (n<10) {
    return n*(n+1)/2;
  }

  int *dp = new int[n+1];
  for (int i = 0; i <= n; i++) {
    dp[i] = i*(i+1)/2;
  }
  
  for (int i = 10; i<=n; i++) {
    dp[i] = (i/10) + 1%10 + dp[i-1] ;
  }

  return dp[n];
}

int main()
{
  int n;
  cout << "Enter n: ";
  cin >> n;
  cout << "Sum of Digits till n : " << sumDig(n) << endl;
}

