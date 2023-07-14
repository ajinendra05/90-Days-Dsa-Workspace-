#include <bits/stdc++.h>

using namespace std;




class compare{
    public:
    bool operator()(pair<int,int> p1,pair<int,int> p2){
        return p1.second>p2.second;
    }
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int,int> m;
        for(auto x:nums)
            m[x]++;
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,compare> pq;

        int i=0;

        for(auto x: m){
            if(i<k){
                pq.push(make_pair(x.first,x.second));
            }else{
                if(pq.top().second<x.second){
                    pq.pop();
                    pq.push(make_pair(x.first,x.second));
                }
            }
            i++;
        }
        vector<int> ans;
        for(int i=0;i<k;i++){
            ans.push_back(pq.top().first);
            pq.pop();
        }
        return ans;
    }
};



class MedianFinder { 
    priority_queue<int> maxQ;
    priority_queue<int,vector<int>,greater<int>> minQ;
    double medium;
public:
    MedianFinder() {
        this->medium=-1;
    }
    
    void addNum(int num) {
        if(maxQ.size()==minQ.size()){
            if(num>medium){
                minQ.push(num);
                medium=minQ.top()*1L;
            }else{
                maxQ.push(num);
                medium=maxQ.top()*1L;
            }
                
        }else if(maxQ.size()<minQ.size()){
            if(num>medium){
                maxQ.push(num);
                medium=(minQ.top()+maxQ.top())/2L;

            }else{
                maxQ.push(minQ.top());
                minQ.pop();
                minQ.push(num);
                medium=(minQ.top()+maxQ.top())/2L;
            }
        }else {
            if(num<medium){
                minQ.push(num);
                medium=(minQ.top()+maxQ.top())/2L;

            }else{
                minQ.push(maxQ.top());
                maxQ.pop();
                maxQ.push(num);
                medium=(minQ.top()+maxQ.top())/2L;
            }
        }
    }
    
    double findMedian() {
        
        return medium;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

class dataIndex
{
public:
    int data;
    int i;
    int j;

    dataIndex(int data, int i, int j)
    {
        this->data = data;
        this->i = i;
        this->j = j;
    }
};
class compare
{
public:
    bool operator()(dataIndex* n1,dataIndex *n2){
            return n1->data>n2->data;
    }
    
};
class Solution
{

public:
    // Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        // code here
        vector<int> ans;
        priority_queue<dataIndex*, vector<dataIndex*> , compare> pq;
        dataIndex* temp;
        for(int i=0;i<arr.size();i++){
             temp=new dataIndex(arr[i][0],i,0);
            pq.push(temp);
        }

        while(!pq.empty()){
            temp=pq.top();
            ans.push_back(temp->data);
            pq.pop();
            if(arr[temp->i].size()>temp->j+1){
                temp=new dataIndex(arr[temp->i][temp->j+1],temp->i,temp->j+1);
                pq.push(temp);
            }
        }
    }
};

// kth largest by min heap  O(k+(n-k)logk)
class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        int n = nums.size();
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i = 0; i < k; i++)
        {
            pq.push(nums[i]);
        }

        for (int i = k; i < n; i++)
        {
            if (nums[i] > pq.top())
            {
                pq.pop();
                pq.push(nums[i]);
            }
        }
        return pq.top();
    }
};
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
class Solution
{
    bool check(int index, int total, Node *node, int prevVal)
    {
        if (node == NULL)
            return true;

        if (node->data <= prevVal)
            return false;

        if (node->left)
        {
        }
        if (node->right)
        {
        }
    }

public:
    bool isHeap(struct Node *tree)
    {
        // code here
        int total = 1;
        int index = 1;
        queue<Node *> q;
        q.push(tree);
        int size;
        Node *temp;

        while (!q.empty())
        {
            size = q.size();
            for (int i = 0; i < size; i++)
            {
                temp = q.front();
                q.pop();

                index++;
                if (temp->left)
                {
                    if (temp->left->data >= temp->data)
                        return false;

                    total++;
                    if (index > total)
                        return false;
                    q.push(temp->left);
                }

                index++;
                if (temp->right)
                {
                    if (temp->right->data >= temp->data)
                        return false;
                    total++;
                    if (index > total)
                        return false;
                    q.push(temp->right);
                }
            }
        }
        return true;
    }
};

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        int n = nums.size();
        int x = (n - k) + 1; // xth smallest =kth largest= n-k+1 smallest
        priority_queue<int> pq;

        for (int i = 0; i < x; i++)
        {
            pq.push(nums[i]);
        }

        for (int i = x; i < n; i++)
        {
            if (nums[i] < pq.top())
            {
                pq.pop();
                pq.push(nums[i]);
            }
        }
        return pq.top();
    }
};

// kth smallest

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        int n = nums.size();
        priority_queue<int> pq;

        for (int i = 0; i < k; i++)
        {
            pq.push(nums[i]);
        }

        for (int i = k; i < n; i++)
        {
            if (nums[i] < pq.top())
            {
                pq.pop();
                pq.push(nums[i]);
            }
        }
        return pq.top();
    }
};