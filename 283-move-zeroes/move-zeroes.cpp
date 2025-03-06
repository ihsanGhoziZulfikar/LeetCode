class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zero_total=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0 && i<nums.size()-zero_total){
                zero_total++;
                nums.push_back(0);
                nums.erase(nums.begin()+i);
                i--;
            }
        }
    }
};