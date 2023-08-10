#include<bits/stdc++.h>

using namespace std;

int main(){
    char ch[5] = {'a','b','4','f','g'};
    char c[10] = "ar mj";
    cout<<ch<<" "<<c;
    cout<<sizeof(ch)<<sizeof(c);
    // cin>>c;
    // cout<<c;
    string s = "afssfs";
    cout<<endl<<s.length()<<endl<<s.size();
}
class Solution {
public:
    bool isPalindrome(string st) {
        for(int i=0; i<st.size(); i++){
            if(st[i] >= 'A' && st[i] <='Z')
                st[i] = tolower(st[i]);
            else if(st[i] >= 'a' && st[i] <= 'z') 
                continue;
            else
                st.erase(st.begin() + i);        
        }
        int s = 0, e = st.size()-1;
        while(s<e){
            if(st[s++] != st[e--]) return false;
        }
        return true;
    }
};
class Solution
{
    public:
    //Function to find the maximum occurring character in a string.
    char getMaxOccuringChar(string str)
    {
        // Your code here
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> count(26, 0);
        int ans = INT_MAX;
        for(auto x: str){
            count[x-'a']++;
            ans = max(ans, count[x-'a']);
        }
        return ans;
    }

};
class Solution
{
    public:
    //Function to find the maximum occurring character in a string.
    char getMaxOccuringChar(string str)
    {
        // Your code here
        // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> count(26, 0);
        int ans = INT_MIN;
        char ch;
        for(auto x: str){
            count[x-'a']++;
            if(count[x-'a'] > ans){
                ans = count[x-'a'];
                ch = x;
            }
            if(count[x-'a'] == ans){
                
                ch = min(ch, x);
            }
        }
        return ch;
    }

};
