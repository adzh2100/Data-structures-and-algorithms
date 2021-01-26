#include <cmath>
#include <cstdio>
#include <stdlib.h>
#include <climits>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// program that returns k-th largest element

int k_th(int start,int end,vector<int>& arr, int k)
{
	if (start > end) return INT_MIN;
	int size = end - start + 1;
	int pivot = start+ rand()%size;
	int index = start+1;
	swap(arr[pivot], arr[start]);
	for (int i = start + 1; i <= end; i++)
	{
		if (arr[i] > arr[start])
		{
			swap(arr[index], arr[i]);
			index++;
		}
	}
	swap(arr[index - 1], arr[start]);
	if (index - 1 == k) return arr[index - 1];
	else if (index - 1 < k)
	{
		return k_th(index, end, arr, k);
	}
	else
	{
		return k_th(start, index - 2, arr, k);
	}
}

int main()
{
	srand(time(NULL));
	int n = 0;
	int k = 0;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	cin >> k;
	cout << k_th(0,arr.size()-1,arr, k-1);
}
