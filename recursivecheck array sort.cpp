#include<bits/stdc++.h>
using namespace std;
bool recursive_check(int* arr,int n){
	if(n==0 || n==1){
		return true;
	}
	return recursive_check(arr+1,n-1)&&arr[0]<=arr[1];
}
int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<recursive_check(arr,n);
	return 0;
}
