#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void traverseQueue(queue<int> &q)
    {
        if (q.empty())
        {
            return;
        }
        int x = q.front();
        q.pop();
        traverseQueue(q);
        q.push(x);
    }
    queue<int> rev(queue<int> q)
    {
        // add code here.
        traverseQueue(q);
    }
};

vector<long long> printFirstNegativeInteger(long long int A[],
                                            long long int N, long long int K)
{
    queue<long long> q;
    long long count = 0;
    vector<long long> ans;
    for (int i = 0; i < K; i++)
    {
        if (A[i] < 0)
            q.push(i);
    }
    if (q.empty())
        ans.push_back(0);
    else
        ans.push_back(A[q.front()]);

    for (int i = K; i < N; i++)
    {
        if (A[i] < 0)
            q.push(i);
        while (!q.empty() && q.front() - i >= K)
            q.pop();
        if (q.empty())
            ans.push_back(0);
        else
            ans.push_back(A[q.front()]);
    }
    return ans;
}

// wrong
class Solution
{
public:
    string FirstNonRepeating(string A)
    {
        // Code here
        string s = "";
        s = s + A[0];
        set<char> se;
        se.insert(A[0]);
        int size = 1;
        for (int i = 1; i < A.size(); i++)
        {
            se.insert(A[i]);
            size++;
            if (size == se.size())
            {
                s = s + A[i];
            }
            else
            {
                s = s + '#';
                size--;
            }
        }
        return s;
    }
};

string FirstNonRepeating(string A)
{
    // Code here
    map<char, int> isvisited;
    queue<char> q;
    string s = "";
    for (int i = 0; i < A.size(); i++)
    {
        if (isvisited[A[i]] <= 0)
        {
            q.push(A[i]);
            isvisited[A[i]] = 1;
        }
        else
        {
            isvisited[A[i]]++;
            while (!q.empty() && isvisited[q.front()] > 1)
            {
                q.pop();
            }
        }
        if (q.empty())
            s = s + '#';
        else
            s = s + q.front();
    }
    return s;
}

class Solution
{
public:
    int firstUniqChar(string s)
    {
        map<char, int> isvisited;
        queue<pair<char, int>> q;

        for (int i = 0; i < s.size(); i++)
        {
            isvisited[s[i]]++;
            q.push(make_pair(s[i], i));
            while (!q.empty() && isvisited[q.front().first] > 1)
            {
                q.pop();
            }
        }
        if (q.empty())
            return -1;
        return q.front().second;
    }
};

class Solution
{
    bool checkIt(string s1, string s2, string s3)
    {
        if (s1.empty() && s2.empty() && s3.empty())
            return true;
        if (s1.empty())
            return s2 == s3;
        if (s2.empty())
            return s1 == s3;

        if (s3[0] == s1[0] && s3[0] == s2[0])
        {
            if (s1.size() == 1)
                return s3 == (s1 + s2);
            if (s2.size() == 1)
                return s3 == (s2 + s1);
            return checkIt(s1.substr(1, s1.size() - 1), s2, s3.substr(1, s3.size() - 1)) || checkIt(s1, s2.substr(1, s2.size() - 1), s3.substr(1, s3.size() - 1));
        }
        if (s3[0] == s1[0])
        {
            cout << (s1 + s2) << " z " << s3;
            if (s1.size() == 1)
                return s3 == (s1 + s2);
            return checkIt(s1.substr(1, s1.size() - 1), s2, s3.substr(1, s3.size() - 1));
        }
        if (s2[0] == s3[0])
        {
            cout << (s2 + s1) << " y " << s3;
            if (s2.size() == 1)
                return s3 == (s2 + s1);
            checkIt(s1, s2.substr(1, s2.size() - 1), s3.substr(1, s3.size() - 1));
        }
        return false;
    }

public:
    bool isInterleave(string s1, string s2, string s3)
    {
        return checkIt(s1, s2, s3);
    }
};
int main()
{
    Solution s;
    // cout<<s.isInterleave("aabcc","dbbca","aadbbcbcac");

    stack<int> x;

    return 0;
}

class NumArray
{

