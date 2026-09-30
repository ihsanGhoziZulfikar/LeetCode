class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> m;
        vector<int> v;

        for(int i=0;i<nums.size();i++){
            int want = target - nums[i];

            if(m[want]){
                v={i, m[want]-1};
                break;
            }else{
                m[nums[i]] = i+1;
            }
        }

        return v;
    }
};