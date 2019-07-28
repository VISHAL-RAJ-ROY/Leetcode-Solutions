typedef vector <int> vi;
typedef vector <vi> vvi;

class UF
{
  private: vi rank, p;
    public :
        UF( int n ) { rank.assign(n,0); p.assign(n,0); for( int i = 0; i < n; i++ ) p[i] = i; }
        bool issame(int i,int j) { return find(i) == find(j); }
        int find( int i ) { return ( p[i] == i ) ? i : p[i] = find(p[i]) ; }
        void join( int i, int j ) {
            if( issame(i,j) ) return;
            int x = find(i); int y = find(j);
            if( rank[x] > rank[y] ) p[y] = x;
            else {
                p[x] = y; if( rank[x] == rank[y] ) rank[y]++;
            }
        }
};
 
class Solution {
public:
    unordered_map<int, vector <int>> m;
    void factor( vi & A, vvi & factored )
    {
        for( int i = 0; i < A.size() ; i++ )
        {
            int d = 2; int x = A[i];
            while( d*d <= x )
            {
                if( x%d == 0 )
                {
                    while( !(x%d) )
                    {
                        x /= d;
                    }
                    factored[i].push_back(d);
                }
                d++;
            }
            if( factored[i].empty() || x > 1 )
            {
                factored[i].push_back(x);
            }
        }
    }
    
    void unique( vvi & factored, unordered_set<int> & uniqprime )
    {
        for( vi & v : factored )
        {
            for( int & e : v )
            {
                uniqprime.insert(e);
            }
        }
    }
    
    void toutil( unordered_set<int> & uniqprime, vi & primes, unordered_map<int,int> & primetoindex )
    {
        primes.assign((int)uniqprime.size(),0);
        int t = 0;
        for( int y : uniqprime )
        {
            primes[t++] = y;
            primetoindex.insert({y,t-1});
        }
    }
    
    void connect( vvi & factored, unordered_map<int,int> & primetoindex, UF & u )
    {
        for( vi & v : factored )
        {
            for( int & e : v )
            {
                u.join(primetoindex[v[0]],primetoindex[e]);
            }
        }
    }
    
    int calc( vvi & factored, UF & u, int s, unordered_map<int,int> & primetoindex )
    {
        vi count(s,0);
        for( vi & v : factored )
        {
            count[u.find(primetoindex[v[0]])]++;
        }
        int ans = 0;
        for( int & e : count )
        {
            if( e > ans )
            {
                ans = e;
            }
        }
        return ans;
    }
    
    int largestComponentSize(vector<int>& A) {
        vvi factored(A.size(),vi());
        unordered_set<int>uniqprime;
        vi primes;
        unordered_map<int,int> primetoindex;
        factor(A,factored);
        unique(factored,uniqprime);
        toutil(uniqprime,primes,primetoindex);
        UF u((int)primes.size());
        connect(factored,primetoindex,u);
        return calc(factored,u,primes.size(),primetoindex);
    }
};
