class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int m = prices.size();
        if( !m ) return 0;
        if( m == 1 ) return 0;
        if( m == 2 ) return max(0,prices[1]-prices[0]-fee);
        int a,b,mi;
        b = 0;
        a = max(0,prices[1]-prices[0]-fee);
        mi = min(prices[1],prices[0]);
        for( int i = 2; i < m; i++ )
        {
            int aa = max(a,prices[i]-fee-mi);
            mi = min(mi,prices[i]-a);
            b = a;
            a = aa;
        }
        return a;
    }
};
