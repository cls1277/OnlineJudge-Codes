#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

using _T=long long;

constexpr _T eps=1e-8;

template<typename T> struct __point
{
    T x,y;

    bool operator==(const __point &a) const {return (abs(x-a.x)<=eps && abs(y-a.y)<=eps);}
    bool operator<(const __point &a) const {if (abs(x-a.x)<=eps) return y<a.y-eps; return x<a.x-eps;}
    bool operator>(const __point &a) const {return !(*this<a || *this==a);}
    __point operator+(const __point &a) const {return {x+a.x,y+a.y};}
    __point operator-(const __point &a) const {return {x-a.x,y-a.y};}
    __point operator-() const {return {-x,-y};}
    __point operator*(const T k) const {return {k*x,k*y};}
    __point operator/(const T k) const {return {x/k,y/k};}
    T operator*(const __point &a) const {return x*a.x+y*a.y;}
    T operator^(const __point &a) const {return x*a.y-y*a.x;}
    int toleft(const __point &a) const {const auto t=(*this)^a; return (t>eps)-(t<-eps);}
    T len2() const {return (*this)*(*this);}
    T dis2(const __point &a) const {return (a-(*this)).len2();}
};

using __Point=__point<_T>;

int check(InStream& stream, const vector<__Point> &A)
{
    auto verdict=stream.readLine("YES|NO","verdict");
    if (verdict=="NO") return 0;
    int x1=stream.readInt(-1'000'000'000,1'000'000'000,"x1");
    int y1=stream.readInt(-1'000'000'000,1'000'000'000,"y1");
    int x2=stream.readInt(-1'000'000'000,1'000'000'000,"x2");
    int y2=stream.readInt(-1'000'000'000,1'000'000'000,"y2");
    const __Point a={x1,y1},b={x2,y2};
    if (b==__Point{0,0}) stream.quitf(_wa, "b=(0,0)");
    for (size_t i=1;i<A.size();i++)
    {
        auto t1=(A[i-1]-a)*b;
        auto t2=(A[i]-a)*b;
        if (t1>t2) stream.quitf(_wa, "wrong line");
    }
    return 1;
}

int main(int argc, char* argv[])
{
    registerTestlibCmd(argc, argv);
    int n=inf.readInt();
    vector<__Point> vec(n);
    for (int i=0;i<n;i++)
    {
        int x=inf.readInt();
        int y=inf.readInt();
        vec[i]={x,y};
    }
    int jans=check(ans,vec);
    int pans=check(ouf,vec);
    if (pans<jans) quitf(_wa, "jury has the answer");
    else if (pans>jans) quitf(_fail, "participant has the answer");
    else quitf(_ok, "accepted");
    return 0;
}