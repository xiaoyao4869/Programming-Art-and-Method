#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<double, double> POINT;

// 如果返回正数，则表示顺时针
// 否则，表示逆时针
double direction(POINT p, POINT p1, POINT p2)
{
    POINT v1, v2;
    v1.first = p2.first - p.first;
    v1.second = p2.second - p.second;
    v2.first = p1.first - p.first;
    v2.second = p1.second - p.second;
    return v1.first * v2.second - v1.second * v2.first;
}

// 判断p是否在p1p2上
bool on_segment(POINT p, POINT p1, POINT p2)
{
    double min_x = p1.first < p2.first ? p1.first : p2.first;
    double max_x = p1.first > p2.first ? p1.first : p2.first;
    double min_y = p1.second < p2.second ? p1.second : p2.second;
    double max_y = p1.second > p2.second ? p1.second : p2.second;
    if (p.first >= min_x && p.first <= max_x && p.second >= min_y && p.second <= max_y)
        return true;
    else
        return false;
}

POINT startPoint;

bool sortByPolorAngle(const POINT &p1, const POINT &p2)
{
    double d = direction(startPoint, p1, p2);
    if (d < 0)
        return true;
    if (d > 0)
        return false;
    if (d == 0 && on_segment(startPoint, p1, p2))
        return true;
    if (d == 0 && on_segment(p2, startPoint, p1))
        return true;
    return false;
}

// 计算凸包
void find_convex_hull(vector<POINT> &point)
{
    POINT p0 = point[0];
    int k = 0;
    for (int i = 1; i < point.size(); i++)
    {
        if (point[i].second < p0.second ||
            point[i].second == p0.second && point[i].first < p0.first)
        {
            p0 = point[i];
            k = i;
        }
    }
    point.erase(point.begin() + k);
    point.insert(point.begin(), p0);
    vector<POINT> convex_hull;
    do
    {
        convex_hull.push_back(point[0]);
        startPoint = point[0];
        point.erase(point.begin());
        sort(point.begin(), point.end(), sortByPolorAngle);
        if (point[0] == convex_hull[0])
            break;
        point.push_back(convex_hull[convex_hull.size() - 1]);
    } while (1);
    cout << "凸包点为：";
    for (int i = 0; i < convex_hull.size(); i++)
    {
        cout << "(" << convex_hull[i].first << ", "
             << convex_hull[i].second << ")";
    }
    cout << endl;
}

int main()
{
    int nPtCnt = 10; //生成的随机点数
    cout << "生成随机点数：";
    vector<POINT> point;
    for (int i = 0; i < nPtCnt; ++i)
    {
        POINT ptIn = {rand() % 16, rand() % 16};
        point.push_back(ptIn);
        cout << "(" << ptIn.first << ", " << ptIn.second << ")";
    }
    cout << endl;
    find_convex_hull(point);
}