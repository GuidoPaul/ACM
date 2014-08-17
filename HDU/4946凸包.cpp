/*************************************************************************
	> File Name: 1002.c
	> Author: Bslin
	> Mail: Baoshenglin1994@gmail.com
	> Created Time: 2014年08月14日 星期四 16时09分04秒
 ************************************************************************/

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <map>
using namespace std;
#define N 510

struct Point {
	int x, y;
	int v, id;
	int flag;
	Point(int x = 0, int y = 0) : x(x), y(y) { } 
	bool operator < (const Point& b) const {
		return x < b.x || (x == b.x && y < b.y);
	}
} p[N], a[N], ch[N];
typedef Point Vector;
int Cross(Vector A, Vector B) { return A.x * B.y - A.y * B.x; }
Vector operator - (Point A, Point B) { return Vector(A.x - B.x, A.y - B.y); }
map<int, int> mp;

int ConvexHull(Point* p, int n, Point* ch) {
	int i, top, t;
	sort(p, p + n);
	top = 0;
	for(i = 0; i < n; i++) {
		while(top > 1 && Cross(ch[top-1] - ch[top-2], p[i] - ch[top-2]) <= 0) top--;
		ch[top++] = p[i];
	}
	t = top;
	for(i = n-2; i >= 0; i--) {
		while(top > t && Cross(ch[top-1] - ch[top-2], p[i] - ch[top-2]) <= 0) top--;
		ch[top++] = p[i];
	}
	if(n > 1) top--;
	return top;
}

void ConvexOnLine(Point* p, int tot1, Point* ch, int tot2) {
	int i, j;
	for (i = 0; i < tot1; ++i) {
		for (j = 0; j < tot2; ++j) {
			if(Cross(ch[j] - ch[(j + 1) % tot2], ch[j] - p[i]) == 0) {
				if(mp[(p[i].x + 20001) * (p[i].y + 10001)] == 1) {
					a[p[i].id].flag = 1;
					break;
				}
			}
		}
	}
}

int main(int argc, char *argv[]) {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
	int n, i, j;
	int tot1, tot2;
	int Max;
	int flag, kk = 1;
	while(scanf("%d", &n) != EOF) {
		if(n == 0) break;
		Max = 0;
		for (i = 0; i < n; ++i) {
			scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].v);
			a[i].id = i;
			a[i].flag = 0;
			if(Max < a[i].v) {
				Max = a[i].v;
			}
		}
		if(Max == 0) {
			printf("Case #%d: ", kk++);
			for (i = 0; i < n; ++i) {
				printf("0");
			}
			printf("\n");
			continue;
		}
		tot1 = 0;
		mp.clear();
		for (i = 0; i < n; ++i) {
			if(a[i].v == Max) {
				p[tot1++] = a[i];
				mp[(a[i].x + 20001) * (a[i].y + 10001)] ++;
			}
		}
		tot2 = ConvexHull(p, tot1, ch);
		ConvexOnLine(p, tot1, ch, tot2);
		printf("Case #%d: ", kk++);
		for (i = 0; i < n; ++i) {
			if(a[i].flag) printf("1");
			else printf("0");
		}
		printf("\n");
	}
	return 0;
}
