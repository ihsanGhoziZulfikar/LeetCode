class Solution {
public:
    int compress(vector<char>& chars){
        char current = ' ';
        for(int i=0;i<chars.size();i++){
            if(chars[i]==current){
                int count=1;
                while(i<chars.size() && chars[i]==current){
                    chars.erase(chars.begin()+i);
                    count++;
                }
                // cout << count << endl;
                string count_str = to_string(count);
                for(int j=0;j<count_str.length();j++){
                    // cout << char_c << endl;
                    chars.insert(chars.begin()+i,count_str[j]);
                    i++;
                }
                i--;
            }else{
                current=chars[i];
            }
        }
        return chars.size();
    }
};