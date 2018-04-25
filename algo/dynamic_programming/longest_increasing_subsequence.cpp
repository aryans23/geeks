#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void lic() {
  ifstream input("longest_increasing_subsequence_input.txt");
  if (!input) {
    cout << "Unable to open file..." << endl;
    return;
  }
  int n,arrVal;
  std::vector<int> ivec;
  input >> n;   // size of vector
  for (int i = 0; i < n; i++) {
    input >> arrVal;
    ivec.push_back(arrVal);
  }
  if (ivec.empty()) return;
  cout << "Array: " ;
  for (int i = 0; i < n; i++) {
    cout << ivec[i] << " ";
  }
  cout << endl;

  std::vector<int> L (n,1);
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (ivec[j] < ivec[i] && L[j] + 1 > L[i]) {
        L[i] = L[j] + 1;
      }
    }
  }

  int max = 0;
  for (int i = 0 ; i < n; i++) {
    if (max < L[i]) max = L[i];
  }

  cout << "Longest increasing subsequence: " << max << endl;
}

int main()
{
  lic();
}

