#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Trie {
    TreeNode* root;
public:
    Trie() {
       
    }
    
    void insert(string word) {
        
    }
    
    bool search(string word) {
        
    }
    
    bool startsWith(string prefix) {
        
    }
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

class Solution
{
public:
    void flatten(TreeNode *root)
    {
        TreeNode *currNode;
        TreeNode *predecessor;

        while (currNode != NULL)
            if (currNode->left)
            {
                predecessor = currNode->left;
                while (predecessor->right && predecessor->right != currNode)
                    predecessor = predecessor->right;

                if (predecessor->right)
                {
                    predecessor->right = currNode->right;
                    currNode->right = currNode->left;
                    currNode->left = NULL;
                }
                else
                {
                    predecessor->right = currNode;
                    currNode = currNode->left;
                }
            }
            else
            {
                currNode = currNode->right;
            }
    }
};

class Solution
{
public:
    void flatten(TreeNode *root)
    {
        TreeNode *currNode;
        TreeNode *predecessor;

        while (currNode != NULL)
            if (currNode->left)
            {
                predecessor = currNode->left;
                while (predecessor->right && predecessor->right != currNode)
                    predecessor = predecessor->right;

                predecessor->right = currNode->right;
                currNode->right = currNode->left;
                currNode->left = NULL;
                currNode = currNode->right;
            }
            else
            {
                currNode = currNode->right;
            }
    }
};
class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
       
    }
};
class Solution
{

public:
    int kthSmallest(TreeNode *root, int k)
    {
        TreeNode *curr = root;
        TreeNode *prec;

        while (curr != NULL)
            if (curr->left)
            {
                prec = curr->left;
                while (prec->right && prec->right != curr)
                    prec = prec->right;
                if (prec->right == NULL)
                {
                    prec->right = curr;
                    curr = curr->left;
                }
                else
                {
                    k--;
                    if (k == 0)
                        return curr->val;
                    prec->right = NULL;
                    curr = curr->right;
                }
            }
            else
            {
                k--;
                if (k == 0)
                    return curr->val;
                curr = curr->right;
            }

        return -1;
    }
};

class BinaryTree
{

public:
    Node *root;
    BinaryTree()
    {
        root = nullptr;
    }
    Node *insertData()
    {
        int x;
        cout << "Enter Data To Insert[-1 to Null]: ";
        cin >> x;
        Node *node = new Node(x);

        if (x == -1)
            return nullptr;

        cout << "You are at left node of " << x << endl;
        node->left = insertData();
        cout << "You are at right node of " << x << endl;
        node->right = insertData();
        return node;
    }
    void levelOrderTraversal()
    {
        queue<Node *> q;
        q.push(root);
        q.push(nullptr);

        while (!q.empty())
        {
            Node *temp = q.front();
            q.pop();

            if (temp == NULL)
            {
                if (!q.empty())
                    q.push(temp);
                cout << endl;
                continue;
            }

            cout << temp->val << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
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
    void inorder(Node *node)
    {
        if (node == NULL)
            return;

        inorder(node->left);
        cout << node->val << " ";
        inorder(node->right);
    }
    void preorder(Node *node)
    {
        if (node == NULL)
            return;
        cout << node->val << " ";
        preorder(node->left);
        preorder(node->right);
    }
    void postorder(Node *node)
    {
        if (node == NULL)
            return;

        postorder(node->left);
        postorder(node->right);
        cout << node->val << " ";
    }
    void inorderIteration(Node *root)
    {
        stack<Node *> s;
        s.push(root);

        while (!s.empty())
        {
            if (s.top()->left)
            {
                s.push(s.top()->left);
            }
            else
            {
                Node *temp;
                while (s.top()->right == NULL)
                {
                    temp = s.top();
                    s.pop();
                    cout << temp->val << " ";
                }
                temp = s.top();
                s.pop();
                cout << temp->val << " ";
                s.push(temp->right);
            }
        }
    }
    void inorderIteration2(Node *root)
    {
        stack<Node *> s;
        Node *curr = root;

        while (curr != NULL || !s.empty())
        {
            while (curr)
            {
                s.push(curr);

                curr = curr->left;
            }
            curr = s.top();
            s.pop();
            cout << curr->val << " ";
            curr = curr->right;
        }
    }
    void preorderIterative(Node *node)
    {
        stack<Node *> s;
        Node *curr = root;
        s.push(root);
        while (!s.empty())
        {

            curr = s.top();
            s.pop();
            cout << curr->val << " ";
            if (curr->right)
                s.push(curr->right);
            if (curr->left)
                s.push(curr->left);
        }
    }
    void postOrderIterative(Node *node)
    {
        stack<Node *> s1, s2;
        Node *curr = root;
        s1.push(curr);

        while (!s1.empty())
        {
            curr = s1.top();
            s1.pop();
            s2.push(curr);

            if (curr->left)
                s1.push(curr->left);
            if (curr->right)
                s1.push(curr->right);
        }
        while (!s2.empty())
        {
            cout << s2.top()->val << " ";
            s2.pop();
        }
    }

    void buildTreeFromLevelOrder(Node *root)
    {
        queue<Node *> q;
        int x;
        cin >> x;
        root = new Node(x);
        q.push(root);

        while (!q.empty())
        {
            Node *temp = q.front();
            q.pop();
            cin >> x;
            temp->left = new Node(x);
            q.push(temp->left);
            cin >> x;
            temp->right = new Node(x);
        }
    }
};

int main()
{
    BinaryTree bt;

    // 5 4 2 -1 -1 6 9 -1 -1 8 -1 -1 3 7 -1 -1 -1
    bt.root = bt.insertData();

    cout << endl;
    bt.prettyDisplay(bt.root, 0);
    cout << endl;
    bt.levelOrderTraversal();
    cout << endl;
    bt.inorder(bt.root);
    cout << endl;
    bt.inorderIteration2(bt.root);
    cout << endl;
    bt.preorder(bt.root);
    cout << endl;
    bt.preorderIterative(bt.root);
    cout << endl;
    bt.postorder(bt.root);
    cout << endl;
    bt.postOrderIterative(bt.root);

    return 0;
}