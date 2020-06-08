#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int maze[4][6] = {
    {1, 1, 0, 0, 0, 0},
    {0, 1, 1, 1, 0, 0},
    {1, 1, 0, 1, 1, 0},
    {0, 0, 0, 1, 1, 0}};

int flag[4][6] = {0};
vector<pair<int, int>> path;

const int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void search(vector<pair<int, int>> tpath, int x, int y)
{
    if (x < 0 || y < 0 || x > 5 || y > 3) //越界返回
        return;
    if (x == 3 && y == 3)
    {
        tpath.push_back(make_pair(x, y));
        path = tpath; //如果找到了出口,则记录下路径
        for (const auto &i : path)
            cout << "(" << i.first << ", " << i.second << ")";
        cout << endl;
        return;
    }
    for (int ix = 0; ix < 4; ++ix) //四个方向搜索
    {
        if (maze[x + dir[ix][0]][y + dir[ix][1]] == 1 && !(flag[x + dir[ix][0]][y + dir[ix][1]]))
        {
            flag[x + dir[ix][0]][y + dir[ix][1]] = 1;
            tpath.push_back(make_pair(x, y));
            search(tpath, x + dir[ix][0], y + dir[ix][1]);
            tpath.pop_back();
        }
    }
}

int main()
{
    vector<pair<int, int>> tpath;
    flag[0][0] = 1;
    search(tpath, 0, 0); //从开始点找起
    cout << "路径依次为：";
    for (const auto &i : path)
        cout << "(" << i.first << ", " << i.second << ")";
    cout << endl;
}