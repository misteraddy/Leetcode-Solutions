class RecentCounter {
public:
    
    queue<int> q;
    
    RecentCounter() {
        
    }
    
    int ping(int t) {
    q.push(t);
    
    int lower_bound = t - 3000;
    int upper_bound = t;
    
    while (!q.empty() && q.front() < lower_bound) {
        q.pop();
    }
    
    return q.size();
}
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */