#include <bits/stdc++.h>

using namespace std;
#define MOD 1000000007
#define mod 1e9 + 7


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
    }
};

class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        int firstL = 0, SecondL = 0, MaxL = 0, othersL = 0;

        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 1)
            {
                if (othersL == 0)
                {
                    firstL++;
                }
                if (othersL == 1)
                {
                    SecondL++;
                }
            }
            else
            {
                if (firstL > 0)
                {
                    if (othersL == 0)
                    {
                        othersL++;
                    }
                    else if (othersL == 1)
                    {
                        MaxL = max(MaxL, firstL + SecondL);
                        if (i > 1 && nums[i - 1] == 1)
                        {
                            firstL = SecondL;
                            SecondL = 0;
                        }
                        else
                        {
                            firstL = 0;
                            SecondL = 0;
                            othersL = 0;
                        }
                        
                    }
                    else
                    {
                        SecondL = 0, firstL = 0;
                        othersL = 0;
                    }
                }
            }
        }

        MaxL = max(MaxL, firstL + SecondL);

        return MaxL;
    }
};

class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        int other = 0;
        int ones = 0;
        vector<int> posibleAns;
        int n = nums.size();
        bool flag = false;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 1)
            {
                ones++;
            }
            else
            {
                if (i < n - 1 && nums[i + 1] == 1 && ones > 0)
                {
                    posibleAns.push_back(ones);
                    flag = true;
                }
                else
                {
                    flag = false;
                }
                ones = 0;
            }
        }
    }
};
class Solution
{
public:
    int myAtoi(string s)
    {
        int n = s.size();
        if (n == 0)
            return 0;
        long long x = 0;

        while (!s.empty() && s[0] == ' ')
        {
            s.erase(s.begin());
        }
        int ch;
        bool sign = false;
        int signX = 1;
        int st, e;
        st = 48;
        e = 57;
        while (!s.empty())
        {
            ch = s[0];
            s.erase(s.begin());
            if (sign == false && (ch - '+' == 0 || ch - '-' == 0))
            {
                if (ch - '-' == 0)
                    signX = -1;
            }
            else if (ch >= st && ch <= e)
            {
                int z = ch - st;
                x = (x * 10L) + z;
            }
            else
            {
                break;
            }
        }
        int ans = (x * signX);
        return ans;
    }
};
class Solution
{
public:
    int myAtoi(string s)
    {

        int i = 0;
        int n = s.size();

        while (i < n && s[i] == ' ')
            i++;

        int pos = 0, neg = 0;
        if (s[i] == '+')
        {
            pos++;
            i++;
        }
        if (s[i] == '-')
        {
            neg--;
            i++;
        }
        long long ans = 0;
        while (i < n && s[i] - '0' >= 0 && s[i] - '9' <= 0)
        {
            ans = (ans * 10) + (s[i] - '0');
        }
        if (neg > 0 && pos > 0)
            return 0;

        if (neg > 0)
        {
            ans = ans * -1;
            ans = ans < INT_MIN ? INT_MIN : ans;
            return ans;
        }
        ans = ans > INT_MAX ? INT_MAX : ans;
        return ans;
    }
};

