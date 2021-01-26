#include <cmath>
#include <cstdio>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void quick_sort(int start, int end, vector<int>& arr)
{
    if (start >= end) return;
    int size = end - start + 1;
    int pivot = start + rand() % size;
    swap(arr[start], arr[pivot]);
    int index = start + 1;
    for (int i = start + 1; i <= end; i++)
    {
        if (arr[i] < arr[start])
        {
            swap(arr[index], arr[i]);
            index++;
        }
    }
    swap(arr[start], arr[index-1]);
    quick_sort(start, index-2, arr);
    quick_sort(index, end, arr);

}
int main() {
    int n = 0;
    cin >> n;
    srand(time(NULL));
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    quick_sort(0, arr.size() - 1, arr);
    for (auto num : arr)
    {
        cout << num << ' ';
    }
    return 0;
}
