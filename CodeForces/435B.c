#include <stdio.h>
#include <string.h>

int len;

int maxpos(char *str, int now, int k) {
	//printf("%s\n", str);
	int i;
	int nown = 0, nowvalue = str[0];
	for(i = 1; i <= k && now + i < len; i ++) {
		if(nowvalue < str[i]) {
			nowvalue = str[i];
			nown = i;
		}
	}
	//printf("%d\n", nown);
	return nown;
}

void make(char *str, int maxn) {
	int i;
	if(maxn == 0) return ;
	char temp = str[maxn];
	for(i = maxn - 1; i >= 0; i --) {
		str[i + 1] = str[i];
	}
	str[0] = temp;
}

int main() {
	char str[20];
	int k, i;
	int maxn;
	while(scanf("%s%d", &str, &k) != EOF) {
		len = strlen(str);
		i = 0;
		//printf("%d\n", len);
		while(k != 0 && i < len) {
			//printf("%d\n", i);
			maxn = maxpos(str + i, i, k);
			k -= maxn;
			make(str + i, maxn);
			//printf("%s\n", str);
			i ++;
		}
		printf("%s\n", str);
	}
	return 0;
}
