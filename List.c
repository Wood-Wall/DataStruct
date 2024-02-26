#include <stdio.h>
#include <stdlib.h>

#define INIT_SIZE 10		//默认分配空间
#define INCREATE_SIZE 5		//拓宽空间增量
#define OK 1
#define ERROR 0

typedef int Elemtype;
typedef int Status;

//表存储结构
typedef struct
{
	Elemtype *elem;		//存储空间起始地址
	int length;			//当前列表长度
	int size;			//当前分配的列表空间
}SqList;

/**
 * .初始化顺序表
 * 
 * \param L
 * \return 
 */
Status InitList(SqList *L)
{
	L->elem = (Elemtype*)malloc(sizeof(Elemtype) * INIT_SIZE + 1);
	if (!L->elem)
	{
		return ERROR;
	}
	L->size = INIT_SIZE;
	L->length = 0;
	return OK;
}

/**
 * .销毁顺序表
 * 
 * \param L
 * \return 
 */
Status DestoryList(SqList *L)
{
	free(L->elem);
	L->size = 0;
	L->length = 0;
	return OK;
}
