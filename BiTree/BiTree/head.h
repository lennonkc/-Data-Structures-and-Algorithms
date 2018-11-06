#pragma once
typedef int TElemType;
typedef struct BiTNode {
	TElemType  data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

void PreInOrd(int preord[], int inord[], int i, int j, int k, int h, BiTree *t);
void PreOrder(BiTree t);