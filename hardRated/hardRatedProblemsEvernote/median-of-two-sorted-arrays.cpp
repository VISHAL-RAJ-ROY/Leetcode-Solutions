class Solution {
public:
    double solve( int n, int m, vector<int>& nums1, vector<int>& nums2 )
    {
        int s,e,mid,my,su=(n+m+1)/2;
        s = 0; e = m; 
        int ma1,mi1,ma2,mi2;
        while( s <= e )
        {
            mid = (e+s)/2;
            my = su-mid;
            ma2 = (mid > 0) ? nums2[mid-1] : INT_MIN;
            ma1 = (my > 0) ? nums1[my-1] : INT_MIN;
            mi2 = (mid < m) ? nums2[mid] : INT_MAX;
            mi1 = (my < n) ? nums1[my] : INT_MAX;
            if( mi2 >= ma1 && mi1 >= ma2 )
            {
                if( (n+m)%2 == 1 ) return (max(ma1,ma2))*1.0;
                else return (max(ma1,ma2)+min(mi1,mi2))*1.0/2.0;
            }
            else if( mi1 < ma2 )
            {
                e = mid-1;
            }
            else s = mid+1;
        }
        if( (n+m)%2 == 1 ) return (max(ma1,ma2))*1.0;
        else return (max(ma1,ma2)+min(mi1,mi2))*1.0/2.0;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        if( n >= m ) return solve(n,m,nums1,nums2);
        else return solve(m,n,nums2,nums1);
    }
};
