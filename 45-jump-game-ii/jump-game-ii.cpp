class Solution {
public:
    int jump(vector<int>& nums) {
        int total_jump=0;
        int i=0;
        while(i<nums.size()-1){
            int count=0;
            int max_reach=0;
            int max_i=0;
            for(int j=i+1;j<=nums[i]+i;j++,count++){
                if(j>=nums.size()-1){
                    max_i=nums.size()-1;
                    break;
                }
                if(nums[j]+count>max_reach){
                    cout << "j: " << j << endl;
                    max_reach=nums[j]+count;
                    max_i=j;
                }
            }
            i=max_i;
            if(i<nums.size()){
                cout << "i: " << i << " nums: " << nums[i] << endl;
                total_jump++;
            }
        }
        return total_jump;
    }
};

// class Solution {
// public:
//     int jump(vector<int>& nums) {
//         if(nums.size()==1)return 0;
//         int result=0;
//         for(int i=0;i<nums.size();i++){
//             int maxi=i;
//             int maxlength=0;
//             int count=0;
//             for(int j=i+1;j<=i+nums[i];j++){
//                 if(j>=nums.size()){
//                     maxi=nums.size();
//                     break;
//                 }
//                 if(nums[j]+count>maxlength){
//                     maxi=j;
//                     maxlength=nums[j]+count;
//                 }
//                 count++;
//             }
//             i=maxi;
//             if(i<nums.size()){
//                 cout << "i: " << i << " nums: " << nums[i] << " maxlength: " << maxlength << endl;
//                 result++;
//             }
//         }
//         return result;
//     }
// };