/*Given an array arr[ ] consisting of n integers, find the maximum Geek Value of the array to unleash its true potential.
Geek value is defined as (arri - arrj) × arrk, where 1 ≤ i < j < k ≤ n.
Please note that if the Geek Value turns out to be negative, return 0 as the answer.

Example 1:
Input :
n = 3
arr = {4,2,3}
Output:
6

Explanation:
We choose i=1,j=2,k=3 indices {one based indexing}
Geek value of array is (arr[i]-arr[j])*arr[k] = (4-2)*3 = 6.

Example 2:
Input :
n = 5
arr = {10,1,4,2,7}
Output:
63

Explanation:
Take indices i=1,j=2 and k=5 {one based indexing}
Geek value = (arr[1]−arr[2])×arr[5] = 63.
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(auto &i : nums){
        cin >> i;
    }
    //pre_max is to store the maximum value till the index in [0, i] range
    //suff_max is to store the maximum value till the index in [i, n - 1] range
    //as we iterate over the nums, we fix the value of aj, and look for maximum of ai in left side and ak in right side 
    vector<int> pre_max(n), suff_max(n);
    pre_max[0] = nums[0], suff_max[n - 1] = nums[n - 1];
    for(int i = 1; i < n; i++){
        pre_max[i] = max(nums[i], pre_max[i - 1]);
    }
    for(int i = n - 2; i >= 0; i--){
        suff_max[i] = max(suff_max[i + 1], nums[i]);
    }
    int ans = 0;
    for(int j = 0; j < n; j++){
        ans = max(ans, (pre_max[j] - nums[j])*suff_max[j]);
    }
    cout << ans << endl;
}