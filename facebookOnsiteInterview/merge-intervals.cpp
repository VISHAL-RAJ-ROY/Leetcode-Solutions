bool cmp(vector<int>& a, vector <int> &b) {
    return a[0] < b[0];
}

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // sol 1 n^2
        // sol 2 n * log n sort
        sort(intervals.begin(), intervals.end(), cmp);
        
        vector<vector<int>> ret;
        vector<int> prev_iv;
        prev_iv.push_back(0);
        prev_iv.push_back(0);
        
        bool prev_set = false;
        
        for (auto &iv : intervals) {            
            
            if (prev_iv[0] <= iv[1] && iv[0] <= prev_iv[1]) {
                prev_iv[0] = min(prev_iv[0], iv[0]);
                prev_iv[1] = max(prev_iv[1], iv[1]);                    
                
            } else {
                if (prev_set) {                                    
                    ret.push_back(prev_iv);
                } 
                prev_iv = iv;          
                
            }   
            prev_set = true;
        }
        
        if (prev_set) {
            ret.push_back(prev_iv);            
        }
        
        
        
        
        return ret;
    
    }
};
