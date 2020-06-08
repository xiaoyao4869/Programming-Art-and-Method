#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> getMaxMatrix(vector<vector<int>> &matrix, int &sum)
    {
        vector<int> ans(4, 0);      //存储目前为止的最大子矩阵位置
        int max_sum = matrix[0][0]; //存储目前为止最大子矩阵和的大小
        for (int r1 = 0; r1 < matrix.size(); r1++)
        { //子矩阵的上边缘
            vector<int> dp(matrix[0].size(), 0);
            for (int r2 = r1; r2 < matrix.size(); r2++)
            {                             //一维的前缀和问题
                int dpsum = 0;            //累加和
                int min_dpsum = 0;        //累加和最小值
                int min_dpsum_index = -1; //累加和最小值对应坐标
                for (int c2 = 0; c2 < matrix[0].size(); c2++)
                {
                    dp[c2] += matrix[r2][c2];
                    dpsum += dp[c2];
                    if (dpsum - min_dpsum > max_sum)
                    { //更新最小子矩阵
                        max_sum = dpsum - min_dpsum;
                        ans = {r1, min_dpsum_index + 1, r2, c2};
                    }
                    if (dpsum < min_dpsum)
                    { //更新一维问题的最小累加和
                        min_dpsum = dpsum;
                        min_dpsum_index = c2;
                    }
                }
            }
        }
        sum = max_sum;
        return ans;
    }
};

int main()
{
    int n, m, sum;
    cout << "请输入矩阵行数：";
    cin >> n;
    cout << "请输入矩阵列数：";
    cin >> m;
    cout << "请输入 " << n << " x " << m << " 矩阵：" << endl;
    vector<vector<int>> matrix(n, vector<int>(m, 0));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> matrix[i][j];
    Solution solution;
    vector<int> vec = solution.getMaxMatrix(matrix, sum);
    printf("子矩阵左上角坐标为：(%d, %d)\n", vec[0], vec[1]);
    printf("子矩阵右下角坐标为：(%d, %d)\n", vec[2], vec[3]);
    cout << "所有子矩阵中和的最大值为：" << sum;
    return 0;
}