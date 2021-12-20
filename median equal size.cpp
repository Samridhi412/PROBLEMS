#include<bits/stdc++.h>
using namespace std;
double median(int* v,int size){
	if(size%2){
		return (double)v[size/2];
	}
	return (double)(v[size/2]+v[size/2-1])/2;
}
double median_sorted_arrays(int* v1,int* v2,int n){
	if(n==0){
		return 0;
	}
	else if(n==1){
		int val=v1[0]+v2[0];
		return (val)/2.0;
	}
	else if(n==2){
		int qnt=max(v1[0],v2[0])+min(v1[1],v2[1]);
		return (qnt)/2.0;
	}
	double med1=median(v1,n);
	double med2=median(v2,n);
	if(med1==med2){
		return med1;
	}
	else if(med1>med2){
		if(n%2)
		{
		return median_sorted_arrays(v1,v2+n/2,n-n/2);
	}
		return median_sorted_arrays(v1,v2+n/2-1,n-n/2+1);
	}
	if(n%2){
		return median_sorted_arrays(v1+n/2,v2,n-n/2);
	}
	return median_sorted_arrays(v1+n/2-1,v2,n-n/2+1);
}
int main(){
	int m;
	cin>>m;
	int v1[m],v2[m];
	for(int i=0;i<m;i++){
		cin>>v1[i];
	}
	for(int j=0;j<m;j++){
		cin>>v2[j];
	}
	double med=median_sorted_arrays(v1,v2,m);
	cout<<med;
	return 0;
	return 0;
}
