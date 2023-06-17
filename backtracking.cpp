#include <bits/stdc++.h>

using namespace std;

int countc = 0;
int countPath(pair<int, int> pos, int n)
{
    int x;
    if (pos.first == n || pos.second == n)
    {
        countc++;
        return 1;
    }

    return countPath(make_pair(pos.first + 1, pos.second + 1), n) + countPath(make_pair(pos.first + 1, pos.second), n) + countPath(make_pair(pos.first, pos.second + 1), n);
}
vector<string> pathss;
void addPath(pair<int, int> pos, int n, string s)
{
    int x;
    if (pos.first == n && pos.second == n)
    {
        //   countc++;
        //   return 1;
        pathss.push_back(s);
        return;
    }
    if (pos.first < n && pos.second < n)
    {

        addPath(make_pair(pos.first + 1, pos.second + 1), n, s + 'C');
    }
    if (pos.first < n)
    {
        // for(int i=0;i<n-pos.second;i++)s.push_back('r');
        // s.push_back('D');

        addPath(make_pair(pos.first + 1, pos.second), n, s + 'D');
    }
    if (pos.second < n)
    {
        // s.push_back('R');
        addPath(make_pair(pos.first, pos.second + 1), n, s + 'R');
    }
    return;
    // return countPath(make_pair(pos.first+1,pos.second),n)+countPath(make_pair(pos.first,pos.second+1),n);
}

void addPathWithObstacles(pair<int, int> pos, int n, string s, vector<vector<bool>> canGo)
{
    cout << canGo[pos.first][pos.second];
    if (canGo[pos.first][pos.second] == false)
        return;
    if (pos.first == n && pos.second == n)
    {
        //   countc++;
        //   return 1;
        pathss.push_back(s);
        return;
    }
    if (pos.first < n && pos.second < n)
    {

        addPathWithObstacles(make_pair(pos.first + 1, pos.second + 1), n, s + 'C', canGo);
    }
    if (pos.first < n)
    {
        // for(int i=0;i<n-pos.second;i++)s.push_back('r');
        // s.push_back('D');

        addPathWithObstacles(make_pair(pos.first + 1, pos.second), n, s + 'D', canGo);
    }
    if (pos.second < n)
    {
        // s.push_back('R');
        addPathWithObstacles(make_pair(pos.first, pos.second + 1), n, s + 'R', canGo);
    }
    return;
    // return countPath(make_pair(pos.first+1,pos.second),n)+countPath(make_pair(pos.first,pos.second+1),n);
}

map<pair<int, int>, bool> isVisited;
void addAllPath(pair<int, int> pos, int n, string s)
{
    int x;

    if (pos.first == n && pos.second == n)
    {
        pathss.push_back(s);
        return;
    }
    if (isVisited[pos] == true)
    {
        return;
    }
    else
    {
        isVisited[pos] = true;
    }

    if (pos.first < n)
    {

        addAllPath(make_pair(pos.first + 1, pos.second), n, s + 'D');
    }
    if (pos.second < n)
    {
        // s.push_back('R');
        addAllPath(make_pair(pos.first, pos.second + 1), n, s + 'R');
    }
    if (pos.first > 0)
    {
        // s.push_back('R');
        addAllPath(make_pair(pos.first - 1, pos.second), n, s + 'U');
    }
    if (pos.second > 0)
    {
        // s.push_back('R');
        addAllPath(make_pair(pos.first, pos.second - 1), n, s + 'L');
    }
    isVisited[pos] = false;
    return;
    // return countPath(make_pair(pos.first+1,pos.second),n)+countPath(make_pair(pos.first,pos.second+1),n);
}
void addAllPathwithPathArray(pair<int, int> pos, int n, string s, vector<vector<int>> chosedPathss, int pointNum)
{

    if (pos.first == n && pos.second == n)
    {
        pathss.push_back(s);
        cout << s << endl;
        chosedPathss[n][n] = pointNum;
        for (auto x : chosedPathss)
        {
            for (auto z : x)
            {
                cout << z << " ";
            }
            cout << endl;
        }
        chosedPathss[n][n] = 0;
        return;
    }

    if (isVisited[pos] == true)
    {
        return;
    }
    else
    {
        isVisited[pos] = true;
        chosedPathss[pos.first][pos.second] = pointNum;
    }

    if (pos.first < n)
    {

        addAllPathwithPathArray(make_pair(pos.first + 1, pos.second), n, s + 'D', chosedPathss, pointNum + 1);
    }
    if (pos.second < n)
    {
        // s.push_back('R');
        addAllPathwithPathArray(make_pair(pos.first, pos.second + 1), n, s + 'R', chosedPathss, pointNum + 1);
    }
    if (pos.first > 0)
    {
        // s.push_back('R');
        addAllPathwithPathArray(make_pair(pos.first - 1, pos.second), n, s + 'U', chosedPathss, pointNum + 1);
    }
    if (pos.second > 0)
    {
        // s.push_back('R');
        addAllPathwithPathArray(make_pair(pos.first, pos.second - 1), n, s + 'L', chosedPathss, pointNum + 1);
    }
    isVisited[pos] = false;
    chosedPathss[pos.first][pos.second] = 0;
    return;
    // return countPath(make_pair(pos.first+1,pos.second),n)+countPath(make_pair(pos.first,pos.second+1),n);
}

