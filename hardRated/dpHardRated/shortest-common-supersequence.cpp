class Solution {
public:
    
    string scs( string & s, string & p ) { // shortest-commom-supersequence
	int m = s.length(), n = p.length(), i = 0, j = 0; vector <vector <int>> dp(m+1,vector<int>(n+1,0));
	for( i = 0; i <= m; i++ ) {
		for( j = 0; j <= n; j++ ) {
			if(!i) dp[i][j] = j;
			else if( !j ) dp[i][j] = i;
			else if( s[i-1] == p[j-1] ) dp[i][j] = 1+dp[i-1][j-1];
			else dp[i][j] = 1+min(dp[i-1][j],dp[i][j-1]);
		}
	}
	i = m; j = n; int k = dp[m][n]; string ans(k,' ');
	while( i > 0 && j > 0 ) {
		if( s[i-1] == p[j-1] ) ans[--k] = s[--i], j--;
		else if( dp[i-1][j] > dp[i][j-1] ) ans[--k] = p[--j];
		else ans[--k] = s[--i];
	} 
	while( i > 0 ) ans[--k] = s[--i]; while( j > 0 ) ans[--k] = p[--j];
	return ans;
}
    string shortestCommonSupersequence(string str1, string str2) {
        return scs(str1,str2);
    }
};
