isSubsetSumDivbynum(int m, int n, int arr[])
{
	if( n > m ) return true;
	bool dp[m];
	memset(dp,false,m);
	for( int i = 0; i < n; i++ )	0
	{
		if(dp[0]) return true;
		bool t[m]; memset(t,false,m);
		for( int j = 0; j < m; j++ )
		{
			if(dp[j]) 
			{
				int u = (j+arr[i])%m;
				if( !dp[u] )
				{
					t[u] = true;		
				} 
			}
		}
		for( int j = 0; j < m; j++ ) if(t[j]) dp[j] = true;
		dp[arr[i]%m] = true;
	}
	return dp[0];
}
