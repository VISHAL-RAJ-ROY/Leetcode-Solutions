class Solution {
public:
    #define lli long long int
        void print( vector <int> & vv ) {
            for( int e : vv ) cout<<e<<" ";cout<<"\n";
        }
        vector <pair<int,int>> v;
        //multiset<pair<int,int>> m;
        unordered_map<int,unordered_set<int>> m;
        /*bool ifp( pair<int,int> p ) {
            return binary_search(v.begin(), v.end(), p);
        }*//*
        bool ifp( pair<int,int> p ) {
            return (m.find(p) != m.end());
        }*/
        bool ifp( pair<int,int> p ) {
            return ( m.find(p.first) != m.end() && m[p.first].find(p.second) != m[p.first].end() );
        }
    vector<int> gridIllumination(int N, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        vector <unordered_map<int,int>> a(4,unordered_map<int,int>()); 
        int n= N; 
       // a[0].assign(n,0); a[1].assign(n,0); a[2].assign(2*n-1,0); a[3].assign(2*n-1,0);
        for( auto e : lamps ) {
            a[0][e[0]]++; 
            a[1][e[1]]++; 
            a[2][e[0]+e[1]]++; 
            a[3][e[0]-e[1]+n-1]++;
        } 
        //for( auto f : a ) print(f);
        for( auto e : lamps ) {
            //v.push_back({e[0],e[1]}); 
            m[e[0]].insert(e[1]);
        } //sort(v.begin(),v.end()); 
        vector <int> ans;
        vector <int> aa(9,0), b(9,0); aa[0] = b[2] = 1; aa[1] = b[3] = -1; 
        aa[4] = aa[5] = b[4] = b[6] = 1; aa[6] = aa[7] = b[5]= b[7] = -1; int k = 0; 
        print(aa); print(b);
        for( auto u : queries ) {
             vector <int> e(2,0); e[0] = u[0]; e[1] = u[1];
            cout<<u[0]<<" "<<u[1]<<" "<<a[0][e[0]]<<" "<<a[1][e[1]]<<" "<<a[2][e[0]+e[1]]<<" "<<a[3][e[0]-e[1]+n-1]<<"\n";
            if(a[0][e[0]] > 0 || a[1][e[1]] > 0 || a[2][e[0]+e[1]] > 0 
               || a[3][e[0]-e[1]+n-1] > 0) {
                ans.push_back(1);
                for( int i =0; i < 9; i++ ) {
                    int x = u[0]+aa[i]; int y = u[1]+b[i];
                    if( x >= 0 && y >= 0 && x < n && y < n ) {
                        if( m[x].erase(y) ) {
                            e[0] = x; e[1] = y;
                            if(a[0][e[0]]>0)a[0][e[0]]--; 
                            if(a[1][e[1]]>0)a[1][e[1]]--; 
                            if(a[2][e[0]+e[1]]>0)a[2][e[0]+e[1]]--; 
                            if(a[3][e[0]-e[1]+n-1]>0)a[3][e[0]-e[1]+n-1]--;
                        }
                    }
                }
            }
            else ans.push_back(0);
        }
        return ans;
    }
};
