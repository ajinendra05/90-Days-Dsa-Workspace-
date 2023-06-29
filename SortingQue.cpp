#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
bool sortFun(vector<vector<int>>& v1,vector<vector<int>>& v2){
    return v1[0]<v2[0];
}
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> x;
        sort(intervals.begin(),intervals.end());
        int n=intervals.size();
        for(int i=1;i<intervals.size();i++){
            int j=i;
            while(intervals[j-1][1]>=intervals[i][0]&&i<intervals.size()){
                i++;
              intervals[j-1][1]=max(intervals[j-1][1],intervals[i][1]);
              intervals.erase(intervals.begin()+i);
            }
        }
         return intervals;
    }
};

class Solution {
public:
bool sortFun(vector<vector<int>>& v1,vector<vector<int>>& v2){
    return v1[0]<v2[0];
}
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> x;
        sort(intervals.begin(),intervals.end());
        int n=intervals.size();
        for(int i=1;i<intervals.size();i++){
            if(intervals[i-1][1]>=intervals[i][0]){
              intervals[i-1][1]=max(intervals[i-1][1],intervals[i][1]);
              intervals.erase(intervals.begin()+i);
              i--;
            }
        }
         return intervals;
    }
};




int main(){
    return 0;
}
