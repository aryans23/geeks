#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<int> arrayOfInts;

void constructNewInt(int num)
{
	arrayOfInts.push_back(num);
}

void addNewInts()
{
	vector<int>::iterator it = arrayOfInts.begin();	
	
	arrayOfInts.erase(it);	
	
	constructNewInt(3);	
}

int main(int argc, char **argv)
{
	
	arrayOfInts.push_back(1);
	//array.push_back(2);
	
	addNewInts();
	
	for(vector<int>::iterator it = arrayOfInts.begin(); it != arrayOfInts.end(); it++)
		cout << *it << ' ';
	
	cout << endl;
	
}
