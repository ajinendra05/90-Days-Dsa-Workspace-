#include<bits/stdc++.h>

using namespace std;


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
                if(x==t)
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


    queue<pair<int,int>> q;
    vector<int> visited(n);
    vector<int> ans(n);

    q.push({s,0});
    visited[s] = 1;
    ans[s]=0;
    int level=0;

    while (!q.empty())
    {   
        level=q.front().second+1;
        int front = q.front().first;
        q.pop();
        for (int x : adj[front])
        {
            if (visited[x] == 0)
            {   
                ans[x]=level;
                visited[x] = 1;
                q.push({x, level});
            }
        }
    }

    return ans;
}


class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int n,int m, int s){
        // code here
        vector<vector<int>> adj(n);
    for (auto x : edges)
    {
        adj[x[0]].push_back(x[1]);
        adj[x[1]].push_back(x[0]);
    }

    queue<pair<int,int>> q;
    vector<int> visited(n);
    vector<int> ans(n, -1);

    q.push({s,0});
    visited[s] = 1;
    ans[s]=0;
    int level=0;

    while (!q.empty())
    {   
        level=q.front().second+1;
        int front = q.front().first;
        q.pop();
        for (int x : adj[front])
        {
            if (visited[x] == 0)
            {   
                ans[x]=level;
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
    void traverse(vector<pair<int, int>> adj[], int ind, stack<int> &topo, int &k, vector<int> &visited){
        visited[ind] = 1;

        for(auto x: adj[ind]){
            if(visited[x.first] == 0){
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
        int k=N-1;
        

        //find topo sort order
        // O(N)
        for(int i=0; i<N; i++){
            if(visited[i]==0)
                traverse(adj, 0, topo, k, visited);

        }
        

        // step 2 count distance of every node

        dist[0]=0;
        //O(M)
        while(!topo.empty()){
            int i=topo.top();
            topo.pop();

            if(dist[i]!=-1)
                for(auto x: adj[i])
                    dist[x.first]=min(dist[x.first], dist[i]+x.second);
                
            
        }
        
        return dist;
    }
};
class Solution
{
    void traverse(vector<pair<int, int>> adj[], int ind, vector<int> &topo, int &k, vector<int> &visited){
        visited[ind] = 1;

        for(auto x: adj[ind]){
            if(visited[x.first] == 0){
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
        int k=N-1;
        

        //find topo sort order
        // O(N)
        for(int i=0; i<N; i++){
            if(visited[i]==0)
                traverse(adj, 0, topo, k, visited);

        }
        

        // step 2 count distance of every node

        dist[0]=0;
        //O(M)
        for(int i = 0; i<N; i++){
            if(dist[i]!=INT_MAX){
                for(auto x: adj[i]){
                    dist[x.first]=min(x.first,dist[i]+x.second);
                }
            }
        }
        
        return dist;
    }
};


// Dijkstra's  algo
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        using ip = pair<int, int>;
        vector<vector<ip>> adj(n + 1);
        for (auto& t : times) adj[t[0]].push_back({t[1], t[2]});
        
        //start
        priority_queue<ip, vector<ip>, greater<ip>> pq;
        vector<int> dist(n + 1, INT_MAX);
        vector<bool> visited(n + 1, false);

        pq.push({0, k});
        dist[k] = 0;

        while (!pq.empty()) {
            auto [n_cost, node] = pq.top();
            pq.pop();

            visited[node] = true;
            if (dist[node] < n_cost) continue;  // Optimization: skip node if we already find better option.
            
            for (auto& [next, cost] : adj[node]) {
                if (visited[next] == true) continue; // Optimization: do not re-visit nodes.
                if (dist[next] > dist[node] + cost) {
                    dist[next] = dist[node] + cost;
                    pq.push({dist[next], next});
                }
            }
        }
        int res = 0;
        for_each(dist.begin() + 1, dist.end(), [&](int d) {
            res = max(res, d);
        });
        return res == INT_MAX ? -1 : res;
    }
};
class Solution {
public:
    void Dijkstras(vector<vector<int>>& times, int n, int k) {
        using ip = pair<int, int>;
        vector<vector<ip>> adj(n + 1);
        for (auto& t : times) adj[t[0]].push_back({t[1], t[2]});
        
        //start
        priority_queue<ip, vector<ip>, greater<ip>> pq;
        vector<int> dist(n + 1, INT_MAX);
        vector<bool> visited(n + 1, false);

        pq.push({0, k});
        dist[k] = 0;

        while (!pq.empty()) {
            auto [n_cost, node] = pq.top();
            pq.pop();

            visited[node] = true;
            
            for (auto& [next, cost] : adj[node]) {
                if (visited[next] == true) continue; // Optimization: do not re-visit nodes.
                if (dist[next] > n_cost + cost) {
                    dist[next] = n_cost + cost;
                    pq.push({dist[next], next});
                }
            }
        }
       
    }
};
class Solution
{

public:
    vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
    {
        vector<pair<int, int>> adj[N];

        for (auto x : edges)        //O(e)
            adj[x[0]].push_back({x[1], x[2]});
        

        vector<int> dist(N,INT_MAX);
        set<pair<int,int>> st;

        st.insert({0,0});
        dist[0]=0;

        while(!st.empty()){
            auto ele= *st.begin();

            int d=ele.first;
            int i=ele.second;

            st.erase(st.begin());

            for(auto x: adj[i]){
                int adjN=x.first;
                int edgW=x.second;

                if(edgW+d < dist[adjN]){

                    if(dist[adjN]!=INT_MAX)
                        st.erase({dist[adjN],adjN});
                    
                    dist[adjN]=edgW+d;
                    st.insert({dist[adjN],edgW});
                }
            }
        }
        return dist;
    }
};
class Solution
{

public:
    vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
    {
        vector<pair<int, int>> adj[N];

        for (auto x : edges)        //O(e)
        {
            adj[x[0]].push_back({x[1], x[2]});
        }

        vector<int> dist(N,INT_MAX);
        set<pair<int,int>> st;

        st.insert({0,0});
        dist[0]=0;

        while(!st.empty()){
            auto ele= *st.begin();

            int d=ele.first;
            int i=ele.second;

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
            for(auto x: adj[i]){
                int adjN=x.first;
                int edgW=x.second;

                if(edgW+d<dist[adjN]){

                    if(dist[adjN]!=INT_MAX)
                        st.erase({dist[adjN],adjN});
                    
                    dist[adjN]=edgW+d;
                    st.insert({dist[adjN],edgW});
                }
            }
        }
        return dist;
    }
};

// BELLMON FORD O(n*e)
class Solution {
  public:
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        vector<int> dist(V, 1e8);
        dist[S] = 0;
        for(int i=0; i<V-1; i++){
            for(auto x: edges){
                int u = x[0];
                int v = x[1];
                int edW = x[2];

                if(dist[u] + edW < dist[v])
                    dist[v] = dist[u] + edW;
            }
        }

        return dist;
    }
};


// floyd warshell  O(n3)  O(n2)
class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    // Code here
	    int n= matrix.size();
	    
	     for(int i=0; i<n; i++){
	        for(int j=0; j<n; j++){
	            if(matrix[i][j] == -1)
	                matrix[i][j] = 1e9;
	        }
	    }
	    
	    
	    for(int k=0; k<n; k++)
	    for(int i=0; i<n; i++){
	        for(int j=0; j<n; j++){
                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
	        }
	    }
	    
        for(int i=0; i<n; i++)
            if(matrix[i][i] < 0)
               cout<<"negetive cycle present";


	     for(int i=0; i<n; i++){
	        for(int j=0; j<n; j++){
	          if(matrix[i][j] == 1e9)
	                matrix[i][j] = -1;
	        }
	    }
	}
};
//prim's algo
class Solution         //O(v2 * logv)  // o(elogv) we check for each edge only once and than decrease/add it
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.   
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
       
        vector<int> visited(V, 0);
        set<pair<int, int>> st; //{edgw, v, u}
        int sum = 0;
        
        st.insert({0, 0});
        

        // O(v)
        while(!st.empty()){

            //log(v)
            int node = (*st.begin()).second;
            int edgW = (*st.begin()).first;
            st.erase(st.begin());
            
            if(visited[node] == 1){
                continue;
            }
            sum += edgW;
            visited[node] = 1;
            
            // o(v logV)
            for(auto x: adj[node]){
              if(visited[x[0]] == 0)  st.insert({x[1], x[0]});    
            }
            
            
        }
        return sum;
    }
};
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
       
        vector<int> visited(V, 0);
        set<pair<int, pair<int, int>>> st; //{edgw, v, u}
        int sum = 0;
        
        st.insert({-1 ,{0, 0}});
        
        while(!st.empty()){
            int node = (*st.begin()).second.first;
            int parent = (*st.begin()).second.second;
            int edgW = (*st.begin()).first;
            st.erase(st.begin());
            
            if(visited[node] == 1){
                continue;
            }
            if(edgW != -1) sum += edgW;
            visited[node] = 1;
            
            for(auto x: adj[node]){
                st.insert({x[0], {x[1], node}});    
            }
            
            
        }
        return sum;
    }
};