class Solution
{
public:
    int myAtoi(string s)
    {
        int n = s.size();
        if (n == 0)
            return 0;
        long long int x = 0;

        while (!s.empty() && s[0] == ' ')
        {
            s.erase(s.begin());
        }
        int ch;
        bool sign = false;
        int signX = 1;
        int st, e;
        st = '0';
        e = '9';
        while (!s.empty())
        {
            ch = s[0];
            s.erase(s.begin());
            if (sign == false && (ch - '+' == 0 || ch - '-' == 0))
            {
                if (ch - '-' == 0)
                    signX = -1;
            }
            else if (ch >= st && ch <= e)
            {
                int z = ch - st;
                x = (x * 10L) + z;
            }
            else
            {
                break;
            }
        }
        int ans = (x * signX);
        return ans;
    }
};
class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.size();
        int ans = 0;
        string ansS, countS;
        int count = 0;
        int k = 1;
        if (n == 1)
            return s;
        if (n == 2)
        {
            if (s[0] == s[1])
                return s;
            return "" + s[0];
        }
        for (int i = 1; i < n - 1; i++)
        {
            if (s[i - 1] == s[i + 1])
            {
                count += 3;
                countS = s[i - 1] + s[i] + s[i + 1];
                while (1)
                {
                    if (i - k >= 0 && i + k < n)
                    {
                        if (s[i - k] == s[i + k])
                        {
                            countS.insert(countS.begin(), s[i - k]);
                            countS.push_back(s[i + k]);
                            k++;
                            count += 2;
                            continue;
                        }
                    }
                    if (count > ans)
                    {
                        ansS = countS;
                    }
                    break;
                }
            }
        }
        return ansS;
    }
};
class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.size();
        int ans = 0;

        string ansS, countS;
        ansS.push_back(s[0]);
        int count = 0;
        int k = 2;
        if (n == 1)
            return s;
        if (n == 2)
        {
            if (s[0] == s[1])
                return s;
            return "" + s[0];
        }
        for (int i = 1; i < n - 1; i++)
        {
            if (s[i - 1] == s[i + 1])
            {
                count += 3;
                countS.push_back(s[i - 1]);
                countS.push_back(s[i]);
                countS.push_back(s[i + 1]);
                while (1)
                {
                    if (i - k >= 0 && i + k < n)
                    {
                        if (s[i - k] == s[i + k])
                        {
                            countS.insert(countS.begin(), s[i - k]);
                            countS.push_back(s[i + k]);
                            k++;
                            count += 2;
                            continue;
                        }
                    }
                    if (count > ans)
                    {
                        ansS = countS;
                    }
                    count = 0;
                    countS.clear();
                    break;
                }
            }
        }
        return ansS;
    }
};
class Solution
{
public:
    void help(vector<int> &cookies, vector<int> &bag, int index, int *ans, int k)
    {

        if (index == cookies.size())
        {
            int max = *max_element(bag.begin(), bag.end());
            *ans = min(*ans, max);
            return;
        }

        for (int i = 0; i < k; i++)
        {
            bag[i] += cookies[index];
            help(cookies, bag, index + 1, ans, k);
            bag[i] -= cookies[index];
        }
    }
    int distributeCookies(vector<int> &cookies, int k)
    {
        vector<int> bag(k, 0);
        int ans = INT_MAX;
        help(cookies, bag, 0, &ans, k);
        return ans;
    }
};
class Solution
{
public:
    int distributeCookies(vector<int> &c, int k)
    {
        int min = *max_element(c.begin(), c.end());
        int max = accumulate(c.begin(), c.end(), 0);
        int s = min, e = max, mid, count, sum;

        while (s <= e)
        {
            mid = (s + e) / 2;
            count = 0;
            sum = 0;
            for (auto x : c)
            {
                if (sum + x > mid)
                {
                    count++;
                    sum = x;
                }
                else
                {
                    sum += x;
                }
            }
            count++;
            if (count <= k)
            {
                e = mid;
            }
            else
            {
                s = mid + 1;
            }
        }
        return mid;
    }
};

class Solution
{
public:
    bool buddyStrings(string s, string goal)
    {
        int s1 = s.size();
        int s2 = goal.size();
        if (s1 != s2)
            return;
        map<char, bool> m;
        if (s.compare(goal) == 1)
        {
            for (auto x : s)
            {
                if (m[x] == true)
                    return true;
                m[x] = true;
            }
        }
        int count = 0;
        char c;
        int index;
        for (int i = 0; i < s1; i++)
        {
            if (s[i] != goal[i])
            {
                if (count == 0)
                {
                    count++;
                    index = i;
                    c = s[i];
                }
                else if (count == 1)
                {
                    s[i] = s[index];
                    s[index] = c;
                    if (s.compare(goal) == 1)
                        return true;

                    return false;
                }
            }
        }
        return false;
    }
};

class Solution
{
public:
    bool buddyStrings(string s, string goal)
    {
        if (s.size() != goal.size() || s.size() <= 1)
        {
            return false;
        }

        if (s == goal)
        {
            unordered_map<char, int> uniqueAlpha(s.begin(), s.end());
            if (uniqueAlpha.size() < s.size())
                return true;
            return false;
        }
        vector<int> diffIndex;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != goal[i])
                diffIndex.push_back(i);
        }
        if (diffIndex.size() != 2)
            return false;

        swap(s[diffIndex[0]], s[diffIndex[1]]);
        return s == goal;
    }
};

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int slow = 0, fast = 0;
        int index = 0;
        int n = p.size();

        while (slow < p.size())
        {

            if (p[slow] != '.' && p[slow] != '*')
            {
                if (s[index] != p[slow])
                    return false;
                if (slow + 1 < n && p[slow + 1] == '*')
                {
                    while (p[index] == s[slow])
                        index++;
                    slow += 2;
                    fast = slow;
                }
                else
                {
                    slow++;
                    index++;
                    fast = slow;
                }
            }
            if (p[slow] == '.')
            {
                if (slow + 1 < n && p[slow + 1] == '*')
                {
                    if (slow + 1 == n - 1)
                        return true;
                    if (slow + 2 < n && p[slow + 2])
                    {
                    }
                }
                else
                {
                    slow++;
                    fast++;
                    index++;
                }
            }
        }
    }
};

