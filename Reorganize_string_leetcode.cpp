//https://leetcode.com/problems/reorganize-string/description/

#include<bits/stdc++.h>
using namespace std;

string reorganizeString(string s){
    vector<int> freq(26, 0);
    int n = s.length();
    for(int i = 0; i < n; i++){
        freq[s[i] - 'a']++;
    }
    priority_queue<pair<int, char>> pq;
    for(int i = 0; i < 26; i++){
        if(freq[i] != 0){
            pq.push(make_pair(freq[i], 'a' + i));
        }
    }
    pair<int, char> p = {-1, '$'};
    string ans;
    while(!pq.empty()){
        auto temp = pq.top();
        pq.pop();
        ans.push_back(temp.second);
        temp.first--;
        if(p.first > 0){
            pq.push(p);
        }
        p = temp;
    }
    if(n == ans.length()){
        return ans;
    }
    return "";
}

int main(){
    string s;
    cin >> s;
    cout << reorganizeString(s) << endl;
}