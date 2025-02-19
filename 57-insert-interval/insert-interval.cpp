class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // vector<vector<int>> result;
        bool added=false;
        if(intervals.size()==0){
            return {newInterval};
        }
        // if(newInterval[0] < intervals[0][0]){
        //     if(newInterval[1]>=intervals[0][0]){
        //         intervals[0][0]=newInterval[0];

        //     }else{
        //         intervals.insert(intervals.begin()+0,newInterval);
        //     }
        //     added=true;
        // }
        for(int i=0;i<intervals.size();i++){
            if(!added && (intervals[i][1] >= newInterval[0] && intervals[i][0]<=newInterval[1])){

                intervals[i][1] = max(intervals[i][1], newInterval[1]);
                // if(intervals[i][0] > newInterval[0])
                    intervals[i][0] = min(intervals[i][0], newInterval[0]);
                int idx=i;
                i++;
                while(i<intervals.size() && intervals[i][0]<=intervals[idx][1]){
                    intervals[idx][1] = max(intervals[idx][1],intervals[i][1]);
                    intervals.erase(intervals.begin()+i);
                }
                added=true;
            }
            if(!added && intervals[i][0]>newInterval[1]){
                intervals.insert(intervals.begin()+i,newInterval);
                added=true;
            }
        }
        if(!added){
            // if(newInterval[1]<intervals[0][0])
            //     intervals.insert(intervals.begin()+0,newInterval);
            // else
                intervals.push_back(newInterval);
        }
        return intervals;
    }
};