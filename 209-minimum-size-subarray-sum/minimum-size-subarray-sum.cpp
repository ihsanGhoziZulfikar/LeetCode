class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0,j=0,total=0,min_len=100001;
        while(i<nums.size() && j<nums.size()){
            if(total<target){
                total+=nums[j];
                j++;
            }else{
                int cur_len=j-i;
                if(cur_len<min_len)min_len=cur_len;
                total-=nums[i];
                i++;
            }
        }
        while(i<nums.size() && total>=target){
            int cur_len=j-i;
            if(cur_len<min_len)min_len=cur_len;
            total-=nums[i];
            i++;
        }
        if(min_len==100001)return 0;
        return min_len;
    }
};