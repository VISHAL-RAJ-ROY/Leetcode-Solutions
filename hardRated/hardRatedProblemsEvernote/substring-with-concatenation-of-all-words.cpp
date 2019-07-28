class Solution {
public:
    vector <int> g;//, done;
    vector <pair<string,int>> w; 
    vector <int> kmpProcess( string & p )
{
	int len = p.length();
	vector <int> b(len+1,0);
	int i = 0, j = -1; b[0] = -1;
	while( i < len )
	{
		while( j >= 0 && p[i] != p[j] ) j = b[j];
		i++;j++;
		b[i] = j; 
	}
	return b;
}

void kmp( string & t, int index)
{
    string p = words[index].first;
    //int num = words[index].second;
	vector <int> b = kmpProcess(p);
	int i = 0, j = 0;
	int m = p.length();
	int len = t.length();
	while( i < len )
	{
		while( j >= 0 && t[i] != p[j] ) j = b[j];
		i++;j++;
		if( j == m ) 
		{
			g[i-m] = index;
			j = b[j];
		}
	}
	
}
    
    vector <int> loot( int len, int m )
    {
        vector <int> ans;
        if( m > len ) return ans;
        for( int i = 0; i <= len%m; i++ )
        {
            
        }
    }
    
    vector<int> findSubstring(string s, vector<string>& words) {
        sort(words.begin(),words.end());
        int i = 0, j = 1, k = 0;
        while( true )
        {
            while( j < words.size() )
            {
                if( words[i] == words[j] ) j++;
                else break;
            }
            w.push_back(make_pair(words[i],j-i));
            if( j == words.size() ) break; 
            else 
            {
                i = j;
                j++;
            }
        }
        g.assign(s.length(),-1);
        for( i = 0; i < w.size(); i++ ) kmp(s,i);
        //done.assign(w.size(),0);
        return loot(s.length(),w[0].length());
    }
};
