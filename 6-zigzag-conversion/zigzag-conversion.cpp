class Solution {
public:
    string convert(string s, int numRows) {
        if(s.length()<=numRows || numRows==1)return s;
        int i=0,round=0;
        int first=true;
        int last=false;
        int rgap = (numRows-1)*2;
        int gap = (numRows-1)*2;
        bool down = true;
        string res = "";
        while(res.length() != s.length()){
            res += s[i];
            if(last)
                i+=rgap-gap;
            else if(down || first)
                i+=gap;
            else
                i+=rgap-gap;

            down=!down;
            if(i>=s.length()){
                round++;
                i=round;
                gap-=2;
                down=true;
                if(round+1 == numRows)
                    last = true;
                first=false;
            }
        }
        return res;
    }
};