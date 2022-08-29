class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n=wordList.size();
        set<string> s;
        for(int i=0;i<n;i++){
            s.insert(wordList[i]);
        }
        if(s.count(endWord)==0)return 0;
        if(s.count(beginWord)==0){
            s.insert(beginWord);
        }
        queue<string> q;
        q.push(beginWord);
        int lvl=0;
        while(!q.empty()){
            lvl++;
            int size=q.size();
            while(size--){
                 string str=q.front();
                 q.pop();
                if(str==endWord){
                    return lvl;
                }
                for(int pos=0;pos<str.size();pos++){
                    char ch=str[pos];
                    for(char c='a';c<='z';c++){
                        str[pos]=c;
                        if(s.count(str)){
                            q.push(str);
                            s.erase(str);
                        }
                    }
                    str[pos]=ch;
                }
            }
        }
        return 0;
    }
};