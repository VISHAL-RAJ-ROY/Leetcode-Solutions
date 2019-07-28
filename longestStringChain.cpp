#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector <vector <int>> alist;
    vector <int> visited;
    vector <int> topso;
    
    bool isadj( string & a, string & b, int len )
    {
        int i = 0; int j = 0;
        while( i < len )
        {
            if( a[i] == b[j] ) 
            {
                i++; j++;
            }
            else break;
        }
        j++;
        if( i == len ) return true;
        while( i < len )
        {
            if( a[i] == b[j] ) 
            {
                i++; j++;
            }
            else 
            {
                return false;
            }
        }
        return true;
    }
    
    void dfs( int k )
    {
        visited[k] = 1;
        for( int i = 0;i < alist[k].size(); i++ )
        {
            int u = alist[k][i];
            if( !visited[u] ) dfs(u);
        }
        topso.push_back(k);
    }

    int longestStrChain(vector<string>& words)    
    {
        int len = words.size();
        alist.assign(len,vector <int>());
        sort(words.begin(), words.end());
        vector <int> lens(len);
        for( int i = 0; i < len; i++ ) lens[i] = words[i].length(); 
        for( int i = 0; i< len; i++ )
        {
            for( int j = i+1; j < len; j++ )
            {
                int l1 = lens[i]; int l2 = lens[j];
                if( l1 == l2-1 )
                {
                    if( isadj(words[i],words[j],l1) ) { alist[i].push_back(j); }
                }
                else if( l2 == l1-1 )
                {
                    if( isadj(words[j],words[i],l2) ) { alist[j].push_back(i); }
                }
            }
        } 
        visited.assign(len,0);
        for( int i = 0; i < len; i++ )
        {
            if( !visited[i] ) dfs(i);
        }
        int maxx = INT_MIN;
        for( int i = 0; i < len; i++ )
        {
            vector <int> d(len,INT_MIN);
            d[i] = 0;
            for( int h = len-1; h >= 0; h-- )
            {
                int j = topso[h];
                if( d[j] != INT_MIN )
                {
                    for( int k = 0; k < alist[j].size(); k++ )
                    {
                        int u = alist[j][k];
                        if(  d[u] < d[j]+1 ) { d[u] = d[j]+1; maxx = max(maxx,d[u]); } 
                    }
                }
            }
        }
   /*     for( int i = 0; i < len; i++ )
        {
            cout<<"node = "<<words[i]<<"\n";
            for( int j = 0; j < alist[i].size(); j++ )
            {
                cout<<" "<<words[alist[i][j]];
            }
            cout<<"\n";
        }*/
        if( maxx == INT_MIN ) maxx = 1;
        else maxx++;
        return maxx;
    }
};

int main()
{
    for( int i = 0; i  )
    return 0;
}

