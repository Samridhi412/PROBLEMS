class Solution {
public:
    int divide(int divi, int dsor) {
        long long dividend=divi;
        long long divisor=dsor;
        // if(divisor==1){
        //     if(dividend>=INT_MAX)return INT_MAX;
        //     else if(dividend<=INT_MIN)return INT_MIN;
        //     return dividend;
        // }
        // else if(divisor==-1){
        //     if(dividend>=INT_MAX)return INT_MIN;
        //     else if(dividend<=INT_MIN)return INT_MAX;
        //     return -dividend;
        // }
        int sign=(dividend<0)^(divisor<0)?-1:1;
        dividend=abs(dividend);
        divisor=abs(divisor);
        long long temp=0,quotient=0;
        for(int i=31;i>=0;i--){
            if (temp + ((long long)divisor << i) <= dividend) {
              temp += divisor << i;
              quotient |= 1LL << i;
            }
        }
        if(sign==-1)quotient*=-1;
        if(quotient>=INT_MAX){
            return INT_MAX;
        }
        else if(quotient<=INT_MIN){
            return INT_MIN;
        }
        return quotient;
    }
};