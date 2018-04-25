#include <iostream>     
#include <algorithm>   
#include <vector>
using namespace std;

int main ()
{
  int input[] = {1,2,4,5,7,10,45};
  vector<int> v(input,input+12);
  
  vector<int>::iterator it1 , it2;

  it1 = lower_bound(v.begin(), v.end(), 6); 
  /* points to fifth element in v */ 
  cout << *it1 << endl;

  it2 = upper_bound(v.begin(), v.end(), 3);
  /* points to second last element in v */
  cout << *it2 << endl;
}