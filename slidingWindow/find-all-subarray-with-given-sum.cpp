void find-all-subarray-with-given-sum( vector<int>A, int K ) {
	unordered_map<int,vector<int>> count;
	count[0].push_back(-1);
	int curr = 0;
	int n = A.size();
	for( int i = 0; i < n; i++ ) {
		curr += A[i];
		if( count[curr-K].size() ) {
			for( int u : count[curr-K] ) cout<<"found between "<<u+1<<" and "<<i<<"\n";
		}
		count[curr].push_back(i);
	}
}
