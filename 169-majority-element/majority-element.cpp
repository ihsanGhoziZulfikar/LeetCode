class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> m;
        int highest=1, result=nums[0];
        for(auto it=nums.begin();it<nums.end();it++){
            if(m.count(*it)){
                m[*it]++;
                if(m[*it]>highest){
                    highest=m[*it];
                    result=*it;
                }

            }else{
                m.insert(make_pair(*it,1));
            }
        }
        
        return result;
    }
};
// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         int count[100000]={0}, count2[100000]={0};
//         for(int i=0;i<nums.size();i++){
//             if(nums[i]>=0){
//                 cout << "start " << count[nums[i]] << endl;
//                 count[nums[i]]++;
//                 if(count[nums[i]]>nums.size()/2){
//                     cout << "return " << count[nums[i]] << endl;
//                     return nums[i];
//                 }
//             }else{
//                 nums[i]/=-1;
//                 count2[nums[i]]++;
//                 if(count2[nums[i]]>nums.size()/2){
//                     return nums[i]/-1;
//                 }
//             }
            
//         }
//         return 0;
//     }
// };