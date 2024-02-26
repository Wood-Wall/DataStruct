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
