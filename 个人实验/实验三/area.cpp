#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const double eps = 1e-10;
int dcmp(double x)
{
    if (fabs(x) < eps)
        return 0;
    return x < 0 ? -1 : 1;
}
struct Point
{
    double x, y;
    Point() {}
    Point(double x, double y) : x(x), y(y) {}
};

typedef Point Vector;
Vector operator-(Point A, Point B)
{
    return Vector(A.x - B.x, A.y - B.y);
}
double Dot(Vector A, Vector B)
{
    return A.x * B.x + A.y * B.y;
}
double Length(Vector A)
{
    return sqrt(Dot(A, A));
}
double Cross(Vector A, Vector B)
{
    return A.x * B.y - A.y * B.x;
}
bool InSegment(Point P, Point a1, Point a2)
{ //判断点P是否在线段a1a2上(在端点上也算)
    //注意这里的<=0
    return dcmp(Cross(a1 - P, a2 - P)) == 0 && dcmp(Dot(a1 - P, a2 - P)) <= 0;
}
bool SegmentIntersection(Point a1, Point a2, Point b1, Point b2)
{ //判断线段a1a2与线段b1b2是否存在任何公共点
    double c1 = Cross(a2 - a1, b1 - a1), c2 = Cross(a2 - a1, b2 - a1);
    double c3 = Cross(b2 - b1, a1 - b1), c4 = Cross(b2 - b1, a2 - b1);
    if (dcmp(c1) * dcmp(c2) < 0 && dcmp(c3) * dcmp(c4) < 0)
        return true;
    if (dcmp(c1) == 0 && InSegment(b1, a1, a2))
        return true;
    if (dcmp(c2) == 0 && InSegment(b2, a1, a2))
        return true;
    if (dcmp(c3) == 0 && InSegment(a1, b1, b2))
        return true;
    if (dcmp(c4) == 0 && InSegment(a2, b1, b2))
        return true;
    return false;
}
bool Is_Polygon(Point *p, int n) //判定是否能构成多边形
{
    p[n] = p[0];
    for (int i = 0; i < n; ++i)         //枚举第一条线段
        for (int j = i + 1; j < n; ++j) //枚举第二条线段
        {
            if (j == i + 1 || (j + 1) % n == i)
                continue; //两线段本来就相邻
            if (SegmentIntersection(p[i], p[i + 1], p[j], p[j + 1]))
                return false;
        }
    return true;
}
double PolygenArea(Point *p, int n) //计算多边形面积
{
    double area = 0;
    for (int i = 1; i < n - 1; ++i)
        area += Cross(p[i] - p[0], p[i + 1] - p[0]);
    return fabs(area) / 2;
}

const int maxn = 1000 + 5;
int n;         //点数
Point p[maxn]; //点
int main()
{
    int kase = 0;
    double area;
    vector<double> vecArea;
    while (scanf("%d", &n) == 1 && n)
    {
        for (int i = 0; i < n; ++i)
            cin >> p[i].x >> p[i].y;
        if (n < 3 || !Is_Polygon(p, n))
            area = -1;
        else
            area = PolygenArea(p, n);
        vecArea.push_back(area);
    }
    for (int i = 1; i <= vecArea.size(); ++i)
    {
        if (vecArea[i - 1] != -1)
            cout << "Figure " << i << ": " << vecArea[i - 1] << endl;
        else
            cout << "Figure " << i << ": "
                 << "Impossible\n";
    }
    return 0;
}