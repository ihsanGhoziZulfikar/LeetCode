class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int res=0;
        for(auto it=nums.begin();it<nums.end();it++){
            if(*it==val){
                nums.erase(it);
                it--;
            }else{
                res++;
            }
        }
        return res;
    }
};