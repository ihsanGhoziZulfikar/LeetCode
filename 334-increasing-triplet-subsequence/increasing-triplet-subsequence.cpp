typedef long long int ll;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        ll xx=2147483648;
        ll n1=xx;
        ll n2=xx;
        ll c1=xx;

        for(int i=0;i<nums.size();i++){
            if(nums[i]>n2){
                return true;
            }
            if(n2==xx){
                if(n1<nums[i]){
                    n2=nums[i];
                }else{
                    n1=nums[i];
                }
                continue;
            }
            if(n1<nums[i] && n2>nums[i]){
                n2=nums[i];
                continue;
            }
            if(c1>=nums[i]){
                c1=nums[i];
                continue;
            }
            if(n2>nums[i]){
                n1=c1;
                n2=nums[i];
                continue;
            }
        }
        return false;
    }
};