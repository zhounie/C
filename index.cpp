#include <iostream>
#include <iomanip>   // 控制小数点后位数
#include <cmath>     // fabs函数
using namespace std;

const double EPSILON = 1e-8;   // 定义一个极小值

class DivideByZeroException : public exception {
public:
    virtual const char* what() const noexcept override {
        return "除数不能为0";
    }
};

struct Expression {
    double num1;
    double num2;
    char op;
};

class Calculator {
private:
    double num1;    // 第一个数字
    double num2;    // 第二个数字
    char op;        // 操作符

public:
    // 构造函数
    Calculator(double n1 = 0.0, double n2 = 0.0, char o = '+') : num1(n1), num2(n2), op(o) {}

    // 判断除数是否为0
    bool isDivideByZero() const {
        return (op == '/' && isApproximatelyEqual(num2, 0.0));
    }

    // 计算结果
    double calculate() const {
        switch(op) {
            case '+':
                return num1 + num2;
            case '-':
                return num1 - num2;
            case '*':
                return num1 * num2;
            case '/':
                if(isDivideByZero()) throw DivideByZeroException();
                return num1 / num2;
            default:
                return 0.0;
        }
    }

    // 极小值判断
    bool isApproximatelyEqual(double x, double y) const {
        return fabs(x - y) < EPSILON;
    }

    // 设置数字和操作符
    void setExpression(const Expression& expr) {
        num1 = expr.num1;
        num2 = expr.num2;
        op = expr.op;
    }

    void setNum1(double& n1) {
        num1 = n1;
    }

    void setNum2(double& n2) {
        num2 = n2;
    }

    void setOp(char& o) {
        op = o;
    }

    // 获取数字和操作符
    double getNum1() const {
        return num1;
    }

    double getNum2() const {
        return num2;
    }

    char getOp() const {
        return op;
    }
};

// 输入操作
void input(Calculator& calc) {
    Expression expr;
    cout << "请输入两个数字和操作符，格式为：num1 operator num2" << endl;
    cin >> expr.num1 >> expr.op >> expr.num2;

    calc.setExpression(expr);
}

int main() {
    Calculator calc;
    while (true) {
        try {
            input(calc);

            double result = calc.calculate();

            // 控制小数点后位数
            cout << fixed << setprecision(2) << calc.getNum1() << " " << calc.getOp() << " " 
                 << calc.getNum2() << " = " << result << endl;

            cout << "是否继续计算？(y/n)" << endl;
            char choice;
            cin >> choice;
            if (choice != 'y' && choice != 'Y') break;
        } catch (const DivideByZeroException& e) {
            cerr << "Error: " << e.what() << endl;
        } catch (exception& e) {
            cerr << "Error: " << e.what() << endl;
        }
    }

    return 0;
}