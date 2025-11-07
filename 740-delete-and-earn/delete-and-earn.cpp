class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<pair<int,int>> nums2;
        sort(nums.begin(), nums.end(), greater<int>());
        for(int i=0;i<nums.size();i++){
            int num=nums[i];
            int num_total=num;
            i++;
            while(i<nums.size() && nums[i]==num){
                num_total+=num;
                i++;            
            }
            nums2.push_back({num,num_total});
            i--;
        }

        if(nums2.size()==1)
            return nums2[0].second;

        if(nums2[1].first+1 != nums2[0].first){
            nums2[1].second+=nums2[0].second;
        }
        if(nums2.size()==2){
            return max(nums2[0].second, nums2[1].second);
        }

        if(nums2[2].first+1 != nums2[1].first){
            nums2[2].second+=max(nums2[1].second,nums2[0].second);
        }else{
            nums2[2].second = max(nums2[0].second+nums2[2].second, nums2[1].second);
        }

        if(nums2.size()==3)
            return max(nums2[2].second, nums2[1].second);

        for(int i=3;i<nums2.size();i++){
            // cout << nums2[i].second << endl;
            if(nums2[i].first+1==nums2[i-1].first){
                int temp = max(nums2[i-2].second + nums2[i].second, nums2[i-1].second);
                nums2[i].second = max(temp, nums2[i-3].second + nums2[i].second);
            }else{
                nums2[i].second+=max(nums2[i-1].second,nums2[i-2].second);
            }
        }

        return max(nums2[nums2.size()-2].second,nums2[nums2.size()-1].second);
    }
};


// class Solution {
// public:
//     int deleteAndEarn(vector<int>& nums) {
//         map<int, int> m;
//         int total=0;
//         int result=0;
//         for(int i=0;i<nums.size();i++){
//             total += nums[i];
//             if(m[nums[i]])m[nums[i]]+=nums[i];
//             else nums[i] = nums[i];
//         }

//         for(auto it=m.begin();it!=m.end();++it){
//             if()
//         }
//         return 0;
//     }
// };