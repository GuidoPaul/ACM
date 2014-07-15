/*************************************************************************
	> File Name: 1558.c
	> Author: Bslin
	> Mail: Baoshenglin1994@gmail.com
	> Created Time: 2014年07月14日 星期一 15时08分17秒
 ************************************************************************/

#include <stdio.h>
#include <math.h>
#define M 1100
const double eps = 1e-10;
#define dcmp(x) (fabs(x) < eps ? 0 : (x < 0 ? -1 : 1))

struct Point {
	double x, y;
} p1[M], p2[M];
int fa[M], root[M], k;

double Cross(Point p0, Point p1, Point p2) { 
    return (p2.x - p0.x) *(p1.y - p0.y) - (p1.x - p0.x) * (p2.y - p0.y); 
} 

int min(int a, int b) {
	return a < b ? a : b;
}
int max(int a, int b) {
	return a > b ? a : b;
}

bool OnSegment(Point p0, Point p1, Point p2) {
    if((min(p0.x, p1.x) <= p2.x && p2.x <= max(p0.x,p1.x))
			&& (min(p0.y,p1.y) <= p2.y && p2.y <= max(p0.y,p1.y))) {
		return true; 
	}
    return false; 
} 

bool Intersection(int i) {
	double c1 = Cross(p1[i], p2[i], p1[k]);
	double c2 = Cross(p1[i], p2[i], p2[k]);
	double c3 = Cross(p1[k], p2[k], p1[i]);
	double c4 = Cross(p1[k], p2[k], p2[i]);
	if(dcmp(c1) * dcmp(c2) < 0 && dcmp(c3) * dcmp(c4) < 0)
		return true;
	if(c1 == 0 && OnSegment(p1[i], p2[i], p1[k])) {
		return true;
	}
	if(c2 == 0 && OnSegment(p1[i], p2[i], p2[k])) {
		return true;
	}
	if(c3 == 0 && OnSegment(p1[k], p2[k], p1[i])) {
		return true;
	}
	if(c4 == 0 && OnSegment(p1[k], p2[k], p2[i])) {
		return true;
	}
	return false;
}


int getfa(int x) {
	while(x != fa[x]) {
		x = fa[x];
	}
	return x;
}

void Union(int x, int y) {
	x = getfa(x);
	y = getfa(y);
	if(x != y) {
		if(root[x] <= root[y]) {
			fa[x] = y;
			root[y] += root[x];
		} else {
			fa[y] = x;
			root[x] += root[y];
		}
	}
}

void add(int k) {
	int i;
	for (i = 1; i < k; ++i) {
		if(Intersection(i)) {
			Union(i, k);
		}
	}
}

int main(int argc, char *argv[]) {
	freopen("in.txt", "r", stdin);
	int cas, n, i;
	char op[2];
	int x;

	scanf("%d", &cas);
	while(cas --) {
		scanf("%d", &n);
		k = 1;
		for (i = 0; i < n; ++i) {
			scanf("%s", &op);
			if(op[0] == 'P') {
				scanf("%lf%lf%lf%lf", &p1[k].x, &p1[k].y, &p2[k].x, &p2[k].y);
				root[k] = 1;
				fa[k] = k;
				add(k);
				k ++;
			} else if(op[0] == 'Q') {
				scanf("%d", &x);
				x = getfa(x);
				printf("%d\n", root[x]);
			}
		}
		if(cas) {
			printf("\n");
		}
	}
	return 0;
}
