#include<iostream>
using namespace std;
bool checkab(char s[],int start)
{
	if(s[start]=='\0')
	{
		return true;
	}
	bool ans=checkab(s,start+1);
	if(s[start]=='a')
	{
		if(s[start+1]=='a')
		return true;
		else if(s[start+1]=='b' && s[start+2]=='b')
		return true;
		else if(s[start+1]=='\0')
		return true;
		else
		return false;
	}
	else if(s[start]=='b') 
	{
		if(s[start+1]=='b' && s[start+2]=='a')
		return true;
		else if(s[start+1]=='b' && s[start+2]=='\0')
		return true;
		else
		return false;
	}
	else
	{
		return false;
	}
	if(!ans)
	{
		return false;
	}
	else
	{
		if(s[0]=='a')
		{
			return true;
		}
		else
		return false;
	}
}
int main()
{
	char str[100];
	for(int i=0;str[i]!='\0';i++)
	{
	cin>>str[i];
}
bool output=checkab(str,0);
if(!output)
{
	cout<<"false\n";
}
else
{
	cout<<"true\n";
}
return 0;
}
