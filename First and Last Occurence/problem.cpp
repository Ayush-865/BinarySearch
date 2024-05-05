#include <bits/stdc++.h>
using namespace std;

int lowerBound(int low, int high, vector<int> &arr, int target)
{
    int ans = high + 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= target)
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans;
}

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

pair<int, int> firstAndLastPosition(vector<int> &arr, int n, int target)
{
    int lb = lowerBound(0, arr.size() - 1, arr, target);
    if (lb == arr.size() || arr[lb] != target)
    {
        return {-1, -1};
    }
    else
        return {lb, higherBound(0, arr.size() - 1, arr, target) - 1};
}

int main()
{
    int n, target;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());

    cout << "Enter the target element: ";
    cin >> target;

    pair<int, int> ans = firstAndLastPosition(arr, arr.size(), target);
    cout << "First Occurence: " << ans.first << "\n"
         << "Last Occurence: " << ans.second << endl;
    return 0;
}