#include <iostream>
#include <list>

using namespace std;

void print_list(const list<int> &l)
{
    for (const auto &i : l)
        cout << i << " ";
    cout << endl;
}

bool sortsp(int v1, int v2)
{
    return v1 > v2;
}

int main()
{
    list<int> glist1, glist2;
    int value[] = {2, 4, 5, 7, 9, 12};
    glist1.push_front(1);
    glist1.push_front(2);
    glist1.push_back(4);
    glist1.push_back(3);
    cout << "list1的元素为: ";
    print_list(glist1);

    glist1.sort();
    cout << "排序后list1的元素为: ";
    print_list(glist1);

    glist2.insert(glist2.begin(), value, value + 6);
    cout << "list2的元素为: ";
    print_list(glist2);

    glist1.splice(glist1.end(), glist2);
    cout << "执行splice后list1的元素为: ";
    print_list(glist1);

    glist1.sort(sortsp);
    cout << "按大到小list1的排序为: ";
    print_list(glist1);

    glist1.unique();
    cout << "执行unique后list1的元素为: ";
    print_list(glist1);

    glist1.remove(9);
    cout << "执行remove(9)后list1的元素为: ";
    print_list(glist1);

    glist2.insert(glist2.end(), value, value + 5);
    glist1.swap(glist2);
    cout << "执行swap后list2的元素为: ";
    print_list(glist1);

    return 0;
}