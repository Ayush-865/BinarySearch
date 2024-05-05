/*
Time Complexity in case of sorted array: O(n)
Time Complexity in case of unsorted array: O(n)+O(nlogn)
Space Complexity: O(logn)
*/
#include <bits/stdc++.h>
using namespace std;

int binarySearch(int low, int high, vector<int> &arr, int target)
{
    if (low > high)
        return -1;
    int mid = low + (high - low) / 2;
    if (arr[mid] == target)
        return mid;
    else if (arr[mid] > target)
        return binarySearch(low, mid - 1, arr, target);
    return binarySearch(mid + 1, high, arr, target);
}

int main()
{
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    int target;
    cout << "Enter the target element: ";
    cin >> target;
    int index = binarySearch(0, n - 1, arr, target);
    if (index == -1)
        cout << "Element not found" << endl;
    else
        cout << "Element found at index " << index << endl;
    return 0;
}