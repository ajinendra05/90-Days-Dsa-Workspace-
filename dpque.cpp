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

//combination sum 1 not dp only backtracking
class Solution {
   void solve(vector<int>& candidates, int remTar, vector<int> curr, set<vector<int>>& ans){
        if(remTar < 0) return;
        if(remTar == 0){
            ans.insert(curr);
            return;
        }
        
       
       for(int x: candidates){
           curr.push_back(x);
           solve(candidates, remTar - x, curr, ans);
           curr.pop_back();
       }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // unordered_map<int, vector<vector<int>>> mp;
        
        set<vector<int>> temp;
        
        solve(candidates, target, {}, temp);
        vector<vector<int>> ans(temp.begin(), temp.end());
        return ans;
    }
};

//Combination Sum IV

class Solution {
    int solve(vector<int>& nums, int target, vector<int>& dp){
        if(target == 0) return 1;
        if(target < 0) return 0;
       
        if(dp[target] != -1) return dp[target];
        int ans = 0;
        for(int i = 0; i< nums.size(); i++){
            if(nums[i] <= target){
                ans += solve(nums, target - nums[i], dp);
            }
        }
        
        dp[target] = ans;
        return dp[target];
    }

    
    int solve2(vector<int>& nums, int target, vector<long long>& dp){
        
        dp[0] = 1;
       
        for(int i = 1; i<= target; i++){
            for(auto x: nums){
                if(i - x >= 0 )
                    dp[i] = (dp[i] + dp[i - x]) % INT_MAX;
            }
        }
        return dp[target];
    }
    

public:
    int combinationSum4(vector<int>& nums, int target) {
        // vector<int> dp(target+1, -1);
        // return solve(nums, target, dp);
        vector<long long> dp(target+1, 0);
        return solve2(nums, target, dp);        
    }
};

// 279. Perfect Squares
class Solution {
    int solve(int n, vector<int>& dp){
        if(n == 0) return 0;  //number of way to get 0 from perfect square is 0;
        
        if(dp[n] != -1) return dp[n];
        
        int ways = INT_MAX;
        for(int i = 1; i*i <= n; i++){
            ways = min(ways, solve(n - (i*i), dp) + 1);
        }
        
        dp[n] = ways;
        return dp[n];
    }
    
    int solve2(int n){
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        
        for(int i=1; i<=n; i++){
            
            for(int j = 1; j*j <= n; j++){
                if(i - j*j >= 0)
                dp[i] = min(dp[i], dp[i - (j*j)] + 1);
            }
        }
        return dp[n];
    }    
    
public:
    int numSquares(int n) {
        vector<int> dp(n+1, -1);
        return solve2(n);
    }
};

//983 minimum cost 
class Solution {
    // O(n), O(n + n)
    int solve(vector<int>& days, vector<int>& costs, vector<int>& dp, int s){
        
        if(s >= days.size()) return 0;
        
        if(dp[s] != -1) return dp[s];
        
        int currDay = days[s];
        int nextDays[] = {currDay, currDay+6, currDay+29};
        int amount = INT_MAX;
        
        for(int i=0; i<3; i++){
            int k = s;
            while(k<days.size() && days[k] <= nextDays[i]) 
                k++;
            
            amount = min(amount, costs[i] + solve(days, costs, dp, k));
            
        }
        
        dp[s] = amount;
        return dp[s];
    }
    
    
    int solve2(vector<int>& days, vector<int>& costs, vector<int>& dp, int index){
        
        int n = days.size();
        if(index >= days.size()) return 0;
        
        if(dp[index] != -1) return dp[index];
        
        int currDay = days[index];
        
        int opt1 = costs[0] + solve2(days, costs, dp, index+1);   //1 daay
        
        int i;
        
        for(i = index; i<n && days[i] < currDay+7; i++);
        
        int opt2 = costs[1] + solve2(days, costs, dp, i);      //7 day
        
        for(i = index; i<n && days[i] < currDay+30; i++);
        
        int opt3 = costs[2] + solve2(days, costs, dp, i);     //30 day
        
        return dp[index] = min(opt1, min(opt2, opt3));
        
        
    }
    //O(n), O(n)  tabulation
        int solve3(vector<int>& days, vector<int>& costs){
        
            int n = days.size();
            vector<int> dp(n+1, INT_MAX);

            dp[n] = 0;

            
            for(int ind = n-1; ind >= 0; ind--){
                int currDay = days[ind];
                int nextDays[] = {currDay, currDay+6, currDay+29};

                for(int i=0; i<3; i++){
                    int k = ind;
                    while(k < n && days[k] <= nextDays[i]) 
                        k++;

                    dp[ind] = min(dp[ind], costs[i] + dp[k]);

                }

            }

            return dp[0];
    }
    
