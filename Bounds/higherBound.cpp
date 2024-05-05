/*
Time Complexity in case of sorted array: O(n)
Time Complexity in case of unsorted array: O(n)+O(nlogn)
Space Complexity: O(1)

C++ equivalent function
int idx=upper_bound(arr.begin(), arr.end(), target)-arr.begin()
*/
#include <bits/stdc++.h>
using namespace std;

int higherBound(int low, int high, vector<int> &arr, int target)
{
    int ans = high + 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] > target)
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans;
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
    int index = higherBound(0, n - 1, arr, target);
    if (index == -1)
        cout << "Higher Bound not found" << endl;
    else
        cout << "Higher Bound is " << arr[index] << " found at index " << index << endl;
    return 0;
}