//kruskal's algo
class disjoint{
    vector<int> rank, parents;  

    public:
        disjoint(int size){
            rank.resize(size+1, 0);
            parents.resize(size+1);
            
            for(int i=0; i<= size; i++){
                parents[i] = i;
            }
        }

        // find parent + pathcompression
        int findPar(int node){
            if(node<parents.size() && parents[node] == node)
                return node;

            return parents[node] = findPar(parents[node]);    
        }

        //union by rank
        void unionRank(int u, int v){
            int ulp_u = findPar(u);
            int ult_v = findPar(v);

            if(ult_v == ulp_u){
                return ;
            }

            if(rank[ult_v] < rank[ulp_u]){
                parents[ulp_u] = ult_v;
                return ;
            }

            if(rank[ult_v] > rank[ulp_u]){
                parents[ult_v] = ulp_u;
                return ;
            }

            parents[ult_v] = ulp_u;
            rank[ult_v]++;
            return ;
            
        }
};

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<pair<int, pair<int, int>>> edges;
        for(int i=0; i<V; i++){              //o(e)
            for(auto it: adj[i]){
                int u = i;
                int v = it[0];
                int edgW = it[1];
                
                edges.push_back({edgW, {u, v}});
            }
        }
        sort(edges.begin(), edges.end());      //o(eloge)
        
        int mst = 0;
        disjoint d(V);
          
        for(auto it: edges){                      //o(e * 4alpha)
            int node = it.second.first;
            int adjNode = it.second.second;
            int weight = it.first;
            
            if(d.findPar(node) != d.findPar(adjNode)){
                d.unionRank(node, adjNode);
                mst += weight;
            }
        }
        return mst;
    }
};


