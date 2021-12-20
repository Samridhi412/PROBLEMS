#include<iostream>
using namespace std;
int main()
{
	int m,n;
	cout<<"enter the numbers of rows and columns\n";
	cin>>m>>n;
	int arr[m][n];
	int arr1[m];
	int arr2[n];
	cout<<"enter the elements\n";
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>arr[i][j];
		}
}
	
	for(int i=0;i<m;i++)
	{
		int min=arr[i][0];
		for(int j=0;j<n;j++)
		{
			if(arr[i][j]<min)
			{
				min=arr[i][j];
				
			 } 
		}
		arr1[i]=min;
	}
	for(int l=0;l<n;l++)
	{
		int max=arr[0][l];
		for(int k=0;k<m;k++)
		{
			if(arr[k][l]>max)
			{
				max=arr[k][l];
			 } 
		}
		arr2[l]=max;
	}
	for(int i=0;i<m;i++)
	{
		cout<<arr1[i]<<" ";
	}
	for(int i=0;i<n;i++)
	{
		cout<<arr2[i]<<" ";
	}
for(int i=0;i<m;i++)
{
	for(int j=0;j<n;j++)
	{
		if(arr1[i]==arr2[j])
		{
			cout<<"saddle point is"<<arr1[i]<<endl;
		}
	}
}

		return 0;
	
}
