#include<bits/stdc++.h>
using namespace std;
// space =O{N+N}
void permutate(int* arr,int n,	vector<int> temp,vector<vector<int>>& ans,	map<int,int>& mp){
	if(temp.size()==n){
		ans.push_back(temp);
		return;
	}
	for(int i=0;i<n;i++){
		if(mp[arr[i]]){
			continue;
		}
		temp.push_back(arr[i]);
		mp[arr[i]]=1;
		permutate(arr,n,temp,ans,mp);
		mp[arr[i]]=0;
		temp.pop_back();
	}
}
int fact(int n){
	if(n==0 || n==1){
		return n;
	}
	return n*fact(n-1);
}
int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	vector<vector<int>> ans;
	vector<int> temp;
	map<int,int> mp;
	permutate(arr,n,temp,ans,mp);
    cout<<ans.size();
	for(auto i:ans){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
	return 0;
}
