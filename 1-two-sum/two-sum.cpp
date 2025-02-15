class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> m;
        map<int,int> m2;
        for(int i=0;i<nums.size();i++){
            int remain = target-nums[i];
            if(m.count(nums[i])){
                return {i,m[nums[i]]};
            }else{
                m[remain] = i;
            }
        }
        return {0,0};
    }
};

// nums[i] = current number
// i = current index
// target-nums[i] = remains needed