map<pair<int, int>, bool> isQueen;
void NqueenProblem(vector<vector<bool>> board, pair<int, int> pos, int r, int c)
{
    bool flag = true;
    if (pos.first == r - 1)
    {
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (isQueen[make_pair(i, j)] == true)
                {
                    cout << "Q"
                         << " ";
                }
                else
                {
                    cout << "X"
                         << " ";
                }
            }
            cout << endl;
        }
        cout << endl;
    }
    for (int a = 0; a < c; a++)
    {
        for (int i = pos.first; i >= 0; i--)
        {
            if (isQueen[make_pair(i, a)] == true)
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            for (int i = pos.first, j = a; i >= 0, j <= r; i--, j++)
            {
                if (isQueen[make_pair(i, j)] == true)
                {
                    flag = false;
                    break;
                }
            }
        }
        if (flag)
        {
            for (int i = pos.first, j = a; i >= 0, j >= 0; i--, j--)
            {
                if (isQueen[make_pair(i, j)] == true)
                {
                    flag = false;
                    break;
                }
            }
        }
        if (flag == true)
        {
            isQueen[pos] = true;
            NqueenProblem(board, make_pair(pos.first + 1, 0), r, c);
            isQueen[pos] = false;
        }
    }
}

bool isSafe(vector<vector<bool>> board, int r, int c)
{
    for (int i = r; i >= 0; i--)
    {
        if (board[i][c] == true)
        {
            return false;
        }
    }
    int leftMax = min(r, c);
    int t = board.size() - c;
    int rightMax = min(r, t);

    for (int i = 0; i <= leftMax; i++)
    {
        if (board[r - i][c - i] == true)
        {
            return false;
        }
    }
    for (int i = 0; i <= rightMax; i++)
    {
        if (board[r - i][c + i] == true)
        {
            return false;
        }
    }
    return true;
}
void display(vector<vector<bool>> board)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            if (board[i][j] == true)
            {
                cout << "Q"
                     << " ";
            }
            else
            {
                cout << "X"
                     << " ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

int NqueenProblem2(vector<vector<bool>> board, int r)
{
    int count = 0;
    if (r == board.size())
    {
        display(board);
        return 1;
    }
    for (int c = 0; c < board[0].size(); c++)
    {

        if (isSafe(board, r, c))
        {

            board[r][c] = true;
            count += NqueenProblem2(board, r + 1);
            board[r][c] = false;
        }
    }
    return count;
}

bool issafeKnight(vector<vector<bool>> board, int r, int c)
{
    if (r - 2 >= 0)
    {
        if (c - 1 >= 0)
        {
            if (board[r - 2][c - 1] == true)
            {
                return false;
            }
        }
    }
    if (r - 2 >= 0)
    {
        if (c + 1 < board.size())
        {
            if (board[r - 2][c + 1] == true)
            {
                return false;
            }
        }
    }
    if (r + 2 < board.size())
    {
        if (c - 1 >= 0)
        {
            if (board[r + 2][c - 1] == true)
            {
                return false;
            }
        }
    }
    if (r + 2 < board.size())
    {
        if (c + 1 < board.size())
        {
            if (board[r + 2][c + 1] == true)
            {
                return false;
            }
        }
    }
    if (c - 2 >= 0)
    {
        if (r - 1 >= 0)
        {
            if (board[r - 1][c - 2] == true)
            {
                return false;
            }
        }
    }
    if (c - 2 >= 0)
    {
        if (r + 1 < board.size())
        {
            if (board[r + 1][c - 2] == true)
            {
                return false;
            }
        }
    }
    if (c + 2 < board.size())
    {
        if (r - 1 >= 0)
        {
            if (board[r - 1][c + 2] == true)
            {
                return false;
            }
        }
    }
    if (c + 2 < board.size())
    {
        if (r + 1 < board.size())
        {
            if (board[r + 1][c + 2] == true)
            {
                return false;
            }
        }
    }
    return true;
}

int kknightsproblem(vector<vector<bool>> board, int r, int c, int target)
{
    int count = 0;
    if (target <= 0)
    {
        display(board);
        return 1;
    }
    if(r==board.size()-1&&c==board.size()){
        return 0;
    }
    if(c==board.size()){
        count+=kknightsproblem(board, r + 1, 0, target);
        return count;
    }
    if (issafeKnight(board, r, c))
    {
        board[r][c] = true;
        // target--;
       
            count += kknightsproblem(board, r, c + 1, target - 1);
       

        board[r][c] = false;
    }
    
    count+=kknightsproblem(board,r,c+1,target);
    return count;
}

int main()
{
    // addPath(make_pair(0,0),2,"");
    // addPathWithObstacles(make_pair(0, 0), 2, "", {{true, true, true}, {true, false, true}, {true, true, true}});
    // addAllPath(make_pair(0,0),2,"");
    // for (auto x : pathss)
    // {
    //     cout << x << endl;
    // }
    // addAllPathwithPathArray(make_pair(0, 0), 2, "", {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}, 1);
    vector<vector<bool>> board(4, vector<bool>(4, false));
    // cout << NqueenProblem2(board, 0);
    cout<<kknightsproblem(board,0,0,4);
    // cout << countPath(make_pair(0, 0), 2);
    return 0;
}