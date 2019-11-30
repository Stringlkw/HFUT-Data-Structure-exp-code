#include "LinkedList.h"



int main()
{
	LinkedList List;
	int sign = 1;

	cout << "********************************************" << endl;
	cout << "请输入序号来实现对应的操作" << endl;
	cout << "0:尾插法创建一个单链表（给数据赋值)，输入-1结束" << endl;
	cout << "1:头插法创建一个单链表 (给数据赋值)，输入-1结束" << endl;
	cout << "2:销毁单链表" << endl;
	cout << "3:求链表长度" << endl;
	cout << "4:查找第i个元素" << endl;
	cout << "5:在第i个结点前插入值为x的结点" << endl;
	cout << "6:查找链表中元素值为x的结点" << endl;
	cout << "7:删除单链表中第i个元素结点" << endl;
	cout << "8:在一个递增有序的单链表L中插入一个值为x的元素，并保持其递增有序特性" << endl;
	cout << "9:将单链表Ｌ中的奇数项和偶数项结点分解开，分别放入新的单链表中" << endl;
	cout << "10:求两个递增有序单链表L1和L2中的公共元素，放入新的单链表L3中" << endl;
	cout << "11:删除递增有序单链表中的重复元素，并统计移动元素次数" << endl;
	cout << "12:合并递增有序的单链表L1、L2，放入L1中，并使得合并后成为一个集合" << endl;
	cout << "13:遍历输出顺序表中的元素" << endl;
	cout << "14:退出程序" << endl;
	cout << "********************************************" << endl;
	while (sign)
	{

		cout << ("请输入序号:");
		int i;
		cin >> i;
		switch (i)
		{
		case 0:
			if (!List.IsEmpty())
			{
				List.Clear();
			}
			List.CreateListRear();
			break;

		case 1:
			if (!List.IsEmpty())
			{
				List.Clear();
			}
			List.CreateListHead();
			break;

		case 2:
			List.Clear();
			cout << "链表已销毁" << endl;
			break;

		case 3:
		{
			int len;
			len = List.Length();
			cout << "链表的长度为：" << len << endl;
			break;
		}

		case 4:
		{
			int n = 0;
			cout << "请输入要查找的结点位置:";
			cin >> n;
			PNode L = List.Find(n);
			if (L == nullptr)
			{
				cout << "查找结点不存在" << endl;
			}
			else
			{
				cout << "结点元素为：" << L->Data << endl;
			}
			break;
		}

		case 5:
		{
			int n = 0;
			ElementType data = 0;
			cout << "请输入要插入结点的位置，以及结点的元素值:";
			cin >> n >> data;
			bool sign = List.Insert(n, data);
			if (sign == false)
			{
				cout << "插入位置错误" << endl;
			}
			else
			{
				cout << "插入成功" << endl;
				List.Traverse();	
			}
			break;
		}

		case 6:
		{
			int n = 0;
			cout << "请输入要查找的结点的元素值:";
			cin >> n;
			PNode L;
			L = List.Findx(n);
			if (L == nullptr)
			{
				cout << "查找失败，该结点不存在" << endl;
			}
			else
			{
				cout << "查找成功" << endl;
			}
			break;
		}
		case 7:
		{
			int n = 0;
			cout << "请输入要删除的结点的位置:";
			cin >> n;
			bool sign = List.Delete(n);
			if (sign == false)
			{
				cout << "结点不存在" << endl;
			}
			else
			{
				cout << "删除成功" << endl;
				List.Traverse();
			}
			break;
		}

		case 8:
		{
			ElementType data = 0;
			cout << "请输入要插入结点的元素值:";
			cin >> data;
			List.Insertx(data);
			List.Traverse();
			break;
		}

		case 9:
		{
			LinkedList Odd;
			LinkedList Even;
			List.Split(Odd, Even);
			cout << "链表中的元素有：";
			List.Traverse();
			cout << "奇数有：";
			Odd.Traverse();
			cout << "偶数有：";
			Even.Traverse();
			break;
		}

		case 10:
		{	
			LinkedList List1;
			LinkedList List2;
			List1.CreateListRear();
			cout << "L1中的元素为：";
			List.Traverse();
			cout << "L2中的元素为：";
			List1.Traverse();
			List2 = List.Cross(List1);
			cout << "L3中的元素为：";
			List2.Traverse();
			break;
		}

		case 11:
		{
			int i = 0;
			i = List.uniquify();
			cout << "移动元素次数为：" << i << endl;
			List.Traverse();
			break;
		}

		case 12:
		{
			List.uniquify();
			LinkedList List1;
			List1.CreateListRear();
			cout << "L1中的元素为：";
			List.Traverse();
			cout << "L2中的元素为：";
			List1.Traverse();
			List.Merge(List1);
			cout << "L1和L2合并之后的L1中的元素为：";
			List.Traverse();
			break;
		}

		case 13:
			cout << "链表中的元素有：";
			List.Traverse();
			break;

		case 14:
			sign = 0;
			break;

		default:
			cout << "输入错误，请重新输入" << endl;
		}
		cout << endl;
	}
}









