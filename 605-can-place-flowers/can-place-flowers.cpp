class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int empty_len=0;
        if(flowerbed.size()>0 && flowerbed[0]==0) empty_len=1;
        for(int i=0;i<flowerbed.size();i++){
            if(flowerbed[i]==0)empty_len++;
            else empty_len=0;
            if(empty_len==3){
                empty_len=1;
                n--;
            }
        }
        if(empty_len>1)n--;
        if(n>0)return false;
        return true;
    }
};