#include <bits/stdc++.h>

using namespace std;
#define MOD 1000000007
#define mod 1e9 + 7

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    string addBinary(string a, string b) {
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    
    string ans;
    int carry=0;
    int x,y,sum=0;
    while(!a.empty()||!b.empty()){
        x=0;y=0;
        if(!a.empty()){
            x=a[0]-48;
            a.erase(a.begin());
        }
         if(!a.empty()){
            y=b[0]-48;
            b.erase(b.begin());
        }
        sum=x+y+carry;
        carry=sum>1?1:0;
        sum=sum%2==1?49:48;
        ans.push_back(char(sum));

    }    
    if(carry)ans.push_back(char(49));
    reverse(ans.begin(),ans.end());
    return ans; 
    }
};




class Codec
{

public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        if (root == NULL)
            return "";
        queue<TreeNode *> q;
        q.push(root);
        string cur;

        while (!q.empty())
        {
            TreeNode *temp = q.front();
            q.pop();
            if (temp->val < 0)
            {
                cur.push_back(char(1));
                temp->val *= (-1);
            }
            else
            {
                cur.push_back(char(2));
            }
            cur.push_back(char((temp->val) % 127));
            cur.push_back(char((temp->val) / 127));
            if (temp->left)
            {
                q.push(temp->left);
                cur.push_back('L');
                if (temp->left->val < 0)
                {
                    cur.push_back(char(1));
                    temp->left->val *= (-1);
                }
                else
                {
                    cur.push_back(char(2));
                }
                cur.push_back(char((temp->left->val) % 127));
                cur.push_back(char((temp->left->val) / 127));
            }
            if (temp->right)
            {
                q.push(temp->right);
                cur.push_back('R');
                if (temp->right->val < 0)
                {
                    cur.push_back(char(1));
                    temp->right->val *= (-1);
                }
                else
                {
                    cur.push_back(char(2));
                }
                cur.push_back(char((temp->right->val) % 127));
                cur.push_back(char((temp->right->val) / 127));
            }
        }
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if (data.empty())
            return NULL;
        queue<TreeNode *> q;
        TreeNode *root = new TreeNode(int(data[0]));
        TreeNode *temp = root;
        q.push(root);
        // data.erase(data.begin());

        while (!q.empty())
        {
            temp = q.front();

            TreeNode *temp2;
            q.pop();
            int num = (int(data[2]) * 127) + int(data[1]);
            num = int(data[0]) == 1 ? -num : num;
            if (num != temp->val)
            {
                continue;
            }
            data.erase(data.begin());
            data.erase(data.begin());
            data.erase(data.begin());
            if (data[0] == 'L')
            {
                data.erase(data.begin());
                num = (int(data[2]) * 127) + int(data[1]);
                num = int(data[0]) == 1 ? -num : num;
                temp2 = new TreeNode(num);
                temp->left = temp2;
                data.erase(data.begin());
                data.erase(data.begin());
                data.erase(data.begin());
                q.push(temp2);
            }
            if (data[0] == 'R')
            {
                data.erase(data.begin());
                num = (int(data[2]) * 127) + int(data[1]);
                num = int(data[0]) == 1 ? -num : num;
                temp2 = new TreeNode(num);
                temp->right = temp2;
                data.erase(data.begin());
                data.erase(data.begin());
                data.erase(data.begin());
                q.push(temp2);
            }
        }
        return root;
    }
};
int main()
{
    Codec c;
    // c.deserialize(c.serialize());

    cout << int(char(129));
    return 0;
}

// // Your Codec object will be instantiated and called as such:
// // Codec ser, deser;
// // TreeNode* ans = deser.deserialize(ser.serialize(root));
// class Solution {

// public:
//     int largestVariance(string s) {
//         set<char> st(s.begin(),s.end());

//         if(st.size()==s.size())return 0;
//         int count=0;
//         int ans=0;
//         bool flag=false;
//         for(auto a: st){
//             for(auto b:st){
//                 count=0;
//                 flag=false;
//                 if(a!=b){
//                     for(int i=0;i<s.size();i++){
//                         if(s[i]==a)count++;
//                         if(s[i]==b){
//                             count--;
//                             flag=true;
//                             if(count<0){
//                                 count=0;
//                                 flag=false;
//                                 }
//                         }
//                         flag? ans=max(ans,count):ans=max(ans,count-1);
//                     }

//                 }
//             }
//         }
//         return ans;
//     }
// };
// class Solution
// {
// public:
//     int largestVariance(string s)
//     {
//         int ans = 0;
//         vector<int> f(27, 0);
//         vector<int> f2(27, INT_MAX);
//         // unordered_map<char,int> m;
//         int mx, mi;

//         for (int i = 0; i < s.size(); i++)
//         {
//             vector<int> freq=f;
//             vector<int> freq2=f2;
//             for (int j = i; j < s.size(); j++)
//             {
//                 freq[s[j] - 'a']++;
//                 if (freq2[s[j] - 'a'] == INT_MAX)
//                     freq2[s[j] - 'a'] = 1;
//                 else
//                     freq2[s[j] - 'a']++;

