#include <bits/stdc++.h>

using namespace std;

#define mod 100000

#define MOD 1000000007;

class Solution
{
    void helper(int node,int parent, vector<int> adj[], int inTime[],int low[], vector<vector<int>> &ans,int &time)
    {
        inTime[node] = time;
        low[node] = time;
        time++;

        for(int x: adj[node]){
            if(x == parent) continue;
            if(inTime[x] != 0){
                low[node] = min(low[node], low[x]);
            }else{
                helper(x, node, adj, inTime, low, ans, time);
                low[node] = min(low[node], low[x]);
                if(low[x] > inTime[node]){
                    ans.push_back({node, x});
                }
            }
        }
        
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
    {
        vector<vector<int>> ans;
        int insertTime[n] = {0};
        int low[n];
        vector<int> adj[n];
        int time = 1;
        for (auto x : connections)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }

        for (int i = 0; i < n; i++)
        {
            if (insertTime[i] == 0)
                helper(i, -1,  adj, insertTime, low, ans, time);
        }

        return ans;
    }
};
class Solution
{

    void traverse(vector<vector<int>> &adj, int visited[], int index, bool flag, stack<int> &s)
    {
        visited[index] = 1;

        for (int x : adj[index])
        {
            if (visited[x] == 0)
            {
                traverse(adj, visited, x, flag, s);
            }
        }

        if (flag)
            s.push(index);
        return;
    }

public:
    // Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>> &adj)
    {
        stack<int> s;

        int visited[V] = {0};
        for (int i = 0; i < V; i++)
        {
            if (visited[i] == 0)
            {
                traverse(adj, visited, 0, true, s);
            }
        }
        vector<vector<int>> adjT(V);

        for (int i = 0; i < V; i++)
        {
            visited[i] = 0;
            for (int it : adj[i])
                adjT[it].push_back(i);
        }
        int count = 0;
        while (!s.empty())
        {
            int top = s.top();
            s.pop();

            if (visited[top] == 0)
            {
                count++;
                traverse(adjT, visited, top, false, s);
            }
        }
        return count;
    }
};
class Solution
{
public:
    int countPaths(int n, vector<vector<int>> &roads)
    {
        vector<pair<int, int>> adj[n];

        for (auto x : roads)
        {
            adj[x[0]].push_back({x[1], x[2]});
            adj[x[1]].push_back({x[0], x[2]});
        }

        vector<pair<int, int>> time(n, {1e9, 0});
        set<pair<int, int>> st;
        int ans = 0;

        st.insert({0, 0});
        time[0] = {0, 1};

        while (!st.empty())
        {
            int node = (*st.begin()).second;
            int tm = (*st.begin()).first;
            int count = time[node].second;

            st.erase(st.begin());
            for (auto x : adj[node])
            {
                int child = x.first;
                int edjW = x.second;
                if (tm + edjW < time[child].first)
                {
                    time[child] = {tm + edjW, count};
                    st.insert({tm + edjW, child});
                }
                else if (tm + edjW == time[child].first)
                {
                    time[x.first].second = (time[x.first].second + count) % MOD;
                }
            }
        }
        return time[n - 1].second;
    }
};
class Solution
{
public:
    int countPaths(int n, vector<vector<int>> &roads)
    {
        vector<pair<int, int>> adj[n];

        for (auto x : roads)
        {
            adj[x[0]].push_back({x[1], x[2]});
            adj[x[1]].push_back({x[0], x[2]});
        }

        vector<pair<int, int>> time(n, {1e9, 0});
        set<pair<int, int>> st;
        int ans = 0;

        st.insert({0, 0});
        time[0] = {0, 1};

        while (!st.empty())
        {
            int node = (*st.begin()).second;
            int tm = (*st.begin()).first;
            st.erase(st.begin());
            for (auto x : adj[node])
            {
                if (tm + x.second < time[x.first].first)
                {
                    time[x.first] = {tm + x.second, time[node].second};
                    st.insert({tm + x.second, x.first});
                }
                else if (tm + x.second == time[x.first].first)
                {
                    time[x.first].second++;
                }
            }
        }
        return time[n - 1].second;
    }
};