class Solution
{
public:
    int romanToInt(string s)
    {
        int i = 0;
        int n = s.size();
        int ans = 0;
        while (i < n)
        {
            if (s[i] == 'I')
            {
                if (i + 1 < n && s[i + 1] == 'V')
                {
                    ans += 4;
                    i += 2;
                }
                else if (i + 1 < n && s[i + 1] == 'X')
                {
                    ans += 9;
                    i += 2;
                }
                else
                {
                    ans += 1;
                    i++;
                }
            }
            if (s[i] == 'X')
            {
                if (i + 1 < n && s[i + 1] == 'L')
                {
                    ans += 40;
                    i += 2;
                }
                else if (i + 1 < n && s[i + 1] == 'C')
                {
                    ans += 90;
                    i += 2;
                }
                else
                {
                    ans += 10;
                    i++;
                }
            }
            if (s[i] == 'C')
            {
                if (i + 1 < n && s[i + 1] == 'D')
                {
                    ans += 400;
                    i += 2;
                }
                else if (i + 1 < n && s[i + 1] == 'M')
                {
                    ans += 900;
                    i += 2;
                }
                else
                {
                    ans += 100;
                    i++;
                }
            }
            switch (s[i])
            {
            case 'V':
                ans += 5;
                break;
            case 'L':
                ans += 50;
                break;
            case 'D':
                ans += 500;
                break;
            case 'M':
                ans += 1000;
                break;
            default:
                break;
            }
            i++;
        }
        return ans;
    }
};
class Solution
{
public:
    bool buddyStrings(string s, string goal)
    {
        int s1 = s.size();
        int s2 = goal.size();

        if (s1 != s2)
            return false;

        char c1, c2;
        int count = 0;
        vector<int> v(26);
        bool flag = false;
        for (int i = 0; i < s1; i++)
        {
            if (s[i] != goal[i])
            {
                if (count == 0)
                {
                    count++;
                    c1 = s[i];
                    c2 = goal[i];
                }
                else if (count == 1)
                {
                    if (s[i] == c2 && goal[i] == c1)
                    {
                        flag = true;
                    }
                    else
                        return false;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                v[s[i] - 'a']++;
            }
        }
        if (flag == true)
            return true;
        for (int x : v)
        {
            if (x >= 2)
                return true;
        }
        return false;
    }
};
class Solution
{
    int ans;

public:
    void check(int n, vector<vector<int>> &requests, vector<int> &building, int selected)
    {
        if (n == requests.size())
        {
            for (auto x : building)
                if (x != 0)
                    return;
            ans = max(ans, selected);

            return;
        }

        check(n + 1, requests, building, selected);
        building[requests[n][0]]--;
        building[requests[n][1]]++;
        check(n + 1, requests, building, selected + 1);
        building[requests[n][0]]++;
        building[requests[n][1]]--;
    }
    int maximumRequests(int n, vector<vector<int>> &requests)
    {
        ans = 0;
        vector<int> building(n, 0);
        check(0, requests, building, 0);
    }
};
class Solution
{
public:
    int maximumRequests(int n, vector<vector<int>> &requests)
    {
        vector<int> building(n, 0);

        for (auto x : requests)
        {
            building[x[0]]--;
            building[x[1]]++;
        }
        int plus = 0, minus = 0;
        for (auto x : building)
        {
            if (x > 0)
                plus++;
            if (x < 0)
                minus++;
        }
        if (plus - minus == 0)
            return plus;
        return max(plus, minus);
    }
};
class Solution
{
    map<int, bool> isVisit;

public:
    void traverse(vector<vector<int>> movments, int index, int start)
    {
        if (isVisit[index] == true)
        {
            return;
        }
    }
    int maximumRequests(int n, vector<vector<int>> &requests)
    {
        vector<vector<int>> movments(n);
        int completed = 0;
        for (auto x : requests)
        {
            if (x[0] == x[1])
                completed++;
            else
                movments[x[0]].push_back(x[1]);
        }

        for (int i = 0; i < n; i++)
        {

            for (auto z : movments[i])
            {
                movments[i].erase(movments[i].begin());
            }
        }
    }
};