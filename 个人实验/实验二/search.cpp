#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int maze[4][6] = {
    {1, 1, 0, 0, 0, 0},
    {0, 1, 1, 1, 1, 0},
    {1, 1, 0, 1, 1, 0},
    {0, 0, 0, 1, 1, 0}};

int flag[4][6] = {0};

const int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void search(vector<pair<int, int>> &tpath, int x, int y)
{
    flag[x][y] = 1;
    tpath.push_back(make_pair(x, y));
    if (x == 3 && y == 3)
    {
        for (const auto &i : tpath)
            cout << "(" << i.first << ", " << i.second << ")";
        cout << endl;
        tpath.pop_back();
        flag[x][y] = 0;
        return;
    }
    for (int ix = 0; ix < 4; ++ix) //四个方向搜索
    {
        int nx = x + dir[ix][0];
        int ny = y + dir[ix][1];
        if (nx >= 0 && ny >= 0 && nx < 4 && ny < 6 && !flag[nx][ny] && maze[nx][ny])
            search(tpath, nx, ny);
    }
    tpath.pop_back();
    flag[x][y] = 0;
}

int main()
{
    vector<pair<int, int>> tpath;
    search(tpath, 0, 0); //从开始点找起
}