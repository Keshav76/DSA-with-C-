#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i ++)
        {
            int index = nums[i] - 1;
            if (nums[i] < 0)
            {
                index = -nums[i] - 1;
            }
            if (nums[index] < 0)
            {
                continue;
            }
            nums[index] = 0-nums[index];
        }
        vector<int> ans;
        for (int i = 0; i < nums.size(); i ++)
        {
            if (nums[i] < 0)
            {
                continue;
            }
            else
            {
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};
int main()
{
    vector<int> a = {4,3,2,7,8,2,3,1};
    Solution s;
    vector<int> b = s.findDisappearedNumbers(a);
    for (auto i : b)
    {
        cout << i << endl;
    }
}