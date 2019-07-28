class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int m = prices.size();
        if( !m ) return 0;
        if( m == 1 ) return 0;
        if( m == 2 ) return max(0,prices[1]-prices[0]);
        if( m == 3 ) return max(0,max(prices[1]-prices[0],max(prices[2]-prices[1],prices[2]-prices[0])));
        int a,b,c,mi;
        mi = min(prices[0],min(prices[2],prices[1]));
        a = max(0,max(prices[1]-prices[0],max(prices[2]-prices[1],prices[2]-prices[0])));
        b = max(0,prices[1]-prices[0]);
        c = 0;
        for( int i = 3; i < m; i++ )
        {
            mi = min(mi,prices[i]-b);
            int aa = max(a,prices[i]-mi);
            c = b; 
            b = a;
            a = aa;
        }
        return a;
    }
};
