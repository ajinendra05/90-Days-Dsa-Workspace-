#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
#define MOD 1e9 + 7;
// A -> Top Down ( Recursion+Memorization)
// B -> Bottom Up (Tabulation)

// fibonacci  A  O(n) O(n) ~ 2n
class Solution
{
    int fibonacci(int x, vector<int> &dp)
    {
        if (x == 0 || x == 1)
            return x;
        if (dp[x] != -1)
            return dp[x];
        dp[x] = fibonacci(x - 1, dp) + fibonacci(x - 2, dp);
        return dp[x];
    }

public:
    int fib(int n)
    {
        vector<int> dp(n + 1, -1);

        return fibonacci(n, dp);
    }
};

// B O(n) O(n)
class Solution
{
public:
    int fib(int n)
    {
        if (n == 0)
            return 0;
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 1;

        for (int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

// B memory optimization O(n) O(1)
class Solution
{
public:
    int fib(int n)
    {
        if (n == 0)
            return 0;
        int x1 = 0, x2 = 1, temp;

        for (int i = 2; i <= n; i++)
        {
            temp = x1 + x2;
            x1 = x2;
            x2 = temp;
        }
        return x2;
    }
};

// 2nd que stairs mini cost
//  A O(n), O(n)
class Solution
{
    int solve(vector<int> &cost, int dp[], int n)
    {
        if (n == 0)
            return cost[0];
        if (n == 1)
            return cost[1];

        if (dp[n] != -1)
            return dp[n];

        dp[n] = cost[n] + min(solve(cost, dp, n - 1), solve(cost, dp, n - 2));
        return dp[n];
    }

public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        int dp[n] = {-1};
        int ans = min(solve(cost, dp, n - 1), solve(cost, dp, n - 2));
        return ans;
    }
};

// B  O(n) O(n)
int solve(vector<int> &cost, int n)
{
    vector<int> dp(n + 1);
    dp[0] = cost[0];
    dp[1] = cost[1];

    for(int i=2; i<n; i++){
        dp[i] += min(dp[i-1], dp[i-2]);
    }
    return min(dp[n-1], dp[n-2]);
}

//B O(n), O(n)
class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        vector<int> c(cost.begin(), cost.end());
        for (int i = cost.size() - 3; i >= 0; i--)
        {
            c[i] += min(c[i + 1], c[i + 2]);
        }

        return min(c[0], c[1]);
    }
};

// space optimization
// O(n) O(1)
int solve(vector<int> &cost, int n)
{
    int prev1 = cost[0], prev2 =cost[1];
    int n = cost.size();
    for(int i=2; i<n; i++){
        int temp = cost[i] + min(prev1, prev2);
        prev1 = prev2;
        prev2 = temp;
        }
    return min(prev1, prev2);
}

// que 3 coin change
class Solution {
    int helper(vector<int>& coins, int amount){
        if(amount == 0) return 0;
        if(amount < 0) return INT_MAX;
        
        int mini = INT_MAX;
        for(auto x: coins){
            int curr = helper(coins, amount - x);
            mini = min(mini, curr);
        }
        return mini == INT_MAX ? INT_MAX : mini + 1;
    }
    
    // A O(amount*coins.size), O(amount)
    int helper2(vector<int>& coins, int amount, vector<int>& dp){
        if(amount == 0) return 0;
        if(amount < 0) return INT_MAX;
        
        if(dp[amount] != -1) return dp[amount];
        
        int mini = INT_MAX;
        for(auto x: coins){
            int curr = helper2(coins, amount - x, dp);
            mini = min(mini, curr);
        }
        dp[amount] = (mini == INT_MAX ? INT_MAX : mini + 1);
        return dp[amount];
    }
    
//    B O(amount * coins.size) O(amount)
   int helper3(vector<int>& coins, int amount){
        vector<int> dp(amount+1 ,INT_MAX);
        dp[0] = 0;
       
       for(int i = 1; i<=amount; i++)
           for(auto x: coins)
               if(i - x >= 0)
                   if(dp[i-x] != INT_MAX)
                       dp[i] = min(dp[i], dp[i-x]+1);
          return dp[amount];         
    }    
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, -1);
        // int ans = helper2(coins, amount, dp);
        int ans = helper3(coins, amount);

        return  ans == INT_MAX ? -1 : ans;
    }
};

