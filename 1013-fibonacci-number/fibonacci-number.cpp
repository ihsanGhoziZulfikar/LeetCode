class Solution {
public:
    int fib(int n) {
        vector<int> v = {0,1};
        for(int i=2;i<n+1;i++){
            int t = v[i-2] + v[i-1];
            v.push_back(t);
        }

        return v[n];
    }
};