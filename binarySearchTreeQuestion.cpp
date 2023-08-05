#include <bits/stdc++.h>

using namespace std;

struct Node2
{
    int data;
    Node2 *left, *right;
};
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Node
{

public:
    int val;
    Node *left;
    Node *right;
    Node(int val)
    {
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


//convert bst into sorteed doubly linked list or bt to doubly inorder linked list;
void flatten(TreeNode* node,TreeNode* &head){
    if(node==NULL)return;

    flatten(node->right,head);

    node->right=head;

    if(head!=NULL)
    head->left=node;
    head=node;

    flatten(node->left,head);

}


class Solution {
    bool helper(TreeNode* node,pair<long,long> range){
        if(node==NULL)
            return true;
        
        if(node->val<=range.first||node->val>=range.second)
            return false;
        
        return helper(node->left,make_pair(range.first,node->val))&&helper(node->right,make_pair(node->val,range.second));

    }
public:
    bool isValidBST(TreeNode* root) {
        pair<long,long> p=make_pair(INT_MIN-5,INT_MAX+5);
        return helper(root,p);
    }
};


// genrate multiple tree in every recursion and then add in previous tree leetcode 95
class Solution {
    vector<TreeNode*> BanjaTreeTree(int s, int e){
        if(s > e) return {NULL};
        
        vector<TreeNode*> allTree; 
        for(int i=s; i<=e; i++){
            vector<TreeNode*> lTrees = BanjaTreeTree(s, i-1);
            vector<TreeNode*> rTrees = BanjaTreeTree(i+1, e);
            
            for(auto l: lTrees){
                for(auto r: rTrees){
                    TreeNode* curr = new TreeNode(i);
                    curr->left = l;
                    curr->right = r;
                    allTree.push_back(curr);
                }
            }
        }
        return allTree;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        return BanjaTreeTree(1, n);
    }
};