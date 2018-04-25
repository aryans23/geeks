#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int lcs() {

  // Input
  //
  ifstream input("longest_common_subsequence_input.txt");
  if (!input) {
    cout << "Unable to open file..." << endl;
    return 0;
  }
  int n,m,arrVal;
  std::vector<int> A;
  std::vector<int> B;
  input >> n;   // size of vector
  for (int i = 0; i < n; i++) {
    input >> arrVal;
    A.push_back(arrVal);
  }
  if (A.empty()) return 0;
  cout << "Array 1: " ;
  for (int i = 0; i < n; i++) {
    cout << A[i] << " ";
  }
  cout << endl;

  input >> m;   // size of vector
  for (int i = 0; i < m; i++) {
    input >> arrVal;
    B.push_back(arrVal);
  }
  if (B.empty()) return 0;
  cout << "Array 2: " ;
  for (int i = 0; i < m; i++) {
    cout << B[i] << " ";
  }
  cout << endl;

  // Input Ends
  //
  
  std::vector<std::vector<int> > L(n+1, vector<int>(m+1,0));

  /*
  // Printing 
  // ***********************************
  cout << "\t\t";
  for (int i = 0; i <=m; i++) {
    if (i) cout << B[i-1] << "\t";
  }
  cout << endl;

  for (int i = 0; i <= n; i++) {
    if (i) cout << A[i-1] << "\t";
    else cout << "\t";
    for (int j = 0; j <= m; j++) {
      cout << L[i][j] << "\t";
    }
    cout << endl;
  }
  // **********************************
  // Printing ends
  // */

  // Formulating length of LCS
  //
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      if ( i == 0 || j == 0 ) {
        L[i][j] = 0;
      }
      else if (A[i-1] == B[j-1]) {
        L[i][j] = 1 + max(L[i-1][j], L[i][j-1]);
      }
      else {
        L[i][j] = max(L[i-1][j], L[i][j-1]);
      }
    }
  }
  // Formulating length of LCS ends
  //

  cout << endl;

  // Printing 
  // **********************************
  cout << "\t\t";
  for (int i = 0; i <=m; i++) {
    if (i) cout << B[i-1] << "\t";
  }
  cout << endl;

  for (int i = 0; i <= n; i++) {
    if (i) cout << A[i-1] << "\t";
    else cout << "\t";
    for (int j = 0; j <= m; j++) {
      cout << L[i][j] << "\t";
    }
    cout << endl;
  }
  // **********************************
  // Printing ends

  // Finding the LCS
  //
  int i = 1, j = 1;
  cout << "\nCommon Subsequence: ";
  while (i <= n && j <= m) {
    if (A[i-1] == B[j-1]) {
      cout << A[i-1] << " ";
      i++; j++;
    }
    else if (L[i+1][j] >= L[i][j+1]) {
      i++;
    }
    else {
      j++;
    }
  }
  cout << endl;
  // Finding the LCS ends
  //
  
  return L[n][m];
}

int main()
{
  int res = lcs();
  cout << "LCS : " << res << endl;
}

