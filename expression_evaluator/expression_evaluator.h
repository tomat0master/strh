/**
 * @file expression_evaluator.h
 * @author tomotomaster
 * @brief 四则运算器
 * @version 0.1
 * @date 2.24.11.14
 */

#include<iostream>
#include<stack>
#include<string>
using namespace std;

template<typename T>
class MyStack : public stack<T> {
	public:
    // 重载pop()函数，返回被删除元素的值
    T pop() {
        if (this->empty()) {
            cerr << "ILLEGAL " ;
			return T();
        }
        T top = this->top(); 
        this->stack<T>::pop(); 
        return top; 
    }
};


/**
 * @brief 判断字符是否为运算符 
 */
bool isOperator(char c) {
	return c == '+' || c == '-' || c == '*' || c == '/';
}

/**
 * @brief 刻画运算符的优先级 
 */
int precedence(char op) {
	if (op == '+' || op == '-') return 1;
	if (op == '*' || op == '/') return 2;
	return 0;
}

/**
 * @brief 运算输出
*/
double applyOp(double a,double b,char op) {
	switch (op){
		case '+': return (a + b);
		case '-': return (a - b);
		case '*': return (a * b);
		case '/': if(b == 0){cerr << "Warning: Divisor cannot be 0! ";return 0;}
				  return (a / b); 
	}
	return 0;
}


/**
 * @brief 判断表达式是否合法并计算表达式的值
*/
double evaluate(const string& expr) {
    MyStack<float> values;
    MyStack<char> ops;
	int flag = 3;             //记录上一个字符的类型。数字1，运算符2，左括号3，右括号4, 负号5
	double mark = 1;          //判断正负
    for (unsigned int i = 0; i < expr.length(); i++) {
        string num;
		if (i == 0)           //这里对i进行分类是为了不访问expr[-1]，防止段错误
		while (i < expr.length() && isdigit(expr[i])) {
            num += expr[i++];
        }
		if (i != 0)
		//‘.’，‘e’，‘e’后的‘-’都被判定为数字的一部分
        while (i < expr.length() && (isdigit(expr[i]) || expr[i] == '.' || expr[i] == 'e' || (expr[i] == '-' && expr[i-1] == 'e' ))) {
            num += expr[i++];
        }
        if (!num.empty()) {
			//判断是否为负数
			if (flag == 5) {values.push(stof(num)*(-1));}
			if (flag != 5) {values.push(stof(num));}
			flag = 1;         //记录数字类型
            if (i < expr.length()) i--; 
			continue;
        }
        if (expr[i] == '(') {
			if (flag == 5) {mark = -1;}     //这里要处理"-(expression)"型，用mark记录正负
            ops.push(expr[i]);
			flag = 3;                       //记录左括号类型
        } else if (expr[i] == ')') {
			if (2 == flag || flag == 3) {cerr << "ILLEGAL " ; return 0;}
            while (!ops.empty() && ops.top() != '(') {
                values.push((applyOp(values.pop(), values.pop(), ops.pop()))*mark);
				mark = 1;
            }
            ops.pop();
			flag = 4;                       //记录右括号类型
        } else if (isOperator(expr[i])) {   //判断负号，运算符号 
			if(expr[i] != '-') {
				if(flag == 2 || flag == 3 ||flag == 5) {cerr << "ILLEGAL " ; return 0;}     //非‘-’情况是简单的
			} else if (expr[i] == '-'){
				if(flag == 5) {cerr << "ILLEGAL " ; return 0;}               //负号不能连用，但可以‘1--5’，此时前者表示减号，后者表示加号
				if(flag == 2 || flag == 3) {flag = 5; continue;}             //前为左括号或运算符为负号
			}
            while (!ops.empty() && precedence(ops.top()) >= precedence(expr[i])) {
                values.push(applyOp(values.pop(), values.pop(), ops.pop()));
            }
            ops.push(expr[i]);
			flag = 2;
        }
    }
	if(2 == flag || flag == 3 || flag == 5) {cerr << "ILLEGAL " ; return 0;}
    while (!ops.empty()) {
        values.push(applyOp(values.pop(), values.pop(), ops.pop()));
    }
    return values.top();
}


