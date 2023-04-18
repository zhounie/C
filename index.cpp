#include <iostream>
#include <windows.h>
#include <cmath>

using namespace std;

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    while (true)
    {
        double num1, num2;
        char op;

        cout << "请输入第一个数字：";
        while (!(cin >> num1))
        {
            cout << "无效的输入，请重新输入第一个数字：";
            cin.clear();
            cin.ignore(10000, '\n');
        }

        cout << "请输入运算符（+、-、*、/、%）：";
        while (!(cin >> op) || (op != '+' && op != '-' && op != '*' && op != '/' && op != '%'))
        {
            cout << "无效的输入，请重新输入运算符：";
            cin.clear();
            cin.ignore(10000, '\n');
        }

        cout << "请输入第二个数字：";
        while (!(cin >> num2))
        {
            cout << "无效的输入，请重新输入第二个数字：";
            cin.clear();
            cin.ignore(10000, '\n');
        }

        switch(op)
        {
            case '+':
                cout << num1 + num2;
                break;
            case '-':
                cout << num1 - num2;
                break;
            case '*':
                cout << num1 * num2;
                break;
            case '/':
                if (num2 == 0)
                {
                    cout << "除数不能为0";
                }
                else
                {
                    cout << num1 / num2;
                }
                break;
            case '%':
                if (num2 == 0)
                {
                    cout << "除数不能为0";
                }
                else
                {
                    cout << fmod(num1, num2);
                }
                break;
            default:
                cout << "无效的运算符";
        }

        cout << "\n";
    }
    return 0;
}