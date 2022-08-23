class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        if(digits[n-1]<9){
            digits[n-1]+=1;
        }
        else{
            int j=n-1;
            while(j>=0&&digits[j]==9){
                digits[j]=0;
                j--;
            }
            if(j<0){
                digits.push_back(1);
                sort(digits.begin(),digits.end(),greater<int>());
            }
            else{
                digits[j]+=1;
            }
        }
        return digits;
    }
};