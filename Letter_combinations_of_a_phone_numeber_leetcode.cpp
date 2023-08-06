//https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/

#include<bits/stdc++.h>
using namespace std;

vector<string> letterCombinations(string digits){
    if(digits.empty()){
        return {};
    }
    vector<string> numbers = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
//The main logic here is to generate the possible number of combinations till the previous value.
//For example the first digit is 2
//At the beginning of the iteration for 2, there is only one possible combination and that is an exmpty string.
//At the end of the iteration for 2, the ans is {"a", "b", "c}
//This denotes that when we start the iteration for 3, we already stored the possible number of combinations of 2 in the ans
//After the iteration for 3, the ans is {"ad","bd","cd","ae","be","ce","af","bf","cf"} 
    vector<string> ans = {""};
    for(auto digit : digits){
        vector<string> temp;
        for(auto ch : numbers[digit - '0']){
            for(auto it : ans){
                temp.push_back(it + ch);
            }
        }
        ans = temp;
    }
    return ans;
}

int main(){
    string digit;
    cin >> digit;
    vector<string> ans = letterCombinations(digit);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
}