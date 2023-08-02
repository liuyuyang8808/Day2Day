#include <iostream>
#include <map>
#include <string>
using namespace std;

typedef void *(*funcPtr)(void);

// 反射类-单例模式
class Base
{
public:
    static Base *getInstance();
    void registerClass(string className, funcPtr func);
    void *getClass(string className);

private:
    Base(){};
    map<string, funcPtr> m_imp;
};

Base *Base::getInstance()
{
    static Base instance;
    return &instance;
}

// 注册类
void Base::registerClass(string name, funcPtr func)
{
    m_imp.insert(std::make_pair(name, func));
}

// 根据类名获取类
void *Base::getClass(string className)
{
    auto iter = m_imp.find(className);
    if (iter != m_imp.end())
    {
        return iter->second();
    }
    else
    {
        return nullptr;
    }
}

// 学生类
class Student
{
public:
    string getName() { return m_name; }
    void setName(string name) { m_name = name; }

private:
    string m_name;
};

// 工厂函数
void *StudentFactory(void)
{
    return new Student;
}

int main()
{
    Base::getInstance()->registerClass("Student", &StudentFactory);
    Student *stu = (Student *)Base::getInstance()->getClass("Student");

    stu->setName("liu yu yang ");

    cout << stu->getName() << endl;
}
