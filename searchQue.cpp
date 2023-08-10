#include <bits/stdc++.h>

using namespace std;

bool StringSearch(string s, char t)
{
    if (s.size() == 0)
        return false;

    for (char x : s)
    {
        if (x == t)
            return true;
    }
    return false;
}

int StringSearch2(string s, char t)
{
    if (s.size() == 0)
        return -1;
    int i = 0;
    for (char x : s)
    {

        if (x == t)
            return i;
        i++;
    }
    return -1;
}

bool SearchInBetween(int *arr, int s, int first, int end)
{
    if (end < first)
        return -1;

    for (int i = first; i <= end; i++)
    {
        if (arr[i] == s)
            return true;
    }
    return false;
}

bool SearchIn2darray(int n, int m, int a[][2], int ele)
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == ele)
                return true;
        }
    }
    return false;
}
vector<int> SearchIn2darray2(int n, int m, int a[][2], int ele)
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == ele)
                return {i, j};
        }
    }
    return {-1, -1};
}

int main()
{
    cout << StringSearch2("ajsndhf", 'n');

    int a[3][2] = {{1, 2}, {2, 6}, {7, 8}};

    cout << SearchIn2darray(3, 2, a, 7);

    return 0;
}
class Solution
{
public:
    int findNumbers(vector<int> &nums)
    {
        int count = 0;
        int d;
        for (int i = 0; i < nums.size(); i++)
        {
            d = log10(nums[i]) + 1;
            d % 2 == 0 ? count++ : count;
        }
        return count;
    }
};

class Solution
{
public:
    int maximumWealth(vector<vector<int>> &accounts)
    {
        int n = accounts.size();
        int m = accounts[0].size();
        int greatest = INT_MIN;
        int sum = 0;

        for (int i = 0; i < n; i++)
        {
            sum = 0;
            for (int j = 0; j < m; j++)
            {
                sum += accounts[i][j];
            }
            greatest = max(sum, greatest);
        }
        // for(auto x:accounts){
        //     for(auto y: x){
        //       sum+=y;
        //     }
        //     greatest=max(sum,greatest);
        // }
        return greatest;
    }
};

class Solution
{

    map<pair<int, int>, bool> isVisited;
    int size;
    int n;
    int m;
    vector<vector<char>> board;

public:
    bool traverss(string word, int i, int x, int y)
    {
        if (isVisited[make_pair(x, y)] == true)
            return false;
        if (size == i)
        {
            return true;
        }

        isVisited[make_pair(x, y)] = true;
        bool a = false, b = false, c = false, d = false;
        if (check(x - 1, y, word[i]))
        {
            a = traverss(word, i + 1, x - 1, y);
        }
        if (check(x, y - 1, word[i]))
        {
            b = traverss(word, i + 1, x, y - 1);
        }
        if (check(x + 1, y, word[i]))
        {
            c = traverss(word, i + 1, x + 1, y);
        }
        if (check(x, y + 1, word[i]))
        {
            d = traverss(word, i + 1, x, y + 1);
        }
        isVisited[make_pair(x, y)] = false;
        return (a || b || c || d);
    }
    bool check(int i, int j, char s)
    {
        if (i < 0 || i >= n || j < 0 || j >= m)
        {
            return false;
        }
        if (board[i][j] == s)
            return true;

        return false;
    }
    bool exist(vector<vector<char>> &board, string word)
    {
        this->board = board;
        this->n = board.size();
        this->m = board[0].size();
        this->size = word.size();

        bool flag = false;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == word[0])
                {
                    flag = traverss(word, 1, i, j);
                }
                if (flag == true)
                    return true;
            }
        }
        return false;
    }
};

// Binary search

class Solution
{
public:
    vector<int> searchRange(vector<int> &arr, int target)
    {
        int s = 0;
        int e = arr.size() - 1;
        int mid;
        vector<int> ans;
        bool flag = false;
        while (s <= e)
        {
            mid = s + (e - s) / 2;
            if (arr[mid] == target)
            {
                flag = true;
            }

            if (arr[mid] < target)
                s = mid + 1;
            else
                e = mid - 1;
        }
        ans.push_back(s);
        while (s <= e)
        {
            mid = s + (e - s) / 2;
            if (arr[mid] == target)
            {
                flag = true;
            }

            if (arr[mid] <= target)
                s = mid + 1;
            else
                e = mid - 1;
        }
        ans.push_back(e);

        if (flag)
            return ans;

        return vector<int>({-1, -1});
    }
};

