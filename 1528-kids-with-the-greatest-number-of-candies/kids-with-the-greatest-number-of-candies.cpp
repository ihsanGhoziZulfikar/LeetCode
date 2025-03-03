class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int highest=0;
        vector<bool> v;
        for(int i=0;i<candies.size();i++){
            if(candies[i]>highest) highest=candies[i];
        }
        for(int i=0;i<candies.size();i++){
            if(candies[i]+extraCandies>=highest){
                v.push_back(true);
            }else{
                v.push_back(false);
            }
        }
        return v;
    }
};