#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left=0;
        int right=0;
        while(right<nums.size())
        {
            if(nums[right] == 0)
            {
                ++right;
            }
            else
            {
                nums[left++] = nums[right++];
            }
        }
        while(left<nums.size())
        {
            nums[left++] = 0;
        }
    }
};

int main()
{
    vector<int> vec = {0,1,0,3,12};
    Solution so;
    so.moveZeroes(vec);
    for(int x:vec)
    {
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}