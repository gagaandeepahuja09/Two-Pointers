class Solution {
public:
    bool judgeSquareSum(int c) {
        long l = 0, h = (long)sqrt(c), lc = (long)c;
        while(l <= h) {
            long sq = l * l + h * h;
            if(sq == lc)
                return true;
            else if(sq < lc)
                l++;
            else
                h--;
        }
        return false;
    }
};