//Topological Sort [DAG, DFS, T: O(n+e), S: O(n)]
class Solution
{ 
    void traverse(vector<int> adj[],  vector<int> &ans, int visited[],int index,int &k){
        visited[index]=1;

        for(int i=0; i<adj[index].size(); i++){
            if(visited[adj[index][i]]==0)
                traverse(adj,ans,visited,adj[index][i],k);
        }

        ans[k--]=index;
    }
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
        vector<int> ans(V);
        int visited[V]={0};
        int k=V-1;
        for(int i=0; i<V; i++){
            if(visited[i]==0)
                traverse(adj,ans,visited,i,k);
        }
        return ans;
	}
};
class Solution
{ 
    void traverse(vector<int> adj[],  vector<int> &ans, int visited[],int index,int &k){
        visited[index]=1;

        for(int i=0; i<adj[index].size(); i++){
            if(visited[index]==0)
                traverse(adj,ans,visited,index,k);
        }

        ans[k--]=index;
    }
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
        vector<int> ans(V);
        int visited[V];
        int k=V-1;
        for(int i=0; i<V; i++){
            if(visited[i]==0)
                traverse(adj,ans,visited,i,k);
        }
        return ans;
	}
};


//topological sort by BFS [kahn's algorithm]:    O(n+e) O(n)
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
        vector<int> indegree(V);
        queue<int> q;
        vector<int> ans;

        for(int i=0; i<V; i++){
            for(int x: adj[i])
                indegree[x]++;
        }
        
        for(int i=0; i<V; i++){
            if(indegree[i]==0)
                q.push(i);
        }
        
        while(!q.empty()){
            int front=q.front();
            q.pop();
            ans.push_back(front);
            for(int i=0; i<adj[front].size(); i++){
                indegree[adj[front][i]]--;
                if(indegree[adj[front][i]]==0)
                    q.push(adj[front][i]);
            }
        }
        return ans;
	}
};



