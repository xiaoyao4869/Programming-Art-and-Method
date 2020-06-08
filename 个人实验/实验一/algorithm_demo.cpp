#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <numeric>

using namespace std;

void print_vector(const vector<int> &vec)
{
    cout << "vector中的元素为：";
    for (const auto &i : vec)
        cout << i << " ";
    cout << endl;
}

void print_list(const list<int> &l)
{
    cout << "list中的元素为：";
    for (const auto &i : l)
        cout << i << " ";
    cout << endl;
}

void find_demo()
{
    cout << "find查找：\n";
    vector<int> g;
    for (int i = 0; i <= 5; ++i)
        g.push_back(i);

    print_vector(g);
    int i = find(g.begin(), g.end(), 4) - g.begin();
    cout << "4在元素中的下标为：" << i;
    cout << "\n--------------------------------------------\n";
}

void accumulate_demo()
{
    cout << "accumulate求和：";
    vector<int> vi = {1, 2, 3, 4};
    vector<string> vs = {"2018218779", "ZP"};
    cout << "\n整数累加后为：" << accumulate(vi.begin(), vi.end(), 0);
    cout << "\n字符串累加后为："
         << accumulate(vs.begin(), vs.end(), string(""));
    cout << "\n--------------------------------------------\n";
}

void count_demo()
{
    cout << "count计算目标元素个数：" << endl;
    vector<int> vi = {1, 2, 3, 4, -1, 1, 1};
    print_vector(vi);
    cout << "包含1的元素个数为：" << count(vi.begin(), vi.end(), 1);
    cout << "\n--------------------------------------------\n";
}

void equal_demo()
{
    cout << "equal判断两容器是否相等：" << endl;
    list<int> a = {1, 2};
    vector<int> b = {1, 2};
    print_list(a);
    print_vector(b);
    if (equal(a.begin(), a.end(), b.begin()))
        cout << "两容器相等";
    else
        cout << "两容器不相等";
    cout << "\n--------------------------------------------\n";
}

void fill_demo()
{
    cout << "填充fill/fill_n：" << endl;
    vector<int> vi = {1, 2, 3, 4};
    print_vector(vi);

    cout << "fill_n(vi.begin(), vi.size(), 0)后：";
    fill_n(vi.begin(), vi.size(), 0);
    print_vector(vi);

    cout << "fill(vi.begin(), vi.end(), 1)后：";
    fill(vi.begin(), vi.end(), 1);
    print_vector(vi);

    cout << "--------------------------------------------\n";
}

void copy_demo()
{
    cout << "拷贝copy：" << endl;
    int a[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> b(9, 0);
    print_vector(b);
    cout << "copy(begin(a), end(a), b.begin())后";
    copy(begin(a), end(a), b.begin());
    print_vector(b);
    cout << "--------------------------------------------\n";
}

void replace_demo()
{
    cout << "替代replace：" << endl;
    vector<int> vi = {1, 2, 1, 4, 1, 6, 1, 8, 1};
    print_vector(vi);
    cout << "将vector中所有的1替换为10后，";
    replace(vi.begin(), vi.end(), 1, 10);
    print_vector(vi);
    cout << "--------------------------------------------\n";
}

int main()
{
    cout << "--------------------------------------------\n";
    find_demo();
    accumulate_demo();
    count_demo();
    equal_demo();
    fill_demo();
    copy_demo();
    replace_demo();
}