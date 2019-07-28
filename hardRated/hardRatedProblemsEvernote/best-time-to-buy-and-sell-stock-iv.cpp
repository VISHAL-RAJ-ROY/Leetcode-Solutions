class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        // dp[i][k] = max(dp[i-1][k],prices[i]-prices[j]+dp[j-1][k-1])
        int m = prices.size();
        if( !m ) return 0;
        if( k >= m/2 )
        {
            int profit = 0;
            for( int i = 1; i < prices.size(); i++ ) 
                if( prices[i] > prices[i-1] ) 
                    profit += prices[i]-prices[i-1];
            return profit;
        }
        vector <vector <int>> dp(m,vector <int>(2,0));
        for( int j = 1; j < k+1; j++ )
        {
            int mi = prices[0];
            for( int i = 1; i < m; i++ )
            {
                mi = min(mi,prices[i]-dp[(i-1)][(j-1)%2]);
                dp[i][j%2] = max(dp[(i-1)][j%2],prices[i]-mi);
            }
        }  
        return dp[(m-1)][k%2];
    }
};


