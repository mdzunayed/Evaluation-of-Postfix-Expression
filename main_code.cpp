
#include <iostream>
#include <string.h>
using namespace std;

char stack[1000];
char PostfixExpression[1000];
double evaluation[1000];

int top = -1;
int topPostfix = -1;
int topEva = -1;

void printEva()
{
    for (int i = 0; i < topEva + 1; i++)
    {
        cout << evaluation[i] << " ";
    }
    cout << endl;
}

void Push(char x)
{
    if (top >= 999)
    {
        cout << "Your stack is full.\n";
    }
    else
    {
        top++;
        stack[top] = x;
    }
}
void PushEva(double x)
{
    if (topEva >= 999)
    {
        cout << "Your stack is full.\n";
    }
    else
    {
        topEva++;
        evaluation[topEva] = x;
        cout << "stack: ";
        printEva();
    }
}

char Pop()
{
    if (top == -1)
    {
        return '#';
    }
    else
    {
        char a = stack[top];
        top--;
        return a;
    }
}
double popEva()
{
    if (topEva == -1)
    {
        return -1;
    }
    else
    {
        double a = evaluation[topEva];
        topEva--;
        return a;
    }
}

void display_Postfix()
{
    for (int i = 0; i < topPostfix + 1; i++)
    {
        cout << PostfixExpression[i] << " ";
    }
    cout << endl;
}

void pushPostfix(char x)
{
    if (topPostfix >= 999)
    {
    }
    else
    {
        topPostfix++;
        PostfixExpression[topPostfix] = x;
    }
}

char Peek()
{
    if (top == -1)
    {
        return '#';
    }
    else
    {
        return stack[top];
    }
}

void postfix(string s)
{
    int n = s.size();
    if (n == top)
    {
         cout<<"Your stack is full.\n";
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            char a = s[i];
            if (isdigit(a))
            {
                pushPostfix(a);
            }
            else if (a == '(')
            {
                Push(a);
            }
            else if (a == ')')
            {
                bool run = true;
                char a = Pop();
                while (a != '(')
                {
                    pushPostfix(a);
                    a = Pop();
                }
            }
            else
            {
                if (a == '+' || a == '-')
                {
                    bool run = true;
                    while (run)
                    {
                        char b = Peek();
                        if (b == '+' || b == '-' || b == '*' || b == '/')
                        {
                            pushPostfix(Pop());
                        }
                        else
                        {
                            Push(a);
                            run = false;
                        }
                    }
                }
                else if (a == '*' || a == '/')
                {
                    bool run = true;
                    while (run)
                    {
                        char b = Peek();
                        if (b == '*' || b == '/')
                        {
                            pushPostfix(Pop());
                        }
                        else
                        {
                            run = false;
                        }
                    }
                    Push(a);
                }
            }
        }
        if (char a = Peek() != '#')
        {
            while (top != -1)
            {
                pushPostfix(Pop());
            }
        }
    }
}

double eva()
{
    if (topPostfix != -1)
    {

        for (int i = 0; i < topPostfix + 1; i++)
        {
            char b = PostfixExpression[i];
            if (isdigit(b))
            {
                cout << b << " push in stack.\n";
            }

            switch (b)
            {
            case '+':
            {
                double a = popEva();
                double d = popEva();
                double c = d + a;
                cout << "Calculate last two values of the stack (" << a<<" "<< b <<" "<< d <<").\n";
                PushEva(c);
                break;
            }
            case '-':
            {
                double a = popEva();
                double d = popEva();
                cout << "Calculate last two values of the stack (" << a<<" "<< b <<" "<< d <<").\n";
                double c = d - a;
                PushEva(c);

                break;
            }
            case '*':
            {
                double a = popEva();
                double d = popEva();
                cout << "Calculate last two values of the stack (" << a<<" "<< b <<" "<< d <<").\n";
                double c = d * a;
                PushEva(c);
                break;
            }
            case '/':
            {
                double a = popEva();
                double d = popEva();
                cout << "Calculate last two values of the stack (" << a<<" "<< b <<" "<< d <<").\n";
                double c = d / a;
                PushEva(c);
                break;
            }
            default:
                PushEva(double(int(b) - 48));
                break;
            }
            cout << '\n';
        }
        return evaluation[0];
    }
    return -1;
}

int main()
{
    cout << "\n\n\t\t\t\t\tWelcome to our calculator...\n";
    string s;
    cout << "\t\t\t\t\tEnter the infix (without space): ";
    cin >> s;
    postfix(s);
    cout << "PostFix: ";
    display_Postfix();
    cout << endl;
    cout << "Evaluation: " << eva() << endl;
}
