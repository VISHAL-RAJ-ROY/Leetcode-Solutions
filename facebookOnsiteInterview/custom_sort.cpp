#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

vector <int> c(26,-1);
bool cmp(char c1, char c2)
{
    return c[c1-'a']<c[c2-'a'];
}

string customSortString(string S, string T) { int l = S.length();
        for( int i = 0; i < l;i++ ) c[S[i]-'a'] = i;
        sort(T.begin(),T.end(),cmp);
        return T;                                         
    }

int main()
{
	string s = "cba"; string t = "abcd";t= customSortString(s,t); cout<<t<<"\n";
	return 0;
}
