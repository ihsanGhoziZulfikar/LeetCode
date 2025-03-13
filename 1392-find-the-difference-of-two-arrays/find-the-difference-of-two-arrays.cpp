class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> m1,m2;
        for(int i=0;i<nums1.size();i++){
            if(!m1[nums1[i]]){
                m1[nums1[i]]=1;
            }else{
                nums1.erase(nums1.begin()+i);
                i--;
            }
        }
        for(int i=0;i<nums2.size();i++){
            if(!m2[nums2[i]]){
                m2[nums2[i]]=1;
            }else{
                nums2.erase(nums2.begin()+i);
                i--;
            }
        }
        for(int i=0;i<nums1.size();i++){
            if(m2[nums1[i]]){
                nums1.erase(nums1.begin()+i);
                i--;
            }
        }
        for(int i=0;i<nums2.size();i++){
            if(m1[nums2[i]]){
                nums2.erase(nums2.begin()+i);
                i--;
            }
        }
        return {nums1,nums2};
    }
};