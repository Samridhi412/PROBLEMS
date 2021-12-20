#include<bits/stdc++.h>
using namespace std;
void permutate(vector<int> arr,int n,int start,vector<vector<int>>& ans){
	if(start>=n){
		ans.push_back(arr);
		return ;
	}
	for(int i=start;i<n;i++){
		swap(arr[start],arr[i]);
		permutate(arr,n,start+1,ans);
		swap(arr[start],arr[i]);
	}
}
int main(){
	int n;
	cin>>n;
	vector arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	vector<vector<int>> ans;
	permutate(arr,n,0,ans);
	return 0;
}
