class Solution {
public:
    string longestPalindrome(string s) {
        int l,r,c;
        int n=s.size();
        n=2*n+1;
        int imirror,maxlen=1,maxcenter=0;
        int lps[n];
        lps[0]=0;
        lps[1]=1;
        int diff=-1;
        l=0,c=1,r=2;
        int expand=0;
        for(int i=2;i<n;i++){
            imirror=2*c-i;
            diff=r-i;
            expand=0;
            if(diff>=0){
            if(lps[imirror]<diff){
                lps[i]=lps[imirror];
            }
            else if(lps[imirror]==diff&&r==n-1){
                lps[i]=lps[imirror];
            }
            else if(lps[imirror]==diff&&r<n-1){
                lps[i]=lps[imirror];
                expand=1;
            }
            else{
                lps[i]=diff;
                expand=1;
            }
            }
            else{
                lps[i]=0;
                expand=1;
            }
            if(expand){
                while(((i-lps[i])>0&&(i+lps[i])<n)&&(((lps[i]+i+1)%2==0)||(s[(lps[i]+i+1)/2]==s[(i-lps[i]-1)/2]))){
                    lps[i]++;
                }
            }
            if(lps[i]>maxlen){
                maxlen=lps[i];
                maxcenter=i;
            }
            if(i+lps[i]>r){
			c=i;
			r=i+lps[i];
		}
        }
        int start=(maxcenter-maxlen)/2;
	int end=start+maxlen-1;
        string res;
	for(int i=start;i<=end;i++){
		res.push_back(s[i]);
	}
	// cout<<endl;
        return res;
    }
};