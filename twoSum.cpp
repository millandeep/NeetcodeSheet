#include <bits/stdc++.h>
using namespace std;

// this appraoch is only if array is sorted.
vector<int> twoSum2(vector<int> &nums, int target)
{
    vector<int> ans(2);

    sort(nums.begin(), nums.end());

    int start = 0;
    int end = nums.size() - 1;

    while (start < end)
    {
        if (nums[start] + nums[end] == target)
        {
            ans[0] = start;
            ans[1] = end;
            break;
        }
        else if (nums[start] + nums[end] > target)
        {
            end--;
        }
        else
        {
            start++;
        }
    }
    return ans;
}

// this is a brute force appraoch using twi nested for loops
vector<int> twoSum(vector<int> &nums, int target)
{
    vector<int> ans(2);
    for (int i = 0; i < nums.size() - 1; i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[i] + nums[j] == target)
            {
                ans[0] = i;
                ans[i] = j;
            }
        }
    }
    return ans;
}

int main()
{
    vector<int> a = {2, 7, 11, 15};
    vector<int> ans = twoSum(a, 9);
    for (int i = 0; i < 2; i++)
    {
        cout << ans[i] << endl;
    }
}