class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        string bit;
        while(n>0){
            if(n%2==0){
                bit += "0";
            }else{
                bit += "1";
            }
            n/=2;
        }
        while(bit.length()<32){
            bit+="0";
        }
        uint32_t result=0;
        for(int i=0;i<bit.length();i++){
            if(bit[bit.length()-i-1]=='1'){
                result+=(pow(2,i));
            }
        }
        return result;
    }
};