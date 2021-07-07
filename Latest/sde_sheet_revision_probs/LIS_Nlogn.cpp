// Intelligent subsequence building --> leetcode editorial
// Patience sort. We form a subsequence. Whenever, we encounter a larger number, we add it to 
// our sequence. But if we encounter or smaller or equal number, then we replace the first larger/equal
// number with this number since it gives more options and it's valid subsequence since we are travelling
// towards right direction all the time so things are in order.


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> res;
        res.push_back(nums[0]);
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] > res.back())
            {
                res.push_back(nums[i]);
            }
            else
            {
                int index = lower_bound(res.begin(), res.end(), nums[i]) - res.begin();
                res[index]=nums[i];
                // for(int j = 0; j < res.size(); j++)
                // {
                //     if(res[j] >= nums[i])
                //     {
                //         res[j] = nums[i]; // wider options
                //         break;
                //     }
                // }
            }
        }
        return res.size();
    }
};
