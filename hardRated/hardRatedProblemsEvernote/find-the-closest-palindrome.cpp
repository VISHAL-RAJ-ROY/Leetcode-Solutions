class Solution {
public:
    string nearestPalindromic(string n) {
        long long int num = stoll(n); 
        long long int hi = high(num+1);
        long long int lo = low(num-1);
       // cout<<hi<<" "<<lo<<"\n";
        return abs(hi-num) >= abs(num-lo) ? to_string(lo) : to_string(hi);
    }
    long long int high( long long int n )
    {
        string h = to_string(n);
        string t = h; int l = h.length();
        for( int i = 0; i < l/2; i++ ) t[l-i-1] = h[i];
        for( int i = 0; i < l ; i++ )
        {
            if( h[i] < t[i] ) return stoll(t);
            else if( h[i] > t[i] )
            {
                for( int j = (l-1)/2; j >= 0; j-- )
                {
                    if( ++t[j] > '9' ) t[j] = '0';
                    else break;
                }
                for( int i = 0; i < l/2; i++ ) t[l-i-1] = t[i]; return stoll(t);
            }
        }
        return stoll(t);
    }
    long long int low( long long int n )
    {
        string h = to_string(n);
        string t = h; int l = h.length();
        for( int i = 0; i < l/2; i++ ) t[l-i-1] = h[i];
        for( int i = 0; i < l ; i++ )
        {
            if( h[i] > t[i] ) return stoll(t);
            else if( h[i] < t[i] )
            {
                for( int j = (l-1)/2; j >= 0; j-- )
                {
                    if( --t[j] < '0' )t[j] = '9';
                    else break;
                }
                if( t[0] == '0' )
                {
                    string y(l-1,'9'); return stoll(y);
                }
                for( int i = 0; i < l/2; i++ ) t[l-i-1] = t[i]; return stoll(t);
            }
        }
        return stoll(t);
    }
};
