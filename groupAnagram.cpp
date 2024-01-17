#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    unordered_map<string, vector<string>> mp;
    vector<vector<string>> ans;

    for (int i = 0; i < strs.size(); i++)
    {
        string sorted = strs[i];
        sort(sorted.begin(), sorted.end());
        mp[sorted].push_back(strs[i]);
    }

    for (auto it : mp)
    {
        ans.push_back(it.second);
    }
    return ans;
}

int main()
{
    vector<string> ann = {"eat",
                          "tea",
                          "tan",
                          "ate",
                          "nat",
                          "bat"};

    vector<vector<string>> ans = groupAnagrams(ann);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
    }
}