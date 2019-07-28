class Solution {
public:
    bool isMatch(string  s, string p) {
        int n = s.length(); int m = p.length();
        vector <vector <int>> dp(2,vector <int>(m+1,0));
        dp[n%2][m] = 1;
        for( int i = n; i >= 0 ; i-- )
        {
            if( i < n ) dp[i%2][m] = 0; 
            for( int j = m-1; j >= 0; j-- )
            {
                bool fmat = (i < n && ((p[j]==s[i])||(p[j]=='.')));
                if( j+1 < m && p[j+1] == '*' ){
                    dp[i%2][j] = dp[i%2][j+2] || (fmat&&dp[(i+1)%2][j]);
                } else {
                    dp[i%2][j] = fmat && dp[(i+1)%2][j+1];
                }
            }
        }
        return dp[0][0];
    }
};
