#include <bits/stdc++.h>
using namespace std;

int search(vector<int> &nums, int target)
{
    int start = 0;
    int end = nums.size() - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }
        else if (nums[mid] > target)
        {
            end--;
        }
        else
        {
            start++;
        }
    }
    return -1;
}

int main()
{
    vector<int> a = {-1, 0, 3, 5, 9, 12};
    cout << search(a, 9) << endl;
}