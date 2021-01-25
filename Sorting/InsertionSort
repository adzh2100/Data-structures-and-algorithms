#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void insertion_sort(vector<int>& arr)
{
    for(unsigned i=1;i<arr.size();i++)
    {
        int el=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>el)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=el;
    }
}
int main() {
    int n=0;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    insertion_sort(arr);
    for(auto num:arr)
    {
        cout<<num<<' ';
    }
    return 0;
}
