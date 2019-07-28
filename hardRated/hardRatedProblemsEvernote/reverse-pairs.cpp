class Solution {
public:
    int ms(vector <int>&n,int s, int e)
    {
        if(s >= e) return 0;
        int mid = s+(e-s)/2;
        int cnt = ms(n,s,mid)+ms(n,mid+1,e);
        for( int i = s, j = mid+1; i <= mid; i++ )
        {
            while(j<=e&&n[i]/2.0>n[j]) j++;
            cnt += j-(mid+1);
        }
        sort(n.begin()+s,n.begin()+e+1);
        return cnt;
    }
    int reversePairs(vector<int>& nums) {
        return ms(nums,0,nums.size()-1);
    }
};

