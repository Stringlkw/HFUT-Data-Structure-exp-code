#include "SequentialList.h"

int main()
{
	int sign = 1;
	Plist SList = InitList();
	printf("********************************************\n");
	printf("�����������ʵ�ֶ�Ӧ�Ĳ���\n");
	printf("0:����һ��˳��������ݸ�ֵ��\n");
	printf("1:���ҵ�i��Ԫ��\n");
	printf("2:�ڵ�i�����ǰ����ֵΪx�Ľ��\n");
	printf("3:ɾ��˳����е�i��Ԫ�ؽ��\n");
	printf("4:��һ�����������˳���L�в���һ��ֵΪx��Ԫ��\n");
	printf("5:��˳�����е��������ż������ֽ⿪���ֱ�����µ�˳�����\n");
	printf("6:��������������˳���L1��L2�еĹ���Ԫ�أ������µ�˳���L3��\n");
	printf("7:ɾ����������˳����е��ظ�Ԫ�أ���ͳ���ƶ�Ԫ�ش���\n");
	printf("8:�������˳����е�Ԫ��\n");
	printf("9:�˳�����\n");
	printf("********************************************\n");
	while (sign)
	{
		printf("���������:");
		int i;
		scanf("%d", &i);
		switch (i)
		{
		case 0:
			if (SList->Length != 0)
			{
				SList->Length = 0;
			}
			CreatSList(SList);
			printf("�ɹ�����˳���\n");
			break;
		case 1:
		{
			int n;
			printf("������Ҫ���ҵ�λ��:");
			scanf("%d", &n);
			Find(SList, n);
			break;
		}

		case 2:
		{
			int n, data;
			printf("����������Ҫ�����Ԫ�ص�λ���Լ�Ԫ�أ��ÿո������:");
			scanf("%d%d", &n, &data);
			Insert(SList, n, data);
			break;
		}
		case 3:
		{
			int n;
			printf("����������Ҫɾ����Ԫ��λ��:");
			scanf("%d", &n);
			Delete(SList, n);
			break;
		}
		case 4:
		{
			int x;
			printf("����������Ҫ�����Ԫ��:");
			scanf("%d", &x);
			int a = Insertx(SList, x);
			printf("����ɹ�");
			break;
		}
		case 5:
			Split(SList);
			break;
		case 6:
		{
			Plist SList1 = InitList();
			Plist SList2 = InitList();
			CreatSList(SList1);
			SList2 = Cross(SList, SList1);
			Traverse(SList);
			printf("\n");
			Traverse(SList1);
			printf("\n");
			if (SList2 != NULL)
			{
				printf("L1��L2�Ĺ���Ԫ��Ϊ��");
				Traverse(SList2);
			}
			else
			{
				printf("�޹���Ԫ��");
			}
			free(SList1);
			free(SList2);
			break;
		}
		case 7:
		{
			int i = DeleteRepeat(SList);
			if (i == 0)
			{
				printf("���ظ�Ԫ��");
			}
			else
			{
				printf("ɾ���ɹ�\n");
			}
			break;
		}
		case 8:
			Traverse(SList);
			break;
		case 9:
			sign = 0;
			break;
		default:
			printf("�����������������\n");
		}
		printf("\n");
	}
}