class Solution {
public:
    int longestValidParentheses(string s) {
        int l, r;
        l = r = 0;
        int ans = 0;
        int len = s.length();
        for( int i =0; i < len; i++ )
        {
            if( s[i] == '(' ) l++;
            else r++;
            if( l == r ) ans = max(ans,r+l);
            else if( r > l ) { r = l = 0; }
        }
        r=l=0;
        for( int i =len-1; i >= 0; i-- )
        {
            if( s[i] == ')' ) l++;
            else r++;
            if( l == r ) ans = max(ans,r+l);
            else if( r > l ) { r = l = 0; }
        }
        return ans;
    }
};
