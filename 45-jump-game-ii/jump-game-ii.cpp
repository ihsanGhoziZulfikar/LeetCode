class Solution {
public:
    int jump(vector<int>& nums) {
        int total_jump=0;
        int i=0;
        while(i<nums.size()-1){
            int count=0;
            int max_reach=0;
            int max_i=0;
            for(int j=i+1;j<=nums[i]+i;j++,count++){
                if(j>=nums.size()-1){
                    max_i=nums.size()-1;
                    break;
                }
                if(nums[j]+count>max_reach){
                    max_reach=nums[j]+count;
                    max_i=j;
                }
            }
            i=max_i;
            if(i<nums.size()){
                total_jump++;
            }
        }
        return total_jump;
    }
};