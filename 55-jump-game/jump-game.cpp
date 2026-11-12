class Solution {
public:
    bool canJump(vector<int>& nums) {
        bool flag = true;
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]==0){
                flag=false;
                int dis=2;
                int c_i=i;
                i--;
                while(i>=0){
                    if(nums[i]<dis){
                        dis++;
                        i--;
                    }else{
                        flag=true;
                        break;
                    }
                }
            }
        }
        return flag;
    }
};