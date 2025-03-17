class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int longest=0;
        int curr=0;
        deque<int> q_k;
        q_k.push_back(0);
        int i=0;
        for(i=0;i<nums.size();i++){
            if(nums[i]==0){
                if(k>0){
                    q_k.push_back(i);
                    k--;
                }else{
                    break;
                }
            }
            // if(nums[i]==1){
            //     continue;
            // }else if(k>0){
            //     k--;
            //     curr++;
            //     q_k.push(i);
            // }else if(k==0){
            //     break;
            // }
        }
        longest = i;

        for(;i<nums.size();i++){
            longest = max(longest,i-q_k.front()-1);
            if(nums[i]==0){
                // longest = max(longest,i-q_k.front());
                q_k.pop_front();
                q_k.push_back(i);
            }
            // cout << i << " " << q_k.front() << endl;
        }
        longest = max(longest,i-q_k.front()-1);


        return longest;
    }
};