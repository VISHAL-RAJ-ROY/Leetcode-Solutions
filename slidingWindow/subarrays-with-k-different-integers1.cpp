static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        int res = 0;
        std::vector<short> help(A.size()+1,0);
        
        int first = 0;
        int last = 0;
        int count = 0;
        int end = A.size();
        while(last<end){
            int num = 0;
            
            while(count!=K && last<end) {
                if(!help[A[last]]) count++;
                help[A[last]]++;
                last++;
            }
            
            if(count==K) num++;
            int index = last;
            while(index<end){
                if(help[A[index++]]){
                    num++;
                }else{
                    break;
                }
            }
            
            //std::cout<<num<<std::endl;
            while(count==K){
                res += num;
                int val = A[first++];
                help[val]--;
                if(!help[val]) count--;
            }
        }
        return res;
    }
};
