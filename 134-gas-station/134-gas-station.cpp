class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int balance=0,deficit=0,start=0;
        for(int i=0;i<n;i++){
            balance+=gas[i]-cost[i];
            if(balance>=0){
                continue;
            }
            else{
                start=i+1;
                deficit+=balance;
                balance=0;
            }
        }
        if(deficit+balance>=0)return start;
        return -1;
    }
};