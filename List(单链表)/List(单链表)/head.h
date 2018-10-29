typedef int ElemType;
typedef enum{fail,success} Status;

typedef struct Node
{
	ElemType elem;
	struct Node * next;
}Node,*Ptr;

typedef Ptr *SqListPtr;

Status List_Retrieve(SqListPtr L, int pos, ElemType *elem);
Status List_Locate(SqListPtr L,ElemType elem,int* pos);