     // space optimization
    int solve4(vector<int>& days, vector<int>& costs){
        int ans =0;
        queue<pair<int, int>> week, month;
        
        for(int day: days){
            while(!week.empty() && week.front().first+7 <= day)
                week.pop();
            while(!month.empty() && month.front().first+30 <= day)
                month.pop();
            
            week.push({day, ans + costs[1]});
            month.push({day, ans + costs[2]});
            
            ans = min(ans + costs[0], min(week.front().second, month.front().second));
                
        }
        return ans;
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n+1, -1);
        // return solve(days, costs, dp, 0);
        return solve4(days, costs);
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
        
        //both are same but this is optimized way
        // for(int w=wt[0]; w<=W; w++){
        //     if(wt[0] <= W) dp[0][w] = val[0];
        // }
        // its concept behind that
        for(int w=0; w<=W; w++){
            if(wt[0] <= w) dp[0][w] = val[0];
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

// que 6 ninjas training 

int solve(int ind, vector<vector<int>> &points, int prev,
vector<vector<int>>& dp){
   
    if(ind == 0){
        int maxi = INT_MIN;
        for(int i=0; i<points[0].size(); i++ ){
            if(i != prev) maxi = max(maxi, points[ind][i]);
        }
        return maxi;
    }
    
    if( dp[ind][prev] != -1) return dp[ind][prev];

    int maxi = INT_MIN;
    
    for(int i=0; i<points[0].size(); i++ ){
        if(i != prev){
            maxi = max(maxi, points[ind][i] + solve(ind-1, points, i, dp));
        }
    }
    dp[ind][prev] = maxi;
    return maxi;
}


int solve2(int n, vector<vector<int>> &points){
    vector<vector<int>> dp(n+1, vector<int>(points[0].size()+1, -1));

    dp[0][0] =  max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][1], points[0][0]);
    dp[0][3] = max(points[0][1], max(points[0][1], points[0][2]));

    
    
    for(int day = 1; day < n; day++){
        for(int prev = 0; prev < 4; prev++){
            int maxi = INT_MIN;
            for(int i=0; i<points[0].size(); i++ ){
                if(i != prev){
                    maxi = max(maxi, points[day][i] + dp[day-1][i] );
                }
            }
            dp[day][prev] = maxi;
        }

    }

    return dp[n-1][3];
}


int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    return solve2(n, points);
    vector<vector<int>> dp(n+1, vector<int>(points[0].size()+1, -1));
    return solve(n-1, points, 3, dp);
}

// 221 maximal square
class Solution {
    // O(m*n) O(m*n)
    int solve(vector<vector<char>>& matrix, int i, int j, int& ans, vector<vector<int>>& dp){
        if(i >= matrix.size() || j >= matrix[0].size())
            return 0;          //we cant make square outside
        
        if(dp[i][j] != -1) return dp[i][j];
        int right = solve(matrix, i+1, j, ans, dp);
        int down = solve(matrix, i, j+1, ans, dp);
        int digo = solve(matrix, i+1, j+1, ans, dp);
        
        if(matrix[i][j] == '1'){
            int curr = 1 + min(digo, min(down, right));
            ans = max(ans, curr);
            dp[i][j] = curr;
            return curr;
        }   
        
        return 0;    
        
    }
    
    //tabulation  O(m*n) O(m*n)
    void solve2(vector<vector<char>>& matrix, int& ans){
        int n =matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
          
        for(int i = n-1; i>=0; i--){
            for(int j = m-1; j>=0; j--){
                
                int right = dp[i+1][j];
                int down = dp[i][j+1];
                int digo = dp[i+1][j+1];

                if(matrix[i][j] == '1'){
                    dp[i][j] = 1 + min(digo, min(down, right));
                    ans = max(ans, dp[i][j]);
                }   
            }
        }
      
    }    
    
    //space optimization
    void solve3(vector<vector<char>>& matrix, int& ans){
        int n =matrix.size();
        int m = matrix[0].size();
        // vector<vector<int>> dp(2, vector<int>(m+1, 0));
          
        vector<int> next(m+1, 0);
        
        for(int i = n-1; i>=0; i--){
            vector<int> curr(m+1, 0);
            for(int j = m-1; j>=0; j--){
                
                int right = next[j];
                int down = curr[j+1];
                int digo = next[j+1];

                if(matrix[i][j] == '1'){
                    curr[j] = 1 + min(digo, min(down, right));
                    ans = max(ans, curr[j]);
                }   
            }
            // dp[1] = dp[0];
            next = curr;
        }
      
    } 
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n =matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        int ans = 0;
        // solve(matrix, 0, 0, ans, dp);
        solve3(matrix, ans);
        return ans*ans;
    }
};

// 1824
class Solution {
    int solve(vector<int>& obs, int index, int currLane, vector<vector<int>>& dp){
        if(index >= (obs.size() - 2)) return 0;
        
        if(dp[index][currLane] != -1) return dp[index][currLane];
        
        int curr = INT_MAX;
        if(obs[index + 1] != currLane){
            curr = solve(obs, index + 1, currLane, dp);
        }else{
            for(int i = 1; i <= 3; i++){
                if(currLane != i && obs[index] != i){
                    curr = min(curr, solve(obs, index, i, dp) + 1);
                    }
            }
        }
        
        dp[index][currLane] = curr;
        return curr;
    }
    
