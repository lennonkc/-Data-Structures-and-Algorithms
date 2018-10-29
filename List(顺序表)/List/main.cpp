#include "head.h"
#include<stdio.h>
#include "malloc.h"

Status List_Init(SqListPtr L)
{
	Status s = success;
	L->list_size = LIST_INIT_SIZE;
	L->length = 0;
	L->elem = (ElemType *)malloc(sizeof(ElemType)*L->list_size);
	if (L->elem == NULL)
		s = fail;
	return s;
}//o(1)

Status List_Retrival(SqListPtr L, int pos, ElemType *elem)
{
	Status s = fail;
	if (L) {
		if ((pos - 1) >= 0 && (pos - 1) < L->length) {
			*elem = L->elem[pos - 1];
			s = success;
		}
	}
	return s;
}

Status List_Locate(SqListPtr L, ElemType elem, int *pos)
{
	Status s = fail;
	if (L) {
		for(int i = 0; i < L->length;++i){
			if (L->elem[i] == elem) {
				*pos = i + 1;
				s = success;
				break;
			}
		}
	}
	return s;
}//o(n)

Status List_Insert(SqListPtr L, int pos, ElemType elem)
{
	Status s = fail;
	if ((pos - 1) >= 0 && (pos - 1) <= L->length) {
		if (L && L->length < L->list_size) {
			for (int i = L->length - 1; i >= pos - 1; --i) {
				L->elem[i + 1] = L->elem[i];
			}
			L->elem[pos - 1] = elem;
			L->length++;
			s = success;
		}
	}
	return s;
}//o(n)

Status List_delete(SqListPtr L, int pos)
{
	Status s = fail;
	if ((pos - 1) >= 0 && (pos - 1) < L->length) {
		if (L && L->length > 0) {
			for (int i = pos; i < L->length; i++) {
				L->elem[i - 1] = L->elem[i];
			}
			L->length--;
			s = success;
	}
		return s;
}