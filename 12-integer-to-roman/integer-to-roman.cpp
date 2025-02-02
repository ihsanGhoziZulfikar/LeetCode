class Solution {
public:
    string intToRoman(int num) {
        string result="";
        vector<pair<int,string>> roman = {{1000,"M"}, {900,"CM"}, {500,"D"}, {400,"CD"}, {100,"C"}, {90,"XC"}, {50,"L"}, {40,"XL"}, {10,"X"}, {9,"IX"}, {5,"V"}, {4,"IV"}, {1,"I"}};
        // vector<pair<int,string>> roman;
        // roman.push_back(make_pair(1000,"M"));
        // roman.push_back(make_pair(900,"CM"));
        // roman.push_back(make_pair(500,"D"));
        // roman.push_back(make_pair(400,"CD"));
        // roman.push_back(make_pair(100,"C"));
        // roman.push_back(make_pair(90,"XC"));
        // roman.push_back(make_pair(50,"L"));
        // roman.push_back(make_pair(40,"XL"));
        // roman.push_back(make_pair(10,"X"));
        // roman.push_back(make_pair(9,"IX"));
        // roman.push_back(make_pair(5,"V"));
        // roman.push_back(make_pair(4,"IV"));
        // roman.push_back(make_pair(1,"I"));
        while(num>0){
            for(int i=0;i<roman.size();){
                if(num>=roman[i].first){
                    result.append(roman[i].second);
                    num-=roman[i].first;
                    break;
                }else{
                    i++;
                }
            }
        }
        return result;
    }
};

