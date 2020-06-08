#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    string longestCommonSubsequence(string text1, string text2)
    {
        int len1 = text1.length();
        int len2 = text2.length();
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));

        // 更新状态方程
        for (int i = 1; i < len1 + 1; i++)
        {
            for (int j = 1; j < len2 + 1; j++)
            {
                if (text1[i - 1] == text2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        string line;
        int count = 1; // 记录下标恰好到哪里子序列最大
        for (int i = 1; i < len1 + 1; i++)
        {
            for (int j = 1; j < len2 + 1; j++)
                if (dp[i][j] == count)
                {
                    line.push_back(text1[i - 1]);
                    ++count;
                    break;
                }
        }
        // 返回最长子序列
        return line;
    }
};

int main()
{
    string text1;
    string text2;
    string substr;
    Solution solution;
    cout << "请输入序列1：";
    cin >> text1;
    cout << "请输入序列2：";
    cin >> text2;
    substr = solution.longestCommonSubsequence(text1, text2);
    cout << "最长公共子序列为：" << substr << endl;
}