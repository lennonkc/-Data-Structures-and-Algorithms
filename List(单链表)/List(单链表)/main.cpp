#include "head.h"
#include <stdio.h>

//��λ�ò���
Status List_Retrieve(SqListPtr L, int pos, ElemType *elem)
{
	Status s = fail;
	Ptr p = (*L)->next;
	int i = 1;
	while (p && (i < pos)) //pָ��Ľ�����, ����δ����ָ��λ��; �ж��˵�һ��pos>1 ����pos����
	{						//����һ: ��ֹpos>�� ������: ����ȡ��pos����, ���ҷ�ֹpos<1
		i++;
		p = p->next;
	}
	if (p&&i == pos) {
		*elem = p->elem;
		s = success;
	}
	return s;
}

//��ֵ����
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
		*pos = i;				//���ظ�λ��
		s = success;
	}
	return s;
}