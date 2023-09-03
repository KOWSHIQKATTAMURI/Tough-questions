//https://leetcode.com/problems/interleaving-string/

#include<bits/stdc++.h>
using namespace std;

bool isInterleave(string &s1, string &s2, string &s3, int n, int m, int o, vector<vector<int>>& dp){
    if(o == 0){
        return true;
    }
    if(dp[n][m] != -1){
        return dp[n][m];
    }
    int first = 0, second = 0;
    if(n >= 0 and s1[n] == s3[o]){
        first = isInterleave(s1, s2, s3, n - 1, m, o - 1, dp);
    }
    if(m >= 0 and s2[m] == s3[o]){
        second = isInterleave(s1, s2, s3, n, m - 1, o - 1, dp);
    }
    return dp[n][m] = first or second;
}

int main(){
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    int n = s1.length(), m = s2.length(), o = s3.length();
    if(n + m != o){
        cout << "0" << endl;
        return 0;
    }
    vector<vector<int>> dp(n, vector<int>(m, -1));
    cout << isInterleave(s1, s2, s3, n - 1, m - 1, o - 1, dp) << endl;
}