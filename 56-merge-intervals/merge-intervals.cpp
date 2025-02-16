class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        sort(intervals.begin(), intervals.end(),[](auto &left, auto &right){
            return left[0] < right[0];
        });
        
        int i=0;
        while(i<intervals.size()){
            vector<int> current = intervals[i];
            while(i+1<intervals.size() && current[1] >= intervals[i+1][0]){
                current[1] = max(current[1], intervals[i+1][1]);
                i++;
            }
            result.push_back(current);
            i++;
        }
        return result;
    }
};