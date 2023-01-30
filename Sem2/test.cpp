#include <stdio.h>
#include <math.h>

double intersection(double qx, double qy, double ql, double cx, double cy, double cr) {
    if (qx+ql<=cx-cr || cx+cr<=qx || cy-cr>=qy+ql || qy>=cy+cr) {
	    //nao se intersetam
	    return 0;
	}
	if (cx+cr<=qx+ql && cx-cr>=qx && cy+cr<=qy+ql && cy-cr>=qy ) {
	    //circulo está dentro do quadrado
	    return M_PI*cr*cr;
	}
	if( sqrt((qx-cx)*(qx-cx)+(qy+ql-cy)*(qy+ql-cy))<=cr &&
	    sqrt((qx+ql-cx)*(qx+ql-cx)+(qy+ql-cy)*(qy+ql-cy))<=cr &&
	    sqrt((qx-cx)*(qx-cx)+(qy-cy)*(qy-cy))<=cr &&
	    sqrt((qx+ql-cx)*(qx+ql-cx)+(qy-cy)*(qy-cy))<=cr ) {
	    //quadrado está dentro do circulo
	    return (ql*ql);
	}
	double area = 0;
	if (ql>0.001) {
	    area = area + intersection(qx,qy,ql/2,cx,cy,cr)
	                + intersection(qx+ql/2,qy,ql/2,cx,cy,cr)
	                + intersection(qx+ql/2,qy+ql/2,ql/2,cx,cy,cr)
	                + intersection(qx,qy+ql/2,ql/2,cx,cy,cr);
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