class Solution
{
public:
    int countPaths(int n, vector<vector<int>> &roads)
    {
        vector<pair<int, int>> adj[n];

        for (auto x : roads)
        {
            adj[x[0]].push_back({x[1], x[2]});
            adj[x[1]].push_back({x[0], x[2]});
        }

        vector<int> time(n, 1e9);
        set<pair<int, int>> st;
        int ans = 0;

        st.insert({0, 0});
        time[0] = 0;

        while (!st.empty())
        {
            int node = (*st.begin()).second;
            int tm = (*st.begin()).first;
            st.erase(st.begin());

            for (auto x : adj[node])
            {
                if (x.first == n - 1)
                {
                    if (tm + x.second == time[n - 1])
                    {
                        ans++;
                    }
                    else if (tm + x.second < time[n - 1])
                    {
                        ans = 1;
                        time[n - 1] = tm;
                    }
                }
                if (tm + x.second < time[x.first])
                {
                    time[x.first] = tm + x.second;
                    st.insert({tm + x.second, x.first});
                    cout << time[x.first] << " " << x.first;
                }
            }
        }
        return ans;
    }
};
//  minimum multiplication
class Solution
{
public:
    int minimumMultiplications(vector<int> &arr, int start, int end)
    {
        // code here
        // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int> > pq;
        if (start == end)
            return 0;
        set<pair<int, int>> st;
        vector<int> steps(mod, 1e9);

        st.insert({0, start});
        steps[start] = 0;

        while (!st.empty())
        {
            int val = (*st.begin()).second;
            int stp = (*st.begin()).first;
            st.erase(st.begin());

            for (int x : arr)
            {
                int mul = (x * val) % mod;

                if (mul == end)
                    return stp + 1;

                if (stp + 1 < steps[mul])
                {
                    steps[mul] = stp + 1;
                    st.insert({stp + 1, mul});
                }
            }
        }

        return -1;
    }
};
class Solution
{
    void helper(string curr, unordered_map<string, vector<string>> &parents,
                vector<vector<string>> &ans, vector<string> currList, string beginWord)
    {
        if (curr == beginWord)
        {
            currList.push_back(beginWord);
            ans.push_back(currList);
        }

        currList.push_back(curr);
        for (string x : parents[curr])
        {
            helper(x, parents, ans, currList, beginWord);
        }
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        {
            queue<pair<string, int>> q;
            unordered_set<string> st(wordList.begin(), wordList.end());
            unordered_map<string, vector<string>> parents;

            q.push({beginWord, 1});
            st.erase(beginWord);
            parents[beginWord].push_back("\0");

            // O(wordlist.size())
            while (!q.empty())
            {
                int size = q.size();
                for (int i = 0; i < size; i++)
                {
                    string word = q.front().first;
                    int steps = q.front().second;

                    if (word == endWord)
                        break;

                    q.pop();

                    // O(10 * 26 ) maxwordlength * 26
                    string node = word;
                    for (int i = 0; i < node.size(); i++)
                    {
                        char original = node[i];
                        for (char ch = 'a'; ch <= 'z'; ch++)
                        {
                            node[i] = ch;
                            if (st.find(node) != st.end() && node != word)
                            {
                                q.push({node, steps + 1});
                                parents[node].push_back(word);
                            }
                        }
                        node[i] = original;
                    }
                    st.erase(word);
                }
            }

            vector<vector<string>> ans;
            if (q.front().first == endWord)
                helper(endWord, parents, ans, {}, beginWord);

            return ans;
        }
    }
};
class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        queue<pair<string, int>> q;
        unordered_set<string> st(wordList.begin(), wordList.end());
        unordered_map<string, vector<string>> parents;

        q.push({beginWord, 1});
        st.erase(beginWord);
        parents[beginWord].push_back("\0");

        // O(wordlist.size())
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                string word = q.front().first;
                int steps = q.front().second;

                if (word == endWord)
                    break;

                q.pop();

                // O(10 * 26 ) maxwordlength * 26
                string node = word;
                for (int i = 0; i < node.size(); i++)
                {
                    char original = node[i];
                    for (char ch = 'a'; ch <= 'z'; ch++)
                    {
                        node[i] = ch;
                        if (st.find(node) != st.end() && node != word)
                        {
                            q.push({node, steps + 1});
                            parents[node].push_back(word);
                        }
                    }
                    node[i] = original;
                }
                st.erase(word);
            }
        }

        vector<string> ans;
        if (!q.empty() && q.front().first == endWord)
        {
            int pathSize = q.front().second;

            // for()
        }

        return 0;
    }
};

// ~O(n2)
// ??TLE
// class Solution {
// public:
//     int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
//         map<string, vector<string>> adj;
//         map<string, bool> visited;
//         queue<string> q;
//         q.push(beginWord);
//         int count = 0;
//         visited[beginWord] = true;

//         while(!q.empty()){
//             int size = q.size();
//             count++;

//             for(int i=0; i<size; i++){
//                 string node = q.front();
//                 q.pop();

//                 if(node == endWord)
//                     return count;
//                 for(string z: wordList){
//                     if(visited[z]) continue;
//                     if(node.size()-z.size() == 1 || node.size()-z.size() == -1){
//                         if(node.find(z) || z.find(node)){
//                             q.push(z);
//                             visited[z] = true;
//                         }
//                     }
//                     else if(node.size() == z.size()){
//                         int  k =0;
//                         for( int i=0; i<z.size(); i++){
//                             if(node[i] != z[i]) k++;
//                             if(k>1) break;
//                         }
//                         if(k == 1){
//                             q.push(z);
//                             visited[z] = true;
//                         }
//                     }
//                 }