//                 // m[s[i]]++;
//                 mi = *min_element(freq2.begin(), freq2.end());
//                 mx = *max_element(freq.begin(), freq.end());
//                 ans = max(ans, mx - mi);
//             }
//         }
//         return ans;
//     }
// };

// class Solution
// {
// public:
//     vector<int> relocateMarbles(vector<int> &nums, vector<int> &moveFrom, vector<int> &moveTo)
//     {
//         map<int, vector<int>> pos;
//         map<int, int> marbel;

//         for (int i = 0; i < nums.size(); i++)
//         {
//             pos[nums[i]].push_back(i);
//             marbel[i] = nums[i];
//         }

//         for (int i = 0; i < moveFrom.size(); i++)
//         {
//             for (int j = 0; j < pos[moveFrom[i]].size(); j++)
//             {
//                 marbel[pos[moveFrom[i]][j]] = moveTo[i];
//                 pos[moveTo[i]].push_back(pos[moveFrom[i]][j]);
//             }
//             pos[moveFrom[i]].clear();
//         }
//         for (int i = 0; i < nums.size(); i++)
//         {
//             nums[i] = marbel[i];
//         }
//         sort(nums.begin(), nums.end());
//         nums.erase(unique(nums.begin(), nums.end()));
//         return nums;
//     }
// };

// class Solution
// {
// public:
//     int alternatingSubarray(vector<int> &nums)
//     {
//         int ans = 1;
//         int curr = 0;
//         int s1 = 0, s2 = 0;
//         int i = 1;
//         while (i < nums.size())
//         {
//             if ((nums[i] - nums[i - 1]) == 1)
//             {
//                 if (s1 == nums[i - 1] && s2 == nums[i])
//                 {
//                     curr += 2;
//                     i += 2;
//                 }
//                 else
//                 {
//                     ans = max(ans, curr);
//                     curr = 2;
//                     s1 = nums[i - 1];
//                     s2 = nums[i];
//                 }
//             }
//             else
//             {
//                 ans = max(ans, curr);
//                 curr = 0;
//             }
//         }
//         ans = max(ans, curr);
//         return ans;
//     }
// };
// class Solution
// {
// public:
//     int alternatingSubarray(vector<int> &nums)
//     {
//     }
// };
// class Solution
// {
// public:
//     int alternatingSubarray(vector<int> &nums)
//     {

//         int ans = 1;
//         int curr = 0;
//         int s1 = 0, s2 = 0;

//         for (int i = 0; i < nums.size(); i++)
//         {
//             curr = 0;
//             if (nums[i] - nums[i - 1] == 1)
//             {
//                 s1 = nums[i - 1];
//                 s2 = nums[i];
//                 for (int j = i; j < nums.size(); j += 2)
//                 {
//                     if (nums[j - 1] == s1 && nums[j] == s2)
//                     {
//                         curr += 2;
//                     }
//                     else
//                     {
//                         if (nums[j - 1] == s1)
//                             curr++;
//                         break;
//                     }

//                     if (j == nums.size() - 2 && nums[j + 1] == s1)
//                     {
//                         curr++;
//                     }
//                 }

//                 ans = max(ans, curr);
//             }
//         }
//         ans = max(ans, curr);
//         return ans;
//     }
// };

// class Solution
// {
// public:
//     long long putMarbles(vector<int> &weights, int k)
//     {
//         vector<long long> consicutiveSum;
//         int n = weights.size();

//         for (int i = 1; i < n; i++)
//             consicutiveSum.push_back(weights[i - 1] + weights[i]);

//         // 1st and last will always include in final score [so we can take it as one pair]
//         long long sum = weights[0] + weights[n - 1];

//         // order doesn't matter in final score
//         sort(consicutiveSum.begin(), consicutiveSum.end());

//         long long minScore = 0, maxScore = 0;
//         minScore = maxScore = sum;
//         n = consicutiveSum.size();
//         for (int i = 0; i < k - 1; i++)
//         {
//             minScore += consicutiveSum[i];
//             maxScore += consicutiveSum[n - i];
//         }
//         return maxScore - minScore;
//     }
// };

// class Solution
// {

//     long long absU(int val)
//     {
//         if (val == INT_MIN)
//             return INT_MAX + 1;
//         return abs(val);
//     }

// public:
//     int divide(int dividend, int divisor)
//     {
//         if (dividend == divisor)
//             return 1;
//         if (divisor == INT_MIN)
//             return 0;
//         if (divisor == 1)
//             return dividend;
//         if (dividend == INT_MIN)
//         {
//             if (divisor == -1)
//                 return INT_MAX;
//         }
//         if (divisor == -1)
//             return -dividend;
//         long long x = absU(divisor);
//         long long y = absU(dividend);
//         if (dividend == 0 || x > y)
//             return 0;

//         long long count = 1;
//         long long sum = x;

//         while (sum + x <= y && count < INT_MAX)
//         {
//             sum += x;
//             count++;
//         }

//         if (dividend * 1L * divisor > 0)
//             return count;
//         return -count;
//     }
// };

