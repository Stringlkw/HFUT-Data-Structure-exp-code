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


Plist InitList(); //初始化顺序表
void CreatSList(Plist L); //创建一个顺序表
ElementType Find(Plist L, int i); //查找第i个元素
int binSearch(Plist L, ElementType x, int left, int right); //二分查找
int Insert(Plist L, int n, ElementType x); //插入一个元素
ElementType Delete(Plist L, int n); // 删除一个元素
int InsertElement(Plist L, ElementType data, int Left, int Right); // 有序顺序表中插入一个元素不改变顺序
int Insertx(Plist L, ElementType x); //将InsertElement封装
void Split(Plist L); // 将顺序表中奇数和偶数分开并打印
Plist Cross(Plist L1, Plist L2); //求两个有序顺序表的公共元素，放入一个新的顺序表中
int DeleteRepeat(Plist L); //删除有序顺序表中的重复元素
void Traverse(Plist L); //遍历顺序表中的元素
#endif // !_SEQUENTIALLIST_H
