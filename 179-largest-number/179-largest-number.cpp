class Solution {
    static bool cmp(int n1,int n2){
        string s1=to_string(n1);
        string s2=to_string(n2);
        return s1+s2>s2+s1;
    }
public:
    string largestNumber(vector<int>& nums) {
        int n=nums.size();
        string res;
        sort(nums.begin(),nums.end(),cmp);
        for(auto x:nums){
            res+=to_string(x);
        }
        return res[0]=='0'?"0":res;
    }
};