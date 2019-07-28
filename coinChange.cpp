int m; 
int V[m];

coinChange( int n )
{
	int t[n+1];
	memset(t,0,n+1);
	t[0] = 1;
	for( int i = 0; i < m; i++ )
		for( int j = V[i]; j <= n ; j++ )
			t[j] += t[j-V[i]];
	return t[n];
}
