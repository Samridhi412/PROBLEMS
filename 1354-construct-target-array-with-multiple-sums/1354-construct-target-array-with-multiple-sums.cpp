class Solution {
public:
    bool isPossible(vector<int>& target) {
        int n=target.size();
       priority_queue<int> pq;
        long long sum=0;
        for(auto x:target){
            pq.push(x);
            sum+=x;
        }
        while(!pq.empty()){
            int maxi=pq.top();
            pq.pop();
            long long remaining_tot=sum-maxi;
            if(maxi==1||remaining_tot==1)return true;
            if(remaining_tot==0||maxi<remaining_tot)return false;
            int updated_maxi=(int)maxi%remaining_tot;
            if(updated_maxi==0){
                return false;
            }
            maxi=updated_maxi;
            sum=updated_maxi+remaining_tot;
            pq.push(maxi);
        }
        return true;
    }
};