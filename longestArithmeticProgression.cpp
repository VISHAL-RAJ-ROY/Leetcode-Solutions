#include <iostream>
#include <vector>
#include <cstdio>
#include <unordered_map>

using namespace std;

void longestArithmeticProgression( vector <int> & v )
{
	int n = v.size();
	int ma = v[0]; int mi = v[0];
	for( int i = 1; i < n; i++ ) 
	{ 
		ma = max(ma,v[i]);
		mi = min(mi,v[i]);
	}
	int pos[ma+1];
	memset(pos,-1,sizeof(pos));
	int dp[n][n]; 
	memset(dp,0,sizeof(dp));
	pos[A[0]] = 1;
	maa = 0;
	for( int i = 1; i < n-1; i++ )
	{
		for( int j = i+1; j < n; j++ )
		{
			int prev = 2*A[i]-A[j];
			if( prev < mi || prev > ma || pos[prev] == -1 ) continue;
			dp[i][j] = dp[pos[prev]][i] + 1;
			maa = max(maa,dp[i][j]);		
		}
		p[A[i]] = i;
	}
	return maa;
}

int main()
{
	
	return 0;
}
