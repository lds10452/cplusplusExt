#include <iostream>
using namespace std;
void fun();
void test();
void externalTest();
namespace A {
	int a = 1000;
	namespace B {											//�����ռ��Ƕ��
		//cout << a << end;									//�����ڿռ��ڵ���
		int a = 2000;
		void fun()
		{
			cout << "B::fun" << endl;
		}
	}
}
namespace A {
	//int a = 300;											//err�������ض������a
	int c = 3000;											//��ʱ����ӿռ�A��������
}
namespace C {
	void fun();												//����ֻ���������壬�������ⲿ����
}
int main()
{
	//test();
	externalTest();
	system("pause");
	return 0;
}
void fun()
{
	cout << "fun is called:" << endl;
	//namespace A{}											//err,�����ھֲ���Χ���������ռ�
}
void C::fun()
{
	cout << "�����ռ��������������ⲿ����" << endl;
}
int c = 300;
void test()
{
	int a = 100;
	//using A::a;											//err��usingֱ��ʹ�� �����ռ�ĳ�Ա��;ֲ�������ͻ
	using A::c;												//usingֱ��ʹ�� �����ռ��еĳ�Ա ����� ȫ�ֱ�����ͻ
	cout << c << " " << ::c << endl;
	using namespace A;
	cout << a << endl;										//100,���ȷ��ʾֲ�����a
	namespace refA = A;										//�������ռ������
	cout << A::a << " " << A::B::a << " " << refA::c << endl;
	C::fun();
}
#include "external_test.h"									//1
//namespace EX1												//2,���ַ�ʽʹ�������ռ�EX1
//{
//	extern void func(void);
//}
void externalTest()
{
	using namespace EX1;
	func();
	//fund();												//err,���������ռ��еķ��Ŵ����ռ��ڲ�ʹ�ã����ܱ��ⲿ���ã�Ч��������ȫ�ֱ����ͺ�����static

	person p;
	p.print();
}