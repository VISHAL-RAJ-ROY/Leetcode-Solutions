class Solution {
public:
    int minCut(string s) {
        int n = s.length(); 
        if( n == 1 ) return 0;
        vector <vector <int>> ispal(n,vector <int>(n,0));
        for( int i = 0; i < n; i++ )
        {
            ispal[i][i] = 1;
            int r = 1;
            while( i-r >= 0 && i+r < n && s[i-r] == s[i+r] )
                ispal[i-r][i+r]=1, r++;
            if( i+1 < n && s[i] == s[i+1] )
            {
                r = 1;
                ispal[i][i+1] = 1;
                while( i-r >= 0 && i+1+r < n && s[i-r] == s[i+1+r] )
                    ispal[i-r][i+1+r]=1, r++;
            }
        }
        vector <int> cut(n,0);
        for( int i = 1; i < n; i++ )
        {
            if( ispal[0][i] ) continue;
            int mi = 0x3f3f3f3f;
            for( int j = i-1; j >= 0; j-- )
                if( ispal[j+1][i] )
                    mi = min(mi,cut[j]);
            cut[i] = mi+1;
        }       
        return cut[n-1];
    }
};
