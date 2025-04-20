class RecentCounter {
public:
    deque<int> q;
    int count=0;
    RecentCounter() {
        
    }
    
    int ping(int t) {
        q.push_back(t);
        count++;
        while(!q.empty() && q.front()+3000 < t){
            q.pop_front();
            count--;
        }
        return count;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */