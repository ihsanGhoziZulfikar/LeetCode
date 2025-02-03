class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            int start=i+1;
            int end=nums.size()-1;
            while(start<end){
                int current_total=nums[i]+nums[start]+nums[end];
                if(current_total==0){
                    result.push_back({nums[i],nums[start],nums[end]});
                    start++;
                    while(nums[start]==nums[start-1] && start<end)
                        start++;
                }else if(current_total<0){
                    start++;
                }else{
                    end--;
                }
            }
        }
        return result;
    }
};