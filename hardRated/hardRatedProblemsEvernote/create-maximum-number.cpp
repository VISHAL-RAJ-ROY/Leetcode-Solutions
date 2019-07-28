#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;	

void print( vector <int> & v )
    {
        for( int i =0; i < v.size(); i++ ) cout<<v[i]<<" ";
        cout<<"\n";
    }

	void maxarr( vector <int> & n, int len, vector <int> & ans )
    {
        ans.assign(len,0);	
        int i = 0, j = 0;
        int sz = n.size();
        for( int i = 0; i < sz; i++ )
        {
            while( sz-i+j > len && j > 0 && ans[j-1] < n[i] ) j--;
            if( j < len ) ans[j++] = n[i];
        }
    }
    
    void ismore( vector <int> & c, vector <int> & ans )
    {
        int i = 0; int len = c.size();
        while( i < len )
        {
            if( ans[i] > c[i] ) return;
            else if( ans[i] == c[i] ) i++;
            else
            {
                while( i < len ) { ans[i] = c[i]; i++; }
                return;
            }
        }
    }
    
    void merge( vector <int> & c, vector<int>& nums1, int i, vector<int>& nums2, int j )
    {
        vector <int> a1, a2; maxarr(nums1,i,a1); maxarr(nums2,j,a2);
        cout<<i<<" "<<j<<"\n";
        cout<<"a1 : ";print(a1);cout<<"a2 : ";print(a2);
        int k = c.size();
        int d = 0, f = 0, l = 0;
        for( ; l < k; l++ )
        {
            if( d < i && f < j )
            {
                if( a1[d] > a2[f] ) c[l] = a1[d++];
                else if( a1[d] < a2[f] ) c[l] = a2[f++];
                else 
                {
                	int r,r1 = d, r2 = f;
                    while( d < i && f < j && a1[d] == a2[f] && l < k ) 
                    {
                        c[l++] = a1[d++]; f++;  
                    }
                    if( l == k ) return;
                    else if( d == i )
                    {
                        d = r1;
                        if( f < j ) c[l] = a2[f++]; else l--;
                    }
                    else if( f == j )
                    {
                        f = r2; if( d < i ) c[l] = a1[d++]; else l--;
                    }
                    else 
                    {
                        if( a1[d] > a2[f] ) 
                        {
                            c[l] = a1[d++]; f = r2;
                        }
                        else { c[l] = a2[f++]; d = r1; }
                    }
                }
            }
            else if( d == i )
            {
                c[l] = a2[f++];
            }
            else if( f == j )
            {
                c[l] = a1[d++];
            }
        }
        print(c);
    }
    
    
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int sz1 = nums1.size();
        int sz2 = nums2.size();
        vector <int> c(k,0);
        vector <int> ans(k,0);
        for( int i = max(0,k-sz2); i <= k && i <= sz1; i++ )
        {
            merge(c,nums1,i,nums2,k-i);
            ismore(c,ans);
            print(ans);
        }
        return ans;
    }
    
int main()
{
	vector <int> v1{1,6,5,4,7,3,9,5,3,7,8,4,1,1,4};
	vector <int> v2{4,3,1,3,5,9};
	int k = 21;
	vector <int> ans = maxNumber(v1,v2,k);
	print(ans);
	return 0;
}
