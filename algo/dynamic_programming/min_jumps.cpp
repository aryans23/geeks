#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int mj() {
  ifstream input("min_jumps_input.txt");
  if (!input) {
    cout << "Unable to open file..." << endl;
    return -1;
  }
  int n;
  input >> n;   // size of vector
  std::vector<int> jump(n);
  for (int i = 0; i < n; i++) {
    input >> jump[i];
  }
  if (jump.empty()) return -1;
  
  if (0 == n || 0 == jump[0]) {
    return -1;
  }

  std::vector<int> minJump(n,INT_MAX);
  minJump[0] = 0;
  
  int _minJump[n];
  int _jump[n];
  for (int i = 0; i < n; i++) {
    _minJump[i] = minJump[i];
    _jump[i] = jump[i];
  }
  cout << "_minJump: " ;
  for (int i = 0; i < n; i++) {
    cout << _minJump[i] << " ";
  }
  cout << endl;
  cout << "_jump: " ;
  for (int i = 0; i < n; i++) {
    cout << _jump[i] << " ";
  }
  cout << endl;

  for (int i = 1; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (i <= j + _jump[j] && _minJump[i] > _jump[j] + 1) {
        _minJump[i] = _minJump[j] + 1;
      }
    }
  }
  cout << "_minJump: " ;
  for (int i = 0; i < n; i++) {
    cout << _minJump[i] << " ";
  }
  cout << endl;
  return _minJump[n-1];
}

int main()
{
  int res = mj();
  if (res != -1) {
    cout << "Minimum jumps req: " << res << endl;
  }
  else {
    cout << "Not possible" << endl;
  }
}