class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        unordered_map<int, bool> isVisited;
        vector<int> ans;
        queue<int> q;
        q.push(0);
        isVisited[0]=true;

        while(!q.empty()){
            int ind=q.front();
            q.pop();
            ans.push_back(ind);
            for(auto x:adj[ind]){
                if(isVisited[x]==false){
                    isVisited[x]=true;
                    q.push(x);
                }
            }
        }
        return ans;

    }
};


class Solution {
    void dfs(int V, vector<int> adj[],unordered_map<int,int> &visited,vector<int> &ans,int index){
        if(visited[index]==true)
            return ;

        visited[index]=true;
        ans.push_back(index);
        for(int i=0;i<adj[index].size();i++){
                dfs(V,adj,visited,ans,adj[index][i]);
        }    
    }
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        unordered_map<int,int> isVisited;
        vector<int> ans;
        dfs(V,adj,isVisited,ans,0);
        return ans;
    }
};


//Cycle detection in undirected graph
// Cycle detection with BFS
class Solution {
    bool detectCycleInComponent(int V, vector<int> adj[], unordered_map<int,bool> &isVisited,int start){
        isVisited[start] = true;
        queue<pair<int,int>> q;
        q.push(make_pair(start, -1));

        while(!q.empty()){
            int ele = q.front().first;
            int parents = q.front().second;

            for(int x: adj[ele]){
                if(isVisited[x] == true){
                    if(x != parents)
                    return true;
                }else{
                    q.push(make_pair(x, ele));
                    isVisited[x] = true;
                }
            }
        }
        return false;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here

        //if components are present
        unordered_map<int,bool> isvisited;

        for(int i=0; i<V; i++){
            if(isvisited[i] == false)
               if(detectCycleInComponent(V,adj,isvisited,i))
                 return true;
        }
        return false;
    }
};

//cycle detection with dfs
class Solution {
    bool traverseGraph(vector<int> adj[],int vis[],int index,int prev){
        vis[index]=1;

        for(int x: adj[index]){
            if(vis[x]==1){
                if(x!=prev)
                    return true;
            }else{
                if(traverseGraph(adj,vis,x,index))
                    return true;
            }
        }
        return false;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        int isVisited[V];
        for(int i=0; i<V; i++){
            if(isVisited[i]!=1){
                if(traverseGraph(adj,isVisited,i,-1))
                    return true;
            }
        }
        return false;
    }
};


// cycle detection in directed graph
// with DFS 
class Solution {

    bool traverse(vector<int> adj[], int visited[], int pathVisited[], int index){
        visited[index]=1;
        pathVisited[index]=1;

        for(int x: adj[index]){
            if(pathVisited[x]==1)
                return true;
            if(visited[x]==0){
                if(traverse(adj,visited,pathVisited,x))
                    return true;
            }
        }
        pathVisited[index]=0;
        return false;
    }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        // unordered_map<int,bool> visited;
        // unordered_map<int,bool> pathVisited;
        
