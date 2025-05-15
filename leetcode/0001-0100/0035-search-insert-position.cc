#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left=0;
        int right=nums.size()-1;
        while(left<=right)
        {
            int mid = left + (right-left)/2;
            if(nums[mid]==target)
            {
                return mid;
            }
            else if(nums[mid]>target)
            {
                right=mid-1;
            }
            else
            {
                left=mid+1;
            }
        }
        return left;
    }
};

int main()
{
    Solution so;
    vector<int> vec = {1,2,3,5,6,10,15,19,22,32};
    for(auto x:vec)
    {
        cout<<x<<" ";
    }
    cout<<endl;
    int target;
    while(cin>>target)
    {
        cout<<so.searchInsert(vec,target)<<endl;
    }
    
    return 0;
}