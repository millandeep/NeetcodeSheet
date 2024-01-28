#include <bits/stdc++.h>
using namespace std;

vector<int> topKFrequent(vector<int> &nums, int k)
{
    sort(nums.begin(), nums.end());

    map<int, int> mp;
    if (nums.size() == 1)
    {
        return nums;
    }
    for (int i = 0; i < nums.size(); i++)
    {
        mp[nums[i]]++;
    }

    vector<pair<int, int>> freqVector = {mp.begin(), mp.end()};

    // get clarity on this lambda function its still not clear.

    sort(freqVector.begin(), freqVector.end(),
         [](const pair<int, int> &left, const pair<int, int> &right)
         {
             return left.second > right.second;
         });

    vector<int> ans;

    for (int i = 0; i < k && i < freqVector.size(); i++)
    {
        ans.push_back(freqVector[i].first);
    }
    return ans;
}

int main()
{
    vector<int> a = {3, 3, 3, 4, 7, 6, 5, 5, 5, 6};
    // vector<int> a = {1, 1, 1, 2, 2, 3};

    vector<int> ans = topKFrequent(a, 2);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }

    // topKFrequent(a, 2);
}