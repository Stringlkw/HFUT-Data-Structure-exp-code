#include "LinkedList.h"
void LinkedList::Init()
{
	Head = new ListNode();
	Rear = new ListNode();
	Head->Data = 0;
	Head->Next = nullptr;
	Rear = Head;
}

void LinkedList::Destory()
{
	PNode Tmp;
	PNode L = Head;
	while (L->Next != nullptr)
	{
		Tmp = L->Next;
		L->Next = Tmp->Next;
		delete Tmp;
	}
	delete Head;
}

void LinkedList::Clear()
{
	PNode Tmp;
	PNode L = Head;
	while (L->Next != nullptr)
	{
		Tmp = L->Next;
		L->Next = Tmp->Next;
		delete Tmp;
	}
	Head->Next = nullptr;
	Rear = Head;
}

void LinkedList::CreateListHead()
{
	ElementType data;
	cout << "请输入数据:";
	cin >> data;
	if (data != -1)
	{
		PNode P = new ListNode();
		P->Data = data;
		P->Next = nullptr;
		Head->Next = P;
		Rear = P;
	}
	cout << "请输入数据:";
	cin >> data;
	while (data != -1)
	{
		PNode P = new ListNode();
		P->Data = data;
		P->Next = Head->Next;
		Head->Next = P;
		cout << "请输入数据:";
		cin >> data;
	}
}

void LinkedList::CreateListRear()
{
	ElementType data;
	cout << "请输入数据:";
	cin >> data;
	while (data != -1)
	{
		PNode P = new ListNode();
		P->Data = data;
		P->Next = nullptr;
		Rear->Next = P;
		Rear = P;
		cout << "请输入数据:";
		cin >> data;
	}

}

PNode LinkedList::GetHead()
{
	return Head;
}
PNode LinkedList::GetRear()
{
	return Rear;
}

void LinkedList::InsertHead(ElementType data)
{
	PNode L = new ListNode();
	L->Data = data;
	L->Next = L->Next;
	L->Next = L;
}

void LinkedList::InsertRear(ElementType data)
{
	PNode L = new ListNode();
	L->Data = data;
	L->Next = nullptr;
	Rear->Next = L;
	Rear = L;
}

void LinkedList::Traverse()
{
	if (Head->Next == nullptr)
	{
		cout << "链表为空";
		cout << endl;
		return;
	}
	PNode L = Head->Next;
	while (L != nullptr)
	{
		cout << L->Data << " ";
		L = L->Next;
	}
	cout << endl;
}


int LinkedList::Length()
{
	int len = 0;
	PNode L = Head->Next;
	while (L != nullptr)
	{
		L = L->Next;
		len++;
	}
	return len;
}

PNode LinkedList::Find(int n)
{
	PNode L = Head->Next;
	int i = 1;
	while (L != nullptr && i != n)
	{
		L = L->Next;
		i++;
	}
	return L;
}


bool LinkedList::Insert(int n, ElementType data)
{
	PNode L = Head;
	int i = 1;
	while (L != nullptr && i != n)
	{
		L = L->Next;
		i++;
	}
	if (L == nullptr)
	{
		return false;
	}
	else
	{
		PNode P = new ListNode();
		P->Data = data;
		P->Next = L->Next;
		L->Next = P;
		return true;
	}
}

PNode LinkedList::Findx(ElementType x)
{
	PNode L = Head->Next;
	while (L->Data != x && L != nullptr)
	{
		L = L->Next;
	}
	return L;
}

bool LinkedList::Delete(int n)
{
	PNode L = Head;
	int i = 0;
	while (i != n - 1 && L != nullptr)
	{
		L = L->Next;
		i++;
	}
	if (L == nullptr || L->Next == nullptr)
	{
		cout << "所删除元素不存在" << endl;
		return false;
	}
	else
	{
		PNode P = L->Next;
		L->Next = P->Next;
		delete P;
	}
	if (Head->Next == nullptr)
	{
		Rear = Head;
	}
	return true;
}

PNode LinkedList::Insertx(ElementType data)
{
	PNode L = Head;
	PNode P = new ListNode();
	P->Data = data;
	P->Next = nullptr;
	if (Rear->Data <= data)
	{
		Rear->Next = P;
		Rear = P;
		return P;
	}
	while (L->Next->Data <= data)
	{
		L = L->Next;
	}
	P->Data = data;
	P->Next = L->Next;
	L->Next = P;
	return P;
}

void LinkedList::Split(LinkedList& Odd, LinkedList& Even)
{
	PNode L = Head->Next;
	while (L != nullptr)
	{
		if (L->Data % 2 != 0)
		{
			Odd.InsertRear(L->Data);
		}
		else
		{
			Even.InsertRear(L->Data);
		}
		L = L->Next;
	}
}

LinkedList& LinkedList::Cross(LinkedList& List1)
{
	LinkedList* List2 = new LinkedList();
	PNode L = Head->Next;
	PNode P = List1.GetHead()->Next;
	while (L->Next != nullptr && P->Next != nullptr)
	{
		if (L->Data < P->Data)
		{
			L = L->Next;
		}
		else if (L->Data > P->Data)
		{
			P = P->Next;
		}
		else
		{
			PNode S = List2->GetRear();
			if (L->Data != S->Data)
			{
				List2->InsertRear(L->Data);
			}
			L = L->Next;
			P = P->Next;
		}
	}
	return *List2;
}

int LinkedList::uniquify()
{
	int n = 0;
	if (Head->Next == nullptr)
	{
		return n;
	}
	PNode P = Head->Next;
	PNode Q = P->Next;
	while (Q != nullptr)
	{
		if (P->Data != Q->Data)
		{
			P = Q;
			Q = P->Next;
		}
		else
		{
			P->Next = Q->Next;
			delete Q;
			Q = P->Next;
			n++;
		}
	}
	Rear = P;
	return n;
}

void LinkedList::Merge(LinkedList& List1)
{
	PNode L = Head;
	PNode P = List1.GetHead()->Next;
	while (L->Next != nullptr && P != nullptr)
	{
		if (L->Next->Data < P->Data)
		{
			L = L->Next;
		}
		else if (L->Next->Data == P->Data)
		{
			PNode Tmp = P;
			P = P->Next;
			delete Tmp;
		}
		else
		{
			PNode S = P;
			P = P->Next;
			S->Next = L->Next;
			L->Next = S;
		}
	}
	if (P != nullptr)
	{
		L->Next = P;
	}
	List1.GetHead()->Next = nullptr;
}

