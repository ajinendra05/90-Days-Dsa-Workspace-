#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class MinStack
{
    ListNode *top;

public:
    MinStack()
    {
        top = NULL;
    }

    void push(int val)
    {
        if (top == NULL)
        {
            ListNode *temp = new ListNode(val);
            top = temp;
        }
        else
        {
            ListNode *temp = top;
            while (temp->next != NULL && temp->next->val < val)
            {
                temp = temp->next;
            }
            if (temp->next == NULL)
            {
            }
        }
    }

    void pop()
    {
    }

    int top()
    {
    }

    int getMin()
    {
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

class MinStack
{

    vector<int> data;
    int top;

public:
    MinStack()
    {
        int top = -1;
    }

    void push(int val)
    {
        // if(top=-1){
        //     data.push_back(val);
        //     top++;
        //     return;
        // }
        // for(int i=0;i<top+1;i++){
        //     if(data[i]<val){
        //        data.insert(data.begin()+i,val);
        //        return;
        //     }
        // }
        // data.push_back(val);
        // return;
    }

    void pop()
    {
        data.pop_back();
    }

    int top()
    {
        return data.back();
    }

    int getMin()
    {
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

#define ll long long int
class MinStack
{
    stack<int> minS;
    vector<int> data;
    int min;

public:
    MinStack()
    {
        min = INT_MAX;
        minS.push(min);
    }

    void push(int val)
    {
        data.push_back(val);
        if (val <= min)
        {
            min = val;
            minS.push(min);
        }
    }

    void pop()
    {
        int x = data.back();
        if (x == min)
        {
            minS.pop();
            min = minS.top();
        }
        data.pop_back();
    }

    int top()
    {
        return data.back();
    }

    int getMin()
    {
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
class Solution
{
    int count = 0;

public:
    void countWay(int n)
    {
        if (n == 0)
        {
            count++;
            return;
        }
        if (n >= 2)
        {
            countWay(n - 2);
        }
        countWay(n - 1);
    }
    // pass n-1 in function to find fibonachi of that number in o(n);
    int fibonachiNum(int n, int i, int j)
    {
        if (n + 1 == 4)
            return i + j;
        return fibonachiNum(n - 1, j, i + j);
    }
    int climbStairs(int n)
    {
        if (n == 1 || n == 2 || n == 3)
            return n;
        int count = fibonachiNum(n + 1, 2, 3);
        return count;
    }
};

class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int n = gas.size();
        vector<int> net(n);
        long long sum = 0;
        vector<pair<long long, int>> bunch;
        long long curs = 0;
        int si = 0;
        for (int i = 0; i < n; i++)
        {
            net[i] = gas[i] - cost[i];
            sum += net[i];
            if (curs * net[i] < 0)
            {
                bunch.push_back(make_pair(curs, si));
                curs = net[i];
                si = i;
            }
            else
            {
                curs += net[i];
            }
        }
        bunch.push_back(make_pair(curs, si));
        if (sum < 0)
            return -1;
        bool flag = true;
        int m = bunch.size();
        for (int i = 0; i < m; i++)
        {
            si = bunch[i].second;
            curs = bunch[i].first;
            flag = true;
            for (int j = i + 1; j < bunch.size(); j++)
            {
                if (curs < 0)
                {
                    flag = false;
                    break;
                }
                curs += bunch[j].first;
            }
            if (flag == true)
                return si;
            bunch.push_back(bunch[i]);
        }
        return -1;
    }
};

class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int sum = 0;
        int currSum = 0;
        int ptr = 0;
        int n = gas.size();

        for (int i = 0; i < n; i++)
        {
            currSum += gas[i] - cost[i];
            sum += gas[i] - cost[i];
            if (currSum < 0)
            {
                ptr = i + 1;
            }
        }
        if (sum < 0)
            return -1;
        return ptr;
    }
};

class Solution
{
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
    {
        stack<int> s;
        int pi = 0, poi = 0;

        while (pi < pushed.size())
        {
            s.push(pushed[pi]);
            while (!s.empty() && s.top() == popped[poi])
            {
                s.pop();
                poi++;
            }
            pi++;
        }
        if (s.empty())
            return true;
        return false;
    }
};

class Solution
{
public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<int> safeNode;
        map<int, bool> isterminal;
        for (int i = 0; i < n; i++)
        {
            if (graph[i].empty())
            {
                safeNode.push_back(i);
                isterminal[i] = true;
            }
        }
        bool flag = true;
        for (int i = 0; i < n; i++)
        {
            flag = true;
            if (isterminal[i] == false)
            {
                for (int j = 0; j < graph[i].size(); j++)
                {
                    if (isterminal[graph[i][j]] == false)
                    {
                        flag = false;
                        break;
                    }
                }
                if (flag)
                    safeNode.push_back(i);
            }
        }
        sort(safeNode.begin(), safeNode.end());
        return safeNode;
    }
};
class Solution
{
    vector<int> safeNode;
    map<int, bool> notsafe;
    map<int, bool> safe;
    map<int, bool> isvited;

public:
    bool traverse(vector<vector<int>> &graph, int i, int k)
    {
        if (isvited[i] == true || notsafe[i] == true)
            return false;
        isvited[i] = true;
        if (graph[i].empty() || safe[i] == true)
        {

            return true;
        }
        bool c = true;
        for (int j = 0; j < graph[i].size(); j++)
        {
            c = c && traverse(graph, graph[i][j], k);
            isvited[graph[i][j]] = false;
            if (c == false)
            {
                return false;
            }
        }
        return c;
    }
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        map<int, bool> isTerminate;
        for (int j = 0; j < graph.size(); j++)
        {
            isvited.clear();
            if (traverse(graph, j, j))
            {
                safeNode.push_back(j);
            }
        }
        return safeNode;
    }
};

