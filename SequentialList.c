#include "SequentialList.h"

Plist InitList()
{
	Plist L = (Plist)malloc(sizeof(List));
	memset(L, 0, sizeof(List));
	return L;
}

void CreatSList(Plist L)
{
	ElementType data;
	printf("请输入元素:");
	scanf("%d", &data);
	if (data != -1)
	{
		L->Data[L->Length++] = data;
		CreatSList(L);
	}
}

ElementType Find(Plist L, int i)
{
	if (i < 1 || i > L->Length)
	{
		printf("元素不存在\n");
		return -1;
	}
	printf("元素为:%d\n", L->Data[i - 1]);
	return L->Data[i - 1];
}

int binSearch(Plist L, ElementType x, int left, int right)
{
	while (left < right)
	{
		int mid = (left + right) / 2;
		(x < L->Data[mid]) ? (right = mid) : (left = mid + 1);
	}
	return --left;
}

int Insert(Plist L, int n, ElementType x)
{
	if (L->Length == MAXSIZE)
	{
		printf("顺序表已满，无法插入");
		return MAXSIZE;
	}
	if (n < 1 || n > L->Length)
	{
		printf("插入失败\n");
		return n;
	}
	for (int i = L->Length; i >= n; i--)
	{
		L->Data[i] = L->Data[i - 1];
	}
	L->Data[n - 1] = x;
	L->Length++;
	printf("插入成功");
	return 0;
}

ElementType Delete(Plist L, int n)
{
	if (L->Length <= 0)
	{
		printf("顺序表为空。\n");
		return 0;
	}
	else if (n < 1 || n > L->Length)
	{
		printf("所删除的位置不在顺序表中。\n");
		return -1;
	}
	else
	{
		ElementType deletedata = L->Data[n - 1];
		for (int i = n; i <= L->Length; i++)
		{
			L->Data[i - 1] = L->Data[i];
		}
		L->Length--;
		printf("删除成功。\n");
		return deletedata;
	}
}

int InsertElement(Plist L, ElementType data, int Left, int Right)
{
	int Pos = binSearch(L, data, Left, Right);
	if (L->Length == MAXSIZE)
	{
		printf("顺序表已满，无法插入");
		return MAXSIZE;
	}
	for (int i = L->Length; i > Pos + 1; i--)
	{
		L->Data[i] = L->Data[i - 1];
	}
	L->Data[Pos + 1] = data;
	L->Length++;
	return Pos + 2;
}

int Insertx(Plist L, ElementType x)
{
	int a = InsertElement(L, x, 0, L->Length);
	return a;
}

void Split(Plist L)
{
	Plist odd = InitList();
	Plist even = InitList();
	if (odd == NULL || even == NULL)
	{
		return;
	}
	for (int i = 0; i < L->Length; i++)
	{
		if (L->Data[i] % 2 != 0)
		{
			odd->Data[odd->Length++] = L->Data[i];
		}
		else
		{
			even->Data[even->Length++] = L->Data[i];
		}
	}
	printf("顺序表中的元素有：");
	Traverse(L);
	printf("\n");
	printf("顺序表中的奇数有：");
	Traverse(odd);
	printf("\n");
	printf("顺序表中的偶数有：");
	Traverse(even);
}

Plist Cross(Plist L1, Plist L2)
{
	int i = 0, j = 0, n = 0;
	Plist L3 = InitList();
	if (L3 == NULL)
	{
		return NULL;
	}
	if (L1->Length == 0 || L2->Length == 0)
	{
		return NULL;
	}
	else if (L1->Data[L1->Length - 1] <= L2->Data[0] || L2->Data[L1->Length - 1] <= L1->Data[0])
	{
		if (L1->Data[L1->Length - 1] == L2->Data[0])
		{
			L3->Data[L3->Length++] = L2->Data[0];
			return L3;
		}
		else if (L2->Data[L1->Length - 1] == L1->Data[0])
		{
			L3->Data[L3->Length++] = L1->Data[0];
		}
		else
		{
			return NULL;
		}
	}
	else
	{
		while (i < L1->Length || j < L2->Length)
		{
			if (L1->Data[i] > L2->Data[j])
			{
				j++;
			}
			else if (L1->Data[i] < L2->Data[j])
			{
				i++;
			}
			else
			{
				L3->Data[L3->Length++] = L1->Data[i];
				i++;
				j++;
			}
		}
		return L3;
	}
}

int DeleteRepeat(Plist L)
{
	int i = 0, j = 0;
	int length = L->Length;
	while (++j < L->Length)
	{
		if (L->Data[i] != L->Data[j]) //跳过雷同者
		{
			L->Data[++i] = L->Data[j]; //发现不同元素时，向前移至紧邻于前者右侧
		}
	}
	L->Length = ++i;//直接截除尾部多余元素
	return length - L->Length; //被删除元素总数
}

void Traverse(Plist L)
{
	printf("顺序表中的元素有：");
	for (int i = 0; i < L->Length; i++)
	{
		printf("%d  ", L->Data[i]);
		if ((i + 1) % 20 == 0)
		{
			printf("\n");
		}
	}
}