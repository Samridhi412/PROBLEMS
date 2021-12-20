#include<iostream>
using namespace std;
int subsequence(string input,string output[])
{
	//int const temp=size;
	if(input.empty())
	{
		output[0]="";
		return 1;
	}
	int count=subsequence(input.substr(1),output);
	for(int i=0;i<count;i++)
	{
		output[i+count]=input[0]+output[i];
		//out[count+i][1]=out[i][0];
	}
	

	return 2*count;
}
int main()
{
	string s1;
	cin>>s1;
	string* output=new string[100];
	int c=subsequence(s1,output);
	for(int i=0;i<c;i++)
	{
		cout<<output[i];
	}
		return 0;
}

