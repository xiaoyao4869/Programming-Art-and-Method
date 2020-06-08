#include <iostream>
#include <vector>

using namespace std;

const int N = 5;

// 对应骑士可以走的八个方向
const int dir[8][2] = {
    {2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};

class Solution
{
private:
    vector<vector<string>> ans;
    int board[N][N] = {0};

    bool check()
    {
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                if (board[i][j] == 0)
                    return false;
        return true;
    }

    void dfs(int x, int y)
    {
        if (check())
        {
            vector<string> lines;
            string line;
            for (int i = 0; i < N; ++i)
            {
                for (int j = 0; j < N; ++j)
                    line.append(to_string(board[i][j]) + "\t");
                lines.push_back(line);
                line.clear();
            }
            ans.push_back(lines);
            lines.clear();
        }

        for (int i = 0; i < 8; ++i)
        {
            int tmpX = x + dir[i][0];
            int tmpY = y + dir[i][1];

            if (tmpX < 0 || tmpX > N - 1 || tmpY < 0 || tmpY > N - 1)
                continue;
            if (!board[tmpX][tmpY])
            {
                board[tmpX][tmpY] = board[x][y] + 1; // 进入下一步
                dfs(tmpX, tmpY);
                board[tmpX][tmpY] = 0; // 该步重置为0
            }
        }
    }

public:
    vector<vector<string>> traverse(int x, int y)
    {
        board[x][y] = 1;
        dfs(x, y);
        return ans;
    }
};

int main()
{
    Solution solution;
    vector<vector<string>> ans = solution.traverse(0, 0);
    // 输出每一份满足条件的皇后地图
    int count = 0;
    for (const auto &Map : ans)
    {
        ++count;
        cout << "第" << count << "个解：\n";
        for (const auto &line : Map)
            cout << line << endl;
        cout << endl;
    }
}