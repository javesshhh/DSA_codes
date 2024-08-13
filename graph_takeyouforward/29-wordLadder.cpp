// https://leetcode.com/problems/word-ladder/description/

#include <bits/stdc++.h>
using namespace std;

int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        // Code here
        queue<pair<string,int>>q;
        q.push({startWord,1});
        unordered_set <string>s;
        for(int i=0;i<wordList.size();i++){
            s.insert(wordList[i]);
        }
        s.erase(startWord);
        while(!q.empty()){
            string word=q.front().first;
            int len=q.front().second;
            q.pop();
            if(word==targetWord){
                return len;
            }
            for(int i=0;i<word.length();i++){
                char original=word[i];       // character I am looking to change in loop
                for(char c='a';c<='z';c++){
                    word[i]=c;
                    if(s.find(word)!=s.end()){
                        q.push({word,len+1});
                        s.erase(word);
                    }
                }
                word[i]=original;
            }
        }
        return 0;
    }

int main() {

}