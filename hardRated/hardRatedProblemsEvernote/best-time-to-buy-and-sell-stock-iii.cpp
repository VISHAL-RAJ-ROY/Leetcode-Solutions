class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy1 = INT_MAX, buy2 = INT_MAX;
        int sell1 = 0, sell2 = 0;
        for( int e : prices )
        {
            buy1 = min(buy1,e);
            sell1 = max(sell1,e-buy1);
            buy2 = min(buy2,e-sell1);
            sell2 = max(sell2,e-buy2);
        }
        return sell2;
    }
};
