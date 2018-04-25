#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int min(int a, int b, int c) {
  return min(min(a,b),c);
}

int ed() {

  // Input
  //
  
  string A,B;
  cout << "Enter first string: ";
  cin >> A;
  cout << "Enter second string: ";
  cin >> B;

  int n,m;
  n = A.size();
  m = B.size();

  /*
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
  */

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

  // Formulating edit distance
  //
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      if ( i == 0 ) {
        L[i][j] = j;
      }
      else if ( j == 0 ) {
        L[i][j] = i;
      }
      else if (A[i-1] == B[j-1]) {
        L[i][j] = L[i-1][j-1];
      }
      else {
        L[i][j] = 1 + min(L[i-1][j], L[i][j-1], L[i-1][j-1]);
      }
    }
  }
  // Formulating edit distance ends
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

  return L[n][m];
}

int main()
{
  int res = ed();
  cout << "No. of edits : " << res << endl;
}

