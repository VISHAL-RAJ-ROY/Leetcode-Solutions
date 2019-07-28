class Solution {
public:
    unordered_map<int,int>count;
    int countTriplets(vector<int>& A) {
        for( int & i : A )
        {
            for( int & j : A )
            {
                count[(i&j)]++;
            }
        }
        int ct = 0;
        for( auto h : count )
        {
            for( int & i : A )
            {
                if( (i&h.first) == 0 )  ct += h.second;
            }
        }
        return ct;
    }
};
