class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int, int> m;
        for(int i=0;i<arr.size();i++){
            m[arr[i]]++;
        }
        map<int,int> count;
        for(auto it=m.begin();it!=m.end();it++){
            if(count[it->second]){
                return false;
            }else{
                count[it->second]=1;
            }
        }
        return true;
    }
};