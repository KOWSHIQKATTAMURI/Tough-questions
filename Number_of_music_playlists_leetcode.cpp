//https://leetcode.com/problems/number-of-music-playlists/description/

#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
long solve(vector<vector<int>> &dp, int current, int unique, int n, int goal, int k){
    if(current == goal){
        if(unique == n){
            return dp[current][unique] = 1;
        }else{
            return dp[current][unique] = 0;
        }
    }
    if(dp[current][unique] != -1){
        return dp[current][unique];
    }
    long ans = 0;
    //There are total of two options:
    //1. If present number of unique songs that has been taken is still less than number of total unique songs available, then we will
    //   add 1 to number of unique songs as well as to current number of songs arranged in the playlist. 
    //2. The reason why we are multiplying by (n - unique) is because if (unique) number of songs are already choosen, then (n - unique)
    //   number of songs can be arranged in solve(dp, current + 1, unique + 1, n, goal, k).
    //3. If present unique number of songs taken is greater than k, then we can repeat the songs. 
    //4. Only (Unique - k) number of songs are available to be repeated.
    if(unique < n){
        ans += (n - unique)*solve(dp, current + 1, unique + 1, n, goal, k);
    }
    if(unique > k){
        ans += (unique - k)*solve(dp, current + 1, unique, n, goal, k);
    }
    return dp[current][unique] = ans%mod;
}
int numMusicPlaylists(int n, int goal, int k){
    vector<vector<int>> dp(goal + 1, vector<int>(n + 1, -1));
    return solve(dp, 0, 0, n, goal, k);
}

int main(){
    int n, goal, k;
    cin >> n >> goal >> k;
    cout << numMusicPlaylists(n, goal, k) << endl;
}