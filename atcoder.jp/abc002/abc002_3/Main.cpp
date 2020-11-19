#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
#include<cassert>
#include<complex>
#include<numeric>
#include<array>

#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
#define printVec(v) printf("{"); for (const auto& i : v) { std::cout << i << ", "; } printf("}\n");
#define all(v) (v).begin(),(v).end()
#define all_rev(v) (v).rbegin(),(v).rend()
#define debug(x) cout << #x << ": " << x << '\n';
#define degreeToRadian(deg) (((deg)/360)*2*M_PI)
#define radianTodegree(rad) (((rad)/2/M_PI)*360)

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using namespace std;
using ll = long long;
using P = pair<int,int>;
using PL = pair<ll, ll>;
const ll INF = 1LL<<60;
const int MOD = 1e9 + 7;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

#define EPS (1e-10)
#define equals(a, b) (fabs((a) - (b)) < EPS)
static const int COUNTER_CLOCKWISE = 1;
static const int CLOCKWISE = -1;
static const int ONLINE_BACK = 2;
static const int ONLINE_FRONT = -2;
static const int ON_SEGMENT = 0;

//点
struct Point{
  double x, y;
  Point (){}
  Point (double x,double y) :x(x),y(y){}
  Point operator + (Point p) {return Point(x+p.x,y+p.y);}
  Point operator - (Point p) {return Point(x-p.x,y-p.y);}
  Point operator * (double k) {return Point(x*k,y*k);}
  Point operator / (double k) {return Point(x/k,y/k);}
  double norm(){return x*x+y*y;}
  double abs(){return sqrt(norm());}

  bool operator < (const Point &p) const{
    return x!=p.x ? x < p.x : y < p.y;
  }

  bool operator == (const Point &p) const{
    return fabs(x-p.x) < EPS && fabs(y-p.y) < EPS;
  }
};

typedef Point Vector; //ベクトル
typedef vector<Point> Polygon; //多角形

//線分
struct Segment{
  Point p1,p2; //端点
  Segment(){}
  Segment(Point p1, Point p2):p1(p1),p2(p2){}
};
typedef Segment Line;

//円
struct Circle{
  Point c; //中心点
  double r; //半径
  Circle(Point c,double r):c(c),r(r){}
};


//以下関数

//ベクトル(基本演算)
double norm(Vector a) { return (a.x * a.x) + (a.y * a.y); }
double abs(Vector a){ return sqrt(norm(a)); }
double dot(Vector a,Vector b){ return (a.x * b.x) + (a.y * b.y); } //内積
double cross(Vector a,Vector b){ return (a.x*b.y) - (a.y*b.x); } //外積

//ベクトル(直行判定)
bool isOrthogonal(Vector a,Vector b){
  return equals(dot(a, b), 0.0);
}

//ベクトル(直行判定 点入力)
bool isOrthogonal(Point a1,Point a2,Point b1,Point b2){
  return isOrthogonal(a1 - a2, b1 - b2);
}

//線分(直行判定)
bool isOrthogonal(Segment s1,Segment s2){
  return equals(dot(s1.p2 - s1.p1, s2.p2 - s2.p1), 0.0);
}

//ベクトル(平行判定)
bool isParallel(Vector a,Vector b){
  return equals(cross(a,b),0.0);
}

//ベクトル(平行判定 点入力)
bool isParallel(Point a1,Point a2,Point b1,Point b2){
  return isParallel(a1-a2,b1-b2);
}

//線分(平行判定)
bool isParallel(Segment s1,Segment s2){
  return equals(cross(s1.p2-s1.p1,s2.p2-s2.p1),0.0); 
}

//点cが線分ab上にあるかの判定(abの長さは無限)
bool isPointOnLine(Point a, Point b, Point c) {
  return equals(cross(b - a, c - a), 0.0);
}

//点cが線分ab上にあるかの判定(abの長さは有限)
bool isPointOnLimitedLine(Point a, Point b, Point c) {
  return (Point(a - c).abs() + Point(c - b).abs() < Point(a - b).abs() + EPS);
}

//点(射影)
Point project(Segment s, Point p) {
  Vector base = s.p2 - s.p1;
  double r = dot(p - s.p1, base) / base.norm();
  return s.p1 + base * r;
}