class Solution
{
public:
    int peakIndexInMountainArray(vector<int> &arr)
    {

        int s = 0;
        int e = arr.size() - 1;
        int mid;
        int m1, m2;
        while (s <= e)
        {

            if (s == e)
                return s;
            mid = s + (e - s) / 2;
            m1 = s + (mid - s) / 2;
            m2 = mid + (e - mid) / 2;

            if (arr[s] < arr[m1] && arr[m1] < arr[mid])
                s = mid;
            else
                e = mid;
        }
        return s;
    }
};

class Solution
{
public:
    int peakIndexInMountainArray(vector<int> &arr)
    {
        if (arr.size() == 3)
            return 1;

        int s = 0;
        int e = arr.size() - 1;
        int mid;
        int m1, m2;
        while (s <= e)
        {
            mid = s + (e - s) / 2;

            if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1])
            {
                return mid;
            }
            if (arr[mid - 1] < arr[mid])
            {
                s = mid;
            }
            else
            {
                e = mid + 1;
            }
        }

        return mid;
    }
};

class Solution
{
public:
    int peakIndexInMountainArray(vector<int> &arr)
    {
        if (arr.size() == 3)
            return 1;

        int s = 0;
        int e = arr.size() - 1;
        int mid;
        int m1, m2;
        while (s != e)
        {
            mid = s + (e - s) / 2;

            if (arr[mid] > arr[mid + 1])
            {
                e = mid;
            }
            else
            {
                s = mid + 1;
            }
        }

        return s;
    }
};

class Solution
{

public:
    int search(vector<int> &arr, int target)
    {
        int s = 0;
        int e = arr.size() - 1;
        if (e < 3)
        {
            for (int i = 0; i <= e; i++)
            {
                if (arr[i] == target)
                    return i;
            }
            return -1;
        }
        int mid;
        while (s != e)
        {

            mid = s + (e - s) / 2;

            if (arr[mid] < arr[s])
                e = mid - 1;
            else
                s == mid ? s = mid + 1 : s = mid;
        }

        int pivit = s;
        s = 0;
        e = pivit;
        while (s <= e)
        {
            mid = s + (e - s) / 2;
            if (arr[mid] == target)
                return mid;
            if (arr[mid] < target)
                s = mid + 1;
            else
                e = mid - 1;
        }
        s = pivit + 1;
        e = arr.size() - 1;
        while (s <= e)
        {
            mid = s + (e - s) / 2;
            if (arr[mid] == target)
                return mid;
            if (arr[mid] < target)
                s = mid + 1;
            else
                e = mid - 1;
        }
        return -1;
    }
};

class Solution
{

public:
    int search(vector<int> &arr, int target)
    {
        int s = 0;
        int e = arr.size() - 1;
        if (e < 3)
        {
            for (int i = 0; i <= e; i++)
            {
                if (arr[i] == target)
                    return i;
            }
            return -1;
        }
        int mid;
        while (s != e)
        {

            mid = s + (e - s) / 2;

            if (arr[mid] < arr[s])
                e = mid - 1;
            else if (arr[mid] > arr[mid + 1])
            {
                s = mid;
                break;
            }
            else
                s = mid + 1;
        }

        int pivit = s;
        s = 0;
        e = pivit;
        while (s <= e)
        {
            mid = s + (e - s) / 2;
            if (arr[mid] == target)
                return mid;
            if (arr[mid] < target)
                s = mid + 1;
            else
                e = mid - 1;
        }
        s = pivit + 1;
        e = arr.size() - 1;
        while (s <= e)
        {
            mid = s + (e - s) / 2;
            if (arr[mid] == target)
                return mid;
            if (arr[mid] < target)
                s = mid + 1;
            else
                e = mid - 1;
        }
        return -1;
    }
};
// search in roated array 
//without finding pivit
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int s = 0, e = n-1;
        
        while(s <= e){
            int m = (s+e) / 2;
            
            if(target == nums[m]) return m;
            if(nums[s] <= nums[m]){     // we're in first part
                if(target >= nums[s] && target <= nums[m])
                    e = m-1;              
                else
                    s = m+1;
            } 
            // we're in 2nd half 
            else {                              
                if(nums[m] <= target && nums[e] >= target)
                    s = m + 1;
                else
                    e = m - 1;
            }
        }
        
        return -1;
    }
};

