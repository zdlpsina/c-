// big_add.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <string>
#define nmax 100
using namespace std;

char *add(char *a, char*b) {

	int lenA = strlen(a);
	int lenB = strlen(b);    //strlen 输出长度
	
	int len = lenA > lenB ? lenA : lenB; //比较最大长度
	int *result = new int[len + 1];    //动态数组
	char*back = new char[len + 1];
	for (int i = len; i >= 0; i--) {
		//如果当前的i超过了其中的一个，就用0代替，和另一个字符数组中的数字相加
		int aint = i >(len - lenA) ? (a[lenA - 1 - len + i] - '0') : 0;
		int bint = i >(len - lenB) ? (b[lenB - 1 - len + i] - '0') : 0;
		result[i] = aint + bint;
		//printf("%d\n", result[i]);
	}


	for (int i = len; i >= 0; i--) {
		if (result[i] > 10) {
			result[i - 1] += result[i] / 10;
			result[i] %= 10;
		}
		
	}
	int ssa = 0;
	bool flag = true;
	int se = 0;
	while (flag == true) {
		if (result[se]!=0) {
			flag = false;
		}
		se++;
		ssa = se-1;
	}
	for (int i = 0; i <len+1-ssa; i++) {
	
		back[i] = result[i+ssa] + '0';
		printf("%c\n", back[i]);
	
	}
	back[len + 1 - ssa] = '\0';

	return back;
	
}


int main() {
	int n;
	printf("%s",add("123", "2132"));

	
 	return 0;
}



