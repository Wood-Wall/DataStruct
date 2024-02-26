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

/**
 * .在指定位置插入目标元素，顺序表需要将插入出往后元素移位
 * 
 * \param L
 * \param i
 * \param e
 * \return 
 */
Status InsertElem(SqList *L, int i, Elemtype e)
{
	//插入位置不合法
	if (i<1 || i>L->length + 1)
	{
		return ERROR;
	}
	//存储空间不足，需要再分配
	Elemtype * newList;
	if (L->length >= L->size)
	{
		newList = realloc(L->elem, sizeof(Elemtype)*L->length + INCREATE_SIZE);
		if (!newList)
		{
			return ERROR;
		}
	}
	L->elem = newList;
	L->size += INCREATE_SIZE;
	//元素后移
	Elemtype *p = &L->elem[i-1];
	Elemtype *q = &L->elem[L->length - 1];
	for (; q >= p; q--)
	{
		*(q + 1) = *q;
	}
	*p = e;
	L->length++;
	return OK;
}

/**
 * .删除指定位置元素，并返回呗删除的值
 * 
 * \param L
 * \param i
 * \param e
 * \return 
 */
Status DeleteElem(SqList *L, int i, Elemtype *e)
{
	if (i<1 || i>L->length + 1)
	{
		return ERROR;
	}
	Elemtype *p = &L->elem[i - 1];
	*e = *p;
	for (; p < &L->elem[L->length]; p++)
	{
		*p = *(p + 1);
	}
	L->length--;
	return OK;
}
