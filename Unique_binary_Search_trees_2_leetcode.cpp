//https://leetcode.com/problems/unique-binary-search-trees-ii/

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

vector<TreeNode*> solve(int start, int end){
        if(start > end){
            return {NULL};
        }
        if(start == end){
            TreeNode* temp = new TreeNode(start);
            return {temp};
        }
        vector<TreeNode*> ans;
        for(int i = start; i <= end; i++){
            vector<TreeNode*> left = solve(start, i - 1);
            vector<TreeNode*> right = solve(i + 1, end);
            for(auto l : left){
                for(auto r : right){
                    TreeNode* root = new TreeNode(i);
                    root -> left = l;
                    root -> right = r;
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n){
        return solve(1, n);
    }

int main(){
    int n;
    cin >> n;
    vector<TreeNode*> ans = generateTrees(n);
}