    vector<int> sum;

public:
    NumArray(vector<int> &nums)
    {

        sum.push_back(nums[0]);
        for (int i = 0; i < nums.size() - 1; i++)
        {
            sum.push_back((sum[i] + nums[i + 1]));
        }
    }

    int sumRange(int left, int right)
    {

        if (left == 0)
            return sum[right];

        return sum[right] - sum[left - 1];
    }
};

class Solution
{

public:
    void traverse(queue<vector<int>> q)
    {
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
    {
        int n = people.size();

        vector<vector<int>> arr(n, vector<int>(2, -1));
        sort(people.begin(), people.end());
        int x;
        for (int i = 0; i < n; i++)
        {
            x = people[i][1];
            for (int j = 0; j <= x; j++)
            {
                if (arr[j][0] >= 0 && arr[j][0] != people[i][0])
                {
                    x++;
                }
            }
            arr[x] = people[i];
        }
        return arr;
    }
};

class Solution
{
public:
    vector<int> sumEvenAfterQueries(vector<int> &nums, vector<vector<int>> &queries)
    {

        int sum = 0;
        int n = nums.size();
        int m = queries.size();
        int x;
        vector<int> ans(m);
        for (int i = 0; i < n; i++)
        {

            if ((nums[i] % 2) == 0)
            {
                sum += nums[i];
            }
        }
        for (int i = 0; i < m; i++)
        {
            x = nums[queries[i][1]] + queries[i][0];

            if ((nums[queries[i][1]] % 2) == 0)
            {
                sum -= nums[queries[i][1]];
            }
            if ((x % 2) == 0)
            {
                sum += x;
            }
            nums[queries[i][1]] = x;
            ans[i] = sum;
        }
        return ans;
    }
};

class Solution
{

public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>> &queens, vector<int> &king)
    {
        map<int, bool> haveIt;
        int count = 0;
        vector<vector<int>> pos;
        for (auto queen : queens)
        {
            if (queen[0] == king[0])
            {
                if (queen[0] < king[0])
                {
                    haveIt[6] == true ? count : count++;
                    haveIt[6] = true;
                }
                else if (queen[0] > king[0])
                {
                    haveIt[2] == true ? count : count++;
                    haveIt[2] = true;
                }
            }
            else if (queen[1] == king[1])
            {
                if (queen[1] < king[1])
                {
                    haveIt[0] == true ? count : count++;
                    haveIt[0] = true;
                }
                else if (queen[1] > king[1])
                {
                    haveIt[4] == true ? count : count++;
                    haveIt[4] = true;
                }
            }
            else if (queen[0] - queen[1] == king[0] - king[1])
            {
                if (queen[0] < king[0] && queen[1] < king[1])
                {
                    haveIt[7] == true ? count : count++;
                    haveIt[7] = true;
                }
                else if (queen[0] > king[0] && queen[1] > king[1])
                {
                    haveIt[3] == true ? count : count++;
                    haveIt[3] = true;
                }
                else if (queen[0] < king[0] && queen[1] > king[1])
                {
                    haveIt[5] == true ? count : count++;
                    haveIt[5] = true;
                }
                else if (queen[0] > king[0] && queen[1] < king[1])
                {
                    haveIt[1] == true ? count : count++;
                    haveIt[1] = true;
                }
            }
        }
    }
};

