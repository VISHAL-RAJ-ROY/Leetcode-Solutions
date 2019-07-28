class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = 0;
        int sum = 0;
        int sm = INT_MIN;
        int ct = 0;
        for( int & i : nums )
        {
            sum += i; ans = max(ans,sum); if( sum < 0 ) sum = 0; 
            if(i<0)sm = max(sm,i);
            if(!i)ct++;
        }
        if(!ct)if( ans == 0 ) {if( sm != INT_MIN ){ans = sm;}}
        return ans;
    }
};