// class Solution
// {
// public:
//     int divide(int dividend, int divisor)
//     {
//         if (dividend == INT_MIN)
//         {
//             if (divisor == -1)
//                 return INT_MAX;
//         }

//         long div = labs(dividend);
//         long dis = labs(divisor);
//         int count = 0;
//         while (dis <= div)
//         {
//             int temp = dis;
//             int m = 1;
//             while (temp << 1 <= dis)
//             {
//                 m++;
//                 temp = temp << 1;
//             }
//             div -= temp;
//             count += m;
//         }
//         return count;
//     }
// };

// class Solution
// {
// public:
//     int divide(int dividend, int divisor)
//     {
//         if (dividend == INT_MIN)
//         {
//             if (divisor == -1)
//                 return INT_MAX;
//         }
//         // 4 optional conditions for time optimization
//         if (dividend == divisor)
//             return 1;
//         if (divisor == INT_MIN)
//             return 0;
//         if (divisor == 1)
//             return dividend;
//         if (divisor == -1)
//             return -dividend;

//         long div = labs(dividend);
//         long dis = labs(divisor);
//         int count = 0;
//         while (dis <= div)
//         {
//             int temp = dis;
//             int m = 1;
//             while (temp << 1 <= dis)
//             {
//                 m++;
//                 temp = temp << 1;
//             }
//             div -= temp;
//             count += m;
//         }

//         int sign = dividend * 1L * divisor > 0 ? 1 : -1;
//         return count * sign;
//     }
// };
// class Solution
// {
// public:
//     int divide(int dividend, int divisor)
//     {
//         cout << abs(dividend);
//         if (dividend == 0 || abs(divisor) > abs(dividend))
//             return 0;
//         int count = 1;
//         int x = abs(divisor);
//         int y = abs(dividend);

//         while (x + abs(divisor) <= y && x < INT_MAX)
//         {
//             x += x;
//             count++;
//         }
//         x = dividend;
//         y = divisor;
//         if ((x < 0 && y < 0) || (x > 0 && y > 0))
//             return count;
//         return -1 * count;
//     }
// };
// class Solution
// {
// public:
//     int maxConsecutiveAnswers(string answerKey, int k)
//     {
//         vector<int> count;
//         char c = answerKey[0];
//         int curr = 0;

//         for (auto x : answerKey)
//             if (x == c)
//                 curr++;
//             else
//             {
//                 count.push_back(curr);
//                 curr = 1;
//                 c = x;
//             }

//         count.push_back(curr);
//         int ans = 0;

//         for (int i = 0; i < count.size(); i++)
//         {
//             if (i < count.size() - 2)
//             {
//                 if (count[i + 1] <= k)
//                     ans = max(ans, count[i] + count[i + 2] + count[i + 1]);
//             }
//             else if (i < count.size() - 1)
//             {
//                 if (count[i + 1] <= k)
//                     ans = max(ans, count[i] + count[i + 1]);
//             }

//             ans = max(ans, count[i]);
//         }

//         return ans;
//     }
// };

// class Solution
// {
// public:
//     long long noOfPairs(vector<string> &box)
//     {
//         // Write your code here.
//         int n = box.size();
//         map<vector<long long>, int> m;
//         long long ans = 0;
//         for (auto x : box)
//         {
//             vector<int> count(26);
//             vector<long long> odds;
//             for (int i = 0; i < x.size(); i++)
//             {
//                 count[x[i] - 'a']++;
//             }
//             for (int i = 0; i < 26; i++)
//             {
//                 if (count[i] % 2 == 1)
//                     odds.push_back(i);
//             }
//             if (m[odds] > 0)
//             {
//                 ans += m[odds];
//             }
//             m[odds]++;
//         }
//         return ans;
//     }
// };

// class Solution
// {
// public:
//     int minSubArrayLen(int target, vector<int> &nums)
//     {
//         queue<int> q;
//         int sum = 0;
//         int m = INT_MAX;
//         int curr = 0;

//         for (auto x : nums)
//         {
//             sum += x;
//             q.push(x);
//             curr++;

//             if (sum >= target)
//             {
//                 while (sum - q.front() >= target)
//                 {
//                     sum -= q.front();
//                     q.pop();

//                     curr--;
//                 }
//                 m = min(m, curr);
//             }
//         }

//         return m == INT_MAX ? 0 : m;
//     }
// };

// class Solution
// {
// public:
//     int minSubArrayLen(int target, vector<int> &nums)
//     {
//         queue<int> q;
//         int sum = 0;
//         int m = INT_MAX;
//         int curr = 0;

//         for (auto x : nums)
//         {
//             sum += x;
//             q.push(x);
//             curr++;
//             if (sum >= target)
//             {
//                 while (sum - q.front() >= target)
//                 {
//                     sum -= q.front();
//                     q.pop();
//                     curr--;
//                 }
//                 m = min(m, curr);
//             }
//         }
//         return m == INT_MAX ? 0 : m;
//     }
// };

// class Solution
// {

//     void helper(int x, int y, int n, string s, vector<string> &ans)
//     {
//         if (x == n && y == n)
//         {
//             ans.push_back(s);
//         }

