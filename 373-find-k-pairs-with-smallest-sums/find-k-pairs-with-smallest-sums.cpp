auto cmp = [](pair<vector<int>,int> &a, pair<vector<int>,int> &b){
    return a.second >= b.second;
};

class Solution {
public:
    int init_k;
    map<pair<int,int>,int> m;
    vector<pair<vector<int>,int>> res;
    // vector<int> nums1, nums2;
    // void foo(int k, int i, int j){
    //     if(k==0 || i>=nums1.size() || j>=nums2.size() || m[{i,j}])return;
    //     m[{i,j}]=1;
    //     res.push_back({{nums1[i], nums2[j]},nums1[i]+nums2[j]});
    //     push_heap(res.begin(), res.end(), cmp);

    //     foo(k-1, i+1, j);
    //     foo(k-1, i, j+1);
    // }

    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        init_k = k;
        // this->nums1=nums1;
        // this->nums2=nums2;
        vector<vector<int>> res2;
        // foo(k,0,0);
        int i=0,j=0;
        res.push_back({{i, j},nums1[i]+nums2[j]});
        make_heap(res.begin(),res.end(),cmp);
        while(k-- && !res.empty()){
            i = res.front().first[0];
            j = res.front().first[1];
            res2.push_back({nums1[i], nums2[j]});

            pop_heap(res.begin(), res.end(), cmp);
            res.pop_back();

            if(i+1<nums1.size() && !m[{i+1,j}]){
                m[{i+1,j}]=1;
                res.push_back({{i+1, j},nums1[i+1]+nums2[j]});
                push_heap(res.begin(), res.end(), cmp);
            }
            if(j+1<nums2.size() && !m[{i,j+1}]){
                m[{i,j+1}]=1;
                res.push_back({{i, j+1},nums1[i]+nums2[j+1]});
                push_heap(res.begin(), res.end(), cmp);
            }
        }

        // for(int i=0;i<k;i++){
        //     res2.push_back(res.front().first);
        //     pop_heap(res.begin(), res.end(), cmp);
        //     res.pop_back();
        // }

        // for(auto it:res){
        //     cout << it.first[0] << " " << it[1] << endl;
        // }
        return res2;
    }
};


/*
1 1 2
1 2 3

*/