// max sum of non adjacent element
class Solution {
    //expo
    int solve(vector<int>& nums, int i){
        if(i >= nums.size()) return 0;
        if(i == nums.size()-1) return nums[i];

        int curr = max(nums[i] + solve(nums, i+2), nums[i+1] + solve(nums, i+3));
        
        return curr;
    }
    
    // A O(n) ~ n/2   O(n)
    int solve2(vector<int>& nums, int i, vector<int>& dp){
        if(i >= nums.size()) return 0;
        if(i == nums.size()-1) return nums[i];
        
        if(dp[i] != -1) return dp[i];
        
        int curr = max(nums[i] + solve2(nums, i+2, dp), nums[i+1] + solve2(nums, i+3, dp));
        dp[i] = curr;
        return dp[i];
    }
    
//     A O(n) O(n)
    int solve3(vector<int>& nums, int i, vector<int>& dp){
        if(i >= nums.size()) return 0;
        if(i == nums.size()-1) return nums[i];
        
        if(dp[i] != -1) return dp[i];
        
        int curr = max(nums[i] + solve2(nums, i+2, dp), solve2(nums, i+1, dp));
        dp[i] = curr;
        return dp[i];
    } 
    // B O(n) O(N)
      int solve4(vector<int> nums){
          int n= nums.size();
          if(n == 1) return nums[0];
          vector<int> dp(n, 0);
          
          dp[0] = nums[0];
          dp[1] = max(nums[0], nums[1]);
          
          for(int i=2; i<n; i++){
              int inc = nums[i] + dp[i-2];
              int excl = dp[i-1];
              
              dp[i] = max(inc, excl);
          }
          return dp[n-1];
      }
    //   space Optimization O(n) O(1)
      int solve5(vector<int> nums){
          int n= nums.size();
          if(n == 1) return nums[0];
        //   vector<int> dp(n, 0);
          
          int prev2 = nums[0];
          int prev1 = max(nums[0], nums[1]);
          
          for(int i=2; i<n; i++){
              int inc = nums[i] + prev2;
              int excl = prev1;
              
              prev2 = prev1;
              prev1 = max(inc, excl);
          }
          return prev1;
      }
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 2) return max(nums[0], nums[1]);
        
        vector<int> dp(nums.size()+1, -1);
        // return solve3(nums, 0, dp);
        return solve4(nums);
    }
};


// que 4
class Solution
{ 
    int solve(int n, vector<int>& cuts){
        if(n == 0) return 0;
        if(n < 0) return INT_MIN;
        
        int maxi =INT_MIN;
        for(int x: cuts){
            maxi = max(maxi, solve(n - x, cuts) + 1);
        }
        
        return maxi;
    }
    
    // A 
    int solve2(int n, vector<int>& cuts, vector<int>& dp){
        if(n == 0) return 0;
        if(n < 0) return INT_MIN;
        
        if(dp[n] != -1) return dp[n];
        
        int maxi =INT_MIN;
        
        for(int x: cuts){
            if(n-x >= 0)
            maxi = max(maxi, solve2(n - x, cuts, dp) + 1);
        }
        
        dp[n] = maxi;
        return dp[n];
    }
    
    // B
    int solve3(int n, vector<int>& cuts){
        vector<int> dp(n+1, INT_MIN);
        
        dp[0] = 0;
        
        for(int i = 1; i<=n; i++){
            for(int x: cuts){
                if(i - x >=0 && dp[i - x] != INT_MIN)
                    dp[i] = max(dp[i], dp[i - x] + 1);
            }
        }
        return dp[n];
    }
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        vector<int> cuts = {x, y, z};
        vector<int> dp(n+1, -1);
        // int ans = solve2(n, cuts, dp);
        // return ans < 0 ? 0 : ans;
        
        int ans = solve3(n, cuts);
        return ans < 0 ? 0 : ans;
        
        
    }
};

