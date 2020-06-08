#include <iostream>
#include <vector>

using namespace std;

void print_vector(const vector<int> &vec)
{
    cout << "vector中的元素为：";
    for (const auto &i : vec)
        cout << i << " ";
    cout << endl;
}

void iter_demo()
{
    vector<int> g1;
    for (int i = 1; i <= 5; ++i)
        g1.push_back(i);

    cout << "vector中各种迭代器演示：" << endl;
    cout << "begin()与end()迭代器的输出：";
    for (auto iter = g1.begin(); iter != g1.end(); ++iter)
        cout << *iter << " ";

    cout << "\ncbegin()与cend()迭代器的输出：";
    for (auto iter = g1.cbegin(); iter != g1.cend(); ++iter)
        cout << *iter << " ";

    cout << "\nrbegin()与rend()迭代器的输出：";
    for (auto iter = g1.rbegin(); iter != g1.rend(); ++iter)
        cout << *iter << " ";

    cout << "\ncrbegin()与crend()迭代器的输出：";
    for (auto iter = g1.crbegin(); iter != g1.crend(); ++iter)
        cout << *iter << " ";
    cout << "\n--------------------------------------------\n";
}

void capacity_demo()
{
    vector<int> g1;
    for (int i = 1; i <= 5; ++i)
        g1.push_back(i);

    cout << "vector中容量相关的方法演示：" << endl;
    cout << "Size: " << g1.size() << endl;
    cout << "Capacity: " << g1.capacity() << endl;
    cout << "Max_Size: " << g1.max_size() << endl;

    // 重新设置size大小
    g1.resize(4);
    cout << "Size : " << g1.size() << endl;
    cout << "检查vector是否为空：";
    if (g1.empty() == false)
        cout << "vector不为空" << endl;
    else
        cout << "vector为空" << endl;

    g1.shrink_to_fit();
    print_vector(g1);
    cout << "--------------------------------------------\n";
}

void element_access_demo()
{
    vector<int> g1;

    for (int i = 1; i <= 10; i++)
        g1.push_back(i * 10);

    cout << "元素访问方法演示：";
    print_vector(g1);
    cout << "元素下标访问： g1[2] = " << g1[2];
    cout << "\nat(): g1.at(4) = " << g1.at(4);
    cout << "\nfront(): g1.front() = " << g1.front();
    cout << "\nback() : g1.back() = " << g1.back();

    // 指向第一个元素的指针
    int *pos = g1.data();
    cout << "\n第一个元素是：" << *pos;
    cout << "\n--------------------------------------------\n";
}

void modifiers_demo()
{
    cout << "修改方法演示：" << endl;
    vector<int> v;
    v.assign(5, 10);
    print_vector(v);

    v.push_back(15);
    cout << "push_back(15)后";
    print_vector(v);

    v.pop_back();
    cout << "pop_back()后";
    print_vector(v);

    cout << "insert(v.begin(), 5)后";
    v.insert(v.begin(), 5);
    print_vector(v);

    cout << "erase(v.begin())后";
    v.erase(v.begin());
    print_vector(v);

    cout << "emplace_back(20)后";
    v.emplace_back(20);
    print_vector(v);

    v.clear();
    cout << "clear()之后size的大小：" << v.size();
    cout << "\n--------------------------------------------\n";
}

int main()
{
    cout << "--------------------------------------------";
    cout << endl;
    iter_demo();
    capacity_demo();
    element_access_demo();
    modifiers_demo();

    return 0;
}