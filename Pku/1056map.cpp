/*************************************************************************
	> File Name: poj1056map.cpp
	> Author: Bslin
	> Mail: Baoshenglin1994@gmail.com
	> Created Time: 2014年07月24日 星期四 11时16分30秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>
#include <map>
using namespace std;

map<string, int> mp;
map<string,int>::iterator it;

bool check(string str) {
	int i, j, len;
	string s;
	len = str.size();
	for (i = 0; i < mp.size(); ++i) {
		for (j = 1; j <= len; ++j) {
			s = str.substr(0, j);
			it = mp.find(s);
			if(it != mp.end()) {
				return true;
			}
		}
	}
	return false;
}

int main(int argc, char *argv[]) {
	freopen("in.txt", "r", stdin);
	bool flag;
	int cas;
	string str;
	mp.clear();
	flag = 0;
	cas = 1;
	while(cin >> str) {
		if(str[0] == '9') {
			if(flag == 0) {
				printf("Set %d is immediately decodable\n", cas);
			} else {
				printf("Set %d is not immediately decodable\n", cas);
			}
			mp.clear();
			flag = 0;
			cas ++;
		}
		if(flag == 0) {
			if(check(str)) {
				flag = 1;
			}
			mp[str] = 1;
		}
	}
	return 0;
}
