class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;
        for(int i=0;i<=n;i++){
            int m=i;
            int count=0;
            while(m){
                if(m%2==1)count++;
                m/=2;
            }
            // res.insert(res.begin(), count);
            res.push_back(count);
        }
        return res;
    }
};