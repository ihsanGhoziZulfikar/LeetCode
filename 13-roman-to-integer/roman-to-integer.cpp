class Solution {
public:
    int romanToInt(string s) {
        int value=0;
        char prev='0';
        for(int i=0;i<s.size();i++){
            switch(s[i]){
                case('I'):
                    value+=1;
                    break;
                case('V'):
                    if(prev=='I')value+=3;
                    else value+=5;
                    break;
                case('X'):
                    if(prev=='I')value+=8;
                    else value+=10;
                    break;
                case('L'):
                    if(prev=='X')value+=30;
                    else value+=50;
                    break;
                case('C'):
                    if(prev=='X')value+=80;
                    else value+=100;
                    break;
                case('D'):
                    if(prev=='C')value+=300;
                    else value+=500;
                    break;
                case('M'):
                    if(prev=='C')value+=800;
                    else value+=1000;
                    break;
            }
            prev=s[i];
        }
        return value;
    }
};