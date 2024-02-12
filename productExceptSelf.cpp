#include <bits/stdc++.h>
using namespace std;

// code is correct but need to optimise it

// vector<int> productExceptSelf2(vector<int> &nums)
// {
//     int index = 0;
//     bool flag = true;
//     vector<int> ans;
//     while (index < nums.size())
//     {
//         int product = 1;

//         for (int i = 0; i < nums.size(); i++)
//         {
//             if (i == index)
//             {
//                 // index++;
//                 continue;
//             }
//             else
//             {
//                 product *= nums[i];
//             }
//         }
//         index++;
//         ans.push_back(product);
//     }
//     return ans;
// }

// another way to do it would be using division operator i:e get product of entire array and then simply divide the value with each
// index and the result will be the required vauue except the no it is being divided with.
// but on leetcode i have to do it without dividing
// this code will give another error as well because division by 0 is not allowed if the product becomes 0;

// vector<int> productExceptSelf2(vector<int> &nums)
// {
//     int product = 1;
//     for (int i = 0; i < nums.size(); i++)
//     {
//         product *= nums[i];
//     }
//     cout << "product is " << product << endl;
//     for (int i = 0; i < nums.size(); i++)
//     {
//         nums[i] = product / nums[i];
//     }
//     return nums;
// }

// this code will work but this code takes two arrays to calculate prefix first and the postfix first and then multiply and modify the
// the provided array. In this we initialize prefix by 1 and postfix by 1.

vector<int> productExceptSelf(vector<int> &nums)
{
    vector<int> preFixArray(nums.size());
    vector<int> postFixArray(nums.size());

    int prefix = 1;
    int postFix = 1;

    // in this we fill prefix array
    preFixArray[0] = prefix;
    for (int i = 0; i < nums.size() - 1; i++)
    {
        preFixArray[i + 1] = prefix * nums[i];
        prefix = preFixArray[i + 1];
    }

    // now in this part we will make the  postfix array;

    postFixArray[postFixArray.size() - 1] = postFix;
    for (int i = postFixArray.size() - 1; i > 0; i--)
    {
        postFixArray[i - 1] = postFix * nums[i];
        postFix = postFixArray[i - 1];
    }
    for (int i = 0; i < nums.size(); i++)
    {
        nums[i] = preFixArray[i] * postFixArray[i];
    }
    return nums;
}

int main()
{
    // vector<int> a = {1, 2, 3, 4};
    vector<int> a = {-1, 1, 0, -3, 3};
    productExceptSelf(a);

    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
}