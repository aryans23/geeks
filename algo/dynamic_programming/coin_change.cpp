#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int min(int a, int b, int c) {
  return min(min(a,b),c);
}

int cc() {

  // Input
  //
  ifstream input("coin_change_input.txt");
  if (!input) {
    cout << "Unable to open file..." << endl;
    return 0;
  }
  int n,m;

  input >> n;   // Sum of changes
  input >> m;   // row size of vector
  std::vector<int> changes(m,0);
  for (int j = 0; j < m; j++) {
    input >> changes[j];
  }
  if (changes.empty()) return 0; 

  // Input Ends
  //

  // Printing
  //
  cout << "Changes:\t";
  for (int j = 0; j < m; j++) {
    cout << changes[j] << " ";
  }
  cout << endl;
  cout << "Total sum:\t" << n << endl;
  // Printing ends
  //

  std::vector<std::vector<int> > table(n+1, std::vector<int> (m,0));

  // Counting changes
  //
  for (int i = 0; i < m; i++) {
    table[0][i] = 1;
  }
  int x,y;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < m; j++) {
      x = (i-changes[j] >= 0) ? table[i-changes[j]][j]:0;
      y = (j >= 1) ? table[i][j-1]:0;
      table[i][j] = x + y;
    }
  }
  // Counting changes ends
  //

  // Printing
  //
  cout << endl;
  for (int i = 0; i <=n ; i++) {
    for (int j = 0; j < m; j++) {
      cout << table[i][j] << "\t";
    }
    cout << endl;
  }
  // Printing ends
  //

  return table[n][m-1];
}

int main()
{
  int res = cc();
  cout << "CC : " << res << endl;
}

