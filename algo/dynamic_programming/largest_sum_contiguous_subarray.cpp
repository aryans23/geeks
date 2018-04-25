#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
  ifstream input("largest_sum_contiguous_subarray_input.txt");
  if (!input) {
    cout << "Unable to open file..." << endl;
    return 1;
  }

  int n,arrVal;
  std::vector<int> ivec;
  input >> n;   // size of vector
  while(n) {
    input >> arrVal;
    ivec.push_back(arrVal);
    n--;
  }

  int max_so_far = ivec[0], curr_max = ivec[0];
  for (int i = 1; i < ivec.size(); i++) {
    curr_max = max(curr_max + ivec[i], ivec[i]);
    max_so_far = max(curr_max,max_so_far);
  }
  cout << max_so_far << endl;
}


