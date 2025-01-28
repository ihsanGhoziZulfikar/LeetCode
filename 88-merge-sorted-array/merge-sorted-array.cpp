class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i1=0,i2=0,length=0;
        while(i1<m && i2<n) {
            if(nums1[length] <= nums2[i2]){
                i1++;
            }else{
                nums1.pop_back();
                nums1.insert(nums1.begin() + length, nums2[i2]);
                i2++;
            }
            length++;
        }
        while(i2<n){
            nums1.pop_back();
            nums1.insert(nums1.begin() + i1+i2, nums2[i2]);
            i2++;
        }
    }
};