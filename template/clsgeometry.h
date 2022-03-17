//By cls1277 , learn from ECNU
#include<vector>
#include<algorithm>
#include<cmath>
using std::min;
using std::max;
using std::sort;
using std::swap;
using std::vector;

#define y1 yy1
#define LD double

const LD PI = 3.14159265358979323846;
const LD eps = 1e-10;

struct L;
struct P;
typedef P V;
typedef vector<P> S;
int sgn(LD x);

struct P {
    LD x, y;
    P(LD x=0, LD y=0): x(x), y(y) {}
    P(const P &p):x(p.x), y(p.y) {}
    P(const L &l);
};

P operator + (const P &p1, const P &p2) { return P(p1.x+p2.x, p1.y+p2.y); }
P operator - (const P &p1, const P &p2) { return P(p1.x-p2.x, p1.y-p2.y); }
P operator * (const P &p, LD k) { return P(p.x*k, p.y*k); }
P operator / (const P &p, LD k) { return P(p.x/k, p.y/k); }
bool operator < (const P & p1, const P &p2) { return (sgn(p1.x-p2.x)<0) || (!sgn(p1.x-p2.x)&&sgn(p1.y-p2.y)<0); }
bool operator == (const P & p1, const P &p2) { return (!sgn(p1.x-p2.x))&&(!sgn(p1.y-p2.y)); }

struct L {
    P s, t;
    L() {}
    L(P s, P t):s(s), t(t) {}
};

P::P(const L &l) { *this = l.t-l.s; }

int sgn(LD x) { return fabs(x)<eps ? 0 : (x>0 ? 1 : -1); }
LD dis(const P & p) { return sqrt(p.x*p.x+p.y*p.y); }
LD dot(const V &v1, const V & v2) { return v1.x*v2.x+v1.y*v2.y; }
LD det(const V &v1, const V & v2) { return v1.x*v2.y-v1.y*v2.x; }
LD cross(const P & p1, const P & p2, const P & p3=P()) { return det(p1-p3, p2-p3); }
V normal_vector(const V & v) { return V(-v.y, v.x) / dis(v); }

int quad(P p) {
    int x=sgn(p.x), y=sgn(p.y);
    if(x>0&&y>0) return 1;
    if(x<=0&&y>0) return 2;
    if(x<=0&&y<=0) return 3;
    if(x>0&&y<=0) return 4;
}

bool line_parallel(const L & l1 , const L & l2) { return !sgn(det(l1, l2)); }
bool line_equal(const L & l1, const L & l2) { return line_parallel(l1, l2)&&line_parallel(L(l1.s, l2.t), L(l2.s, l1.t)); }

P rotate_ccw_r(const P & p, const LD & r) { return P(p.x*cos(r)-p.y*sin(r), p.x*sin(r)+p.y*cos(r)); }
P rotate_ccw_90(const P & p) { return P(-p.y, p.x); }
P rotate_cw_90(const P & p) { return P(p.y, -p.x); }

bool point_on_segment(const P & p, const L & l) {
    P a=l.s, b=l.t;
    return !sgn(det(p-a, b-a)) && sgn(dot(p-a, p-b))<=0;
}

LD node_to_line(const P & p , const L & l) { return fabs(cross(l.s, l.t, p)) / dis(l); }

LD node_to_segment(const P & p, const L & l) {
    if (l.s==l.t) return dis(p-l);
    V vs = p-l.s, vt = p-l.t;
    if(sgn(dot(l, vs)) < 0) return dis(vs);
    else if(sgn(dot(l, vt)) > 0) return dis(vt);
    else return node_to_line(p, l);
}

P line_cross_line(const L & a, const L &b) {
    LD s1 = det(P(a), b.s-a.s), s2 = det(P(a), b.t-a.t);
    return (b.s*s2-b.t*s1)/(s2-s1);
}

