#include<iostream>
#include<stack>
#include<string>

bool is_open(char symbol); // if char is opening bracket
bool is_close(char symbol); // if char is closing bracket
bool matches(char symbol, char open_symbol); // if brackets are of same type, i.e. curly or square

int main()
{
    std::string expressions[] = {"({})", "(()){}()", "()", "{}", "({}(", "){})", "(()"}; // test strings
    std::string expression; // candidate string
    std::stack<char> s;
    int num_expressions = 7; // # of test strings
    int i, turn, limit; // loop parameters
    bool balanced;
    char open_symbol, c;

    for(turn = 0; turn < num_expressions; turn++)
    {
        expression = expressions[turn];
        balanced = true;
        limit = expression.size();

        for(i = 0; i < limit; i++)
        {
            c = expression[i];

            if(is_open(c))
            {
                s.push(c);
            }

            else if(is_close(c))
            {
                if(s.empty())
                {
                    balanced = false;
                    break;
                }

                else
                {
                    open_symbol = s.top();
                    balanced = matches(c, open_symbol);

                    if(balanced)
                    {
                        s.pop();
                    }

                    else
                    {
                        balanced = false;
                    }
                }
            }
        }

        if(balanced && s.empty())
        {
            std::cout<<expression<<" is balanced\n";
        }

        else
        {
            std::cout<<expression<<" is not balanced\n";
        }

        s = std::stack<char>(); // reset stack for next iteration
    }

    return 0;
}

bool is_open(char symbol)
{
    if(symbol == '(' || symbol == '[' || symbol == '{')
    {
        return true;
    }

    return false;
}

bool is_close(char symbol)
{
    if(symbol == ')' || symbol == ']' || symbol == '}')
    {
        return true;
    }

    return false;
}

bool matches(char symbol, char open_symbol)
{
    return ((open_symbol == '(' && symbol == ')') || (open_symbol == '{' && symbol == '}') || (open_symbol == '[' && symbol == ']'));
}