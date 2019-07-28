class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        int m = t.length();
        if( n == 0 || m == 0 ) return "";
        if( m > n ) return "";
        int cc, dd; cc = dd = 0;
        vector <int> c(60,0); for( char e :  t) { if(!c[e-'A']) cc++; c[e-'A']++; }
        vector <int> d(60,0);
        int l,r; l = r = 0;
        int* ans = new int[3]; ans[0] = ans[1] = ans[2] = -1;
        while( r < n ) {
            char ch = s[r];
            if( c[ch-'A'] > 0 ) { d[ch-'A']++; if( d[ch-'A'] ==  c[ch-'A'] ) dd++; }
            while( dd == cc && l <= r ) {
                if( ans[0] == -1 || ans[0] > r-l+1 ) {
                    ans[0] = r-l+1; ans[1] = l; ans[2] = r;
                }
                char cf = s[l];
                if( c[cf-'A'] > 0 ) { d[cf-'A']--; if( d[cf-'A'] < c[cf-'A'] ) dd--; }
                l++;
            }
            r++;
        }
        return (ans[0] == -1) ? "" : s.substr(ans[1],ans[2]-ans[1]+1);
    }
};
