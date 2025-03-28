class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi=0;
        int i=0,j=0,k=0;
        while(j<nums.size() && nums[j]==1){
            j++;
        }
        if(j==nums.size()){
            return j-1;
        }
        k=j;
        j++;
        while(i<nums.size() && j<nums.size()){
            maxi=max(j-i-1,maxi);
            if(nums[j]==1){
                j++;
            }else{
                i=k+1;
                k=j;
                j++;
            }
        }
        maxi=max(j-i-1,maxi);
        return maxi;
    }
};
/*
1,1,0,1
i
j
k

*/