class Solution {
public:
    string fractionToDecimal(int num, int den) {
        if(num==0)return to_string(0);
        int sign=(num>0)^(den>0)?1:0;
        long long numerator=abs(num);
        long long denominator=abs(den);
        // cout<<numerator<<" "<<denominator<<endl;
        string res="";
        long long q=numerator/denominator;
        long long rem=numerator%denominator;
        // cout<<q<<" "<<rem<<endl;
        res+=to_string(q);
        if(rem==0){
            // cout<<sign<<endl;
            return sign==0?res:res.insert(0,"-");
        }
        res+=".";
        unordered_map<long long,long long> mp;
        while(rem){
            if(mp.find(rem)!=mp.end()){
                long long l=mp[rem];
                res.insert(l,"(");
                res.append(")");
                break;
            }
            else{
                mp[rem]=res.size();
                rem*=10;
                long long quotient=rem/denominator;
                rem=rem%denominator;
                res+=to_string(quotient);
            }
         }
        return sign==0?res:res.insert(0,"-");;
    }
};