//             }
//         }

//         return 0;

//     }
// };

// Shortest Path

// BFS Undirected+Unweigted+ Can be cyclic or not

vector<int> shortestPath(vector<pair<int, int>> edges, int n, int m, int s, int t)
{

    // Write your code here
    vector<vector<int>> adj(n);
    for (auto x : edges)
    {
        adj[x.first].push_back(x.second);
        adj[x.second].push_back(x.first);
    }

    vector<int> parent(n);
    queue<int> q;
    vector<int> visited(n);

    q.push(s);
    parent[s] = -1;
    visited[s] = 1;

    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        for (int x : adj[front])
        {
            if (visited[x] == 0)
            {
                parent[x] = front;
                visited[x] = 1;
                q.push(x);
                if (x == t)
                    break;
            }
        }
    }

    vector<int> ans;
    int curr = t;
    ans.push_back(curr);
    while (curr != s)
    {
        cout << curr;
        curr = parent[curr];
        ans.push_back(curr);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

vector<int> shortestPath2(vector<pair<int, int>> edges, int n, int m, int s, int t)
{

    // Write your code here
    vector<vector<int>> adj(n);
    for (auto x : edges)
    {
        adj[x.first].push_back(x.second);
        adj[x.second].push_back(x.first);
    }

    queue<pair<int, int>> q;
    vector<int> visited(n);
    vector<int> ans(n);

    q.push({s, 0});
    visited[s] = 1;
    ans[s] = 0;
    int level = 0;

    while (!q.empty())
    {
        level = q.front().second + 1;
        int front = q.front().first;
        q.pop();
        for (int x : adj[front])
        {
            if (visited[x] == 0)
            {
                ans[x] = level;
                visited[x] = 1;
                q.push({x, level});
            }
        }
    }

    return ans;
}

class Solution
{
public:
    vector<int> shortestPath(vector<vector<int>> &edges, int n, int m, int s)
    {
        // code here
        vector<vector<int>> adj(n);
        for (auto x : edges)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }

        queue<pair<int, int>> q;
        vector<int> visited(n);
        vector<int> ans(n, -1);

        q.push({s, 0});
        visited[s] = 1;
        ans[s] = 0;
        int level = 0;

        while (!q.empty())
        {
            level = q.front().second + 1;
            int front = q.front().first;
            q.pop();
            for (int x : adj[front])
            {
                if (visited[x] == 0)
                {
                    ans[x] = level;
                    visited[x] = 1;
                    q.push({x, level});
                }
            }
        }

        return ans;
    }
};

// DFS Only fro DAG can be weighted or not, but cycle must be absent   O(N+M)
class Solution
{
    void traverse(vector<pair<int, int>> adj[], int ind, stack<int> &topo, int &k, vector<int> &visited)
    {
        visited[ind] = 1;

        for (auto x : adj[ind])
        {
            if (visited[x.first] == 0)
            {
                traverse(adj, x.first, topo, k, visited);
            }
        }

        topo.push(ind);
        return;
    }

public:
    vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
    {
        vector<pair<int, int>> adj[N];

        for (auto x : edges)
        {
            adj[x[0]].push_back({x[1], x[2]});
        }

        stack<int> topo;
        vector<int> dist(N, -1);
        vector<int> visited(N, 0);
        int k = N - 1;

        // find topo sort order
        //  O(N)
        for (int i = 0; i < N; i++)
        {
            if (visited[i] == 0)
                traverse(adj, 0, topo, k, visited);
        }

        // step 2 count distance of every node

        dist[0] = 0;
        // O(M)
        while (!topo.empty())
        {
            int i = topo.top();
            topo.pop();

            if (dist[i] != -1)
                for (auto x : adj[i])
                    dist[x.first] = min(dist[x.first], dist[i] + x.second);
        }

        return dist;
    }
};
class Solution
{
    void traverse(vector<pair<int, int>> adj[], int ind, vector<int> &topo, int &k, vector<int> &visited)
    {
        visited[ind] = 1;

        for (auto x : adj[ind])
        {
            if (visited[x.first] == 0)
            {
                traverse(adj, x.first, topo, k, visited);
            }
        }

        topo[k--] = ind;
        return;
    }

public:
    vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
    {
        vector<pair<int, int>> adj[N];

        for (auto x : edges)
        {
            adj[x[0]].push_back({x[1], x[2]});
        }

        vector<int> topo(N);
        vector<int> dist(N, INT_MAX);
        vector<int> visited(N, 0);
        int k = N - 1;

        // find topo sort order
        //  O(N)
        for (int i = 0; i < N; i++)
        {
            if (visited[i] == 0)
                traverse(adj, 0, topo, k, visited);
        }

        // step 2 count distance of every node

        dist[0] = 0;
        // O(M)
        for (int i = 0; i < N; i++)
        {
            if (dist[i] != INT_MAX)
            {
                for (auto x : adj[i])
                {
                    dist[x.first] = min(x.first, dist[i] + x.second);
                }
            }
        }

        return dist;
    }
};

