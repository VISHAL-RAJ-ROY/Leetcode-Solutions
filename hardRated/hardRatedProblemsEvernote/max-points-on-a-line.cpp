class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int sz = points.size();
        if(sz == 1) return 1; else if( sz == 0 ) return 0;
        map<pair<int,int>,int>s; int gm = 1; int m,o; 
        for(int i = 0; i < sz; i++ )
        {
            int v; o = v = 0; m = 0;
            for( int j = i+1; j < sz; j++ )
            {
                if( points[i] == points[j] ) o++;
                else if( points[i][0] == points[j][0] ) v++;
                else
                {
                    int x = points[i][0] - points[j][0]; int y = points[i][1] - points[j][1]; 
                    int g = __gcd(x,y); x /= g; y /= g;
                    ++s[make_pair(x,y)]; m = max(m,s[make_pair(x,y)]);
                }
            }
            s.clear();
            m = max(m,v);//cout<<m<<" "<<o<<"\n";
            gm = max(gm,m+o+1);
        }
        return gm;
    }
};