//         if (x < n)
//         {
//             helper(x + 1, y, n, s + '(', ans);
//         }
//         if (y < n && x > y)
//         {
//             helper(x, y + 1, n, s + ')', ans);
//         }
//     }

// public:
//     vector<string> generateParenthesis(int n)
//     {
//         vector<string> ans;
//         helper(0, 0, n, "", ans);
//         return ans;
//     }
// };

// class Solution
// {
//     void helper(int x, int y, int n, string s, vector<string> &ans)
//     {
//         if (x == n && y == n)
//             ans.push_back(s);

//         if (x < n)
//             helper(x + 1, y, n, s + '(', ans);
//         if (y < n && x > y)
//             helper(x, y + 1, n, s + ')', ans);
//     }

// public:
//     vector<string> generateParenthesis(int n)
//     {
//         vector<string> ans;
//         helper(0, 0, n, "", ans);
//         return ans;
//     }
// };
// int main()
// {
//     vector<string> s = {};
// }
// class Solution
// {

//     void help(vector<int> &price, vector<int> &magical_price, int index, int &ans, int count, int amount, int m)
//     {
//         if (index == price.size())
//         {
//             if (amount <= m)
//                 ans = min(ans, count);
//             return;
//         }
//         if (amount > m)
//         {
//             return;
//         }
//         help(price, magical_price, index + 1, ans, count, amount + price[index], m);
//         help(price, magical_price, index + 1, ans, count + 1, amount + magical_price[index], m);
//     }

// public:
//     int minimumMagic(int n, int m, vector<int> &price, vector<int> &magical_price)
//     {
//         int ans = INT_MAX;
//         int sum = accumulate(magical_price.begin(), magical_price.end(), 0);
//         if (sum > m)
//             return -1;
//         help(price, magical_price, 0, ans, 0, 0, m);
//         return ans == INT_MAX ? -1 : ans;
//     }
// };

// class Solution
// {
//     int largestRectangleArea(vector<int> &heights)
//     {
//         int n = heights.size();
//         vector<int> prevMin(n);
//         vector<int> afterMin(n);
//         stack<pair<int, int>> s;
//         s.push(make_pair(-1, -1));
//         for (int i = 0; i < n; i++)
//         {
//             if (s.top().first < heights[i])
//             {
//                 prevMin[i] = s.top().second;
//                 s.push(make_pair(heights[i], i));
//             }
//             else
//             {
//                 while (s.top().first >= heights[i])
//                 {
//                     s.pop();
//                 }
//                 prevMin[i] = s.top().second;
//                 s.push(make_pair(heights[i], i));
//             }
//         }
//         stack<pair<int, int>> s1;
//         s1.push(make_pair(-1, n));
//         for (int i = n - 1; i >= 0; i--)
//         {
//             if (s1.top().first < heights[i])
//             {
//                 afterMin[i] = s1.top().second;
//                 s1.push(make_pair(heights[i], i));
//             }
//             else
//             {
//                 while (s1.top().first >= heights[i])
//                 {
//                     s1.pop();
//                 }
//                 afterMin[i] = s1.top().second;
//                 s1.push(make_pair(heights[i], i));
//             }
//         }
//         int maxArea = INT_MIN;
//         for (int i = 0; i < n; i++)
//         {
//             if ((heights[i] * (afterMin[i] - prevMin[i] - 1)) > maxArea)
//                 maxArea = heights[i] * (afterMin[i] - prevMin[i] - 1);
//         }
//         return maxArea;
//     }

// public:
//     int maximalRectangle(vector<vector<char>> &matrix)
//     {
//         int n = matrix.size();
//         int m = matrix[0].size();
//         vector<vector<int>> matrix2(n, vector<int>(m));
//         for (int i = 0; i < n; i++)
//         {
//             for (int j = 0; j < m; j++)
//             {
//                 if (i == 0)
//                 {
//                     if (matrix[i][j] == '0')
//                         matrix2[i][j] = 0;
//                     else if (matrix[i][j] == '1')
//                         matrix2[i][j] = 1;
//                 }
//                 else
//                 {
//                     if (matrix[i][j] == '0')
//                     {
//                         matrix2[i][j] = 0;
//                     }
//                     else
//                     {
//                         matrix2[i][j] = 1 + matrix2[i - 1][j];
//                     }
//                 }
//             }
//         }
//         int curArea = 0;
//         int maxArea = 0;
//         for (int i = 0; i < n; i++)
//         {
//             curArea = largestRectangleArea(matrix2[i]);
//             maxArea = maxArea > curArea ? maxArea : curArea;
//         }
//         return maxArea;
//     }
// };
// class Solution
// {

