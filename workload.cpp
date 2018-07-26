// workload.cpp: 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <cstdio>
using namespace std;
int main()
{
	
	int n;
	scanf("%d", &n);
	int **a = new int*[n];
	for (int i = 0; i < n; i++) {  //为指针数组的每个元素分配一个数组

		a[i] = new int[n];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
		}
	}



	int size = n;
	int min = 0;
	for (int i = 0; i < n; i++) {
		min = min + a[i][i];
	}
	int *b = new int[n];
	for (int i = 0; i < n; i++) {
		b[i] = i;
	}
	int q = n-1;
	int sum = min;
	
	do {
		if (size >= n || q >= n) {
			q = b[size - 1];
			sum = sum - a[size - 1][b[size - 1]];
			q++;
			size--;
			
		}
		else {
			bool flag = false;
			for (int i = 0; i < size; i++) {
				if (q == b[i]) {
					flag = true;
				}
			}
			while ((q< n) && (flag)) {
				q++;
				flag = false;
				for (int i = 0; i < size; i++) {
					if (q == b[i]) {
						flag = true;
					}
				}
				
			}
			if ((n > q)&&((sum+a[size][q])<min)) {
				size++;
				b[size - 1] = q;
				sum = sum + a[size - 1][b[size - 1]];
				if (sum > min) {

				}
				if (size >= n) {
					min = (sum < min) ? sum : min;
				}
				q = 0;
			}
			else { q++; }
		}
		
	} while (q < n || size >0);



	printf("%d", min);
    return 0;
}

