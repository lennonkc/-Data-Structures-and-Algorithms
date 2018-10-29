#define LIST_INIT_SIZE 100
#define LIST_INCREAMENT 10
//ÏßÐÔ±íË³Ðò´æ´¢
typedef int ElemType;
typedef struct SqList
{
	ElemType *elem;
	int length;
	int list_size;
}SqList,*Ptr;
typedef Ptr SqListPtr;
typedef enum { fail, success }Status;
Status List_Init(SqListPtr L); 
void List_Dcstory(SqListPtr L); 
void List_Clear(SqListPtr L); 
bool List_Empty(SqListPtr L); 
int List_Size(SqListPtr L);
Status List_Retrival(SqListPtr L, int pos, ElemType *cIcm);
Status List_Locate(SqListPtr L, ElemType elem, int *pos);
Status List_Insert(SqListPtr L, int pos, ElemType clcm);
Status List_delete(SqListPtr L, int pos);
Status List_Prior(SqListPtr L, int pos, ElemType * clem);
Status List_Next(SqListPtr L, int pos, ElemType *elem);