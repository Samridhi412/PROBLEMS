class Solution {
    bool prime[5000005];
    int seive(int n){
        int cnt=0;
        for(int i=2;i*i<=n;i++){
            if(prime[i]){
                // cnt++;
                for(int j=i*i;j<=n;j+=i){
                    prime[j]=false;
                }
            }
        }
        for(int i=2;i<n;i++){
            if(prime[i]){
                cnt++;
            }
        }
        return cnt;
    }
public:
    int countPrimes(int n) {
        memset(prime,true,sizeof(prime));
        return seive(n);
    }
};