class Solution
{
public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
    }
};

// Definition for a binary tree node.
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
    string smlstr;
    void getString(TreeNode *curr, string s)
    {
        if (curr->left == NULL && curr->right == NULL)
        {
            s = char(97 + curr->val) + s;
            if (smlstr.empty() && (s.size() > 1))
                smlstr = s;
            else
            {
                int x = smlstr.compare(s);
                if (x > 0 && (s.size() > 1))
                    smlstr = s;
            }
            return;
        }
        if (curr->left != NULL)
        {
            getString(curr->left, char(97 + curr->val) + s);
        }
        if (curr->right != NULL)
        {
            getString(curr->right, char(97 + curr->val) + s);
        }
    }

public:
    string smallestFromLeaf(TreeNode *root)
    {
        if (root->left == NULL && root->right == NULL)
        {
            char c = char(97 + root->val);
            smlstr = "";
            smlstr += c;
            return smlstr;
        }
        getString(root, "");
        return smlstr;
    }
};

class Solution
{
    bool gameover = false;
    bool v = false;
    bool h = false;
    char ov;

public:
    bool isMultipleOver(vector<string> &board)
    {
        for (auto x : board)
        {
            if (x[0] == x[1] && x[1] == x[2] && x[0] != ' ')
            {
                if (gameover == false)
                {
                    gameover = true;
                    h = true;
                    ov = x[0];
                }

                else
                    return true;
            }
        }
        gameover = false;

        for (int i = 0; i < 3; i++)
        {
            if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
            {
                if (gameover == false)
                {
                    gameover = true;
                    v = true;
                    ov = board[0][i];
                }
                else
                    return true;
            }
        }
        if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        {
            ov = board[1][1];
            gameover = true;
        }

        if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        {
            ov = board[1][1];
            gameover = true;
        }
        return false;
    }
    bool validTicTacToe(vector<string> &board)
    {
        if (isMultipleOver(board))
            return false;
        int x = 0;
        int o = 0;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] == 'X')
                    x++;
                if (board[i][j] == 'O')
                    o++;
            }
        }
        if (gameover || v || h)
        {
            if (ov == 'X' && x == (o + 1))
                return true;
            if (ov == 'X' && x != (o + 1))
                return false;
            if (ov == 'O' && x == (o))
                return true;
            if (ov == 'O' && x != (o))
                return false;
        }
        if (x == o || x == (o + 1))
            return true;
        return false;
    }
};

class MyQueue
{
    stack<int> s1;
    stack<int> s2;

public:
    MyQueue()
    {
    }

    void push(int x)
    {
        int m = s2.size();
        for (int i = 0; i < m; i++)
        {
            s1.push(s2.top());
            s2.pop();
        }
        s1.push(x);
        int n = s1.size();
        for (int i = 0; i < n; i++)
        {
            s2.push(s1.top());
            s1.pop();
        }
    }

    int pop()
    {
        int x = s2.top();
        s2.pop();
        return x;
    }

    int peek()
    {
        return s2.top();
    }

    bool empty()
    {
        return s2.empty();
    }
};

int countWay(int maxSum, vector<int> a, vector<int> b, int count, int sum)
{
    if (maxSum < sum)
    {
        return count;
    }
    if (a.size() == 0)
    {
        vector<int> by;

        while (!b.empty() && sum < maxSum)
        {
            sum += b[0];
            by = b;
            b.clear();
            copy(by.begin() + 1, by.end(), back_inserter(b));
            count++;
        }
        return count;
    }
    if (b.size() == 0)
    {
        vector<int> by;

        while (!a.empty() && sum < maxSum)
        {
            sum += a[0];
            by = a;
            a.clear();
            copy(by.begin() + 1, by.end(), back_inserter(a));
            count++;
        }
        return count;
    }
    count++;
    int ax = a[0];
    int bx = b[0];
    vector<int> ay;
    vector<int> by;
    copy(a.begin() + 1, a.end(), back_inserter(ay));
    copy(b.begin() + 1, b.end(), back_inserter(by));
    int m = max(countWay(maxSum, ay, b, count, sum + ax), countWay(maxSum, a, by, count, sum + ax));
    return m;
}

int twoStacks(int maxSum, vector<int> a, vector<int> b)
{
    return countWay(maxSum, a, b, 0, 0);
}

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            if (!st.empty())
            {
                if (st.top() == '(' && s[i] == ')')
                    st.pop();
                else if (st.top() == '{' && s[i] == '}')
                    st.pop();
                else if (st.top() == '[' && s[i] == ']')
                    st.pop();
                else
                    st.push(s[i]);
            }
            else
            {
                st.push(s[i]);
            }
        }
        if (st.empty())
            return true;
        return false;
    }
};

