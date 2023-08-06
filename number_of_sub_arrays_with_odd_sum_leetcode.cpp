//https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/description/

#include<bits/stdc++.h>
using namespace std;

int numOfSubarrays(vector<int>& arr){
    long ans = 0;
    int even_sum = 0, odd_sum = 0, total_sum_till_now = 0;
    for(int i = 0; i < arr.size(); i++){
        total_sum_till_now += arr[i];
        if(total_sum_till_now%2 == 1){
            ans += even_sum + 1;
            odd_sum++;
        }else{
            ans += odd_sum;
            even_sum++;
        }
    }
    return (int)(ans%(1000000007));
}

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(auto &i : nums){
        cin >> i;
    }
    cout << numOfSubarrays(nums) << endl;
}