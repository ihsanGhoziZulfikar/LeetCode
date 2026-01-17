class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> v {0};
        int length = 0;

        for(int i=1;i<nums.size();i++){
            if(nums[i] > nums[v[v.size()-1]]){
                v.push_back(i);
            }else{
                for(int j=0;j<v.size();j++){
                    if(nums[i] <= nums[v[j]]){
                        v[j] = i;
                        break;
                    }
                }
            }
            
        }

        return v.size();
    }
};