LD vector_angle(const V & a, const V & b) {
    LD r = asin(fabs(det(a, b)) / dis(a) / dis(b));
    if(sgn(dot(a, b)) < 0) r = PI-r;
    return r;
}

int segment_cross_line(const L & seg, const L & line) {
    int d1 = sgn(cross(line.s, line.t, seg.s));
    int d2 = sgn(cross(line.s, line.t, seg.t));
    if((d1^d2)==-2) return 1;
    if(!d1 || !d2) return 2;
    return 0;
}

int segment_cross_segment(const L & a, const L & b, P & p) {
    int d1 = sgn(cross(a.t, b.s, a.s)), d2 = sgn(cross(a.t, b.t, a.s));
    int d3 = sgn(cross(b.t, a.s, b.s)), d4 = sgn(cross(b.t, a.t, b.s));
    if((d1^d2)==-2 && (d3^d4)==-2) { p = line_cross_line(a, b); return 1; }
    if(!d1 && point_on_segment(b.s, a)) { p = b.s; return 2; }
    if(!d2 && point_on_segment(b.t, a)) { p = b.t; return 2; }
    if(!d3 && point_on_segment(a.s, b)) { p = a.s; return 2; }
    if(!d4 && point_on_segment(a.t, b)) { p = a.t; return 2; }
    return 0;
}

struct C {
    P p; LD r;
    C(LD x=0, LD y=0, LD r=0):p(x,y), r(r) {}
    C(P p, LD r):p(p), r(r) {}
};

P circle_center(P a, P b, P c) {
    b=(a+b)/2; c=(a+c)/2;
    return line_cross_line(L(b, b+rotate_cw_90(a-b)), L(c, c+rotate_cw_90(a-c)));
}

int circle_relation(const C & a, const C & b) {
    LD d = dis(a.p-b.p);
    if(sgn(d-a.r-b.r)>0) return 5;
    if(sgn(d-a.r-b.r)==0) return 4;
    LD l = fabs(a.r-b.r);
    if(sgn(d-l)>0) return 3;
    if(sgn(d-l)==0) return 2;
    if(sgn(d-l)<0) return 1;
}

vector<P> circle_cross_line(const L & l, const C & c) {
    vector<P> res;
    P b(l), a=l.s-c.p;
    LD x=dot(b, b), y=dot(a, b), z=dot(a, a)-c.r*c.r;
    LD D = y*y-x*z;
    if(sgn(D)<0) return res;
    res.push_back(c.p+a+b*(-y+sqrt(D+eps))/x);
    if(sgn(D)>0) res.push_back(c.p+a+b*(-y-sqrt(D))/x);
    return res;
}

vector<P> circle_cross_circle(const C & a, const C & b) {
    vector<P> res;
    LD d = dis(a.p-b.p);
    if(sgn(d)==0 || sgn(d-(a.r+b.r))>0 || sgn(d+min(a.r, b.r)-max(a.r, b.r))<0)
        return res;
    LD x = (d*d-b.r*b.r+a.r*a.r) / (2*d);
    LD y = sqrt(a.r*a.r-x*x);
    P v = (b.p-a.p) / d;
    res.push_back(a.p+v*x+rotate_ccw_90(v)*y);
    if(sgn(y)>0) res.push_back(a.p+v*x-rotate_ccw_90(v)*y);
    return res;
}

P circle_center(P a, P b) {
    return (a+b)/2;
}

bool point_in_circle(const P & p, const C & c) {
    return sgn(dis(p-c.p)-c.r)<=0;
}

C min_circle_cover(const vector<P>&in) {
    vector<P> a(in.begin(), in.end());
    random_shuffle(a.begin(), a.end());
    P c=a[0]; LD r=0; int n=a.size();
    for(int i=1; i<n; i++) {
        if(!point_in_circle(a[i], {c,r})) {
            c = a[i]; r = 0;
            for(int j=0; j<i; j++) {
                if(!point_in_circle(a[j], {c,r})) {
                    c = circle_center(a[i], a[j]);
                    r = dis(a[j]-c);

                    
                    for(int k=0; k<j; k++) {
                        if(!point_in_circle(a[k], {c,r})) {
                            c = circle_center(a[i], a[j], a[k]);
                            r = dis(a[k]-c);
                        }
                    }
                }
            }
        }
    }
    return {c,r};
}

