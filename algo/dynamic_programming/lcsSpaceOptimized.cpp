#include <iostream>
#include <string>
using namespace std;

int lcs(string &X, string &Y)
{
  int m = X.length();
  int n = Y.length();
  bool bi;

  int L[2][n+1];
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < n+1; j++) {
      L[i][j] = 0;
    }
  }

  for (int i = 0; i < m; i++) {
    bi = i&1;
    for (int j = 1; j <= n; j++) {
      printf("i,j = %d,%d\t",i,j);
      printf("X[i] = %c\t",X[i]);
      printf("Y[j-1] = %c\t",Y[j-1]);
      if (X[i] == Y[j-1]) 
        L[bi][j] = 1 + L[1-bi][j-1];
      else 
        L[bi][j] = std::max(L[bi][j-1],L[1-bi][j]);
      printf("bi,j = %d,%d\t", bi,j);
      printf("L[bi][j] = %d\n", L[bi][j]);
    }
  }

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < n; j++) 
      cout << L[i][j] << " ";
    cout << endl;
  }

  return L[bi][n];
}

/* Driver program to test above function */
int main()
{
	string X = "ab";
	string Y = "abcd";

	printf("Length of LCS is %d\n", lcs(X, Y));

	return 0;
}
