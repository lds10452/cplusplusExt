#include "external_test.h"
#include <iostream>
using namespace std;
namespace EX1
{
    void func(void)
    {
        cout << "Func in EX1" << endl;
        fund();
    }
    void person::print()
    {
        cout << "person类函数被调用" << endl;
    }
}
namespace {
    void fund()
    {
        cout << "调用匿名命名空间函数" << endl;
    }
}