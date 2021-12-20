#include<iostream>
using namespace std;
int partition(int arr[],int start,int end)
{
	int c=0;
	int k=arr[start];
	for(int i=start+1;i<end;i++)
	{
		if(arr[i]<k)
		{
			c++;
		}
	}
	int temp;
	temp=arr[start];
	arr[start]=arr[start+c];
	arr[start+c]=arr[start];
	int i=start;
	int j=end;
	if(arr[i]>k && arr[j]<k)
	{
		int temp1;
	temp1=arr[i];
	arr[i]=arr[j];
	arr[j]=arr[i];
	i++;
	j--;
	}
	else if(arr[i]<k)
	{
		i++;
	}
	else if(arr[j]>k)
	{
		j--;
	}
	return c;
}
void quicksort(int arr[],int s,int e)
{
	if(e==0 || e-s+1==1)
	{
		return;
	}
	int count=partition(arr,s,e);
	quicksort(arr,s,count-1);
	quicksort(arr,count+1,e);
}
int main()
{
	int num;
	cout<<"size of array?\n";
	cin>>num;
	int arr[num];
	cout<<"enter the array elements\n";
	for(int i=0;i<num;i++)
	{
		cin>>arr[i];
	}
	quicksort(arr,0,num-1);
	for(int i=0;i<num;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	return 0;
}
