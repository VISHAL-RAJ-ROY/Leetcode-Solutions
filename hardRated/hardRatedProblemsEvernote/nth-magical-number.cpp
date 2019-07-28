

class Solution {
    #define lli long long int
public:
    int nthMagicalNumber(int N, int A, int B) {
        lli lo = 0;
        lli hi = 1e15;
        lli mi;
        lli lcm = (A/__gcd(A,B))*B;
        while( lo < hi )
        {
            mi = lo+(hi-lo)/2;
            if( mi/A+mi/B-mi/lcm < N ) lo = mi+1;
            else hi = mi; 
        }
        return (int)(lo%(lli)(1e9+7));
    }
};
