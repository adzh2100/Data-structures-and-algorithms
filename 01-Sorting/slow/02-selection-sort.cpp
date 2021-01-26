#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void selection_sort(vector<int>& arr)
{
    for(unsigned i=0;i<arr.size();i++)
    {
        int i_min=i;
        for(unsigned j=i+1;j<arr.size();j++)
        {
            if(arr[j]<arr[i_min]) i_min=j;
        }
        swap(arr[i],arr[i_min]);
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
    selection_sort(arr);
    for(auto num:arr)
    {
        cout<<num<<' ';
    }
    return 0;
}
