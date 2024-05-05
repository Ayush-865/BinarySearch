/*
Time Complexity in case of sorted array: O(n)
Time Complexity in case of unsorted array: O(n)+O(nlogn)
Space Complexity: O(1)
*/
#include <bits/stdc++.h>
using namespace std;

int binarySearch(int low, int high, vector<int> &arr, int target)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
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