class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        int sz = A.size();
        vector <int> p(sz+1,0);
        vector <int> count(K,0);
        count[0] = 1;
        for( int i = 0; i < sz; i++ )
        {
            p[i+1] = p[i]+A[i];
            count[(K+p[i+1]%K)%K]++;
        }
        int ct =0;
        for( int i = 0; i < K; i++ ) 
        {
            if( count[i] )
            {
                ct += count[i]*(count[i]-1)/2;
            }
        }
        return ct;
    }
};                                                                          
