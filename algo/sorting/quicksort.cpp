#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> arr, int n) 
{
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    } cout << endl;
}

int partition(vector<int>& arr, int lo, int hi)
{
    int i = lo+1;     
    for(int j = lo+1; j <= hi; j++) {
        if(arr[j] < arr[lo]) {
            swap(arr[i],arr[j]);
            i++;
        }
    }
    swap(arr[i-1],arr[lo]);
    print(arr,arr.size());
    return i-1;
}

void qsort(vector<int>& arr, int lo, int hi) 
{
    printf("lo = %d, hi = %d\n", lo,hi);
    if(lo < hi) {
        printf("arr[lo] = %d\n", arr[lo]);
        int pi = partition(arr,lo,hi);
        cout << "pi = " << pi << endl;
        qsort(arr,lo,pi-1);
        qsort(arr,pi+1,hi);
    }
}

int main()
{
    vector<int> arr;
    int n = rand() %100;
    for(int i =0; i < n; i++) {
        arr.push_back(rand() %100);
    }

    cout << "Array before:" << endl;
    print(arr,n);

    qsort(arr,0,arr.size()-1);
    
    cout << "Array after:" << endl;
    print(arr,n);
}   