//     bool largestRectangleArea(vector<int> &heights, int k)
//     {
//         int n = heights.size();
//         vector<int> prevMin(n);
//         vector<int> afterMin(n);
//         stack<pair<int, int>> s;
//         s.push(make_pair(-1, -1));
//         for (int i = 0; i < n; i++)
//         {
//             if (s.top().first < heights[i])
//             {
//                 prevMin[i] = s.top().second;
//                 s.push(make_pair(heights[i], i));
//             }
//             else
//             {
//                 while (s.top().first >= heights[i])
//                 {
//                     s.pop();
//                 }
//                 prevMin[i] = s.top().second;
//                 s.push(make_pair(heights[i], i));
//             }
//         }
//         stack<pair<int, int>> s1;
//         s1.push(make_pair(-1, n));
//         for (int i = n - 1; i >= 0; i--)
//         {
//             if (s1.top().first < heights[i])
//             {
//                 afterMin[i] = s1.top().second;
//                 s1.push(make_pair(heights[i], i));
//             }
//             else
//             {
//                 while (s1.top().first >= heights[i])
//                 {
//                     s1.pop();
//                 }
//                 afterMin[i] = s1.top().second;
//                 s1.push(make_pair(heights[i], i));
//             }
//         }

//         int m;
//         for (int i = 0; i < n; i++)
//         {
//             m = min(heights[i], (afterMin[i] - prevMin[i] - 1));
//             if (m >= k)
//                 return true;
//         }
//         return false;
//     }

// public:
//     int maxGoodLength(vector<vector<int>> &a)
//     {
//         // Write your code here.
//         int n = a.size();
//         int m = a[0].size();

//         int minMN = min(m, n);
//         for (int k = minMN; k >= 0; k--)
//         {
//             for (int i = 0; i < n; i++)
//             {
//                 for (int j = 0; j < m; j++)
//                 {
//                     if (a[i][j] >= k)
//                     {
//                         a[i][j] = 1;
//                     }
//                     else
//                     {
//                         a[i][j] = 0;
//                     }
//                 }
//             }
//             vector<vector<int>> a2(n, vector<int>(m));
//             for (int i = 0; i < n; i++)
//             {
//                 for (int j = 0; j < m; j++)
//                 {
//                     if (i == 0)
//                     {
//                         if (a[i][j] == 0)
//                             a2[i][j] = 0;
//                         else if (a[i][j] == 1)
//                             a2[i][j] = 1;
//                     }
//                     else
//                     {
//                         if (a[i][j] == 0)
//                         {
//                             a2[i][j] = 0;
//                         }
//                         else
//                         {
//                             a2[i][j] = 1 + a2[i - 1][j];
//                         }
//                     }
//                 }
//             }
//             bool getIt = false;

//             for (int i = 0; i < n; i++)
//             {
//                 getIt = largestRectangleArea(a2[i], k);
//                 if (getIt == true)
//                     return k;
//             }
//         }

//         return 0;
//     }
// };
// class Solution
// {
// public:
//     int minimumMagic(int n, int m, vector<int> &price, vector<int> &magical_price)
//     {
//         if (accumulate(magical_price.begin(), magical_price.end(), 0) > m)
//             return -1;
//         vector<int> diff(n);
//         long long sum = 0;
//         for (int i = 0; i < n; i++)
//         {
//             diff[i] = price[i] - magical_price[i];
//             sum += price[i];
//         }
//         if (sum <= m)
//             return 0;
//         int req = sum - m;
//         sort(diff.begin(), diff.end());
//         int count = -1;
//         for (int i = n - 1; i >= 0; i--)
//         {
//             if (req - diff[i] <= 0)
//             {
//                 count = n - i;
//                 break;
//             }
//             else
//             {
//                 req -= diff[i];
//             }
//         }
//         return count;
//     }
// };
// class Solution
// {
// public:
//     vector<vector<int>> threeSum(vector<int> &nums)
//     {
//         map<int, int> m;

//         for (int x : nums)
//         {
//             m[x]++;
//         }
//         int x, y, z;
//         vector<vector<int>> ans;
//         vector<int> pairs;
//         map<vector<int>, bool> isVisited;
//         for (int i = 0; i < nums.size(); i++)
//         {
//             for (int j = 0; j < nums.size(); j++)
//             {
//                 x = nums[i];
//                 y = nums[j];
//                 if (x != y && abs(x) != 2 * abs(y) && abs(y) != 2 * abs(x))
//                 {
//                     z = -(x + y);
//                     if (m[z] > 0)
//                     {
//                         pairs = {x, y, z};
//                         sort(pairs.begin(), pairs.end());
//                         if (isVisited[pairs] == false)
//                         {
//                             ans.push_back(pairs);
//                             isVisited[pairs] = true;
//                         }
//                     }
//                 }
//             }
//         }
//         return ans;
//     }
// };

// class Solution
// {
// public:
//     int longestSubarray(vector<int> &nums)
//     {
//         int firstL = 0, SecondL = 0, MaxL = 0, othersL = 0;

//         int n = nums.size();
//         for (int i = 0; i < n; i++)
//         {
//             if (nums[i] == 1)
//             {
//                 if (othersL == 0)
//                 {
//                     firstL++;
//                 }
//                 if (othersL == 1)
//                 {
//                     SecondL++;
//                 }
//             }
//             else
//             {
//                 if (firstL > 0)
//                 {
//                     if (othersL == 0)
//                     {
//                         othersL++;
//                     }
//                     else if (othersL == 1)
//                     {
//                         MaxL = max(MaxL, firstL + SecondL);
//                         if (i > 1 && nums[i - 1] == 1)
//                         {
//                             firstL = SecondL;
//                             SecondL = 0;
//                         }
//                         else
//                         {
//                             firstL = 0;
//                             SecondL = 0;
//                             othersL = 0;
//                         }
//                     }
//                     else
//                     {
//                         SecondL = 0, firstL = 0;
//                         othersL = 0;
//                     }
//                 }
//             }
//         }

