class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0], nums[1]);
        vector<int> v(nums.size());
        v[0] = nums[0];
        v[1] = nums[1];
        v[2] = max(v[0] + nums[2], v[1]);

        for(int i=3;i<nums.size();i++){
            v[i] = max(v[i-2] + nums[i], v[i-1]);
            v[i] = max(v[i], v[i-3] + nums[i]);
        }

        return v[v.size()-1];
    }
};