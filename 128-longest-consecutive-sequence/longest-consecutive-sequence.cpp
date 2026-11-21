class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,int>m;
        int res=0;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]=1;
        }
        for(auto it=m.begin();it!=m.end();++it){
            if(!m[it->first-1]){
                int count=0;
                int i=it->first;
                while(m[i]){
                    count++;
                    i++;
                }
                res=max(res,count);
            }
        }

        // for(int i=mini;i<=maxi;i++){
        //     if(m[i]){

        //     }
        // }
        return res;
    }
};