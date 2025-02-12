class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int res=1;
        for(;res<nums.size();){
            if(nums[res]==nums[res-1]){
                nums.erase(nums.begin()+res);
            }else{
                res++;
            }
        }
        return res;
    }
};