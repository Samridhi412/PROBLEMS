#include<bits/stdc++.h>
using namespace std;
string get_permutation(int n,int k){
	vector<int> nums;
	int fact=1;
	for(int i=1;i<n;i++){
		fact*=i;
		nums.push_back(i);
	}
	nums.push_back(n);
	k=k-1;
	string ans="";
	while(1){
		if(nums.size()==0){
			break;
		}
		ans+=to_string(nums[k/fact]);
		nums.erase(nums.begin()+k/fact);
		k=k%fact;
		fact=fact/nums.size();
	}
	return ans;
}
int main(){
	int n,k;
	cin>>n>>k;
	cout<<get_permutation(n,k);
}
