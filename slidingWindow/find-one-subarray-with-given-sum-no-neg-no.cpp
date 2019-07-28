void find-one-subarray-with-given-sum-no-neg-no( vector <int> A, int k ) {
	int start = 0; int i;
	int sum = A[0];
	int n = A.size();
	for( i = 1; i <= n; i++ ) {
		if( sum > K && start < i-1 ) {
			sum -= A[start]; start++;
		} 
		if( sum == K ) cout<<"found between "<<start<<" and "<<i-1<<"\n";
		if( i < n ) sum += A[i];
	}
}