//         MaxL = max(MaxL, firstL + SecondL);

//         return MaxL;
//     }
// };

// class Solution
// {
// public:
//     int longestSubarray(vector<int> &nums)
//     {
//         int other = 0;
//         int ones = 0;
//         vector<int> posibleAns;
//         int n = nums.size();
//         bool flag = false;
//         for (int i = 0; i < n; i++)
//         {
//             if (nums[i] == 1)
//             {
//                 ones++;
//             }
//             else
//             {
//                 if (i < n - 1 && nums[i + 1] == 1 && ones > 0)
//                 {
//                     posibleAns.push_back(ones);
//                     flag = true;
//                 }
//                 else
//                 {
//                     flag = false;
//                 }
//                 ones = 0;
//             }
//         }
//     }
// };
// class Solution
// {
// public:
//     int myAtoi(string s)
//     {
//         int n = s.size();
//         if (n == 0)
//             return 0;
//         long long x = 0;

//         while (!s.empty() && s[0] == ' ')
//         {
//             s.erase(s.begin());
//         }
//         int ch;
//         bool sign = false;
//         int signX = 1;
//         int st, e;
//         st = 48;
//         e = 57;
//         while (!s.empty())
//         {
//             ch = s[0];
//             s.erase(s.begin());
//             if (sign == false && (ch - '+' == 0 || ch - '-' == 0))
//             {
//                 if (ch - '-' == 0)
//                     signX = -1;
//             }
//             else if (ch >= st && ch <= e)
//             {
//                 int z = ch - st;
//                 x = (x * 10L) + z;
//             }
//             else
//             {
//                 break;
//             }
//         }
//         int ans = (x * signX);
//         return ans;
//     }
// };
// class Solution
// {
// public:
//     int myAtoi(string s)
//     {

//         int i = 0;
//         int n = s.size();

//         while (i < n && s[i] == ' ')
//             i++;

//         int pos = 0, neg = 0;
//         if (s[i] == '+')
//         {
//             pos++;
//             i++;
//         }
//         if (s[i] == '-')
//         {
//             neg--;
//             i++;
//         }
//         long long ans = 0;
//         while (i < n && s[i] - '0' >= 0 && s[i] - '9' <= 0)
//         {
//             ans = (ans * 10) + (s[i] - '0');
//         }
//         if (neg > 0 && pos > 0)
//             return 0;

//         if (neg > 0)
//         {
//             ans = ans * -1;
//             ans = ans < INT_MIN ? INT_MIN : ans;
//             return ans;
//         }
//         ans = ans > INT_MAX ? INT_MAX : ans;
//         return ans;
//     }
// };

// class Solution
// {
// public:
//     int myAtoi(string s)
//     {
//         int n = s.size();
//         if (n == 0)
//             return 0;
//         long long int x = 0;

//         while (!s.empty() && s[0] == ' ')
//         {
//             s.erase(s.begin());
//         }
//         int ch;
//         bool sign = false;
//         int signX = 1;
//         int st, e;
//         st = '0';
//         e = '9';
//         while (!s.empty())
//         {
//             ch = s[0];
//             s.erase(s.begin());
//             if (sign == false && (ch - '+' == 0 || ch - '-' == 0))
//             {
//                 if (ch - '-' == 0)
//                     signX = -1;
//             }
//             else if (ch >= st && ch <= e)
//             {
//                 int z = ch - st;
//                 x = (x * 10L) + z;
//             }
//             else
//             {
//                 break;
//             }
//         }
//         int ans = (x * signX);
//         return ans;
//     }
// };
// class Solution
// {
// public:
//     string longestPalindrome(string s)
//     {
//         int n = s.size();
//         int ans = 0;
//         string ansS, countS;
//         int count = 0;
//         int k = 1;
//         if (n == 1)
//             return s;
//         if (n == 2)
//         {
//             if (s[0] == s[1])
//                 return s;
//             return "" + s[0];
//         }
//         for (int i = 1; i < n - 1; i++)
//         {
//             if (s[i - 1] == s[i + 1])
//             {
//                 count += 3;
//                 countS = s[i - 1] + s[i] + s[i + 1];
//                 while (1)
//                 {
//                     if (i - k >= 0 && i + k < n)
//                     {
//                         if (s[i - k] == s[i + k])
//                         {
//                             countS.insert(countS.begin(), s[i - k]);
//                             countS.push_back(s[i + k]);
//                             k++;
//                             count += 2;
//                             continue;
//                         }
//                     }
//                     if (count > ans)
//                     {
//                         ansS = countS;
//                     }
//                     break;
//                 }
//             }
//         }
//         return ansS;
//     }
// };
// class Solution
// {
// public:
//     string longestPalindrome(string s)
//     {
//         int n = s.size();
//         int ans = 0;

