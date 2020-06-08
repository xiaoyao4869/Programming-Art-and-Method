#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int N = 8;

class Solution
{
private:
    vector<vector<string>> res; // 存结果
    vector<string> tmp;         // 存棋盘

    void solveNQueens(string &line, int row, int n)
    {
        if (row == n) // 棋盘绘制完毕，退出递归
        {
            res.push_back(tmp);
            return;
        }
        for (int i = 0; i < n; ++i)
        { // 一格一格试
            if (checkNoQueens(row, i, n))
            {
                line[i] = 'Q';                  // 当前格放皇后
                tmp.push_back(line);            // 该行绘制进棋盘
                line[i] = '.';                  // 设置棋盘下一行没有皇后
                solveNQueens(line, row + 1, n); // 去试下一行
                tmp.pop_back();                 // 去试下一格
            }
        }
    }

    bool checkNoQueens(int row, int col, int n)
    {
        /* 每个皇后的左上方向没有其他皇后
         * 每个皇后的上方没有其他皇后
         * 每个皇后的右上方向没有皇后
         */
        int nSubC = col - 1;
        int nPlusC = col + 1;
        for (int i = row - 1; i >= 0; i--, nSubC--, nPlusC++)
        {
            if (tmp[i][col] == 'Q') // 检查正上方
                return false;
            if (nSubC >= 0 && tmp[i][nSubC] == 'Q') // 检查左上方
                return false;
            if (nPlusC < n && tmp[i][nPlusC] == 'Q') // 检查右上方
                return false;
        }
        return true;
    }

public:
    vector<vector<string>> solveNQueens(int n)
    {
        string line(n, '.');      // 一行一行遍历
        solveNQueens(line, 0, n); // 从第0行开始
        return res;
    }
};

int main()
{
    Solution solution;
    vector<vector<string>> ans = solution.solveNQueens(N);
    // 输出每一份满足条件的皇后地图
    int count = 0;
    for (const auto &queenMap : ans)
    {
        ++count;
        cout << "第" << count << "个解：\n";
        for (const auto &line : queenMap)
            cout << line << endl;
        cout << endl;
    }
}