//点(反射)
Point reflect(Segment s, Point p) {
  return p + (project(s, p) - p) * 2.0;
}

int ccw(Point p0,Point p1,Point p2){
  Vector a = p1-p0;
  Vector b = p2-p0;
  if(cross(a,b) > EPS) return COUNTER_CLOCKWISE;
  if(cross(a,b) < -EPS) return CLOCKWISE;
  if(dot(a,b) < -EPS) return ONLINE_BACK;
  if(a.norm()<b.norm()) return ONLINE_FRONT;
  return ON_SEGMENT;
}

//時計周り・反時計回り
bool intersect(Point p1,Point p2,Point p3,Point p4){
  return (ccw(p1,p2,p3)*ccw(p1,p2,p4) <= 0 &&
	  ccw(p3,p4,p1)*ccw(p3,p4,p2) <= 0 );
}

//線分どうしが交差するかの判定
bool intersect(Segment s1,Segment s2){
  return intersect(s1.p1,s1.p2,s2.p1,s2.p2);
}

//円と線分の交差を判定(最大で２つ)
int intersectCS(Circle c, Segment s) {
	if (norm(project(s, c.c) - c.c) - c.r * c.r > EPS) return 0;
	double d1 = abs(c.c - s.p1), d2 = abs(c.c - s.p2);
	if (d1 < c.r + EPS && d2 < c.r + EPS) return 0;
	if ((d1 < c.r - EPS && d2 > c.r + EPS) || (d1 > c.r + EPS && d2 < c.r - EPS)) return 1;
	Point h = project(s, c.c);
	if (dot(s.p1 - h, s.p2 - h) < 0) return 2;
	return 0;
}

//円と円の交差を判定
int intersectCC(Circle c1, Circle c2) {
	if (c1.r < c2.r) swap(c1, c2);
	double d = abs(c1.c - c2.c);
	double r = c1.r + c2.r;
	if (equals(d, r)) return 3; // 外接する
	if (d > r) return 4; // 離れている
	if (equals(d + c2.r, c1.r)) return 1; // 内接する
	if (d + c2.r < c1.r) return 0; // 内包する
	return 2; // 交わる
}


//距離・交点


double getDistanceLP(Line l,Point p){
  return abs(cross(l.p2 - l.p1, p - l.p1) / abs(l.p2 - l.p1));
}

double getDistanceSP(Segment s,Point p){
  if(dot(s.p2 - s.p1, p - s.p1) < 0.0 ) return abs(p - s.p1);
  if(dot(s.p1 - s.p2, p - s.p2) < 0.0 ) return abs(p - s.p2);
  return getDistanceLP(s, p);
}

double getDistance(Segment s1,Segment s2){
  if(intersect(s1, s2)) return 0.0;
  return min(min(getDistanceSP(s1, s2.p1), getDistanceSP(s1, s2.p2)),
	     min(getDistanceSP(s2, s1.p1), getDistanceSP(s2, s1.p2)));
}

Point getCrossPoint(Segment s1,Segment s2){
  Vector base = s2.p2 - s2.p1;
  double d1 = abs(cross(base, s1.p1 - s2.p1));
  double d2 =abs(cross(base, s1.p2 - s2.p1));
  double t = d1 / (d1 + d2);
  return s1.p1 + (s1.p2 - s1.p1) * t;
}


pair<Point,Point> getCrossPoints(Circle c,Line l){
  Vector pr = project(l, c.c);
  Vector e = (l.p2 - l.p1) / abs(l.p2 - l.p1);
  double base = sqrt(c.r * c.r - norm(pr - c.c));
  return make_pair(pr + e * base, pr - e * base);
}



int main() {
  //cin.tie(0);ios::sync_with_stdio(false);
  cout << fixed << setprecision(15);
  int xa, ya, xb, yb, xc, yc;
  cin >> xa >> ya >> xb >> yb >> xc >> yc;
  //cを基準にした位置ベクトルを定義
  Point a(xa - xc, ya - yc), b(xb - xc, yb - yc);
  cout << abs(cross(a, b) / 2.0) << endl;
  return 0;
}
