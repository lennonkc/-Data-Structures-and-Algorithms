#include "head.h"
#include <stdio.h>

//按位置查找
Status List_Retrieve(SqListPtr L, int pos, ElemType *elem)
{
	Status s = fail;
	Ptr p = (*L)->next;
	int i = 1;
	while (p && (i < pos)) //p指向的结点存在, 并且未到达指定位置; 判断了第一个pos>1 并且pos存在
	{						//条件一: 防止pos>表长 条件二: 控制取缔pos个内, 并且防止pos<1
		i++;
		p = p->next;
	}
	if (p&&i == pos) {
		*elem = p->elem;
		s = success;
	}
	return s;
}

//按值查找
Status List_Locate(SqListPtr L, ElemType elem, int* pos){
	Status s = fail;
	Ptr p = (*L)->next;
	int i = 1;
	while (p != NULL) {
		if (p->elem == elem)break;
		i++;
		p = p->next;
	}
	if (p) {
		*pos = i;				//返回该位置
		s = success;
	}
	return s;
}