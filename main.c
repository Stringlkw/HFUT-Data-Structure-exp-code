#include "SequentialList.h"

int main()
{
	int sign = 1;
	Plist SList = InitList();
	printf("********************************************\n");
	printf("请输入序号来实现对应的操作\n");
	printf("0:创建一个顺序表（给数据赋值）\n");
	printf("1:查找第i个元素\n");
	printf("2:在第i个结点前插入值为x的结点\n");
	printf("3:删除顺序表中第i个元素结点\n");
	printf("4:在一个递增有序的顺序表L中插入一个值为x的元素\n");
	printf("5:将顺序表Ｌ中的奇数项和偶数项结点分解开，分别放入新的顺序表中\n");
	printf("6:求两个递增有序顺序表L1和L2中的公共元素，放入新的顺序表L3中\n");
	printf("7:删除递增有序顺序表中的重复元素，并统计移动元素次数\n");
	printf("8:遍历输出顺序表中的元素\n");
	printf("9:退出程序\n");
	printf("********************************************\n");
	while (sign)
	{
		printf("请输入序号:");
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
			printf("成功创建顺序表\n");
			break;
		case 1:
		{
			int n;
			printf("请输入要查找的位置:");
			scanf("%d", &n);
			Find(SList, n);
			break;
		}

		case 2:
		{
			int n, data;
			printf("请输入你想要插入的元素的位置以及元素（用空格隔开）:");
			scanf("%d%d", &n, &data);
			Insert(SList, n, data);
			break;
		}
		case 3:
		{
			int n;
			printf("请输入你想要删除的元素位置:");
			scanf("%d", &n);
			Delete(SList, n);
			break;
		}
		case 4:
		{
			int x;
			printf("请输入你想要插入的元素:");
			scanf("%d", &x);
			int a = Insertx(SList, x);
			printf("插入成功");
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
				printf("L1和L2的公共元素为：");
				Traverse(SList2);
			}
			else
			{
				printf("无公共元素");
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
				printf("无重复元素");
			}
			else
			{
				printf("删除成功\n");
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
			printf("输入错误，请重新输入\n");
		}
		printf("\n");
	}
}