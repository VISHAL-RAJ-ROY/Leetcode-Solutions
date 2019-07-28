class Solution {
public:
    vector <vector <int>> alist; vector <int>d; vector<vector <string>> ans; vector <int> visited; int s,e=-1;
    vector <string> pu;
    int diff(string & a, string & b)
    {
        int ct = 0; 
        int len = a.length();
        for( int i = 0; i < len; i++ ) if(a[i]!=b[i]) ct++;
        return ct;
    }
    void dfs( int u,  vector<string>& w )
    {
        visited[u] = 1; int sz = alist[u].size();
        for( int i = 0; i < sz;i++ )
        {
            int v = alist[u][i];//if(u==s){pu.clear();pu.push_back(w[s]);}
            if(!visited[v])
            {
                if( d[v] == d[e] )
                {
                    if( v == e )
                    {
                        pu[d[e]] = w[e];
                        ans.push_back(pu);
                    }
                }
                else if( d[v] == d[u]+1 )
                {
                    pu[d[v]]=w[v];
                    dfs(v,w);
                }
            }
        }
        visited[u] = 0;
    }
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        wordList.push_back(beginWord);
        int sz = wordList.size(); bool f1,f2; f1 = false; f2 = false;
        alist.assign(sz,vector <int>());
        for( int i = 0; i < sz; i++ )
        {
            if(!f2)if(wordList[i] == endWord) {e= i;f2=true;}
            for( int j = i+1; j < sz; j++ )
            {
                if( diff(wordList[i],wordList[j]) == 1 ) {alist[i].push_back(j);alist[j].push_back(i);}
            }
        }
        if(e == -1) return ans;
        queue <int> q;
        s = sz-1;
        q.push(s); d.assign(sz,-1); d[s] = 0;
        while( !q.empty() )
        {
            int top = q.front(); q.pop();
            if(top==e)break;
            int ssz = alist[top].size();
            for( int i = 0; i < ssz; i++ )
            {
                int u = alist[top][i]; 
                if(d[u]==-1)
                {
                    d[u] = d[top]+1;
                    q.push(u);
                }
            }
        }
        if(d[e] == -1) return ans;
        visited.assign(sz,0);pu.assign(d[e]+1,"");
        pu[0]=wordList[s];
        dfs(s,wordList);
        return ans;
    }
};
