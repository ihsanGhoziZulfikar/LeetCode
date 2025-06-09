class Solution {
public:
    string res;
    int i;
    void plusZero(){
        if(res.length()==0 || res.length()<i){
            res = "0" + res;
        }else{
            return;
        }
    }
    void plusOne(){
        if(res.length()==0 || res.length()<i){
            res = "1" + res;
        }else{
            if(res[0]=='1'){
                res[0] = '0';
                res = "1" + res;
            }else {
                res[0] = '1';
            }
        }
    }
    void plusTwo(){
        if(res.length()==0 || res.length()<i){
            res = "10" + res;
        }else{
            // if(res[0]=='1'){
            //     res = "1"+ res;
            // }else {
            //     res[0] = '1';
            // }
            res = "1" + res;
        }
    }
    string addBinary(string a, string b) {
        i=1;
        while(i<=a.length() && i<=b.length()){
            if(a[a.length()-i] == '1' && b[b.length()-i] =='1'){
                plusTwo();
            }else if(a[a.length()-i] == '1' || b[b.length()-i] =='1'){
                plusOne();
            }else{
                plusZero();
            }
            i++;
        }
        while(i<=a.length()){
            if(a[a.length()-i] == '1'){
                plusOne();
            }else{
                plusZero();
            }
            i++;
        }
        while(i<=b.length()){
            if(b[b.length()-i] == '1'){
                plusOne();
            }else{
                plusZero();
            }
            i++;
        }
        return res;
    }
};