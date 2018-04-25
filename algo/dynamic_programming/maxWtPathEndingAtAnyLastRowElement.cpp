#include <iostream>
using namespace std;

const int MAX = 1000;

int maxCost(int mat[][MAX], int N)
{
  int dp[N][N];
  memset(dp,0,sizeof(dp));

  dp[0][0] = mat[0][0];

  for (int i = 1; i < N; i++) {
    dp[i][0] = mat[i][0] + dp[i-1][0];
  }
  
  cout << "***" << endl;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cout << dp[i][j] << " ";
    }
    cout << endl;
  }
  cout << "***" << endl;

  for (int i = 0; i < N; i++) {
    for (int j = 1; j < min(i+1,N); j++) {
      printf("i,j = %d,%d \t", i,j);
      dp[i][j] = mat[i][j] + max(dp[i-1][j-1], dp[i-1][j]);
      printf("dp[i][j] = %d\n", dp[i][j]);
    }
  }

  int result = 0;
  for (int i=0; i<N; i++)
    if (result < dp[N-1][i])
      result = dp[N-1][i];

  cout << "***" << endl;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cout << dp[i][j] << " ";
    }
    cout << endl;
  }
  cout << "***" << endl;

  return result;
}

int main()
{
  int mat[MAX][MAX] = {  { 4, 1 ,5 ,6 , 1 },
    { 2 ,9 ,2 ,11 ,10 },
    { 15,1 ,3 ,15, 2 },
    { 16, 92, 41,4,3},
    { 8, 142, 6, 4, 8 }
  };
  int N = 5;
  int res = maxCost(mat, N);

  cout << "Maximum Path Sum : " << res <<endl;
  return 0;
}
