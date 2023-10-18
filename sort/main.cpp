#include <iostream>

using namespace std;
void printArray(int* p, int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << p[i] << " ";
	}
	cout << endl;
}
void swap(int* p, int* q)
{
	int temp = *p;
	*p = *q;
	*q = temp;
}

void insertSort(int* p, int len)
{
	if (p == NULL || len < 2)
	{
		return;
	}
	for (int i = 1; i < len; i++)//需要比较的元素个数
	{
		for (int j = i; j > 0; j--)//每个元素向前比较的次数
		{
			if (p[j - 1] > p[j])
			{
				swap(&p[j - 1], &p[j]);
			}
			else
				break;
		}
	}
	return;
}
void quickSort(int* p, int left, int right)
{
	if (p == NULL || left >= right)
	{
		return;
	}
	srand((unsigned)time(NULL));//防止有序队列导致快速排序效率降低 ，可以去掉
	int len = right - left;
	int randIndex = rand() % (len + 1) + left;
	swap(&p[left], &p[randIndex]);

	int i = left, j = right, key = p[left];
	while (i < j)
	{
		while (p[j] >= key && i < j) j--;//直到找到比key更小的元素
		if (i < j) p[i] = p[j];//将找到的元素放到i的位置
		while (p[i] < key && i < j) i++;//直到找到比key更大的元素
		if (i < j) p[j] = p[i];//将找到的元素放到j的位置
	}
	p[i] = key;
	quickSort(p, left, i - 1);//重新对key左边的元素排序
	quickSort(p, j + 1, right);//右边
}
void bubbleSort(int* p, int len)
{
	for (int i = 0; i < len - 1; i++)//需要比较的元素个数
	{
		bool flag = false;
		for (int j = 0; j < len - 1; j++)//每个元素需要向后比较的次数
		{
			if (p[j] > p[j + 1])
			{
				swap(&p[j], &p[j + 1]);
				flag = true;
			}
		}
		if (!flag)
		{
			break;
		}
	}
	return;
}
void selectSort(int* p, int len)
{
	if (p == NULL || len < 2)
	{
		return;
	}
	for (int i = 0; i < len - 1; i++)//需要比较的元素个数
	{
		int minIndex = i;
		for (int j = i + 1; j < len; j++)//每个元素向后比较的次数
		{
			if (p[j] < p[minIndex])
			{
				minIndex = j;
			}
		}
		swap(&p[i], &p[minIndex]);
	}
	return;
}
void shellSort(int* p, int len)
{
	for (int div = len / 2; div >= 1; div /= 2)//分div组
	{
		for (int i = 0; i < div; i++)//比较的组数
		{
			for (int j = i + div; j < len; j += div)//每组比较元素个数
			{
				for (int k = j; k >= i; k -= div)//每个元素向前比较次数
				{
					if (p[k] < p[k - div])
					{
						swap(p[k], p[k - div]);
					}
					else break;//都已经排好序
				}
			}
		}
	}
}
int main()
{
	int array[] = { 3,1,5,6,7,2,5,1,9,3,8 };
	printArray(array, sizeof(array) / sizeof(array[0]));
	//insertSort(array,sizeof(array)/sizeof(array[0]));
	//quickSort(array,0,sizeof(array)/sizeof(array[0])-1);
	//bubbleSort(array,sizeof(array)/sizeof(array[0]));
	//selectSort(array,sizeof(array)/sizeof(array[0]));
	shellSort(array, sizeof(array) / sizeof(array[0]));
	printArray(array, sizeof(array) / sizeof(array[0]));
	system("pause");
	return 0;
}