//         string ansS, countS;
//         ansS.push_back(s[0]);
//         int count = 0;
//         int k = 2;
//         if (n == 1)
//             return s;
//         if (n == 2)
//         {
//             if (s[0] == s[1])
//                 return s;
//             return "" + s[0];
//         }
//         for (int i = 1; i < n - 1; i++)
//         {
//             if (s[i - 1] == s[i + 1])
//             {
//                 count += 3;
//                 countS.push_back(s[i - 1]);
//                 countS.push_back(s[i]);
//                 countS.push_back(s[i + 1]);
//                 while (1)
//                 {
//                     if (i - k >= 0 && i + k < n)
//                     {
//                         if (s[i - k] == s[i + k])
//                         {
//                             countS.insert(countS.begin(), s[i - k]);
//                             countS.push_back(s[i + k]);
//                             k++;
//                             count += 2;
//                             continue;
//                         }
//                     }
//                     if (count > ans)
//                     {
//                         ansS = countS;
//                     }
//                     count = 0;
//                     countS.clear();
//                     break;
//                 }
//             }
//         }
//         return ansS;
//     }
// };
// class Solution
// {
// public:
//     void help(vector<int> &cookies, vector<int> &bag, int index, int *ans, int k)
//     {

//         if (index == cookies.size())
//         {
//             int max = *max_element(bag.begin(), bag.end());
//             *ans = min(*ans, max);
//             return;
//         }

//         for (int i = 0; i < k; i++)
//         {
//             bag[i] += cookies[index];
//             help(cookies, bag, index + 1, ans, k);
//             bag[i] -= cookies[index];
//         }
//     }
//     int distributeCookies(vector<int> &cookies, int k)
//     {
//         vector<int> bag(k, 0);
//         int ans = INT_MAX;
//         help(cookies, bag, 0, &ans, k);
//         return ans;
//     }
// };
// class Solution
// {
// public:
//     int distributeCookies(vector<int> &c, int k)
//     {
//         int min = *max_element(c.begin(), c.end());
//         int max = accumulate(c.begin(), c.end(), 0);
//         int s = min, e = max, mid, count, sum;

//         while (s <= e)
//         {
//             mid = (s + e) / 2;
//             count = 0;
//             sum = 0;
//             for (auto x : c)
//             {
//                 if (sum + x > mid)
//                 {
//                     count++;
//                     sum = x;
//                 }
//                 else
//                 {
//                     sum += x;
//                 }
//             }
//             count++;
//             if (count <= k)
//             {
//                 e = mid;
//             }
//             else
//             {
//                 s = mid + 1;
//             }
//         }
//         return mid;
//     }
// };

// class Solution
// {
// public:
//     bool buddyStrings(string s, string goal)
//     {
//         int s1 = s.size();
//         int s2 = goal.size();
//         if (s1 != s2)
//             return;
//         map<char, bool> m;
//         if (s.compare(goal) == 1)
//         {
//             for (auto x : s)
//             {
//                 if (m[x] == true)
//                     return true;
//                 m[x] = true;
//             }
//         }
//         int count = 0;
//         char c;
//         int index;
//         for (int i = 0; i < s1; i++)
//         {
//             if (s[i] != goal[i])
//             {
//                 if (count == 0)
//                 {
//                     count++;
//                     index = i;
//                     c = s[i];
//                 }
//                 else if (count == 1)
//                 {
//                     s[i] = s[index];
//                     s[index] = c;
//                     if (s.compare(goal) == 1)
//                         return true;

//                     return false;
//                 }
//             }
//         }
//         return false;
//     }
// };

// class Solution
// {
// public:
//     bool buddyStrings(string s, string goal)
//     {
//         if (s.size() != goal.size() || s.size() <= 1)
//         {
//             return false;
//         }

//         if (s == goal)
//         {
//             unordered_map<char, int> uniqueAlpha(s.begin(), s.end());
//             if (uniqueAlpha.size() < s.size())
//                 return true;
//             return false;
//         }
//         vector<int> diffIndex;
//         for (int i = 0; i < s.size(); i++)
//         {
//             if (s[i] != goal[i])
//                 diffIndex.push_back(i);
//         }
//         if (diffIndex.size() != 2)
//             return false;

//         swap(s[diffIndex[0]], s[diffIndex[1]]);
//         return s == goal;
//     }
// };

// class Solution
// {
// public:
//     bool isMatch(string s, string p)
//     {
//         int slow = 0, fast = 0;
//         int index = 0;
//         int n = p.size();

//         while (slow < p.size())
//         {

//             if (p[slow] != '.' && p[slow] != '*')
//             {
//                 if (s[index] != p[slow])
//                     return false;
//                 if (slow + 1 < n && p[slow + 1] == '*')
//                 {
//                     while (p[index] == s[slow])
//                         index++;
//                     slow += 2;
//                     fast = slow;
//                 }
//                 else
//                 {
//                     slow++;
//                     index++;
//                     fast = slow;
//                 }
//             }
//             if (p[slow] == '.')
//             {
//                 if (slow + 1 < n && p[slow + 1] == '*')
//                 {
//                     if (slow + 1 == n - 1)
//                         return true;
//                     if (slow + 2 < n && p[slow + 2])
//                     {
//                     }
//                 }
//                 else
//                 {
//                     slow++;
//                     fast++;
//                     index++;
//                 }
//             }
//         }
//     }
// };