class Solution
{
public:
    int minAddToMakeValid(string s)
    {
        int n = s.size();
        int ans = 0;
        stack<char> st;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
                st.push(s[i]);
            else if (s[i] == ')')
            {
                if (st.empty())
                {
                    ans++;
                }
                else
                {
                    st.pop();
                }
            }
        }
        ans += st.size();
        return ans;
    }
};

class Solution
{
public:
    vector<int> finalPrices(vector<int> &prices)
    {
        int s = 0, f = 0;
        int n = prices.size();
        int currV = prices[0];
        vector<int> ans;
        for (int i = 1; i < n; i++)
        {
            f++;
            currV = prices[s];
            if (prices[i] <= currV)
            {
                for (int j = s; j < f; j++)
                {
                    prices[j] -= prices[i];
                    ans.push_back(prices[i]);
                    s = f;
                }
            }
        }
        return prices;
    }
};

class Solution
{
public:
    vector<int> finalPrices(vector<int> &prices)
    {
        stack<pair<int, int>> x;

        int n = prices.size();
        vector<int> discp;

        for (int i = 0; i < n; i++)
        {
            if (x.empty() || x.top().first < prices[i])
            {
                x.push(make_pair(prices[i], i));
            }
            else
            {
                while (!x.empty() && x.top().first >= prices[i])
                {
                    prices[x.top().second] = x.top().first - prices[i];
                    x.pop();
                }
                x.push(make_pair(prices[i], i));
            }
        }
        return prices;
    }
};
class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    { 
        int n = heights.size();
        vector<int> prevMin(n);
        vector<int> afterMin(n);
        stack<pair<int, int>> s;
        s.push(make_pair(-1, -1));
        for (int i = 0; i < n; i++)
        {
            if (s.top().first < heights[i])
            {
                prevMin[i] = s.top().second;
                s.push(make_pair(heights[i], i));
            }
            else
            {
                while (s.top().first >= heights[i])
                {
                    s.pop();
                }
                prevMin[i] = s.top().second;
                s.push(make_pair(heights[i], i));
            }
        }
        stack<pair<int, int>> s1;
        s1.push(make_pair(-1, n));
        for (int i = n-1; i >=0; i--)
        {
            if (s1.top().first < heights[i])
            {
                afterMin[i] = s1.top().second;
                s1.push(make_pair(heights[i], i));
            }
            else
            {
                while (s1.top().first >=heights[i])
                {
                    s1.pop();
                }
                afterMin[i] = s1.top().second;
                s1.push(make_pair(heights[i], i));
            }
        }
        int maxArea=INT_MIN;
        for(int i=0;i<n;i++){
            if((heights[i]*(afterMin[i]-prevMin[i]-1))>maxArea)maxArea=heights[i]*(afterMin[i]-prevMin[i]-1);
        }
        return maxArea;
    }
};
int findMinimumCost(string s)
{
    // Write your code here
    // ans=(a+1)/2 +(b+1)/2
    int n = s.size();
    int ans = 0;
    stack<char> st;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '{')
            st.push(s[i]);
        else if (s[i] == '}')
        {
            if (!st.empty() && st.top() == '{')
            {

                st.pop();
            }
            else
            {
                st.push(s[i]);
            }
        }
    }
    ans = st.size() / 2;
    return ans;
}
stack<int> bubbleSort(stack<int> s, int sml, int k)
{
    if (s.size() == k)
    {
        s.push(sml);
        return s;
    }
    int x = s.top();
    s.pop();
    if (x < sml)
    {
        int t = x;
        x = sml;
        sml = t;
    }
    s = bubbleSort(s, sml, k);
    s.push(x);
    return s;
}
stack<int> sortStack(stack<int> s)
{
    int n = s.size();

    for (int i = 0; i < n; i++)
    {
        s = bubbleSort(s, s.top(), i);
    }
    return s;
}

void insertInSorted(stack<int> s, int val)
{

    if (s.empty() || (!s.empty() && val >= s.top()))
    {
        s.push(val);
        return;
    }
    int x = s.top();
    insertInSorted(s, val);
    s.push(x);
    return;
}

void sortStack2(stack<int> s)
{
    if (s.empty())
        return;

    int x = s.top();
    s.pop();
    sortStack2(s);
    insertInSorted(s, x);
    return;
}

int main()
{

    stack<int> s;
    s.push(10);
    s.push(-10);
    s.push(110);
    s.push(2);
    s = sortStack(s);
    while (!s.empty())
    {
        cout << s.top();
        s.pop();
    }

    return 0;
}

bool findRedundantBrackets(string &s)
{
    // Write your code here.
    int n = s.size();
    stack<char> st;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == ')')
        {
            int c = 0;
            while (st.top() != '(')
            {
                st.pop();
                c++;
            }
            st.pop();
            if (c == 0)
                return false;
        }
        else
        {
            st.push(s[i]);
        }
    }
    return true;
}
