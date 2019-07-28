class Solution {
public:
    int findKthNumber(int n, int k) {
        int curr = 1;
        k--;
        while( k > 0 )
        {
            int s = step(n,curr,curr+1);
            if( s <= k )
            {
                k -= s;
                curr += 1;
            }
            else 
            {
                curr *= 10;
                k -= 1;
            }
        }
        return curr;
    }
    int step( int n, long n1, long n2 )
    {
        long s = 0;
        while( n1 <= n )
        {
            s += min((long)(n+1),n2)-n1;
            n1 *= 10;
            n2 *= 10;
        }
        return s;
    }
};
