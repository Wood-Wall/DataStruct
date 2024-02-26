#include <stdio.h>
#include <stdlib.h>

#define INIT_SIZE 10		//Ĭ�Ϸ���ռ�
#define INCREATE_SIZE 5		//�ؿ�ռ�����
#define OK 1
#define ERROR 0

typedef int Elemtype;
typedef int Status;

//��洢�ṹ
typedef struct
{
	Elemtype *elem;		//�洢�ռ���ʼ��ַ
	int length;			//��ǰ�б���
	int size;			//��ǰ������б�ռ�
}SqList;

/**
 * .��ʼ��˳���
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
 * .����˳���
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
 * .��ָ��λ�ò���Ŀ��Ԫ�أ�˳�����Ҫ�����������Ԫ����λ
 * 
 * \param L
 * \param i
 * \param e
 * \return 
 */
Status InsertElem(SqList *L, int i, Elemtype e)
{
	//����λ�ò��Ϸ�
	if (i<1 || i>L->length + 1)
	{
		return ERROR;
	}
	//�洢�ռ䲻�㣬��Ҫ�ٷ���
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
	//Ԫ�غ���
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
 * .ɾ��ָ��λ��Ԫ�أ���������ɾ����ֵ
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
