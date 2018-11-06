#include "head.h"
#include <stdio.h>
#include<stdlib.h>

/*Build a BiTree base on Preord and inord*/
void CreateBiTree(int preord[], int inord[], int n, BiTree root) {
	if (n <= 0)root = NULL;
	else PreInOrd(preord, inord, 1, n, 1, n, &root);
}

void PreInOrd(int preord[], int inord[], int i, int j, int k, int h, BiTree *t) {
/*���������д�i����j, �������д�k��h, ����һ�Ŷ������ŵ�t��*/
	int m;
	(*t) = new BiTNode;
	(*t)->data = preord[i];
	m = k;
	while (inord[m] != preord[i])m++;
	if (m == k)(*t)->lchild = NULL;
	else PreInOrd(preord, inord, i + 1, i + m - k, k, m - 1, &((*t)->lchild));
	if (m == h)(*t)->rchild = NULL;
	else PreInOrd(preord, inord, i + m - k + 1, j, m + 1, h, &((*t)->rchild));
}
void PreOrder(BiTree t) {
	if (t) {
		printf("%d", t->data);
		PreOrder(t->lchild);
		PreOrder(t->rchild);
	}
}


void main() {
	int pre[5] = { 1, 2, 3, 4, 5 }, ord[5] = { 6,7,8,9,10 };
	BiTree Node = new BiTNode;
	CreateBiTree(pre, ord, 4, Node);
	PreOrder(Node);
}