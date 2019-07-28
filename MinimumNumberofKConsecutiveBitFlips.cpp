class Solution {
    public:
        int minKBitFlips(vector <int> & A, int K) {
        int res = 0;
        queue<int> q;
        int sz = A.size();
        for( int i = 0; i < sz; i++ )
        {
            if( A[i] != q.size()%2?0:1 )
            {
                res++;
                q.push(i+K-1);
            }
            if( !q.empty()&& q.front() <= i ) q.pop();
        }
        return q.empty()? res:-1;
    }
};
