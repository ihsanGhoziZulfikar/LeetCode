/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * unsafe fn guess(num: i32) -> i32 {}
 */

impl Solution {
    unsafe fn guessNumber(n: i32) -> i32 {
        let mut min: i32 = 0;
        let mut max: i32 = n;
        let mut mid: i32 = (max+min)/2;
        let mut res: i32 = unsafe {
            guess(mid)
        };
        while res != 0 {
            if res == 1 {
                min = mid + 1;
            } else if res == -1 {
                max = mid - 1;
            }
            mid = min + (max - min)/2;
            res = unsafe {
                guess(mid)
            };
        }
        mid
    }
}