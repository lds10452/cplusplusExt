#include <iostream>
using namespace std;
void fun();
void test();
void externalTest();
namespace A {
	int a = 1000;
	namespace B {											//命名空间可嵌套
		//cout << a << end;									//不能在空间内调用
		int a = 2000;
		void fun()
		{
			cout << "B::fun" << endl;
		}
	}
}
namespace A {
	//int a = 300;											//err，不能重定义变量a
	int c = 3000;											//随时可添加空间A的新内容
}
namespace C {
	void fun();												//不能只声明不定义，可以在外部定义
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
	//namespace A{}											//err,不能在局部范围定义命名空间
}
void C::fun()
{
	cout << "命名空间内声明函数，外部定义" << endl;
}
int c = 300;
void test()
{
	int a = 100;
	//using A::a;											//err，using直接使用 命名空间的成员会和局部变量冲突
	using A::c;												//using直接使用 命名空间中的成员 不会和 全局变量冲突
	cout << c << " " << ::c << endl;
	using namespace A;
	cout << a << endl;										//100,优先访问局部变量a
	namespace refA = A;										//给命名空间起别名
	cout << A::a << " " << A::B::a << " " << refA::c << endl;
	C::fun();
}
#include "external_test.h"									//1
//namespace EX1												//2,两种方式使用命名空间EX1
//{
//	extern void func(void);
//}
void externalTest()
{
	using namespace EX1;
	func();
	//fund();												//err,匿名命名空间中的符号纯本空间内部使用，不能被外部引用，效果类似于全局变量和函数加static

	person p;
	p.print();
}