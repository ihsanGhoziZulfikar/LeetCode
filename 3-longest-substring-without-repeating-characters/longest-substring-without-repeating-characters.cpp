class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> char_idx;
        int max_len=0;
        int i=0;
        for(int j=0;j<s.length();j++){
            auto it=char_idx.find(s[j]);
            if(it==char_idx.end() || it->second<i){ // if not exist or before i (start of window)
                max_len=max(max_len,j-i+1);
                cout << j << " " << i << endl;
            }else{
                i=it->second+1;
            }
            char_idx[s[j]]=j;
        }
        return max_len;
    }
};