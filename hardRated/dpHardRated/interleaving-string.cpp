class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.length(); 
        int m = s2.length();
        if( n+m != s3.length() ) return false;
        vector <int> dp(m+1,0);
        for( int i = 0; i < n+1; i++ )
        { 
            for( int j = 0; j < m+1; j++ )
            {
                if( !i && !j ) dp[j] = 1;
                else if( i == 0 )   
                    dp[j] = dp[j-1] && s2[j-1] == s3[i+j-1];
                else if( j == 0 )
                    dp[j] = dp[j] && s1[i-1] == s3[i+j-1];
                else 
                    dp[j] = (dp[j] && s1[i-1] == s3[i+j-1])||(dp[j-1] && s2[j-1] == s3[i+j-1]);
                    
            }
        }
        return dp[m];
    }
};
