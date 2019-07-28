class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int len = A.size();
        if( len == 1 ) 
        {
            if(A[0] == 0) { if(K == 1) return 1; else return 0; }
            else return 1;
        }
        int start,end,maxCount,maxLen;
        start = end = maxCount = maxLen = 0;
        int count[2] = {0};
        int in = -1;
        for( end = 0; end < len; end++ )
        {
          /*  if( ++count[A[end]] > maxCount )
            {
                maxCount = count[A[end]];
                in = A[end];
            }*/
            maxCount = max(maxCount,++count[A[end]]);
            while( end-start+1-maxCount>K )
            {
                count[A[start]]--;
                start++;
            }
            maxLen = max(maxLen,end-start+1);
        }
        return maxLen;
    }
};
