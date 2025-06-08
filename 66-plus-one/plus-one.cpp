class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i = digits.size()-1;
        bool lead=true;
        while(i>=0 && lead){
            digits[i]+=1;
            if(digits[i]>9){
                digits[i] = 0;
                lead = true;
            } else{
                lead = false;
            }
            i--;
        }
        if(lead){
            digits.insert(digits.begin(),1);
        }
        return digits;
    }
};