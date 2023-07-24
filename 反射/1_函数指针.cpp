#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int add(int a, int b)
{
    return a + b;
}

int sub(int a, int b)
{
    return a - b;
}

int mul(int a, int b)
{
    return a * b;
}

typedef int func4(int, int);

/* 1、函数指针的定义 */
void deFunctionPtr()
{
    // 1.1 直接定义
    int (*func)(int, int);

    // 1.2 使用typedef
    typedef int (*func2)(int, int);
    func2 f2;

    // 1.3 使用using
    using func3 = int (*)(int, int);
    func3 f3;

    // 1.4 使用decltype
    decltype(add) *f4;
}

/* 2、函数指针数组 */
void deFunctionPtrArray()
{
    // 2.1 直接定义
    int (*func[3])(int, int);
    func[0] = add;
    func[1] = sub;
    func[2] = mul;

    // 2.2 使用typedef
    typedef int (*func2[3])(int, int);
    func2 f2 = {add, sub, mul};
    cout << f2[0](1, 2) << endl;
    cout << f2[1](1, 2) << endl;
    cout << f2[2](1, 2) << endl;

    // 2.3 使用using
    using func3 = int (*)(int, int);
    func3 f3[3];

    // 2.4 使用decltype
    decltype(add) *f4[3];
}

int main()
{
    return 0;
}