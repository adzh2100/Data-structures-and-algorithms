#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector<int> negative(1001,0);
vector<int> positive(1001,0);
//works for both positive and negative numbers in the array
void counting_sort(vector<int>& arr)
{
    for(auto number:arr)
    {
        if(number>=0)
        {
            positive[number]++;
        }
        else
        {
            negative[abs(number)]++;
        }
    }
    int index=0;
    for(int i=negative.size()-1;i>=0;i--)
    {
        for(int j=0;j<negative[i];j++)
        {
            arr[index]=-i;
            index++;
        }
    }
    for(unsigned i=0;i<positive.size();i++)
    {
        for(int j=0;j<positive[i];j++)
        {
            arr[index]=i;
            index++;
        }
    }
}
int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n=0;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    counting_sort(arr);
    for(auto number:arr)
    {
        cout<<number<<" ";
    }
    return 0;
}
