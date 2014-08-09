/*************************************************************************
	> File Name: poj1379.c
	> Author: Bslin
	> Mail: Baoshenglin1994@gmail.com
	> Created Time: 2014年08月04日 星期一 15时15分49秒
 ************************************************************************/

#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <stdlib.h>
using namespace std;
#define PI acos(-1)

struct Point {
	double x, y;
	Point(double x = 0, double y = 0) : x(x), y(y) {}
} hole[1010], p[50], now;
double mx, my;
double mdis[50];
int n;

double random1() {
	return (double)(rand() % 1001) / 1000;
}

double dis(Point a, Point b) {
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double minDis(Point p) {
	int i;
	double mmin = 1e10;
	for (i = 0; i < n; ++i) {
		mmin = min(mmin, dis(p, hole[i]));
	}
	return mmin;
}

void solve() {
	int i, j;
	/*
	1、随机选取一个合适的控制条件T作为开始
	2、随机选取P个起始点，作为可行解
	3、分别依据内能更新这P个可行解
	4、减小 控制条件 T，直到终止条件
	*/
	double mm = sqrt(mx * mx + my * my), nowMin;
	for (i = 0; i < 30; ++i) {
		p[i] = Point(random1() * mx, random1() * my);
		mdis[i] = minDis(p[i]);
	}
	while(mm >= 0.001) {
		for (i = 0; i < 30; ++i) {
			for (j = 0; j < 30; ++j) { // 次数
				double angle = (double)random1() * 2 * PI;
				now = Point(p[i].x + cos(angle) * mm, p[i].y + sin(angle) * mm);
				if(now.x >= 0 && now.x < mx && now.y >= 0 && now.y < my) {
					nowMin = minDis(now);
					if(nowMin > mdis[i]) {
						mdis[i] = nowMin;
						p[i] = now;
					}
				}
			}
		}
		mm *= 0.8;
	}
}

int main(int argc, char *argv[]) {
	freopen("in.txt", "r", stdin);
	int cas, i;
	double Max;
	Point now;
	scanf("%d", &cas);
	while(cas --) {
		scanf("%lf%lf%d", &mx, &my, &n);
		for (i = 0; i < n; ++i) {
			scanf("%lf%lf", &hole[i].x, &hole[i].y);
		}
		solve();
		Max = 0;
		for (i = 0; i < 30; ++i) {
			if(Max < mdis[i]) {
				Max = mdis[i];
				now = p[i];
			}
		}
		printf("The safest point is (%.1f, %.1f).\n", now.x, now.y);
	}
	return 0;
}
