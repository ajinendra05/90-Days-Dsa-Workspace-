#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

class Solution
{

public:
    void traversal(Node *node, int length, pair<int, int> &ans, int sum)
    {
        if (node == nullptr)
            return;
        if (node->left == nullptr && node->right == nullptr)
        {
            if (length > ans.first)
            {
                ans.second = sum + node->data;
            }
            return;
        }
        traversal(node->left, length + 1, ans, sum + node->data);
        traversal(node->right, length + 1, ans, sum + node->data);
    }

    int sumOfLongRootToLeafPath(Node *root)
    {
        // code here
        pair<int, int> ans;
        ans = make_pair(0, 0);
        traversal(root, 0, ans, 0);
        return ans.second;
    }
};
class Solution
{
    void leftTraversal(Node *node, vector<int> &ans)
    {
        if (node == NULL || (node->left == nullptr && node->right == nullptr))
        {
            return;
        }
        ans.push_back(node->data);

        if (node->left)
        {
            rightTraverse(node->left, ans);
        }
        else if (node->right)
        {
            rightTraverse(node->right, ans);
        }
    }
    void rightTraverse(Node *node, vector<int> &ans)
    {
        if (node == NULL || (node->left == nullptr && node->right == nullptr))
        {
            return;
        }

        if (node->right)
        {
            leftTraversal(node->right, ans);
        }
        else if (node->left)
        {
            leftTraversal(node->left, ans);
        }
        ans.push_back(node->data);
    }

    void leafNodeTravers(Node *node, vector<int> &ans)
    {
        if (node == nullptr)
            return;

        if (node->left == nullptr && node->right == nullptr)
        {
            ans.push_back(node->data);
        }

        if (node->left)
            leafNodeTravers(node->left, ans);
        if (node->right)
            leafNodeTravers(node->right, ans);
    }

public:
    vector<int> boundary(Node *root)
    {
        // Your code here
        vector<int> ans;
        ans.push_back(root->data);
        leftTraversal(root->left, ans);
        leafNodeTravers(root->left, ans);
        leafNodeTravers(root->right, ans);
        rightTraverse(root->right, ans);
        return ans;
    }
};

class Solution
{
public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        // Your code here
        queue<pair<Node *, int>> q;
        pair<Node *, int> temp;
        unordered_map<int, int> m;
        int mi = 0, ma = 0;
        if (root == nullptr)
            return {};

        q.push(make_pair(root, 0));

        while (!q.empty())
        {
            temp = q.front();
            q.pop();
            if (m.find(temp.second) == m.end())
            {
                m[temp.second] = temp.first->data;
            }
            if (temp.first->left)
                q.push(make_pair(temp.first->left, temp.second - 1));
            if (temp.first->right)
                q.push(make_pair(temp.first->right, temp.second + 1));
            mi = min(mi, temp.second);
            ma = max(ma, temp.second);
        }
        vector<int> ans;
        for (int i = mi; i <= ma; i++)
        {
            ans.push_back(m[i]);
        }
        return ans;
    }
};

class Solution
{
public:
    vector<int> bottomView(Node *root)
    {
        // Your Code Here
        queue<pair<Node *, int>> q;
        pair<Node *, int> temp;
        unordered_map<int, int> m;
        int mi = 0, ma = 0;
        if (root == nullptr)
            return {};

        q.push(make_pair(root, 0));

        while (!q.empty())
        {
            temp = q.front();
            q.pop();

            m[temp.second] = temp.first->data;

            if (temp.first->left)
                q.push(make_pair(temp.first->left, temp.second - 1));
            if (temp.first->right)
                q.push(make_pair(temp.first->right, temp.second + 1));
            mi = min(mi, temp.second);
            ma = max(ma, temp.second);
        }
        vector<int> ans;
        for (int i = mi; i <= ma; i++)
        {
            ans.push_back(m[i]);
        }
        return ans;
    }
};

void help(queue<Node *> q, vector<int> &ans)
{
    if (q.empty())
        return;

    ans.push_back(q.front()->data);
    int size = q.size();
    Node *temp;
    for (int i = 0; i < size; i++)
    {
        temp = q.front();
        q.pop();
        if (temp->left)
            q.push(temp->left);
        if (temp->right)
            q.push(temp->right);
    }
    help(q, ans);
}
vector<int> leftView(Node *root)
{
    // Your code here
    vector<int> ans;
    queue<Node *> q;
    q.push(root);
    help(q, ans);
    return ans;
}
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
    void traversal(TreeNode *node, int k, int &count, vector<int> path)
    {
        if (node == NULL)
            return;

        path.push_back(node->val);

        traversal(node->left, k, count, path);
        traversal(node->right, k, count, path);
        long long int sum = 0;
        for (int i = path.size() - 1; i >= 0; i--)
        {
            sum += path[i];
            if (sum == k)
            {
                count++;
            }
        }
    }

