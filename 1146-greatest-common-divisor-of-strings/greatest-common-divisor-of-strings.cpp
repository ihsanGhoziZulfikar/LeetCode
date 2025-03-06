class Solution {
public:
    int gcd(int a, int b){
        if(a==0){
            return b;
        }
        return gcd(b%a, a);
    }

    string gcdOfStrings(string str1, string str2) {
        int result=0;
        vector<int> divi;
        if(str1.length()<str2.length()){
            string temp = str1;
            str1 = str2;
            str2 = temp;
        }

        // int divider = max(str1.length(), str2.length())/2;
        int lo = gcd(str1.length(),str2.length());

        for(int i=1;i<floor(sqrt(lo))+1;i++){
            if(lo%i==0){
                divi.push_back(i);
                if(lo!=i*i){
                    divi.push_back(lo/i);
                }
            }
        }
        sort(divi.begin(), divi.end(), greater<>());

        for(int i=0;i<divi.size();i++){
            int res=0;
            int same=true;
            string copy = str1.substr(0,divi[i]);
            for(int j=0;j<str2.length()/divi[i];j++){
                if(str2.substr(j*divi[i],divi[i])!=copy){
                    same=false;
                    break;
                }
            }
            if(same){
                for(int j=0;j<str1.length()/divi[i];j++){
                    if(str1.substr(j*divi[i],divi[i])!=copy){
                        same=false;
                        break;
                    }
                }
                if(same){
                    return copy;
                }
            }
        }

        return "";
    }
};

// class Solution {
// public:
//     string gcdOfStrings(string str1, string str2) {
//         string largest;
//         int idx=0;
//         while(idx<str1.length() && idx<str2.length() && str1[idx]==str2[idx]){
//             largest+=str1[idx];
//             idx++;
//         }
//         if(idx==0) return "";
//         if(idx==str1.length() && idx==str2.length()) return largest;

//         return largest;
//     }
// };