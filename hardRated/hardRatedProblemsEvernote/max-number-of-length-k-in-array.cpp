int max-number-of-length-k-in-array( vector <int> v, int k )
{
	int sz = v.size();
	vector <int> temp(sz,0);
	int i = 0; int j = 0;
	for( ; i < sz; i++ )
	{
		while( sz-i+j > 0 && j > 0 && temp[j-1] < v[i] ) j--;
		if( j < k ) temp[j++] = v[i]; 
	}
	return temp;
}
