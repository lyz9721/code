#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int res=0;
        while(left<right)
        {
            res = max( (right-left)*min(height[left],height[right]),res);
            if(height[left]>=height[right])
            {
                right--;
            }
            else
            {
                left++;
            }
        }
        return res;
    }
};

int main()
{
    Solution so;
    vector<int> vec={1,8,6,2,5,4,8,3,7};
    cout<<so.maxArea(vec)<<endl;
    return 0;
}