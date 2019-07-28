class Solution {
public:
    unordered_map<int,int> m;
    int shortestSubarray(vector<int>& A, int K) {
        int sz = A.size(); int ma = INT_MAX;
        for( int i = 0; i < sz; i++ )
        {
            for( auto & p : m )
            {
                int sum = p.first+A[i]; 
                if(m.find(sum)==m.end())m[sum]=p.second+1;
                else m[sum] = min(m[sum],p.second+1);
                if( sum >= K ) ma = min(ma,m[sum]);
            }
            m[A[i]]=1;
            if(A[i]>=K) {ma = 1;break;}
        }
        if(ma==INT_MAX)return -1;
        else return ma;  
    }
};
