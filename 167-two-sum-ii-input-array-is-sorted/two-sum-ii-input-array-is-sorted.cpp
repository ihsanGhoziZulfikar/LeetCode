class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        for(int i=0;numbers[i]*2<=target;i++){
            int j=numbers.size()-1;
            while(numbers[j]*2>=target){
                if(numbers[i]+numbers[j]==target){
                    res.push_back(i+1);
                    res.push_back(j+1);
                    return res;
                }
                j--;
            }
        }
        return res;
    }
};