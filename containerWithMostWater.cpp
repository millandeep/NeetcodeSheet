#include <bits/stdc++.h>
using namespace std;
// not optimised solution in O(N^2) complexity
// int maxArea(vector<int> &height)
// {
//     int maxArea = INT_MIN;

//     for (int i = 0; i < height.size() - 1; i++)
//     {
//         for (int j = i + 1; j < height.size(); j++)
//         {
//             int minHeight = min(height[i], height[j]);
//             int width = j - i;

//             int ans = minHeight * width;
//             maxArea = max(ans, maxArea);
//         }
//     }
//     return maxArea;
// }

// optimised soltuion with two pointer in this the pointers are moving on basis of height of
// each side if height is minimum on one side that pointer will move to maximize the are
int maxArea(vector<int> &height)
{
    int maxArea = INT_MIN;
    int start = 0;
    int end = height.size() - 1;

    while (start < end)
    {
        int minHeight = min(height[start], height[end]);
        int width = end - start;

        int ans = minHeight * width;
        maxArea = max(ans, maxArea);

        if (height[start] <= height[end])
        {
            start++;
        }
        else if (height[start] > height[end])
        {
            end--;
        }
    }
    return maxArea;
}

int main()
{
    // vector<int> arr = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    // vector<int> arr = {1, 1};
    vector<int> arr = {4, 1, 2, 7, 6, 3, 2, 8, 9};

    cout << maxArea(arr);
}