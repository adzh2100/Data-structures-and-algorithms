#include <cmath>
#include <cstdio>
#include <stdlib.h>
#include <climits>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int binary_search(int element,vector<int>& arr)
{
	int start = 0;
	int end = arr.size()-1;
	while (start <= end)
	{
		int mid = (start+end) / 2;
		if (arr[mid] < element) start = mid + 1;
		else if (arr[mid] > element) end = mid - 1;
		else return mid;
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
	int el = binary_search(element,arr);
	if (el != -1) std::cout << "The index of your element is: " << el;
	else cout << "The inserted element is not in the array.";
	return 0;
}
