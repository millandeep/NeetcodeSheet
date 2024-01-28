#include <bits/stdc++.h>
using namespace std;

// code is correct but need to optimise it

vector<int> productExceptSelf(vector<int> &nums)
{
    int index = 0;
    bool flag = true;
    vector<int> ans;
    while (index < nums.size())
    {
        int product = 1;

        for (int i = 0; i < nums.size(); i++)
        {
            if (i == index)
            {
                // index++;
                continue;
            }
            else
            {
                product *= nums[i];
            }
        }
        index++;
        ans.push_back(product);
    }
    return ans;
}

int main()
{
    vector<int> a = {1, 2, 3, 4};
    vector<int> ans = productExceptSelf(a);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}