class Solution
{

public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>> &queens, vector<int> &king)
    {
        map<int, bool> haveIt;
        int count = 0;
        vector<vector<int>> pos(8, vector<int>(2, -1));
        for (auto queen : queens)
        {
            if (queen[0] == king[0])
            {
                if (queen[0] < king[0])
                {
                    if (haveIt[6] == true)
                    {
                        if (pos[6][0] < queen[0])
                        {
                            pos[6] = queen;
                        }
                        break;
                    }
                    pos[6] = queen;
                    haveIt[6] = true;
                }
                else if (queen[0] > king[0])
                {
                   if (haveIt[2] == true)
                    {
                        if (pos[2][0] > queen[0])
                        {
                            pos[2] = queen;
                        }
                        break;
                    }
                    pos[2] = queen;
                    haveIt[2] = true;
                }
            }
            else if (queen[1] == king[1])
            {
                if (queen[1] < king[1])
                {
                     if (haveIt[0] == true)
                    {
                        if (pos[0][0] > queen[0])
                        {
                            pos[0] = queen;
                        }
                        break;
                    }
                    pos[0] = queen;
                    haveIt[0] = true;
                }
                else if (queen[1] > king[1])
                {
                    if (haveIt[4] == true)
                    {
                        if (pos[4][0] < queen[0])
                        {
                            pos[4] = queen;
                        }
                        break;
                    }
                    pos[4] = queen;
                    haveIt[4] = true;
                }
            }
            else if (queen[0] - queen[1] == king[0] - king[1])
            {
                if (queen[0] < king[0] && queen[1] < king[1])
                {
                    haveIt[7] == true ? count : count++;
                     if (haveIt[7] == true)
                    {
                        if (queen[0] > pos[7][0] && queen[1] > pos[7][1])
                        {
                            pos[7] = queen;
                        }
                        break;
                    }
                    pos[7] = queen;
                    haveIt[7] = true;
                }
                else if (queen[0] > king[0] && queen[1] > king[1])
                {
                    if (haveIt[3] == true)
                    {
                        if (queen[0] < pos[3][0] && queen[1] < pos[3][1])
                        {
                            pos[3] = queen;
                        }
                        break;
                    }
                    pos[3] = queen;
                    haveIt[3] = true;
                }
                else if (queen[0] < king[0] && queen[1] > king[1])
                {
                    if (haveIt[5] == true)
                    {
                        if (queen[0] > pos[5][0] && queen[1] < pos[5][1])
                        {
                            pos[5] = queen;
                        }
                        break;
                    }
                    pos[5] = queen;
                    haveIt[5] = true;
                }
                else if (queen[0] > king[0] && queen[1] < king[1])
                {
                    if (haveIt[1] == true)
                    {
                        if (queen[0] < pos[1][0] && queen[1] > pos[1][1])
                        {
                            pos[1] = queen;
                        }
                        break;
                    }
                    pos[1] = queen;
                    haveIt[1] = true;
                }
            }
        }
        vector<vector<int>> ans;
        for(int i=0;i<8;i++){
            if(haveIt[i]==true){
                ans.push_back(pos[i]);
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<int>> ans;
        int arr[]={-1,0,1};
        int coX,coY;
        vector<int> temp;
        for(auto x:arr){
            for(auto y:arr){
                for(int i=0;i<8;i++){
                    coX=king[0]+(x*i);
                    coY=king[1]+(y*i);
                    temp={coX,coY};
                   if(find(queens.begin(),queens.end(),temp)!=queens.end()){
                    ans.push_back(temp);
                   }
                    
                }
            }
        }
        return ans;
    }
};











class NQueue
{
    int *arr;
    int *next;
    int *top;
    int *rear;
    int freSpace;

public:
    // Initialize your data structure.
    NQueue(int N, int S)
    {
        // Write your code here.
        arr = new int(S);
        top = new int(N);
        rear = new int(N);
        next = new int(S);
        freSpace = 0;
        for (int i = 0; i < N; i++)
        {
            top[i] = -1;
            rear[i] = -1;
        }
        for (int i = 0; i < S - 1; i++)
        {
            next[i] = i + 1;
        }
        next[S - 1] = -1;
    }

    // Enqueues 'X' into the Mth queue. Returns true if it gets pushed into the queue, and false otherwise.
    bool enqueue(int x, int m)
    {
        // Write your code here.
        if (freSpace == -1)
            return false;
        int index;
        index = freSpace;
        freSpace = next[index]; // next of free space;
        if (top[m] == -1)
        {
            top[m - 1] = rear[m - 1];
        }
        else
        {
            next[rear[m - 1]] = index;
        }

        rear[m - 1] = index;
        next[rear[m - 1]] = -1;
        arr[index] = x;

        return true;
    }

    // Dequeues top element from Mth queue. Returns -1 if the queue is empty, otherwise returns the popped element.
    int dequeue(int m)
    {
        // Write your code here.
        if (top[m - 1] == -1)
            return -1;
        int temp = top[m - 1];
        top[m - 1] = next[temp];
        next[temp] = freSpace;
        freSpace = temp;
        return arr[temp];
    }
};