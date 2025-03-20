class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int highest=0;
        int current=0;
        for(int i=0;i<gain.size();i++){
            current+=gain[i];
            highest = max(highest,current);
        }
        return highest;
    }
};