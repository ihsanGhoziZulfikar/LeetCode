class Solution {
public:
    int hammingWeight(int n) {
        int res=0;
        while(n){
            if(n%2==1) res++;
            n/=2;
        }
        return res;
    }
};