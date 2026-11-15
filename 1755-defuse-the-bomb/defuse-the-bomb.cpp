class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> v(n);
        int cur=0;
        int i=0,j = 0;

        int tk=k<0?k*-1:k;

        for(i=0;i<tk;i++){
            cur+=code[i];
        }
        v[0]=cur;

        for(i=1;i<code.size();i++){
            j=i+tk-1;
            int val = j<code.size()? code[j] : code[j-code.size()];
            cur=cur+val-code[i-1];
            v[i]=cur;
        }
        if(k>0){
            rotate(v.begin(), v.begin()+1, v.end());
        }else if(k<0){
            rotate(v.begin(), v.end()+k, v.end());
        }
        return v;

        // int j = 0;
        // for(int i=0;i<code.size();i++){
        //     if(k==0){
        //         res[i] = 0;
        //     }else if(k>0){
        //         while(j<i+k){
        //             int val = j<code.size()? code[j] : code[j-code.size()];
        //             res+=val;
        //             j++;
        //         }
        //     }else{
        //         while(j>i-k){
        //             int val = j>=0? code[j] : code[j+code.size()];
        //             res+=val;
        //             j--;
        //         }   
        //     }
        // }
    }
};