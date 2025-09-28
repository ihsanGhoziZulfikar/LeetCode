impl Solution {

    pub fn foo(n: usize, m: &mut Vec<i32>) -> i32 {
        if n <= 2 {
            return n as i32;
        }
        if m[n] != -1 {
            return m[n];
        }
        let result = Self::foo(n-1, m)+Self::foo(n-2, m);
        m[n] = result;
        return result;
    }
    pub fn climb_stairs(n: i32) -> i32 {
        let mut m = vec![-1; (n+1) as usize];
        Self::foo(n as usize, &mut m)
    }
}
// 1=1
// 2=2
// 3=3
// 4=5
// 5=8
// 6=13