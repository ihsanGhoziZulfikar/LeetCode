class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()==0)return true;
        if(nums[0]==0 && nums.size()>1)return false;
        bool result=true;
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]==0){
                i--;
                int length=1;
                while(i>=0){
                    if(nums[i]>length) break;
                    i--;
                    length++;
                }
                if(i<0){
                    result=false;
                }
            }
        }
        return result;
    }
};