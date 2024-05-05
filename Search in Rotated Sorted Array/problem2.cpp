/*
Problem Link: https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/
*/

#include <bits/stdc++.h>
using namespace std;

bool search(vector<int> &nums, int target)
{
    int low = 0, high = nums.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target)
            return true;
        if (nums[low] == nums[mid] && nums[mid] == nums[high])
        {
            low = low + 1;
            high = high - 1;
            continue;
        }
        if (nums[low] <= nums[mid])
        {
            if (nums[low] <= target && target <= nums[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        else
        {
            if (nums[mid] <= target && target <= nums[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return false;
}

int main()
{
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    cout << search(nums, 2) << endl;
    return 0;
}