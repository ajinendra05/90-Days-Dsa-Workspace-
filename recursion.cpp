#include <bits/stdc++.h>

using namespace std;

int SumOfDigits(int x)
{

    if (x == 0)
        return 0;

    return x % 10 + SumOfDigits(x / 10);
    // if(x%10==x){
    //     return x%10 * SumOfDigits(x/10);
    // }
}

int ReversNum(int num, int revNum)
{
    if (num == 0)
        return revNum;

    revNum = revNum * 10 + (num % 10);
    return ReversNum(num / 10, revNum);
}

bool palindromOrNot(int num)
{
    if (num % 10 == num)
        return true;
    int digit = log10(num) + 1;

    return num % 10 == num / int(pow(10, digit - 1)) && palindromOrNot((num % int(pow(10, digit - 1))) / 10);
}

int countZeross(int x, int count)
{
    if (x % 10 == x)
    {
        if (x == 0)
            return ++count;
        return count;
    }
    if (x % 10 == 0)
        return countZeross(x / 10, ++count);
    return countZeross(x / 10, count);
}

int LC1342(int num, int count)
{
    if (num == 0)
        return count;

    if (num & 1 == 0)
        return LC1342(num / 2, ++count);
    return LC1342(num - 1, ++count);
}

vector<int> checkPos(vector<int> a, int target, int index)
{
    vector<int> x;
    if (index == a.size())
    {

        return x;
    }
    if (a[index] == target)
    {
        x.push_back(index);
        vector<int> z = checkPos(a, target, index + 1);
        z.push_back(index);
        return z;
    }
    else
        return checkPos(a, target, index + 1);
}

// PATERN
void triangle(int r, int c)
{
    if (r == 0)
        return;
    if (c < r)
    {
        cout << "*";
        triangle(r, c + 1);
        //   cout<<"*";     for up
    }
    else
    {
        cout << endl;
        triangle(r - 1, 0);
    }
}
void triangle1(int r, int c, int s)
{
    if (r == 0)
        return;
    if (c > 0)
    {
        if (s > r - c)
        {
            cout << " ";
            triangle1(r, c - 1, s);
        }
        else
        {
            cout << "*";
            triangle1(r, c - 1, s);
        }

        //   cout<<"*";     for up
    }
    else
    {
        cout << endl;
        triangle1(r - 1, r - 1, s + 1);
    }
}

// subsets
vector<string> liststr;
void subseting(string str, string str2)
{
    if (str2.empty())
    {
        if (!str.empty())
            liststr.push_back(str);
        return;
    }

    subseting(str + str2.at(0), str2.substr(1));
    subseting(str, str2.substr(1));
}

vector<string> subseting2(string str, string str2)
{
    vector<string> complete;
    if (str2.empty())
    {
        // if(!str.empty())
        // liststr.push_back(str);
        vector<string> v{str};
        // cout<<"me";
        // cout<<v[0];
        // cout<<endl;
        return v;
    }
    // complete.insert()
    vector<string> left = subseting2(str + str2.at(0), str2.substr(1));
    vector<string> right = subseting2(str, str2.substr(1));
    copy(left.begin(), left.end(), back_inserter(complete));
    copy(right.begin(), right.end(), back_inserter(complete));
    // auto a=subseting(str+str2.at(0),/
    //   merge(subseting2(str+str2.at(0),str2.substr(1)).begin(),subseting2(str+str2.at(0),str2.substr(1)).end(),subseting2(str,str2.substr(1)).begin(),subseting2(str,str2.substr(1)).end(),complete.begin());
    //     for(auto e :complete){
    //     cout<<e<<endl;
    //    }
    return complete;
    // vector<string> left=  subseting(str+str2.at(0),str2.substr(1));
    // vector<string> right=  subseting(str,str2.substr(1));
}

list<list<int>> numSubSet(int arr[], int n)
{

    list<list<int>> outerList = list<list<int>>();

    for (int i = 0; i < n; i++)
    {

        for (auto x : outerList)
        {
            list<int> a = list<int>(x);
            a.push_back(arr[i]);
            outerList.push_back(x);
        }
    }

    return outerList;
}


vector<string> subseting3Permutation(string str, string str2)
{
    vector<string> complete;
    vector<string> newstr;
    if (str2.empty())
    {
        vector<string> v{str};
      
        return v;
    }
    // complete.insert()
    for(int i=0;i<=str.size();i++){
        string s= str.substr(0,i);
        string f=str2.substr(i, str.size());

        newstr =(subseting3Permutation(s+str2.at(0)+f,str2.substr(1)));
          copy(newstr.begin(), newstr.end(), back_inserter(complete));
    }
    // vector<string> left = subseting2(str + str2.at(0), str2.substr(1));
    // vector<string> right = subseting2(str, str2.substr(1));
    // copy(left.begin(), left.end(), back_inserter(newstr));
    // copy(right.begin(), right.end(), back_inserter(complete));
  
    return complete;
    
}



class Solution17 {
    string wordMap[8] ={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    map<string,string> wordmap2;
    vector<string> wordsList;
    string word;
public:
Solution17(){
    for(int i=2;i<=9;i++){
        cout<<to_string(i);
        wordmap2[to_string(i)]=wordMap[i-2];
       
    }
}
    void calWord(string str,string str2){
 
        if(str2.empty()){
            if(!str.empty()){
                wordsList.push_back(str);
             
            }
            return;
        }
       string s="";
       s.push_back(str2.at(0));
      
        for(int i=0;i<wordmap2[s].size();i++){
            
            calWord(str+wordmap2[s].at(i),str2.substr(1));
        }
     

    }
    vector<string> letterCombinations(string digits) {
        calWord("",digits);
        return wordsList;
    }
};

vector<vector<int>> finalList;
void rollDice(int remain,vector<int> listt){
    if(remain==0){
        if(!listt.empty()){
            finalList.push_back(listt);
        }
    }
    for(int i=1;i<=6;i++){
        if(i<=remain){
            vector<int> temp=listt;
            temp.push_back(i);
          rollDice(remain-i,temp);
        }
    }
}
int main(){
 rollDice(4,{});
 for( auto a: finalList){
    for(auto x : a){
        cout<<x;
            }
            cout<<endl;
 }
}
// {  int a[]={1,2,3,4};
//     list<list<int>> x=numSubSet(a,4);
//    for(auto i: x){
//     cout<<"hi";
//     for(auto j:i){
//         cout<<j<<" ";
//     }
//     cout<<endl;
//    }
    // vector<string> list2 = subseting2("", "abc");
    // for (auto e : list2)
    // {
    //     cout << e << endl;
    // }
    // triangle1(5, 5, 0);

    //     vector<int> x{1,3,4,4,6,4,8};
    // vector<int> z=  checkPos(x,4,0);
    // for (auto e : z){
    //  cout<<e<<endl;
    //  }
    //  cout<<ReversNum(3147,0)<<endl;
    //  cout<<palindromOrNot(12321);
    //  cout<<endl<<countZeross(0,0);
//     return 0;
// }