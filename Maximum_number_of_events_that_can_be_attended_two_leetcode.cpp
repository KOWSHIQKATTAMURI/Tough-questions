//https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii/description/
//Uses the concept of DP and Binary Search

#include<bits/stdc++.h>
using namespace std;

int solve( vector<vector<int>> &events,  vector<vector<int>> &dp, int k, int index, int n){
    if(index >= n or k == 0){
        return 0;
    }
    if(dp[index][k] != -1){
        return dp[index][k];
    }
    //creating a temp which has the start time as present index end time and other two elements as INT_MAX
    //This leads to finding the value of that vector which has first value strictly greater than present index end time
    vector<int> temp = {events[index][1], INT_MAX, INT_MAX}; 
    int idx = upper_bound(events.begin() + index + 1, events.end(), temp) - events.begin();
    return dp[index][k] = max(solve(events, dp, k, index + 1, n), events[index][2] + solve(events, dp, k - 1, idx, n));
}

int maxValue(vector<vector<int>> &events, int k){
    int index = 0, n = events.size();
    sort(events.begin(), events.end()); //sort to easily get the access of next event whose start time is greater than present end time
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return solve(events, dp, k, 0, n);
}

int main(){
    int n, k;
    cin >> n >> k;
    vector<vector<int>> events(n, vector<int>(3));
    for(int i = 0; i < n; i++){
        int a, b, c;
        cin >> a >> b >> c;
        events[i][0] = a, events[i][1] = b, events[i][2] = c;
    }
    cout << maxValue(events, k);
}