#include "LinkedList.h"



int main()
{
	LinkedList List;
	int sign = 1;

	cout << "********************************************" << endl;
	cout << "�����������ʵ�ֶ�Ӧ�Ĳ���" << endl;
	cout << "0:β�巨����һ�������������ݸ�ֵ)������-1����" << endl;
	cout << "1:ͷ�巨����һ�������� (�����ݸ�ֵ)������-1����" << endl;
	cout << "2:���ٵ�����" << endl;
	cout << "3:��������" << endl;
	cout << "4:���ҵ�i��Ԫ��" << endl;
	cout << "5:�ڵ�i�����ǰ����ֵΪx�Ľ��" << endl;
	cout << "6:����������Ԫ��ֵΪx�Ľ��" << endl;
	cout << "7:ɾ���������е�i��Ԫ�ؽ��" << endl;
	cout << "8:��һ����������ĵ�����L�в���һ��ֵΪx��Ԫ�أ��������������������" << endl;
	cout << "9:����������е��������ż������ֽ⿪���ֱ�����µĵ�������" << endl;
	cout << "10:������������������L1��L2�еĹ���Ԫ�أ������µĵ�����L3��" << endl;
	cout << "11:ɾ���������������е��ظ�Ԫ�أ���ͳ���ƶ�Ԫ�ش���" << endl;
	cout << "12:�ϲ���������ĵ�����L1��L2������L1�У���ʹ�úϲ����Ϊһ������" << endl;
	cout << "13:�������˳����е�Ԫ��" << endl;
	cout << "14:�˳�����" << endl;
	cout << "********************************************" << endl;
	while (sign)
	{

		cout << ("���������:");
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
			cout << "����������" << endl;
			break;

		case 3:
		{
			int len;
			len = List.Length();
			cout << "����ĳ���Ϊ��" << len << endl;
			break;
		}

		case 4:
		{
			int n = 0;
			cout << "������Ҫ���ҵĽ��λ��:";
			cin >> n;
			PNode L = List.Find(n);
			if (L == nullptr)
			{
				cout << "���ҽ�㲻����" << endl;
			}
			else
			{
				cout << "���Ԫ��Ϊ��" << L->Data << endl;
			}
			break;
		}

		case 5:
		{
			int n = 0;
			ElementType data = 0;
			cout << "������Ҫ�������λ�ã��Լ�����Ԫ��ֵ:";
			cin >> n >> data;
			bool sign = List.Insert(n, data);
			if (sign == false)
			{
				cout << "����λ�ô���" << endl;
			}
			else
			{
				cout << "����ɹ�" << endl;
				List.Traverse();	
			}
			break;
		}

		case 6:
		{
			int n = 0;
			cout << "������Ҫ���ҵĽ���Ԫ��ֵ:";
			cin >> n;
			PNode L;
			L = List.Findx(n);
			if (L == nullptr)
			{
				cout << "����ʧ�ܣ��ý�㲻����" << endl;
			}
			else
			{
				cout << "���ҳɹ�" << endl;
			}
			break;
		}
		case 7:
		{
			int n = 0;
			cout << "������Ҫɾ���Ľ���λ��:";
			cin >> n;
			bool sign = List.Delete(n);
			if (sign == false)
			{
				cout << "��㲻����" << endl;
			}
			else
			{
				cout << "ɾ���ɹ�" << endl;
				List.Traverse();
			}
			break;
		}

		case 8:
		{
			ElementType data = 0;
			cout << "������Ҫ�������Ԫ��ֵ:";
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
			cout << "�����е�Ԫ���У�";
			List.Traverse();
			cout << "�����У�";
			Odd.Traverse();
			cout << "ż���У�";
			Even.Traverse();
			break;
		}

		case 10:
		{	
			LinkedList List1;
			LinkedList List2;
			List1.CreateListRear();
			cout << "L1�е�Ԫ��Ϊ��";
			List.Traverse();
			cout << "L2�е�Ԫ��Ϊ��";
			List1.Traverse();
			List2 = List.Cross(List1);
			cout << "L3�е�Ԫ��Ϊ��";
			List2.Traverse();
			break;
		}

		case 11:
		{
			int i = 0;
			i = List.uniquify();
			cout << "�ƶ�Ԫ�ش���Ϊ��" << i << endl;
			List.Traverse();
			break;
		}

		case 12:
		{
			List.uniquify();
			LinkedList List1;
			List1.CreateListRear();
			cout << "L1�е�Ԫ��Ϊ��";
			List.Traverse();
			cout << "L2�е�Ԫ��Ϊ��";
			List1.Traverse();
			List.Merge(List1);
			cout << "L1��L2�ϲ�֮���L1�е�Ԫ��Ϊ��";
			List.Traverse();
			break;
		}

		case 13:
			cout << "�����е�Ԫ���У�";
			List.Traverse();
			break;

		case 14:
			sign = 0;
			break;

		default:
			cout << "�����������������" << endl;
		}
		cout << endl;
	}
}