     int solve2(vector<int>& obs){
         
         int n = obs.size();
        vector<vector<int>> dp(n+1, vector<int>(4, 1e9));
         
        dp[n-1][0] = dp[n-1][1] = dp[n-1][2] = dp[n-1][3] = 0;
        
        for(int index = n-2; index >= 0; index--){
            for(int k = 1; k <= 3; k++ ){
                
                if(obs[index + 1] != k){
                    dp[index][k] = dp[index + 1][k];
                }else{
                    int curr = INT_MAX;
                    for(int i = 1; i <= 3; i++){
                        if(k != i && obs[index] != i){
                             curr = min(curr, dp[index+1][i] + 1);            //index + 1 is extra from memorization because of we can take i = 3 for k = 1 but it's  not calculated yet for current index that's why we take i =  of index +1;
                            }
                    }
                    dp[index][k] = curr;
                }

            }
            
        }        
        
        return min(dp[0][2], min(dp[0][1] + 1, dp[0][3] + 1));
    }   
     int solve3(vector<int>& obs){
         
         int n = obs.size();
         vector<int> prev(4, 0);
         vector<int> curr(4, 1e9);


        for(int index = n-2; index >= 0; index--){
            for(int k = 1; k <= 3; k++ ){

                if(obs[index + 1] != k){
                    curr[k] = prev[k];
                }else{
                    int ans = INT_MAX;
                    for(int i = 1; i <= 3; i++){
                        if(k != i && obs[index] != i){
                             ans = min(ans, prev[i] + 1);            //index + 1 is extra from memorization because of we can take i = 3 for k = 1 but it's  not calculated yet for current index that's why we take i =  of index +1;
                            }
                    }
                    curr[k] = ans;
                    prev = curr;
                }

            }

        }        

        return min(curr[2], min(curr[1] + 1, curr[3] + 1));
    }   
public:
    int minSideJumps(vector<int>& obstacles) {
        // int n = obstacles.size();
        // vector<vector<int>> dp(n, vector<int>(4, -1));
        // return solve(obstacles, 0, 2, dp);
        return solve3(obstacles);
    }
};

            // if(currLane == 1){
            //     if(obs[index] != 2)
            //         curr = solve(obs, index, 2, dp) + 1;
            //     if(obs[index] != 3)
            //         curr = min(curr, solve(obs, index, 3, dp) + 1);
            // }
            // if(currLane == 2){
            //     if(obs[index] != 1)
            //         curr = solve(obs, index, 1, dp) + 1;
            //     if(obs[index] != 3)
            //         curr = min(curr, solve(obs, index, 3, dp) + 1);
            // }
            // if(currLane == 3){
            //     if(obs[index] != 2)
            //         curr = solve(obs, index, 2, dp) + 1;
            //     if(obs[index] != 1)
            //         curr = min(curr, solve(obs, index, 1, dp) + 1);
            // }

// dises satisfaction
class Solution {
//     int solve(vector<int>& sati, int ind, int dishTaken){
//         if(ind == sati.size()) return 0;
        
//         int incl = (dishTaken*sati[ind]) + solve(sati, ind + 1, dishTaken + 1);
//         int excl = solve(sati, ind + 1, dishTaken);
        
//         int ans = max(incl, excl);
//         return ans; 
//     }
    int solve2(vector<int>& sati, int ind, int dishTaken,  vector<vector<int>>& dp){
        if(ind == sati.size()) return 0;
        
        if(dp[ind][dishTaken] != -1) return dp[ind][dishTaken];
        
        int incl = (dishTaken*sati[ind]) + solve2(sati, ind + 1, dishTaken + 1, dp);
        int excl = solve2(sati, ind + 1, dishTaken, dp);
        dp[ind][dishTaken] = max(incl, excl);
        return dp[ind][dishTaken];
    }    
    int solve3(vector<int>& sati){
        int n = sati.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        
        for(int ind = n - 1; ind >= 0; ind--){
            for(int dishTaken = n-1; dishTaken >= 0; dishTaken-- ){
                int incl = ((dishTaken+1)*sati[ind]) + dp[ind+1][dishTaken+1];
                int excl = dp[ind+1][dishTaken];
                dp[ind][dishTaken] = max(incl, excl);
            }
        }
        
        return dp[0][0];
    }
    int solve4(vector<int>& sati){
        int n = sati.size();
        // vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        vector<int> curr(n+1, 0);
        vector<int> next(n+1, 0);
        
        for(int ind = n - 1; ind >= 0; ind--){
            for(int dishTaken = n-1; dishTaken >= 0; dishTaken-- ){
                int incl = ((dishTaken+1)*sati[ind]) + next[dishTaken+1];
                int excl = next[dishTaken];
                curr[dishTaken] = max(incl, excl);
               
            } 
             next = curr;
        }
        
        return curr[0];
    } 
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin() ,satisfaction.end());
        // int n = satisfaction.size();
        // vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        // return solve2(satisfaction, 0, 1, dp);
        return solve4(satisfaction);
    }
};