#pragma once
#ifndef _SEQUENTIALLIST_H
#define _SEQUENTIALLIST_H
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 100
typedef int ElementType;

typedef struct SequentialList
{
	ElementType Data[MAXSIZE];
	int Length;	
}List, * Plist;


Plist InitList(); //��ʼ��˳���
void CreatSList(Plist L); //����һ��˳���
ElementType Find(Plist L, int i); //���ҵ�i��Ԫ��
int binSearch(Plist L, ElementType x, int left, int right); //���ֲ���
int Insert(Plist L, int n, ElementType x); //����һ��Ԫ��
ElementType Delete(Plist L, int n); // ɾ��һ��Ԫ��
int InsertElement(Plist L, ElementType data, int Left, int Right); // ����˳����в���һ��Ԫ�ز��ı�˳��
int Insertx(Plist L, ElementType x); //��InsertElement��װ
void Split(Plist L); // ��˳�����������ż���ֿ�����ӡ
Plist Cross(Plist L1, Plist L2); //����������˳���Ĺ���Ԫ�أ�����һ���µ�˳�����
int DeleteRepeat(Plist L); //ɾ������˳����е��ظ�Ԫ��
void Traverse(Plist L); //����˳����е�Ԫ��
#endif // !_SEQUENTIALLIST_H
