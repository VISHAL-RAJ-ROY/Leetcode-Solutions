class Solution {
public:
    void countSort(int k, vector<int> &sa, vector<int> &ra, int len)
{
	vector<int> c(max(300, len + 1), 0);
	for (int i = 0; i < len; i++)
		c[i + k < len ? ra[i + k] : 0]++;
	int sum = 0;
	for (int i = 0; i < max(300, len); i++)
	{
		int t = c[i];
		c[i] = sum;
		sum += t;
	}
	vector<int> tsa(len, 0);
	for (int i = 0; i < len; i++)
		tsa[c[sa[i] + k < len ? ra[sa[i] + k] : 0]++] = sa[i];
	for (int i = 0; i < len; i++)
		sa[i] = tsa[i];
}

vector<int> buildSA(string &s)
{
	s = s + "$";
	int len = s.length();
	vector<int> ra(len, 0);
	vector<int> sa(len, 0);
	for (int i = 0; i < len; i++)
	{
		ra[i] = s[i];
		sa[i] = i;
	}
	for (int k = 1; k < len; k <<= 1)
	{
		countSort(k, sa, ra, len);
		countSort(0, sa, ra, len);
		int r = 0;
		vector<int> tra(len, 0);
		tra[sa[0]] = r = 0;
		for (int j = 1; j < len; j++)
		{
			if (ra[sa[j]] == ra[sa[j - 1]] && ra[sa[j] + k] == ra[sa[j - 1] + k])
				tra[sa[j]] = r;
			else
				tra[sa[j]] = ++r;
		}
		for (int j = 0; j < len; j++)
			ra[j] = tra[j];
		if (ra[sa[len - 1]] == len - 1)
			break;
	}
	return sa;
}
    
    vector <int> lcp_kasai( vector <int> sa, string & s )
{
	int len = sa.size();
	vector <int> rank(len,0);
	vector <int> lcp(len,0);
	for( int i = 0; i < len; i++ ) rank[sa[i]] = i;
	int k = 0;
	for( int i = 0; i < len; i++, k ? k-- : 0 )
	{
		if( rank[i] == len-1 ) 
		{
			k = 0; continue;
		}
		int j = sa[rank[i]+1];
		while( i+k < len && j+k < len && s[i+k] == s[j+k] ) k++;
		lcp[rank[i]] = k;
	}
	return lcp;
}
    string longestDupSubstring(string S) {
        vector <int> sa = buildSA(S);
        vector <int> lcp = lcp_kasai(sa,S);
        int ma = 0;
        int ii = -1;
        for( int i = 0; i < lcp.size(); i++ ) 
        {
            if( lcp[i] > ma )
            {
                ma = lcp[i];
                ii = i;
            }
        }
        //for( int i = 0; i < lcp.size(); i++ ) cout<<lcp[i]<<" "<<sa[i]<<" "<<S.substr(sa[i])<<"\n";
        S = S.substr(0,S.length()-1);
        if( ii == -1 ) return "";
        else return S.substr(sa[ii],ma);
    }
};
