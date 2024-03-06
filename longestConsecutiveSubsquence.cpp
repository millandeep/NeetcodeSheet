#include <bits/stdc++.h>
using namespace std;
// this solution passed 42 test cases out of 75
// int longestConsecutive(vector<int> &nums)
// {
//     sort(nums.begin(), nums.end());
//     int count = 1;
//     int finalCount = 1;

//     for (int i = 1; i <= nums.size() - 1; i++)
//     {
//         if (abs(nums[i] - nums[i - 1]) == 1)
//         {
//             count++;
//         }
//         else
//         {
//             count = 1;
//         }
//         finalCount = max(count, finalCount);
//     }
//     return finalCount;
// }

int longestConsecutive(vector<int> nums)
{
    sort(nums.begin(), nums.end());
    int longestSeq = 1;
    int currentCount = 0;
    int lastSmaller = INT_MIN;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] - 1 == lastSmaller)
        {
            currentCount += 1;
            lastSmaller = nums[i];
        }
        else if (nums[i] - 1 != lastSmaller)
        {
            currentCount = 1;
            lastSmaller = nums[i];
        }
        longestSeq = max(currentCount, longestSeq);
    }
    return longestSeq;
}

int main()
{
    // vector<int> a = {100, 4, 200, 1, 3, 2};
    vector<int> a = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    // vector<int> a = {0, 0};
    // vector<int> a = {9, 1, 4, 7, 3, -1, 0, 5, 8, -1, 6};
    cout << longestConsecutive(a);
}