public:
    int pathSum(TreeNode *root, int targetSum)
    {
        vector<int> path;
        int count = 0;
        traversal(root, targetSum, count, path);
        return count;
    }
};

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *node, TreeNode *p, TreeNode *q)
    {
        if (node == NULL)
            return NULL;
        if (node->val == p->val || node->val == q->val)
            return node;

        TreeNode *left = lowestCommonAncestor(node->left, p, q);
        TreeNode *right = lowestCommonAncestor(node->right, p, q);

        if (left != NULL && right != NULL)
            return node;
        if (left != NULL && right == NULL)
            return left;
        if (left == NULL && right != NULL)
            return right;
        return NULL;
    }
};
class Solution
{
    TreeNode *ans;

public:
    bool traverse(TreeNode *node, TreeNode *p, TreeNode *q)
    {
        if (node == nullptr)
            return false;

        bool l = traverse(node->left, p, q);
        bool r = traverse(node->right, p, q);

        if (l == true and r == true)
        {
            ans = node;
        }
        if (l == true || r == true)
        {
            if (node->val == p->val || node->val == q->val)
            {
                ans = node;
            }
        }
        if (node->val == p->val || node->val == q->val)
        {
            return true;
        }
        return l or r;
    }
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {

        traverse(root, p, q);
        return ans;
    }
};
class Solution
{
public:
    bool traverse(TreeNode *node, TreeNode *&ans, TreeNode *p, TreeNode *q)
    {
        if (node == nullptr)
            return false;
        if (node->val == p->val || node->val == q->val)
        {
            return true;
        }
        bool l = traverse(node->left, ans, p, q);
        bool r = traverse(node->right, ans, p, q);

        if (l and r)
        {
            ans = node;
        }
        return l or r;
    }
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        TreeNode *ans;
        traverse(root, ans, p, q);
        return ans;
    }
};

class Solution
{

    TreeNode *traversal(TreeNode *node, TreeNode *p, TreeNode *q)
    {
        if (node == nullptr)
        {
            return NULL;
        }
        if (node->val == q->val && node->val == p->val)
        {
            return node;
        }
    }

public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
    }
};
class Solution
{
public:
    void levelOrderTraversal(queue<TreeNode *> q, queue<TreeNode *> &nodes)
    {
        if (q.empty())
            return;

        TreeNode *temp = q.front();
        q.pop();
        nodes.push(temp);
        if (temp->left)
            q.push(temp->left);
        if (temp->right)
            q.push(temp->right);
        levelOrderTraversal(q, nodes);
    }
    int help(TreeNode *node)
    {
        if (node == nullptr)
            return 0;
        if (node->right == nullptr && node->left == nullptr)
        {
            return node->val;
        }
        int l = help(node->left);
        int r = help(node->right);
        int left = l <= 0 ? node->val : l + node->val;
        int right = r <= 0 ? node->val : r + node->val;

        return max(left, right);
    }
    int maxPathSum(TreeNode *root)
    {
        queue<TreeNode *> q;
        queue<TreeNode *> nodes;
        if (root == nullptr)
            return 0;
        q.push(root);
        levelOrderTraversal(q, nodes);

        int ans = INT_MIN;

        TreeNode *temp;
        while (!nodes.empty())
        {
            temp = nodes.front();
            nodes.pop();
            int l = help(temp->left);
            int r = help(temp->right);
            int s = max(l + r + temp->val, max(r + temp->val, l + temp->val));
            s = max(s, +temp->val);
            ans = max(ans, s);
        }
        return ans;
    }
};

class Solution
{
public:
    int help(TreeNode *node, int &maxPath)
    {
        if (node == nullptr)
            return 0;
        // if (node->right == nullptr && node->left == nullptr)
        // {
        //     return node->val;
        // }
        int l = max(0, help(node->left, maxPath));
        int r = max(0, help(node->right, maxPath));
        maxPath = max(maxPath, max(node->val, max(l + r + node->val, max(l + node->val, r + node->val))));

        return max(l, r) + node->val;
    }
    int maxPathSum(TreeNode *root)
    {
        int maxPath = INT_MIN;
        int result = help(root, maxPath);
        return max(maxPath, result);
    }
};
class Solution
{

public:
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        queue<pair<TreeNode *, int>> q;
        pair<TreeNode *, int> temp;
        int dist;
        map<int, vector<int>> m;
        int mi = 0, ma = 0;

        q.push(make_pair(root, 0));
        while (!q.empty())
        {
            temp = q.front();
            q.pop();

            m[temp.second].push_back(temp.first->val);
            if (temp.first->left)
                q.push(make_pair(temp.first->left, temp.second - 1));
            if (temp.first->right)
                q.push(make_pair(temp.first->right, temp.second + 1));
            mi = min(mi, temp.second);
            ma = max(ma, temp.second);
        }
        vector<vector<int>> ans;
        for (int i = mi; i <= ma; i++)
        {
            ans.push_back(m[i]);
        }
        return ans;
    }
};

class Solution
{
public:
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        queue<pair<TreeNode *, pair<int, int>>> q;
        pair<TreeNode *, pair<int, int>> temp;
        int row = 0;
        int col = 0;
        map<int, map<int, vector<int>>> m;
        int mi = 0, ma = 0;

        q.push(make_pair(root, make_pair(row, col)));
        while (!q.empty())
        {
            temp = q.front();
            q.pop();

            m[temp.second.first][temp.second.second].push_back(temp.first->val);
            row = temp.second.first;
            col = temp.second.second;
            if (temp.first->left)
                q.push(make_pair(temp.first->left, make_pair(row - 1, col + 1)));

            if (temp.first->right)
                q.push(make_pair(temp.first->right, make_pair(row + 1, col + 1)));
            mi = min(mi, row);
            ma = max(ma, row);
        }
        vector<vector<int>> ans(ma - mi + 1);
        for (int i = 0; i <= ma - mi; i++)
        {
            for (auto x : m[i + mi])
            {
                sort(x.second.begin(), x.second.end());
                for (auto j : x.second)
                {
                    ans[i].push_back(j);
                }
            }
        }

        return ans;
    }
};
int main()
{
    return 0;
}