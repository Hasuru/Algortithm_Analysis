#include <stdio.h>
#include <math.h>

#define pi 3.1415

double max(double v1, double v2) {
    if (v1 > v2) return v1;
    return v2;
}

bool dontIntersect(double qx, double qy, double ql, double cx, double cy, double cr) {
    return (cx+cr <= qx || cx-cr >= qx+ql || cy-cr >= qy+ql || cy+cr <= qy);
}

bool circInsideRect(double qx, double qy, double ql, double cx, double cy, double cr) {
    return (cx+cr <= qx+ql && cx-cr >= qx && cy+cr <= qy+ql && cy-cr >= qy);
}

bool rectInsideCirc(double qx, double qy, double ql, double cx, double cy, double cr) {
    double dx = max(abs(cx - qx), abs((qx+ql) - cx));
    double dy = max(abs(cy - qy), abs((qy+ql) - cy));
    return cr*cr >= dx*dx + dy*dy;
}

double intersection(double qx, double qy, double ql, double cx, double cy, double cr) {
    if (dontIntersect(qx, qy, ql, cx, cy, cr)) return 0;
    if (circInsideRect(qx, qy, ql, cx, cy, cr)) return M_PI*cr*cr;
    if (rectInsideCirc(qx, qy, ql, cx, cy, cr)) return ql*ql;
    double area = 0;
    if (ql > 0.005) {
        area += intersection(qx,qy,ql/2,cx,cy,cr);
        area += intersection(qx+ql/2,qy,ql/2,cx,cy,cr);
        area += intersection(qx+ql/2,qy+ql/2,ql/2,cx,cy,cr);
        area += intersection(qx,qy+ql/2,ql/2,cx,cy,cr);
    }
    return area;
}

int main() {
    int n;
    double qx, qy, ql, cx, cy, cr;
    scanf("%d", &n);
    while (n--) {
        scanf("%lf %lf %lf %lf %lf %lf", &qx, &qy, &ql, &cx, &cy, &cr);
        double a = intersection(qx, qy, ql, cx, cy, cr);
        printf("%lf\n", a);
    }
    return 0;
}