// Dijkstra's  algo

class Solution
{

public:
    vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
    {
        vector<pair<int, int>> adj[N];

        for (auto x : edges) // O(e)
        {
            adj[x[0]].push_back({x[1], x[2]});
        }

        vector<int> dist(N, INT_MAX);
        set<pair<int, int>> st;

        st.insert({0, 0});
        dist[0] = 0;

        while (!st.empty())
        {
            auto ele = *st.begin();

            int d = ele.first;
            int i = ele.second;

            st.erase(st.begin());

            // for(auto x: adj[i]){
            //     if(x.second+d<dist[x.first]){

            //         auto it= st.find(make_pair(dist[x.first],x.first));
            //         if(it!=st.end()){
            //             st.erase(it);
            //         }

            //         dist[x.first]=x.second+d;
            //         st.insert({dist[x.first],x.first});
            //     }
            // }
            for (auto x : adj[i])
            {
                int adjN = x.first;
                int edgW = x.second;

                if (edgW + d < dist[adjN])
                {

                    if (dist[adjN] != INT_MAX)
                        st.erase({dist[adjN], adjN});

                    dist[adjN] = edgW + d;
                    st.insert({dist[adjN], edgW});
                }
            }
        }
        return dist;
    }
};

class Solution
{
    bool makeIsland(vector<vector<char>> &grid, int row, int col, map<pair<int, int>, bool> &visited)
    {

        visited[{row, col}] = true;

        if (row == 0 || row == grid.size() - 1 || col == 0 || col == grid[0].size() - 1)
            return false;

        bool x1, x2, x3, x4;
        x1 = x2 = x3 = x4 = true;

        if (grid[row + 1][col] == 'O' && visited[{row + 1, col}] == false)
            x1 = makeIsland(grid, row + 1, col, visited);
        if (grid[row - 1][col] == 'O' && visited[{row - 1, col}] == false)
            x2 = makeIsland(grid, row - 1, col, visited);
        if (grid[row][col + 1] == 'O' && visited[{row, col + 1}] == false)
            x3 = makeIsland(grid, row, col + 1, visited);
        if (grid[row][col - 1] == 'O' && visited[{row, col - 1}] == false)
            x4 = makeIsland(grid, row, col - 1, visited);

        if (x1 && x2 && x3 && x4)
        {
            grid[row][col] = 'X';
            return true;
        }
        grid[row][col] = 'O';
        return false;
    }

public:
    void solve(vector<vector<char>> &board)
    {
        map<pair<int, int>, bool> visited;
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] == 'O')
                {
                    makeIsland(board, i, j, visited);
                }
            }
        }
    }
};

class Solution
{
    void makeIsland(vector<vector<char>> &grid, int row, int col)
    {

        grid[row][col] = 0;

        if (row + 1 < grid.size() && grid[row + 1][col] == '1')
            makeIsland(grid, row + 1, col);
        if (row - 1 >= 0 && grid[row - 1][col] == '1')
            makeIsland(grid, row + 1, col);
        if (col + 1 < grid[0].size() && grid[row][col + 1] == '1')
            makeIsland(grid, row + 1, col);
        if (col - 1 >= 0 && grid[row][col - 1] == '1')
            makeIsland(grid, row + 1, col);
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        int ans = 0;

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == '1')
                {
                    ans++;
                    makeIsland(grid, i, j);
                }
            }
        }
        return ans;
    }
};

class Solution
{
    void makeIsland(vector<vector<char>> &grid, map<pair<int, int>, bool> &visited, int row, int col)
    {
        // visited[{row,col}]=true;
        grid[row][col] = 0;

        if (row + 1 < grid.size() && grid[row + 1][col] == '1')
            makeIsland(grid, visited, row + 1, col);
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        int ans = 0;
        map<pair<int, int>, bool> visited;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (visited[{i, j}] == false)
                {
                }
            }
        }
    }
};

class Solution
{
public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[])
    {
        // Code here
        unordered_map<int, bool> isVisited;
        vector<int> ans;
        queue<int> q;
        q.push(0);
        isVisited[0] = true;

        while (!q.empty())
        {
            int ind = q.front();
            q.pop();
            ans.push_back(ind);
            for (auto x : adj[ind])
            {
                if (isVisited[x] == false)
                {
                    isVisited[x] = true;
                    q.push(x);
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