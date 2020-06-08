#include <iostream>

using namespace std;

class Solution
{
public:
    void waterPouring(int cup1, int cup2, int target)
    {
        cout << "两个杯子的水量依次为：" << endl;
        cout << "(0, 0)" << endl;
        int flag = cup1 % cup2;
        cout << "(" << cup1 << ", " << 0 << ")" << endl;
        cout << "(0, " << cup1 << ")" << endl;
        if (flag == target)
        {
            return;
        }
        int count = 2;
        int tmp = flag;
        while (true)
        {
            // cout 为输出倒水顺序
            cout << "(" << cup1 << ", " << tmp << ")" << endl;
            if (cup1 + tmp > cup2)
            {
                cout << "(" << (cup1 + tmp - cup2) << ", " << cup2 << ")" << endl;
                cout << "(" << (cup1 + tmp - cup2) << ", " << 0 << ")" << endl;
            }
            int remain = (count * cup1) % cup2;
            tmp = remain;
            cout << "(0, " << remain << ")" << endl;
            if (remain == target)
            {
                cout << "倒水成功，获得目标水量" << endl;
                break;
            }
            else if (remain == flag)
            {
                cout << "No Solution" << endl;
                break;
            }
            count++;
        }
    }
};

int main()
{
    int A, B, L;
    cout << "请输入两个小杯子的容量：";
    cin >> A >> B;
    cout << "请输入希望得到多少升水：";
    cin >> L;
    if (A > B)
    {
        int tmp = A;
        A = B;
        B = tmp;
    }
    Solution solution;
    solution.waterPouring(A, B, L);
}