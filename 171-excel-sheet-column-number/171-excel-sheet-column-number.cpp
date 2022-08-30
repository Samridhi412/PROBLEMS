class Solution {
public:
    int titleToNumber(string columnTitle) {
        long long finalans=0;
        int n=columnTitle.size();
        for(int i=0;i<n;i++){
            int d=columnTitle[i]-'A'+1;
            finalans=finalans*26+d;
        }
        return finalans;
    }
};