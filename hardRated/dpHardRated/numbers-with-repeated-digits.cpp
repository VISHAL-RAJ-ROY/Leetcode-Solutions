class Solution {
public:
    int d; vector <int> r;
    void ch( int n ) {
        d = 0;
        while( n ) {
            r.push_back(n%10); n /= 10; d++;
        }
    }
    int A(int n,int m){
        return (!m)?1:A(n,m-1)*(n-(m-1));
    }
    int numDupDigitsAtMostN(int N) {
        ch(N+1); int ans =0;
        cout<<d<<"\n";
        for( int i = d-1; i >= 0; i-- ) cout<<r[i]<<" ";cout<<"\n";
        for( int i = 1; i < d; i++ ) {
            ans += 9*A(9,i-1);
        }
        cout<<ans<<"\n";
        vector <int> v(10,0);
        for( int i = d-1; i >= 0; i-- ) {
            for( int j = (i == d-1)?1:0; j < r[i]; j++ ) 
                if( !v[j] )
                    ans += A(9-(d-i-1),i);
            if( v[r[i]] ) break;
            v[r[i]] = 1;
        }
        return N-ans;
    }
};
