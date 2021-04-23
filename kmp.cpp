#include<bits/stdc++.h>
using namespace std;
static vector<int> buildNext(const string &s){
    vector<int> next(s.length());
    int i=0, j=next[0]=-1;
    while(i<s.length()-1){
        if(j==-1 or s[i]==s[j]){
            i++;
            j++;
            next[i] = j;
        }else{
            j = next[j];
        }
    }
    return next;
}
int kmp(const string &s, const string &pat){
    vector<int> next = buildNext(s);
    int i=0, j = 0;
    while(i<(int)s.size() and j<(int)pat.size()){
        if(j==-1 or s[i]==pat[j]){
            i++; j++;
        }else{
            j = next[j];
        }
    }
    return j==pat.size()?i-j:-1;
}