// class Solution
// {
// public:
//     int romanToInt(string s)
//     {
//         int i = 0;
//         int n = s.size();
//         int ans = 0;
//         while (i < n)
//         {
//             if (s[i] == 'I')
//             {
//                 if (i + 1 < n && s[i + 1] == 'V')
//                 {
//                     ans += 4;
//                     i += 2;
//                 }
//                 else if (i + 1 < n && s[i + 1] == 'X')
//                 {
//                     ans += 9;
//                     i += 2;
//                 }
//                 else
//                 {
//                     ans += 1;
//                     i++;
//                 }
//             }
//             if (s[i] == 'X')
//             {
//                 if (i + 1 < n && s[i + 1] == 'L')
//                 {
//                     ans += 40;
//                     i += 2;
//                 }
//                 else if (i + 1 < n && s[i + 1] == 'C')
//                 {
//                     ans += 90;
//                     i += 2;
//                 }
//                 else
//                 {
//                     ans += 10;
//                     i++;
//                 }
//             }
//             if (s[i] == 'C')
//             {
//                 if (i + 1 < n && s[i + 1] == 'D')
//                 {
//                     ans += 400;
//                     i += 2;
//                 }
//                 else if (i + 1 < n && s[i + 1] == 'M')
//                 {
//                     ans += 900;
//                     i += 2;
//                 }
//                 else
//                 {
//                     ans += 100;
//                     i++;
//                 }
//             }
//             switch (s[i])
//             {
//             case 'V':
//                 ans += 5;
//                 break;
//             case 'L':
//                 ans += 50;
//                 break;
//             case 'D':
//                 ans += 500;
//                 break;
//             case 'M':
//                 ans += 1000;
//                 break;
//             default:
//                 break;
//             }
//             i++;
//         }
//         return ans;
//     }
// };
// class Solution
// {
// public:
//     bool buddyStrings(string s, string goal)
//     {
//         int s1 = s.size();
//         int s2 = goal.size();

//         if (s1 != s2)
//             return false;

//         char c1, c2;
//         int count = 0;
//         vector<int> v(26);
//         bool flag = false;
//         for (int i = 0; i < s1; i++)
//         {
//             if (s[i] != goal[i])
//             {
//                 if (count == 0)
//                 {
//                     count++;
//                     c1 = s[i];
//                     c2 = goal[i];
//                 }
//                 else if (count == 1)
//                 {
//                     if (s[i] == c2 && goal[i] == c1)
//                     {
//                         flag = true;
//                     }
//                     else
//                         return false;
//                 }
//                 else
//                 {
//                     return false;
//                 }
//             }
//             else
//             {
//                 v[s[i] - 'a']++;
//             }
//         }
//         if (flag == true)
//             return true;
//         for (int x : v)
//         {
//             if (x >= 2)
//                 return true;
//         }
//         return false;
//     }
// };
// class Solution
// {
//     int ans;

// public:
//     void check(int n, vector<vector<int>> &requests, vector<int> &building, int selected)
//     {
//         if (n == requests.size())
//         {
//             for (auto x : building)
//                 if (x != 0)
//                     return;
//             ans = max(ans, selected);

//             return;
//         }

//         check(n + 1, requests, building, selected);
//         building[requests[n][0]]--;
//         building[requests[n][1]]++;
//         check(n + 1, requests, building, selected + 1);
//         building[requests[n][0]]++;
//         building[requests[n][1]]--;
//     }
//     int maximumRequests(int n, vector<vector<int>> &requests)
//     {
//         ans = 0;
//         vector<int> building(n, 0);
//         check(0, requests, building, 0);
//     }
// };
// class Solution
// {
// public:
//     int maximumRequests(int n, vector<vector<int>> &requests)
//     {
//         vector<int> building(n, 0);

//         for (auto x : requests)
//         {
//             building[x[0]]--;
//             building[x[1]]++;
//         }
//         int plus = 0, minus = 0;
//         for (auto x : building)
//         {
//             if (x > 0)
//                 plus++;
//             if (x < 0)
//                 minus++;
//         }
//         if (plus - minus == 0)
//             return plus;
//         return max(plus, minus);
//     }
// };
// class Solution
// {
//     map<int, bool> isVisit;

// public:
//     void traverse(vector<vector<int>> movments, int index, int start)
//     {
//         if (isVisit[index] == true)
//         {
//             return;
//         }
//     }
//     int maximumRequests(int n, vector<vector<int>> &requests)
//     {
//         vector<vector<int>> movments(n);
//         int completed = 0;
//         for (auto x : requests)
//         {
//             if (x[0] == x[1])
//                 completed++;
//             else
//                 movments[x[0]].push_back(x[1]);
//         }

//         for (int i = 0; i < n; i++)
//         {

//             for (auto z : movments[i])
//             {
//                 movments[i].erase(movments[i].begin());
//             }
//         }
//     }
// };