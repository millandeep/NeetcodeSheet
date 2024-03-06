#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> &numbers, int target)
{
    vector<int> ans(2);
    int start = 0;
    int end = numbers.size() - 1;

    while (start < end)
    {
        int sum = numbers[start] + numbers[end];
        if (sum == target)
        {

            ans[0] = start + 1;
            ans[1] = end + 1;
            break;
        }
        else if (sum > target)
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

int main()
{
    vector<int> nums = {2, 7, 11, 15};
    vector<int> ans = twoSum(nums, 9);

    for (int i = 0; i < 2; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}