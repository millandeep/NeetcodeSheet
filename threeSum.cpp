#include <bits/stdc++.h>
using namespace std;

// not an optimised solution
// vector<vector<int>> threeSum(vector<int> &nums)
// {
//     sort(nums.begin(), nums.end());
//     vector<vector<int>> ans;
//     set<vector<int>> triplet;
//     for (int i = 0; i <= nums.size() - 2; i++)
//     {
//         vector<int> a;
//         for (int j = i + 1; j <= nums.size() - 1; j++)
//         {
//             for (int k = j + 1; k < nums.size(); k++)
//             {

//                 if (nums[i] + nums[j] + nums[k] == 0)
//                 {
//                     triplet.insert({nums[i], nums[j], nums[k]});
//                     // ans.push_back(a);
//                 }
//             }
//         }
//     }
//     for (auto &it : triplet)
//     {
//         ans.push_back(it);
//     }
//     return ans;
// }

// three pointer is more optimized solution
vector<vector<int>> threeSum(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    for (int i = 0; i < nums.size() - 1; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
        {
            continue;
        }
        int start = i + 1;
        int end = nums.size() - 1;

        while (start < end)
        {
            if (nums[i] + nums[start] + nums[end] == 0)
            {
                ans.push_back({nums[i], nums[start], nums[end]});
                start++;

                while (nums[start] == nums[start - 1] && start < end)
                {
                    start++;
                }
            }
            else if (nums[i] + nums[start] + nums[end] > 0)
            {
                end--;
            }
            else if (nums[i] + nums[start] + nums[end] < 0)
            {
                start++;
            }
        }
    }
    return ans;
}

int main()
{
    vector<int> a = {-1, 0, 1, 2, -1, -4};
    // vector<int> a = {0, 1, 1};
    // vector<int> a = {0, 0, 0};
    vector<vector<int>> ams = threeSum(a);

    for (int i = 0; i < ams.size(); i++)
    {
        for (int j = 0; j < ams[0].size(); j++)
        {
            cout << ams[i][j] << " ";
        }
        cout << endl;
    }
}