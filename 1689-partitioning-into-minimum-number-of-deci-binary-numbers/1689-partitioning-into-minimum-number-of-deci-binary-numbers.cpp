class Solution {
public:
    int minPartitions(string s) {
        int max=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]-'0'>max){
                max=s[i]-'0';
            }
        }
        return max;
    }
};