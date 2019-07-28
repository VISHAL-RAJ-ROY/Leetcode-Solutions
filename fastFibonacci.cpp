int f[max];
memset(f,-1,sizeof(f));

int fastFib( int n )
{
	if( n == 0 ) return 0;
	else if( n == 1 ) return 1;
	else if( n == 2 ) return 1;
	else if( f[n] != -1 ) return f[n];
	else 
	{
		int k = (n&1)?(n+1)/2:n/2;
		return f[n] = (n&1)?(fastFib(k)*f[k]+fastFib(k-1)*f[k-1]):(fastFib(k)*(f[k]+2*fastFib(k-1)));
	}
}
