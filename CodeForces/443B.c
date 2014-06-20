/*************************************************************************
	> File Name: 443B.c
	> Author: Bslin
	> Mail: Baoshenglin1994@gmail.com
	> Created Time: 2014年06月20日 星期五 17时01分24秒
	> 题意: 现有一段字符串，可以在该字符串的右边继续加 k 个字符，求 tandem repeat 的长度。
		tandem repeat 是指一段字符子串，长度为偶数长，前一半与后一半字符相同。
	> 思路: 1、若 k 比现有字符串长度长或相等，那么答案一定为 k+len 或 k+len-1 其中的一个
		偶数长度。
		2、若 k 比字符串长度短，那么最起码的 tandem repeat 长度为 2 * k 。
		然后在整个字符串里将 k 长度以上的字符子串都与自己右边相同长度的子串比较一遍，
		找到最长的 tandem repeat 长度。处理时需要在比较最后 k 个字符时，默认是和前面的
		字符相同的即可，即
		if(i + pos + nowlen >= len) {
			continue;
		}
	> 注意: 题中没有说明该 tandem repeat 一定和最后 k 个字符有关，所以要记得同时考虑前面原
	有的字符。
 ************************************************************************/

#include <stdio.h>
#include <string.h>

/**
 * totlen 原有字符串与k的总长度
 * banlen 原有字符串与k的总长度的一半
 * nowlen 需要比较的长度，tandem repeat of length 的一半
 */

int k, len;
char str[210];
int nowlen, banlen, totlen;

/**
 * 字符子串比较
 * 从pos到pos+nowlen-1与pos+nowlen到pos+nowlen+nowlen-1;
 */
int check(int pos, int nowlen) {
	int i;
	for (i = 0; i < nowlen; i++) {
		if(i + pos + nowlen >= len) {
			continue;
		}
		if(str[i + pos] != str[i + pos + nowlen]) {
			return 0;
		}
	}
	return 1;
}

int main(int argc, char *argv[]) {
	freopen("in.txt", "r", stdin);
	int ans, i;
	while(scanf("%s", &str) != EOF) {
		scanf("%d", &k);
		len = strlen(str);
		if(k >= len) {
			totlen = k + len;
			if(totlen % 2 == 0) {
				printf("%d\n", totlen);
			} else {
				printf("%d\n", totlen - 1);
			}
		} else {
			nowlen = k + 1;
			ans = 2 * k;
			banlen = (k + len) / 2;
			while(nowlen <= banlen) {
				int templen = len + k - 2 * nowlen;
				for (i = 0; i <= templen; i++) {
					if(check(i, nowlen)) {
						ans = nowlen * 2;
						break;
					}
				}
				nowlen ++;
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}
