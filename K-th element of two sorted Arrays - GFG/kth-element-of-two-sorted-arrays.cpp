// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        if(n>m)return kthElement(arr2,arr1,m,n,k);
        int low=max(0,k-m);
        int high=min(n,k);
        int ans;
        while(low<=high){
            int cnt1=(low+high)>>1;
            int cnt2=k-cnt1;
            int l1=cnt1==0?INT_MIN:arr1[cnt1-1];
            int l2=cnt2==0?INT_MIN:arr2[cnt2-1];
            int r1=cnt1==n?INT_MAX:arr1[cnt1];
            int r2=cnt2==m?INT_MAX:arr2[cnt2];
            if(l1<=r2&&l2<=r1){
                ans= max(l1,l2);
                break;
            }
            else if(l1>r2){
                high=cnt1-1;
            }
            else{
                low=cnt1+1;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}  // } Driver Code Ends