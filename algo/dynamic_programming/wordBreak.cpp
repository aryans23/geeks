#include <iostream>
#include <string>
using namespace std;

int dictionaryContains(string word)
{
  string dictionary[] = {"mobile","samsung","sam","sung","man","mango",
    "icecream","and","go","i","like","ice","cream"};
  int size = sizeof(dictionary)/sizeof(dictionary[0]);
  for (int i = 0; i < size; i++)
    if (dictionary[i].compare(word) == 0)
      return true;
  return false;
}

bool wordBreak(string str)
{
  int n = str.length();
  if (0 == n) return true;
  // cout << "n = " << n << endl;

  bool wb[n];
  memset(wb,false,sizeof(wb));
/*
  cout << "wb[] intial: "; 
  for (int i = 0; i < n; i++)
    cout << " " << wb[i];
  cout << endl;
*/
  for (int i = 0; i < n; i++) {
/*
    cout << "wb[] now: "; 
    for (int i = 0; i < n; i++)
      cout << " " << wb[i];
    cout << endl;
*/
    if (!wb[i] && dictionaryContains(str.substr(0,i+1))) {
      wb[i] = true;
      continue;
    }
    for (int j = 0; j < i; j++) {
      if (wb[j] && dictionaryContains(str.substr(j+1,i-j))) {
        wb[i] = true;
        break;
      }
    }
  }
/*  
  cout << "wb[] final: "; 
  for (int i = 0; i < n; i++)
    cout << " " << wb[i];
  cout << endl;
*/  
  return wb[n-1];
}

int main()
{
  cout << "String: ilikesamsung" << endl;
  wordBreak("ilikesamsung")? cout <<"Yes\n": cout << "No\n";
  cout << "String: iiiiiiii" << endl;
  wordBreak("iiiiiiii")? cout <<"Yes\n": cout << "No\n";
  cout << "String: " << endl;
  wordBreak("")? cout <<"Yes\n": cout << "No\n";
  cout << "String: ilikelikeimangoiii" << endl;
  wordBreak("ilikelikeimangoiii")? cout <<"Yes\n": cout << "No\n";
  cout << "String: samsungandmango" << endl;
  wordBreak("samsungandmango")? cout <<"Yes\n": cout << "No\n";
  cout << "String: samsungandmangok" << endl;
  wordBreak("samsungandmangok")? cout <<"Yes\n": cout << "No\n";
  return 0;
}
