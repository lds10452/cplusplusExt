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
	for (int i = 1; i < len; i++)//��Ҫ�Ƚϵ�Ԫ�ظ���
	{
		for (int j = i; j > 0; j--)//ÿ��Ԫ����ǰ�ȽϵĴ���
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
	srand((unsigned)time(NULL));//��ֹ������е��¿�������Ч�ʽ��� ������ȥ��
	int len = right - left;
	int randIndex = rand() % (len + 1) + left;
	swap(&p[left], &p[randIndex]);

	int i = left, j = right, key = p[left];
	while (i < j)
	{
		while (p[j] >= key && i < j) j--;//ֱ���ҵ���key��С��Ԫ��
		if (i < j) p[i] = p[j];//���ҵ���Ԫ�طŵ�i��λ��
		while (p[i] < key && i < j) i++;//ֱ���ҵ���key�����Ԫ��
		if (i < j) p[j] = p[i];//���ҵ���Ԫ�طŵ�j��λ��
	}
	p[i] = key;
	quickSort(p, left, i - 1);//���¶�key��ߵ�Ԫ������
	quickSort(p, j + 1, right);//�ұ�
}
void bubbleSort(int* p, int len)
{
	for (int i = 0; i < len - 1; i++)//��Ҫ�Ƚϵ�Ԫ�ظ���
	{
		bool flag = false;
		for (int j = 0; j < len - 1; j++)//ÿ��Ԫ����Ҫ���ȽϵĴ���
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
	for (int i = 0; i < len - 1; i++)//��Ҫ�Ƚϵ�Ԫ�ظ���
	{
		int minIndex = i;
		for (int j = i + 1; j < len; j++)//ÿ��Ԫ�����ȽϵĴ���
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
	for (int div = len / 2; div >= 1; div /= 2)//��div��
	{
		for (int i = 0; i < div; i++)//�Ƚϵ�����
		{
			for (int j = i + div; j < len; j += div)//ÿ��Ƚ�Ԫ�ظ���
			{
				for (int k = j; k >= i; k -= div)//ÿ��Ԫ����ǰ�Ƚϴ���
				{
					if (p[k] < p[k - div])
					{
						swap(p[k], p[k - div]);
					}
					else break;//���Ѿ��ź���
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