#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector<int> merge(vector<int> a,vector<int> b)
{
    vector<int> vec;
    unsigned j=0;
    unsigned i=0;
    while(i<a.size() && j<b.size())
    {
        if(a[i]<=b[j])
        {
            vec.push_back(a[i]);
            i++;
        }
        else
        {
            vec.push_back(b[j]);
            j++;
        }
    }
    while(i<a.size())
    {
        vec.push_back(a[i]);
        i++;
    }
    while(j<b.size())
    {
        vec.push_back(b[j]);
        j++;
    }
    return vec;
}
vector<int> merge_sort(int start,int end,vector<int>& arr)
{
    if(start==end) 
    {
        vector<int> vec;
        vec.push_back(arr[start]);
        return vec;
    }
    int mid=(start+end)/2;
    return merge(merge_sort(start,mid,arr),merge_sort(mid+1,end,arr));
}
int main() {
    int n=0;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    arr=merge_sort(0,arr.size()-1,arr);
    for(auto num:arr)
    {
        cout<<num<<' ';
    }
    return 0;
}
