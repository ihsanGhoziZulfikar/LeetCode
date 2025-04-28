class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int left=0, right=0;
        int pivot=0;
        for(int i=1;i<nums.size();i++){
            right+=nums[i];
        }
        if(left==right){
            return pivot;
        }
        while(pivot<nums.size()-1){
            left+=nums[pivot];
            right-=nums[pivot+1];
            if(left==right){
                return pivot+1;
            }
            pivot++;
        }
        return -1;
    }
};