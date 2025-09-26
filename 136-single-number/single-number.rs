impl Solution {
    pub fn single_number(mut nums: Vec<i32>) -> i32 {
        nums.sort();
        for i in (0..nums.len()).step_by(2) {
            if(i+1<nums.len()){
                if(nums[i] != nums[i+1]){
                    return nums[i];
                }
            }else{
                return nums[i];
            }
        }
        nums[0]
    }
}