// after finding pivit
class Solution
{

public:
    int search(vector<int> &arr, int target)
    {
        int s = 0;
        int e = arr.size() - 1;

        int mid;

        while (s != e)
        {

            mid = s + (e - s) / 2;

            if (arr[mid] < arr[s])
                e = mid - 1;
            else if (arr[mid] > arr[mid + 1])
            {
                s = mid;
                break;
            }
            else
                s = mid + 1;
        }

        int pivit = s;
        s = 0;
        e = pivit;
        while (s <= e)
        {
            mid = s + (e - s) / 2;
            if (arr[mid] == target)
                return mid;
            if (arr[mid] < target)
                s = mid + 1;
            else
                e = mid - 1;
        }
        s = pivit + 1;
        e = arr.size() - 1;
        while (s <= e)
        {
            mid = s + (e - s) / 2;
            if (arr[mid] == target)
                return mid;
            if (arr[mid] < target)
                s = mid + 1;
            else
                e = mid - 1;
        }
        return -1;
    }
};

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int s1 = 0, s2 = 0, n = nums1.size(), m = nums2.size();
        int e1=n-1, e2=m-1;
        int siz =  (n + m + 1) / 2;
        int m1,m2;
        double ans;
        while(s1<=e1){
            m1=(s1+e1)/2;
            m2=siz-(m1+1);

           if(nums1[m1]<nums2[m2]&&nums2[m2-1]<nums1[m1+1]){
             if((n + n) % 2 == 0){
                ans=min(nums1[m1],nums2[m2-1])/2LL+max(nums1[m1+1],nums2[m2])/2LL;
                return ans;

             }else{
                ans=min(nums1[m1],nums2[m2-1]);
                return ans;
             }
           }
           if(nums1[m1]>nums2[m2]){
            e1=m1-1;
           }else{
            s1=m1+1;
           }


        }
    }
};

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int s1 = 0, s2 = 0, n = nums1.size(), m = nums2.size();
        int e1=n, e2=m;
        int siz =  (n + m + 1) / 2;
        int m1,m2;
        double ans;
        while(s1<=e1){
            m1=(s1+e1)/2;
            m2=siz-(m1);

            int l1=m1==0?INT_MIN:nums1[m1-1];
            int l2=m2==0?INT_MIN:nums2[m2-1];
            int r1=m1==n?INT_MAX:nums1[m1];
            int r2=m2==m?INT_MAX:nums2[m2];

           if(l1<r2&&l2<r1){
             if((n + n) % 2 == 0){
                ans=min(l1,l2)/2LL+max(r1,r2)/2LL;
                return ans;

             }else{
                ans=min(l1,l2);
                return ans;
             }
           }
           if(l1>r2){
            e1=m1-1;
           }else{
            s1=m1+1;
           }


        }
    }
};

//Agressive Cow
class Solution {
    bool isPossible(int mid, int k, vector<int> &nums){
        int cow ;
        
    }
public:

    int solve(int n, int k, vector<int> &nums) {
    
        // Write your code here
        sort(nums.begin(),nums.end());
        int s=1;
        int max=*max_element(nums.begin(),nums.end());
        int min=*min_element(nums.begin(),nums.end());
        int e=max;
        
        int mid;
        int p=1;
        int ans=-1;
        int last=0;
        while(s<=e){
            p=1;
            
            last=nums[0];
            mid=s+(e-s)/2;
            
            for(int i=0;i<n;i++){
                if(nums[i]-last>=mid){
                   p++;
                   last=nums[i];
                    
                }
            }
           

            if(p<k)e=mid-1;
            else{
                ans=mid;
                s=mid+1;}
        }

        return ans;
        
    }
};