// que 4 leetcode but different pattern
class Solution
{
    int count = 0;
    int divide2(vector<int> &c, int s, int e, map<pair<int, int>, int> dp)
    {
        if (s >= e)
            return 0;

        if (dp[{s, e}] != 0)
            return dp[{s, e}];
        if ((e - s) % 2 == 0)
        {
            if (find(c.begin(), c.end(), (e - s) / 2) != c.end())
            {
                dp[{s, e}] = e - s + divide2(c, s, (e - s) / 2, dp) + divide2(c, (e - s) / 2, e, dp);
            }
        }
        else
        {
            int cost = INT_MAX;

            for (int i = 0; i < c.size(); i++)
            {
                if (c[i] > s && c[i] < e)
                {
                    cost = min(cost, (e - s + divide2(c, s, c[i], dp) + divide2(c, c[i], e, dp)));
                }
            }
        }
        int cost = INT_MAX;

        for (int i = 0; i < c.size(); i++)
        {
            if (c[i] > s && c[i] < e)
            {
                cost = min(cost, (e - s + divide2(c, s, c[i], dp) + divide2(c, c[i], e, dp)));
            }
        }
        dp[{s,e}] = cost == INT_MAX ? 0 : cost;
        return dp[{s,e}];
    }

public:
    int minCost(int n, vector<int> &cuts)
    {
        sort(cuts.begin(), cuts.end());
        map<pair<int, int>, int> mp;
        int ans = divide2(cuts, 0, n, mp);
    }

    int divide(vector<int> &c, int s, int e)
    {
        if (s >= e)
            return 0;

        if ((e - s) % 2 == 0)
        {
            if (find(c.begin(), c.end(), (e - s) / 2) != c.end())
            {
                return e - s + divide(c, s, (e - s) / 2) + divide(c, (e - s) / 2, e);
            }
        }
        int cost = INT_MAX;

        for (int i = 0; i < c.size(); i++)
        {
            if (c[i] > s && c[i] < e)
            {
                cost = min(cost, (e - s + divide(c, s, c[i]) + divide(c, c[i], e)));
            }
        }
        return cost == INT_MAX ? 0 : cost;
    }
};

//  que 5 count dearrangment

//A
long long int solve(int n, vector<int>& dp){
    if(n == 1) return 0;
    if(n == 2) return 1;
    
    if(dp[n] != -1) return dp[n];
    
    long long int ans = ((n-1) * ((solve(n-1, dp) + solve(n-2, dp)) % mod)) % mod;
    dp[n] = ans;
    return dp[n];
}

//B
long long int solve2(int n){
    vector<long long int> dp(n+1, -1);
    dp[1] = 0;
    dp[2] = 1;

    for(int i=3; i<=n; i++){
        dp[i] = ((i-1) * ((dp[i-1] + dp[i-2]) % mod)) % mod;
    }
    return dp[n];
}

