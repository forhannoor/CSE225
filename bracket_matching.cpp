#include <iostream>
#include <stack>

using namespace std;

bool is_open(char symbol);
bool is_closed(char symbol);
bool matches(char symbol, char open_symbol);

int main()
{

    string expressions[] = {"({})", "(()){}()", "()", "{}", "({}(", "){})", "(()"};

    for(int turn = 0; turn < 7; turn++)
    {
        stack <char> s;
        bool balanced = true;
        char open_symbol;
        string expression = expressions[turn];

        for(int i = 0; i < expression.size(); i++)
        {
            if(is_open(expression[i]))
                s.push(expression[i]);

            else if(is_closed(expression[i]))
            {
                if(s.empty())
                {
                    balanced = false;
                    break;
                }

                else
                {
                    open_symbol = s.top();
                    balanced = matches(expression[i], open_symbol);

                    if(balanced)
                        s.pop();

                    else
                        balanced = false;
                }
            }
        }

        if(balanced && s.empty())
            cout<<expression<<" is balanced"<<endl;

        else
            cout<<expression<<" is not balanced"<<endl;
    }

    return 0;
}

bool is_open(char symbol)
{
    if(symbol == '(' || symbol == '[' || symbol == '{')
        return true;

    return false;
}

bool is_closed(char symbol)
{
    if(symbol == ')' || symbol == ']' || symbol == '}')
        return true;

    return false;
}

bool matches(char symbol, char open_symbol)
{
    return ((open_symbol == '(' && symbol == ')') || (open_symbol == '{' && symbol == '}') || (open_symbol == '[' && symbol == ']'));
}