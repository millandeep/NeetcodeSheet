#include <bits/stdc++.h>

using namespace std;

bool containsDuplicate(vector<int> &nums)
{
    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size() - 1; i++)
    {
        if (nums[i] == nums[i + 1])
        {
            return true;
        }
    }
    return false;
}

// one more approach using map will update once learn about maps

int main()
{
    vector<int> nums = {1, 2, 3, 1};
    cout << containsDuplicate(nums);
}