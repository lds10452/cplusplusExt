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
        cout << "person�ຯ��������" << endl;
    }
}
namespace {
    void fund()
    {
        cout << "�������������ռ亯��" << endl;
    }
}