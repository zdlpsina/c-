// mergesort.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<cstdio>


template <typename T> 
void mergeSort(T *A,int lo, int hi) { //0 <= lo < hi <= size
	    if (hi - lo < 2) return; //单元素区间自然有序，否则...
	    int mi = (lo + hi) / 2; //以中点为界
	    mergeSort(A,lo, mi); mergeSort(A,mi, hi); //分别排序
	    merge(A,lo, mi, hi); //归并
	
}
template <typename T> void merge(T*_elem,int lo,int mi, int hi) { //各自有序的子向量[lo, mi)和[mi, hi)
	    T* A = _elem + lo; //合并后的向量A[0, hi - lo) = _elem[lo, hi)
	    int lb = mi - lo; T* B = new T[lb]; //前子向量B[0, lb) = _elem[lo, mi)
		for (int i = 0; i < lb; i++) { B[i] = A[i]; } //复制前子向量
	    int lc = hi - mi; T* C = _elem + mi; //后子向量C[0, lc) = _elem[mi, hi)
	    for (int i = 0, j = 0, k = 0; j < lb; ) { //B[j]和C[k]中的小者续至A末尾
		       if ((k<lc) && (B[j]>C[k])) A[i++] = C[k++];
		       if (((k >= lc) || C[k] >=  B[j])) A[i++] = B[j++];
		
	}
	    delete[] B; //释放临时空间B
	
} ///归并后得到完整的有序向量[lo, hi)

int main()
{



	int* A = new int[8];
	for (int i = 0; i < 8; i++) {
		A[i] = 10 - i;
	}
	mergeSort(A,0,8);
	for (int i = 0; i < 8; i++) {
		printf("%d", A[i]);
	}
    return 0;
}

