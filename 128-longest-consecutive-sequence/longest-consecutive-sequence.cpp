class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)return 0;
        sort(nums.begin(), nums.end());
        int longest=1;

        map<int, int> m;
        for(int i=0;i<nums.size();i++){
            if(m[nums[i]-1]){
                m[nums[i]]=m[nums[i]-1]+1;
                if(m[nums[i]]>longest){
                    longest = m[nums[i]];
                }
            }
            else{
                m[nums[i]]=1;
            }
        }
        return longest;
    }
};