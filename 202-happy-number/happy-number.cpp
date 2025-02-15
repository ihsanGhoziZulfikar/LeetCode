class Solution {
public:
    bool isHappy(int n) {
        set<int> s;
        while(n!=1){
            int total=0;
            while(n>0){
                int digit = n%10;
                total += digit * digit;
                n/=10;
            }
            if(s.contains(total)){
                return false;
            }else{
                s.insert(total);
            }
            n=total;
        }
        return true;
    }
};