class Solution {
public:
    multiset<int> r; multiset<int, greater<int>> l;
    int n, K;
    vector <double> ans;
    void add( int u) {
        int ll = l.size(); int rr = r.size();
        if( ll == rr ) {
            int j = *l.begin();
            if( u < j ) { l.erase(l.begin()); l.insert(u); r.insert(j); } 
            else r.insert(u);
        } else {
            int j = *r.begin(); 
            if( u > j ) { r.erase(r.begin()); r.insert(u); l.insert(j); }
            else l.insert(u);
        }
        ll = l.size(); rr = r.size();
        if( ll+rr == K ) {
            (K%2)?ans.push_back((*r.begin())*1.0):ans.push_back(((long long int)(*r.begin())-(long long int)(*l.begin()))*0.5+(*l.begin())*1.0);
        } 
    }
    void remove( int u ) {
        int y = *r.begin();
        if( u >= y ) { r.erase(r.find(u)); if( r.size() < l.size() ) { int j = *l.begin(); l.erase(l.begin()); r.insert(j); } }
        else { l.erase(l.find(u)); if( r.size()-l.size() == 2 ){ int j = *r.begin(); r.erase(r.begin()); l.insert(j); } }
    }
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        n = nums.size(); if( !n || !k ) return ans; int i = 0; K = k; 
        if( k == 1 ) { for( int u : nums ) ans.push_back(u*1.0); return ans; }
        r.insert(nums[0]); 
        for( i = 1; i < k ; i++ ) add(nums[i]); 
        for( ; i < n; i++ ) {
            remove(nums[i-k]); add(nums[i]);
        }
        return ans;
    }
};
