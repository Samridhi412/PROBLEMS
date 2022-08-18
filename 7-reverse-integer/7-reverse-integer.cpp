
class Solution {
public:

    int reverse(int x) {
        int rev=0;
        while(x){
            int v=x%10;
            if(rev>INT_MAX/10||(rev==INT_MAX/10&&v>7)){
                return 0;
            }
            else if(rev<INT_MIN/10||(rev==INT_MIN/10&&v<-8)){
                return 0;
            }
            rev=rev*10+v;
            x/=10;
        }
        return rev;
    }
};