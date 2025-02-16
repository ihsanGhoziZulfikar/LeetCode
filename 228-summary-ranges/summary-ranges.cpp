class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        for(int i=0;i<nums.size();i++){
            int current_num = nums[i];
            string current_str = to_string(current_num);
            while(i+1<nums.size() && nums[i+1]==nums[i]+1){
                i++;
            }
            if(current_num!=nums[i]){
                current_str += "->" + to_string(nums[i]);
            }
            result.push_back(current_str);
        }
        return result;
    }
};