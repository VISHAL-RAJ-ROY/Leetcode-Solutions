class UF {
	private :
		int N; vector <int> r, p;
	public :
		UF( int n ) {
			r.assign(n,0); p.assign(n,-1); for( int i = 0; i < n; i++ ) p[i] = i; N = n;
		}
		bool issame( int i, int j ) {
			return findset(i) == findset(j);
		}
		int findset( int i ) {
			return (p[i] == i) ? i : (p[i] = findset(p[i]));
		}
		void join( int i, int j ) {
			int x = findset(i), y = findset(j);
			if( r[x] < r[y] ) {
				p[x] = y;
			} else {
				p[y] = x; if( r[x] == r[y] ) r[x]++;
			}
		}
};
class Solution {
public:
    int n;
    vector <int> ret( int a, int b ) {
        vector<int> ans;
        if( a == -1 ) return ans;
        else {
            ans.push_back(a); ans.push_back(b); return ans;
        }
    }
    vector <int> p;
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        n = edges.size(); 
        p.assign(n+1,-1); UF u(n);
        int v = -1, vv = -1;
        vector <int> g(2,0);
        int gg;
        for( auto e : edges ) {
            int a = e[0]; int b = e[1];
            if( p[b] != -1 ) {
                v = b; g[0] = p[b]; g[1] = a;
                //cout<<v<<" "<<g[0]<<" "<<g[1];
            } else {
                if( u.findset(a-1) == b-1 ) {
                    vv = b; gg = a; p[b] = a;
                } else {
                    p[b] = a; u.join(a-1,b-1);
                }
            }
        }
        if( v == -1 ) return ret(gg,vv);
        else {
            int q = g[0];
            while( q != -1 && q != v ) {
                q = p[q];
            }
            return ret( ((q==-1)?g[1]:g[0]),v );
        }
    }
};
