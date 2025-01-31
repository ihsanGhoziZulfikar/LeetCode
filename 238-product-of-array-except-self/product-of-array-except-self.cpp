class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> front,back(nums.size());
        int total_front=1, total_back=1;
        for(int i=0;i<nums.size();i++){
            total_front*=nums[i];
            total_back*=nums[nums.size()-i-1];

            front.push_back(total_front);
            back[nums.size()-i-1]=total_back;
        }
        nums[0]=back[1];
        nums[nums.size()-1]=front[nums.size()-2];
        for(int i=1;i<nums.size()-1;i++){
            nums[i]=front[i-1]*back[i+1];
        }
        return nums;
    }
};