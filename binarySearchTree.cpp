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

void prettyDisplay(Node *node, int level)
{
    if (node == nullptr)
        return;

    prettyDisplay(node->right, level + 1);
    if (level != 0)
    {
        for (int i = 0; i < level - 1; i++)
        {
            cout << "\t";
        }
        cout << "|------->" << node->val << endl;
    }
    else
    {
        cout << node->val << endl;
    }
    prettyDisplay(node->left, level + 1);
}
void prettyDisplay2(TreeNode *node, int level)
{
    if (node == nullptr)
        return;

    prettyDisplay2(node->right, level + 1);
    if (level != 0)
    {
        for (int i = 0; i < level - 1; i++)
        {
            cout << "\t";
        }
        cout << "|------->" << node->val << endl;
    }
    else
    {
        cout << node->val << endl;
    }
    prettyDisplay2(node->left, level + 1);
}
TreeNode *InsertInBST(TreeNode *node, int data)
{
    if (node == NULL)
        return new TreeNode(data);

    if (node->val > data)
        node->right = InsertInBST(node->right, data);
    else
        node->left = InsertInBST(node->left, data);

    return node;
}

TreeNode *minVal(TreeNode *node)
{

    // return min value of tree or sub tree;
    while (node->left)
    {
        node = node->left;
    }
    return node;
}
TreeNode* maxVal(TreeNode* node){
    //return max value node from tree or sub tree
    while(node->right){
        node=node->right;
    }
    return node;
}

void predecessorAndSuccessor(TreeNode *node, int key, int &predecessor, int &successor)
{
    if (node == NULL)
        return;
    if (node->val == key)
    {
        if (node->left)
        {
            predecessor=maxVal(node->left)->val;
        }
        if (node->right)
        {
            successor=minVal(node->right)->val;
        }
        return;
    }

    if (node->val < key)
    {
        predecessor = node->val;
        predecessorAndSuccessor(node->right, key, predecessor, successor);
    }
    else
    {
        successor = node->val;
        predecessorAndSuccessor(node->left, key, predecessor, successor);
    }
}
class Solution
{
public:
    TreeNode *minVal(TreeNode *node)
    {

        // return min value of sub tree;
        while (node->left)
        {
            node = node->left;
        }
        return node;
    }

    TreeNode *deleteNode(TreeNode *node)
    {
        // when both are null
        if (node->left == NULL && node->right == NULL)
        {
            delete node;
            return NULL;
        }

        // when left is null right is not null
        if (node->right == NULL)
        {
            TreeNode *temp = node->left;
            delete node;
            return temp;
        }

        // when right is null left is not null
        if (node->left == NULL)
        {
            TreeNode *temp = node->right;
            delete node;
            return temp;
        }

        // when both are not null
        int min = minVal(node->right)->val; // min value in right sub tree is succesor of curr value
        node->val = min;
        node->right = deleteHelper(node->right, min);
        return node;
    }

    TreeNode *deleteHelper(TreeNode *node, int key)
    {
        if (node == NULL)
            return NULL;

        if (node->val == key)
        {
            return deleteNode(node);
        }
        else if (node->val < key)
            node->right = deleteHelper(node->right, key);
        else
            node->left = deleteHelper(node->left, key);

        return node;
    }

    TreeNode *deleteNode(TreeNode *root, int key)
    {
        root = deleteHelper(root, key);
        return root;
    }
};
int main()
{

    TreeNode *root = NULL;
    int data = 0;
    // 8 3 10 1 6 4 7 14 13 -1
    while (data != -1)
    {
        cout << "Insert Next Value: ";
        cin >> data;
        root = InsertInBST(root, data);
    }
   int pre=-1,suc=-1;
   predecessorAndSuccessor(root,6,pre,suc);
   
    // prettyDisplay2(root, 0);

    cout<<endl<<pre<<" "<<suc<<endl;

    return 0;
}











//gfg

// struct Node
// {
// 	int key;
// 	struct Node *left;
// 	struct Node *right;
	
// 	Node(int x){
// 	    key = x;
// 	    left = NULL;
// 	    right = NULL;
// 	}
// };
// Node *minVal(Node *node)
// {

//     // return min value of tree or sub tree;
//     while (node->left)
//     {
//         node = node->left;
//     }
//     return node;
// }
// Node* maxVal(Node* node){
//     //return max value node from tree or sub tree
//     while(node->right){
//         node=node->right;
//     }
//     return node;
// }

// void predecessorAndSuccessor(Node *node, int key, int &predecessor, int &successor)
// {
//     if (node == NULL)
//         return;
//     if (node->key == key)
//     {
//         if (node->left)
//         {
//             predecessor=maxVal(node->left)->key;
//         }
//         if (node->right)
//         {
//             successor=minVal(node->right)->key;
//         }
//         return;
//     }

//     if (node->key < key)
//     {
//         predecessor = node->key;
//         predecessorAndSuccessor(node->right, key, predecessor, successor);
//     }
//     else
//     {
//         successor = node->key;
//         predecessorAndSuccessor(node->left, key, predecessor, successor);
//     }
// }

// class Solution
// {  
//     Node *minVal(Node *node)
// {

//     // return min value of tree or sub tree;
//     while (node->left)
//     {
//         node = node->left;
//     }
//     return node;
// }
// Node* maxVal(Node* node){
//     //return max value node from tree or sub tree
//     while(node->right){
//         node=node->right;
//     }
//     return node;
// }


//     public:
//     void findPreSuc(Node* node, Node*& pre, Node*& suc, int key)
//     {
//         // Your code goes here
//       if(node == NULL)
//         return;
//     if (node->key == key)
//     {
//         if (node->left)
//         {
//             pre=maxVal(node->left);
//         }
//         if (node->right)
//         {
//             suc=minVal(node->right);
//         }
//         return;
//     }

//     if (node->key < key)
//     {
//         pre= node;
//         findPreSuc(node->right, pre,suc,key);
//     }
//     else
//     {
//         suc = node;
//         findPreSuc(node->left, pre,suc,key);
//     }
//     }
// };