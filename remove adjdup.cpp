#include<bits/stdc++.h>
using namespace std;
char* remove_dup(char* ch,char& last_removed){
	if(ch[0]=='\0'||ch[1]=='\0'){
		return ch;
	}
	if(ch[0]==ch[1]){
		while(ch[1]&&ch[0]==ch[1]){
			last_removed=ch[0];
			ch++;
		}
		ch++;
		return remove_dup(ch,last_removed);
	}
		char* rem_str=remove_dup(ch+1,last_removed);
		if(rem_str[0]&&rem_str[0]==ch[0]){
			last_removed=ch[0];
			return rem_str+1;
		}
		else if(rem_str[0]=='\0'&&last_removed==ch[0]){
				return rem_str;
		}
		rem_str--;
		rem_str[0]=ch[0];
		return rem_str;
}
string remove(string& s,string& s1){
	if(s.size()==0||s.size()==1){
		return s;
	}
	while(s.empty()&&s[0]==s[1]){
		for(int i=0;s[i]==s[i+1]&&s[i+1];i++){
			s[i]=s[i+1];
		}
		
	}
}
int main(){
	string str;
	cin>>str;
	char s[str.size()+1];
	strcpy(s,str.c_str());
	char last_removed='\0';
//	cout<<remove_dup(s,last_removed);
	cout<<remove(str,"");
	return 0;
}
