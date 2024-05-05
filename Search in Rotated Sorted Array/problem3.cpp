/*
Problem Link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/
*/

#include <bits/stdc++.h>
using namespace std;

int findMin(vector<int> &nums)
{
    int ans = INT_MAX;
    int low = 0, high = nums.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (nums[low] <= nums[high])
        {
            ans = min(ans, nums[low]);
            break;
        }

        if (nums[mid] <= nums[high])
        {
            ans = min(nums[mid], ans);
            high = mid - 1;
        }
        else
        {
            ans = min(nums[low], ans);
            low = mid + 1;
        }
    }
    return ans;
}

int main()
{
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements of array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    cout << "Minimum element in the array is: " << findMin(nums) << endl;
    return 0;
}