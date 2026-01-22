class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int longest = 1;
        vector<pair<int,int>> lis(nums.size());
        lis[nums.size()-1] = {1,1};
        for(int i=nums.size()-2;i>=0;i--){
            lis[i] = {1,1};
            for(int j=i;j<nums.size();j++){
                if(nums[i] < nums[j]){
                    if(1+lis[j].first > lis[i].first){
                        lis[i].first = 1+lis[j].first;
                        lis[i].second = lis[j].second;
                    }else if(1+lis[j].first == lis[i].first){
                        lis[i].second += lis[j].second;
                    }
                }
            }
            longest = max(longest, lis[i].first);
        }

        int res=0;
        for(int i=0;i<lis.size();i++){
            // cout << lis[i].first << " " << lis[i].second << endl;
            if(lis[i].first == longest)res+=lis[i].second;
        }

        return res;
    }
};