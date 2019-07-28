class Solution {
public:
    int brokenCalc(int X, int Y) {
        int x = X; int y = Y;
        int count = 0;
        while( x != y )
        {
            if( x >= y ) return (x-y+count);
            if( y%2 == 0 ) y /= 2;
            else y += 1; 
            count++;
        }
        return count;
    }
};
