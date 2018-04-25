#include <iostream>
#include <vector>

using namespace std;

int main() 
{
  vector<vector<int> > V;

  for (int i = 0; i < 4; i++) {
    vector<int> v;
    for (int j = 0; j < 2; j++) {
      v.push_back(j+12);
    }
    v.clear();
    V.push_back(v);
  }

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 2; j++) {
      cout << V[i][j] << " ";
    }
    cout << endl;
  }
}