// C
long long int solve3(int n){
    // vector<long long int> dp(n+1, -1);
    long long int prev2 = 0;
    long long int prev1 = 1;

    for(int i=3; i<=n; i++){
        long long int ans = ((i-1) * ((prev1 + prev2) % mod)) % mod;
        
        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
}
long long int countDerangements(int n) {
    // Write your code here.
    vector<int> dp(n+1 , -1);
    // return solve(n, dp);
    return solve3(n);
}

// que 6 
// const int mod = 1e9 + 7;

class Solution{
    
    long long solve(int n, int k, vector<long long>& dp){
        if(n == 2) return (k + (k * (k-1)) % mod) % mod;
        if(n == 1) return k;
        
        if(dp[n] != -1) return dp[n];
        
        long long ans = ((k-1) * ((solve(n-1, k, dp) + solve(n-2, k, dp) )% mod)) % mod;
        dp[n] = ans;
        return dp[n];
    }
    public:
    long long countWays(int n, int k){
        // code here
        // return (k * ( ( solve(n-1, k-1) + solve(n-2, k-1) ) % mod)) % mod;
        vector<long long> dp(n+1, -1);
        return solve(n, k, dp);
    }
};

// que 7 leetcode 139
class Solution {
    string realString ;
    
     static bool compare(string &s1,string &s2)
     {
       return s1.size() > s2.size();
     }
    bool helper(string s, vector<string>& wordDict, string currWord,  map<string, bool>& mp){
       
        if(currWord == realString) return true;
        
        if(mp.find(s) != mp.end()) return mp[s]; 
        char ch = s[0];
     
        for(string x: wordDict){
        
            if(x[0] == ch){
                
                if(s.find(x) == 0){
                    
                    if(helper(s.substr(x.size()), wordDict, currWord + x, mp)){
                        mp[s] = true;
                        return true;
                    }   
                    
                }
            }
        }
        mp[s] = false;
        return false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        realString = s;
        map<string, bool> mp;
        sort(wordDict.begin(), wordDict.end(), compare);
        
        return helper(s, wordDict, "", mp);
    }
};

// 2D DP
class Solution
{
    // int solve2(int W, int wt[], int val[], int i, int w){
    //     if( w == W) return 0;
    //     if(i == 0) {
    //         if(w + wt[i] <= W) return val[i];
    //         return INT_MIN;
    //     }
        
    //     int incl = 0;
        
    //     if(w + wt[i] <= W) incl = val[i] + solve(W, wt, val, i-1, w + wt[i]);
    //     int excl = solve(W, wt, val,  i-1, w );
        
    //     return max(incl, excl);
    // }
    
    int solve(int W, int wt[], int val[], int i, int w){
        
        if(i == 0) {
            if(w + wt[i] <= W) return val[i];
            return 0;
        }
        
        int incl = 0;
        
        if(w + wt[i] <= W) incl = val[i] + solve(W, wt, val, i-1, w + wt[i]);
        int excl = solve(W, wt, val,  i-1, w );
        
        return max(incl, excl);
    }   
    
    // A O(n*w) O(n*w);
    int solve2(int W, int wt[], int val[], int i, vector<vector<int>>& dp){
        
        if(i == 0) {
            if(wt[i] <= W) return val[i];
            return 0;
        }
        
        if(dp[i][W] != -1) return dp[i][W];
        int incl = 0;
        
        if( wt[i] <= W) incl = val[i] + solve2(W - wt[i], wt, val, i-1, dp);
        int excl = solve2(W, wt, val,  i-1, dp);
        
        dp[i][W] = max(incl, excl);
        return dp[i][W];
    }     

//B
    int solve3(int W, int wt[], int val[], int n){
        
        vector<vector<int>> dp(n, vector<int>(W+1, 0));
        
        for(int w=wt[0]; w<=W; w++){
            if(wt[0] <= W) dp[0][w] = val[0];
        }
        
        for(int i=1; i<n; i++){
            for(int w=0; w<=W; w++){
                
                int incl = 0;
                
                if(wt[i] <= w)
                    incl = val[i] + dp[i-1][w - wt[i]];
                
                int excl = dp[i-1][w];
                
                dp[i][w] = max(incl, excl);
            }
        }
        return dp[n-1][W];
    }  

// space optimization
    int solve4(int W, int wt[], int val[], int n){
        

        vector<int> prev(W+1, 0);
        
        
        for(int w=wt[0]; w<=W; w++){
            if(wt[0] <= w) prev[w] = val[0];
        }
        
        for(int i=1; i<n; i++){
            vector<int> curr(W+1, 0);
            for(int w=0; w<=W; w++){
                
                int incl = 0;
                
                if(wt[i] <= w)
                    incl = val[i] + prev[w - wt[i]];
                
                int excl = prev[w];
                
                curr[w] = max(incl, excl);
            }
            prev = curr;
        }
        return prev[W];
    }      
    
    int solve5(int W, int wt[], int val[], int n){
        

        vector<int> prev(W+1, 0);
        
        
        for(int w=wt[0]; w<=W; w++){
            if(wt[0] <= w) prev[w] = val[0];
        }
        
        for(int i=1; i<n; i++){
            for(int w=W; w>=0; w--){
                
                int incl = 0;
                
                if(wt[i] <= w)
                    incl = val[i] + prev[w - wt[i]];
                
                int excl = prev[w];
                
                prev[w] = max(incl, excl);
            }
        }
        return prev[W];
    }     
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
    //   int ans = solve(W, wt, val, n-1, 0);
       
    //   return ans < 0 ? 0 : ans;
     
        vector<vector<int>> dp(n, vector<int>(W+1, -1));
        
        // return solve2(W, wt, val, n-1, dp);
        return solve4(W, wt, val, n);
    }
};