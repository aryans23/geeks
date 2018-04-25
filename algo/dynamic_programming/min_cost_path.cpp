#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int min(int a, int b, int c) {
  return min(min(a,b),c);
}

int mcp() {

  // Input
  //
  ifstream input("min_cost_path_input.txt");
  if (!input) {
    cout << "Unable to open file..." << endl;
    return 0;
  }
  int n,m,arrVal;

  input >> m;   // row size of vector
  input >> n;   // col size of vector
  std::vector<std::vector<int> > matrix(m, std::vector<int>(n,0));
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      input >> arrVal;
      matrix[i][j] = arrVal;
    }
  }
  if (matrix.empty()) return 0;

  // Input Ends
  //

  // Printing
  //
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cout << matrix[i][j] << "\t";
    }
    cout << endl;
  }
  // Printing ends
  //

  // Formulating shortest cost
  //
  std::vector<std::vector<int> > cost(m, std::vector<int>(n,0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (i == 0) {
        cost[i][j] = matrix[i][j] + cost[i][j-1];
      }
      else if (j == 0) {
        cost[i][j] = matrix[i][j] + cost[i-1][j];
      }
      else {
        cost[i][j] = matrix[i][j] + min(cost[i-1][j], cost[i][j-1], cost[i-1][j-1]);
      }
    }
  }
  // Formulating shortest cost ends
  //

  // Printing
  //
  cout << endl;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cout << cost[i][j] << "\t";
    }
    cout << endl;
  }
  // Printing ends
  //

  return cost[m-1][n-1];
}

int main()
{
  int res = mcp();
  cout << "MCP : " << res << endl;
}

