#include <iostream>
#include <stack>

using namespace std;
int evaluatePrefix(string);
bool isOperator(char);
bool isNumber(char);
int performOperation(int,int,char);

int main()
{
	string exp;
	cout<<"Enter an expression: "<<endl;
	//cin>>exp;
	getline(cin,exp);
	int result = evaluatePrefix(exp);
	cout<<"Result = "<<result<<endl;
}

int evaluatePrefix(string exp)
{
	stack <int> S;
	char o1, o2;
	int op1, op2, result;
	int exp_length = exp.length();
	cout<<"str len = "<<exp_length<<endl;
	for(int i = 0; i < exp_length; i++)
	{
		if((exp[i] == ' ') || (exp[i] == ','))
			continue;
		else if(isNumber(exp[i]))
			{
				int operand = 0; 
				operand = exp[i] - '0';
				S.push(operand);
				//cout<<"top = "<<S.top()<<endl;
			}
		else if(isOperator(exp[i]))
			{
				o1 = S.top();
				op1 = (int)o1;
				//cout<<"op1 = "<<op1<<endl;
				S.pop();
				op2 = S.top();
				S.pop();
				result = performOperation((int)op1, (int)op2, exp[i]);
				S.push(result);
			}		
	}
	return S.top();
}

int performOperation(int op1, int op2, char op)
{
	if(op == '+')
	{
		//cout<<"returning "<<op1<<" "<<op2<<" "<<op1+op2<<endl;
		return (int)op1 + (int)op2;
	}
	else if(op == '-')
	{
		//cout<<"returning "<<op1<<" "<<op2<<" "<<op1-op2<<endl;
		return (int)op2 - (int)op1;
	}
	else if(op == '*')
	{
		//cout<<"returning "<<op1<<" "<<op2<<" "<<op1*op2<<endl;
		return (int)op1 * (int)op2;
	}
	else if(op == '/')
	{
		//cout<<"returning "<<op1<" "<<op2<<" "<<op1/op2<<endl;
		return op1 / op2;
	}
	else
		cout<<"Unexpected operator"<<endl;
	return -1;
}

bool isOperator(char oper)
{
	if((oper == '+') || (oper == '-') || (oper == '*') || (oper == '/'))
	{
		//cout<<"op found"<<oper<<endl;
		return true;
	}
	else
		return false;
}

bool isNumber(char num)
{
	if(num >='0' && num <= '9')
	{
	//	cout<<"num found"<<num<<endl;
		return true;
	}
	else
		return false;
}

