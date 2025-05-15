#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> umap;
        for(int i=0;i<nums.size();i++)
        {
            auto it = umap.find(target-nums[i]);
            if(it==umap.end())
            {
                umap[nums[i]] = i;
            }
            else
            {
                return {i, umap[target-nums[i]]};
            }
        }
        return {0,0};
    }
};

int main()
{
    Solution so;
    vector<int> vec = {2,7,11,15};
    vector<int> res = so.twoSum(vec,9);
    cout<<res[0]<<" "<<res[1]<<endl;
    return 0;
}