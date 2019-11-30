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
	PNode Head;  //ͷ���
	PNode Rear;	//β���
	void Init(); //�б���ʱ�ĳ�ʼ��
	void Destory(); //����������������ͷ��㣩

public:
	LinkedList() { Init(); } //Ĭ�Ϲ��캯��
	~LinkedList() { Destory(); } //������������������
	void Clear(); //�������������ͷ��㣩
	PNode GetHead(); //��ȡͷ���
	PNode GetRear(); //��ȡβ���
	void CreateListHead(); //ͷ�巨��������
	void CreateListRear(); // β�巨��������
	void InsertHead(ElementType data); //ͷ��
	void InsertRear(ElementType data); //β��
	bool IsEmpty() { return Head->Next == nullptr; }; //�п�
	int Length(); //��ȡ������
	void Traverse(); //�����������
	PNode Find(int n); //���ҵ�i��Ԫ��
	bool Insert(int n, ElementType data); //�ڵ�i�����ǰ����ֵΪx�Ľ��
	PNode Findx(ElementType x); //����ֵΪx�Ľ�㣬���ص�һ���ҵ��Ľ��
	bool Delete(int n); //ɾ����i�����
	PNode Insertx(ElementType data); //���������в���һ��Ԫ���Ҳ��ı�˳��
	void Split(LinkedList& Odd, LinkedList& Even); //����������е��������ż������ֽ⵽��������L1��L2
	LinkedList& Cross(LinkedList& P); //������������������L1��L2�еĹ���Ԫ��,�����µĵ�����L3��
	int uniquify(); //ɾ�����������е��ظ�Ԫ��
	void Merge(LinkedList& List1); //����ԭ�������������кϲ�����ʹ�úϲ����Ϊһ������
};
#endif // !LINKEDLIST_H





