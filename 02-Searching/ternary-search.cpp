#include <cmath>
#include <cstdio>
#include <stdlib.h>
#include <climits>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int ternary_search(int element,vector<int>& arr)
{
	int start = 0;
	int end = arr.size()-1;
	while (start <= end)
	{
		int mid1 = (start+end) / 3;
		int mid2 = 2 * (start + end) / 3;
		if (element == arr[mid1]) return mid1;
		if (element == arr[mid2]) return mid2;
		if (element < arr[mid1]) end = mid1 - 1;
		else if (element > arr[mid1] && element < arr[mid2])
		{
			start = mid1 + 1;
			end = mid2 - 1;
		}
		else if (element > arr[mid2]) start = mid2 + 1;
	}
	return -1;
}
int main()
{
	int n = 0;
	int element;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	std::sort(arr.begin(), arr.end());
	cout << "Input element to find: ";
	cin >> element;
	int el = ternary_search(element,arr);
	if (el != -1) std::cout << "The index of your element in sorted order is: " << el;
	else cout << "The inserted element is not in the array.";
	return 0;
}
