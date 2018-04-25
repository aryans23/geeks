#include <iostream>
#include <vector>
using namespace std;

void init(vector<int>& arr)
{
    int n = rand() % 100;
    for(int i = 0; i < n; i++) {
        arr.push_back(rand()%100);
    }
}
void heapify(vector<int>& arr, int i)
{
    int n = arr.size();
    if (n == 0) return;

    int largest = i;
    int l = 2*i+1, r = 2*i+2;
    if (l < n && arr[largest] > arr[l]) {
        largest = l;
    }
    if (r < n && arr[largest] > arr[r]) {
        largest = r;
    }
    if (largest != i) {
        swap(arr[i],arr[largest]);
        heapify(arr, largest);
    }
}

void print(vector<int>& arr)
{
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    } cout << endl;
}

void heapsort(vector<int>& arr) 
{
    int n = arr.size();
    for(int i = n/2-1; i >= 0; i--)
        heapify(arr,i);

    for (int i = n-1; i >= 0; i--) {
        swap(arr[0],arr[i]);
        heapify(arr,i);
    }
}

int main() 
{
    vector<int> arr;
    init(arr);
    cout << "Array before:" << endl;
    print(arr);
    heapsort(arr);
    cout << "Array after:" << endl;
    print(arr);
}