#define nxt(i) ((i+1)%s.size())
int polygon_inside(const S & s, const P & p) {
    int cnt = 0;
    for(int i=0; i<s.size(); i++) {
        P a=s[i], b=s[nxt(i)];
        if(point_on_segment(p, L(a, b))) return -1;
        if(sgn(a.y-b.y)<=0) swap(a,b);
        if(sgn(p.y-a.y)>0) continue;
        if(sgn(p.y-b.y)<=0) continue;
        cnt += sgn(cross(b, a, p))>0;
    }
    return bool(cnt&1);
}

LD polygon_area(const S & s) {
    LD res = 0;
    for(int i=1; i<s.size()-1; i++)
        res += cross(s[i], s[i+1], s[0]);
    return res/2;
}

const int maxn = 1e3;
S convex_hull(S & s) {
    sort(s.begin(), s.end());
    S res(maxn*2);
    int sz = 0;
    for(int i=0; i<s.size(); i++) {
        while(sz>1&&sgn(cross(res[sz-1], s[i], res[sz-2]))<0) sz--;
        res[sz++] = s[i];
    }
    int k = sz;
    for(int i=s.size()-2; i; i--) {
        while(sz>k && sgn(cross(res[sz-1], s[i], res[sz-2]))<0) sz--;
        res[sz++] = s[i];
    }
    res.resize(sz-(s.size()>1));
    return res;
}

P compute_centroid(const vector<P> & p) {
    P c(0,0);
    LD scale = 6.0*polygon_area(p);
    for(int i=0; i<p.size(); i++) {
        int j = (i+1)%p.size();
        c = c+(p[i]+p[j])*(p[i].x*p[j].y-p[j].x*p[i].y);
    }
    return c/scale;
}

struct LV {
    P p, v; LD angle;
    LV() {}
    LV(P s, P t): p(s), v(t-s) { angle = atan2(v.y,v.x); }
};

bool operator < (const LV & a , const LV & b) { return a.angle<b.angle; }

bool on_left(const LV & l, const P & p) { return sgn(cross(l.v, p-l.p))>=0; }

P line_cross_line(const LV & a, const LV & b) {
    P u = a.p-b.p; LD t = cross(b.v, u) / cross(a.v, b.v);
    return a.p+a.v*t;
}

S half_plane_intersection(vector<LV> & L) {
    int n=L.size(), fi, la;
    sort(L.begin(), L.end());
    vector<P> p(n); vector<LV> q(n);
    q[fi = la = 0] = L[0];
    for(int i=1; i<n; i++) {
        while(fi<la && !on_left(L[i], p[la - 1])) la--;
        while(fi<la && !on_left(L[i], p[fi])) fi++;
        q[++la] = L[i];
        if(sgn(cross(q[la].v, q[la - 1].v))==0) {
            la--;
            if(on_left(q[la], L[i].p)) q[la] = L[i];
        }
        if(fi<la) p[la-1] = line_cross_line(q[la-1], q[la]);
    }
    while(fi<la && !on_left(q[fi], p[la-1])) la--;
    if(la-fi<=1) return vector<P>();
    p[la]=line_cross_line(q[la], q[fi]);
    return vector<P>(p.begin()+fi, p.begin()+la+1);
}

S convex_intersection(const vector<P> & v1, const vector<P> & v2) {
    vector<LV> h; int n=v1.size(), m=v2.size();
    for(int i=0; i<n; i++) h.push_back(LV(v1[i], v1[(i+1)%n]));
    for(int i=0; i<m; i++) h.push_back(LV(v2[i], v2[(i+1)%m]));
    return half_plane_intersection(h);
}