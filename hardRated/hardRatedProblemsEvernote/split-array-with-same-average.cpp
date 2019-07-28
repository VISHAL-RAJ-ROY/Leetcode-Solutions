class Solution {
public:
    bool splitArraySameAverage(vector<int>& A) {
        int ct  =0, sz = A.size(), sum = 0;
        for( int i = 0; i < sz; i++ ) sum += A[i];
        for( int i = 1; i < sz; i++ ) if( sum*i%sz == 0 ) ct++;
        if(!ct) return false;
        vector <unordered_set<int>> s(sz/2+1); s[0].insert(0);
        for( int i = 0; i < sz; i++ )
        {
            for( int k = sz/2; k >= 1; k-- )
            {
                for( int j : s[k-1] ) s[k].insert(j+A[i]);
            }
        }
        for( int i = 1; i <= sz/2; i++ ) 
        {
            if( sum*i%sz == 0 && s[i].find(sum*i/sz) != s[i].end() ) return true;
        }
        return false;
    }
};