        int visited[V]={0};
        int pathVisited[V]={0};
        for(int i=0;i<V;i++){
            if(visited[i]==false){
                if(traverse(adj,visited,pathVisited,i))
                    return true;
            }
        }
        return false;
    }
};  

class Solution {

    bool traverse(vector<int> adj[], map<int,bool> &visited, map<int,bool> &pathVisited,int index){
        visited[index]=true;
        pathVisited[index]=true;

        for(int x: adj[index]){
            if(pathVisited[x]==true)
                return true;
            if(visited[x]==false){
                if(traverse(adj,visited,pathVisited,index))
                    return true;
            }
        }
        pathVisited[index]=false;
        return false;
    }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        map<int,bool> visited;
        map<int,bool> pathVisited;

        for(int i=0;i<V;i++){
            if(visited[i]==false){
                if(traverse(adj,visited,pathVisited,i))
                    return true;
            }
        }
        return false;
    }
};

//cycle deteciton in directed graph With BFS, Khan's algo

class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	bool topoSort(int V, vector<int> adj[]) 
	{
	    // code here
        vector<int> indegree(V);
        queue<int> q;
        vector<int> ans;

        for(int i=0; i<V; i++){
            for(int x: adj[i])
                indegree[x]++;
        }
        
        for(int i=0; i<V; i++){
            if(indegree[i]==0)
                q.push(i);
        }
        
        int count=0;
        while(!q.empty()){
            int front=q.front();
            q.pop();
            ans.push_back(front);
            count++;

            for(int i=0; i<adj[front].size(); i++){
                indegree[adj[front][i]]--;
                if(indegree[adj[front][i]]==0)
                    q.push(adj[front][i]);
            }
        }
        return count==V;
	}
};


// kosjaru's algo
class Solution
{   
    
     void traverse(vector<vector<int>> &adj, int visited[], int index,bool flag ,stack<int> &s){
        visited[index]=1;

        for(int x: adj[index]){
            if(visited[x]==0 ){
                traverse(adj,visited,x, flag, s);
                   
            }
        }
        
        if(flag) s.push(index);
        return ;
    }
    
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    { 
        stack<int> s;
        
        int visited[V] = {0};
        for(int i=0 ; i<V; i++){
            if(visited[i] == 0){
                 traverse(adj, visited, 0, true, s);
            }
        }
        vector<vector<int>> adjT(V);
        
        for(int i=0 ; i<V; i++){
           visited[i] = 0;
           for(int it: adj[i])
            adjT[it].push_back(i);
        }
        int count = 0;
        while(!s.empty()){
            int top = s.top();
            s.pop();
            
            if(visited[top] == 0){
                count++;
                traverse(adjT, visited, top, false, s);
                
            }
        }
        return count;
    }
};







template<typename T>
class Graph{
public:
unordered_map<T, vector<T>> adjacencyList;

void addEdge(T u, T v, int direction){
    //direction 0 for undirected, 1 for directed;

    adjacencyList[u].push_back(v);
    if(direction == 0)
        adjacencyList[v].push_back(u);
}

void printGraphEdges(){
 
    for(auto x: adjacencyList){
        cout<<endl<<x.first<<"--->";
        for(auto z: x.second){
            cout<<" "<<z;

        }
      
    }
}

};
/*
4 5 0 1 1 2 2 3 3 1 3 4 0 4
5 6 0 1 1 2 2 3 3 1 3 4 0 4
*/

int main(){
    Graph<int> g;
    int n,m;
    cout<<"Enter number of nodes and edge with space";
    cin>>n>>m;
    
    int u,v;
    for(int i=0; i<m; i++){
        cout<<"Enter node1 : ";
        cin>>u;
        cout<<"Enter node2 : ";
        cin>>v;
        g.addEdge(u,v,0);
    }
    
    g.printGraphEdges();
    return 0;
}