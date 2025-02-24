class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==1){
            return 1;
        }
        int exist = 0, res=1;
        auto it=nums.begin()+1;
        if(*it == *(it-1)){
            exist=1;
        }
        for(;it<nums.end();){
            if(*it == *(it-1)){
                if(exist==0 || exist==1){
                    exist++;
                    res++;
                    it++;
                }else {
                    nums.erase(it);
                }
            }else{
                res++;
                exist=1;
                it++;
            }
        }
        return res;
    }
};