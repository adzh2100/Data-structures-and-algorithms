#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void bubble_sort(vector<int>& arr)
{
    for(unsigned i=0;i<arr.size()-1;i++)
    {
        for(unsigned j=i;j<arr.size();j++)
        {
            if(arr[i]>arr[j]) swap(arr[i],arr[j]);
        }
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
    bubble_sort(arr);
    for(auto num:arr)
    {
        cout<<num<<' ';
    }
    return 0;
}
