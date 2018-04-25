#include <iostream>
using namespace std;

int count(int n)
{
  if (n<4) {
    return n;
  }
  long long c = 0;

  int *dp = new int[n+1];
  dp[0] = 0;
  dp[1] = 1;
  dp[2] = 2;
  dp[3] = 3;
  for (int i = 4; i<=n; i++) {
    dp[i] = i;
  }

  for (int i = 4; i <=n; i++) {
    dp[i] = i;
    for (int x = 1; x <= i; x++) {
      int temp = x*x;
      if (temp > i)
        break;
      else {
        dp[i] = std::min(dp[i],dp[i-temp]+1);
        // if (dp[i] == 1) break;
        c++;
      }
    }
  }
  cout << c << endl;
  return dp[n];
}

int main()
{
  int n;
  cout << "Enter n: ";
  cin >> n;
  cout << "Count : " << count(n) << endl;
}

