class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans=0;
        int i=31;
        while(i>=0){
            // int rem=(1<<(31-i))&n;
            
            int rem=(n>>(31-i))&1;
            // cout<<rem<<endl;
            if(rem==1){
                ans+=pow(2,i);
            }
            i--;
        }
        return ans;
    }
};