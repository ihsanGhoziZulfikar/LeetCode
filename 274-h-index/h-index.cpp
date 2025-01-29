class Solution {
public:
    int hIndex(vector<int>& citations) {
        int max_h=0;
        sort(citations.begin(), citations.end(), greater<>());
        int i=0;
        while(i<citations.size()){
            int start_i=i;
            while(i<citations.size() && citations[i]==citations[start_i]){
                i++;
            }
            int h=min(i,citations[start_i]);
            if(h>max_h ){
                max_h=min(i,citations[start_i]);
            }
        }
        return max_h;
    }
};