#ifndef LINKEDLIST_H
#define LINKEDLIST_H


#include <iostream>
#include <stdlib.h>
using namespace std;


typedef int ElementType;

struct ListNode
{
	ElementType Data;
	ListNode* Next;

};
typedef ListNode* PNode;

class LinkedList
{
private:
	PNode Head;  //头结点
	PNode Rear;	//尾结点
	void Init(); //列表创建时的初始化
	void Destory(); //销毁整个链表（包含头结点）

public:
	LinkedList() { Init(); } //默认构造函数
	~LinkedList() { Destory(); } //析构函数（销毁链表）
	void Clear(); //清空链表（不包含头结点）
	PNode GetHead(); //获取头结点
	PNode GetRear(); //获取尾结点
	void CreateListHead(); //头插法创建链表
	void CreateListRear(); // 尾插法创建链表
	void InsertHead(ElementType data); //头插
	void InsertRear(ElementType data); //尾插
	bool IsEmpty() { return Head->Next == nullptr; }; //判空
	int Length(); //获取链表长度
	void Traverse(); //遍历链表并输出
	PNode Find(int n); //查找第i个元素
	bool Insert(int n, ElementType data); //在第i个结点前插入值为x的结点
	PNode Findx(ElementType x); //查找值为x的结点，返回第一个找到的结点
	bool Delete(int n); //删除第i个结点
	PNode Insertx(ElementType data); //有序链表中插入一个元素且不改变顺序
	void Split(LinkedList& Odd, LinkedList& Even); //将单链表Ｌ中的奇数项和偶数项结点分解到两个链表L1，L2
	LinkedList& Cross(LinkedList& P); //求两个递增有序单链表L1和L2中的公共元素,放入新的单链表L3中
	int uniquify(); //删除有序单链表中的重复元素
	void Merge(LinkedList& List1); //利用原表结点对两个表进行合并，并使得合并后成为一个集合
};
#endif // !LINKEDLIST_H





