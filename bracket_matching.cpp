#include<iostream>
#include<stack>
#include<string>

// Function prototypes.
bool is_open(char symbol);
bool is_close(char symbol);
bool matches(char symbol, char open_symbol);

int main()
{
    // Test strings.
    std::string expressions[] = {"({})", "(()){}()", "()", "{}", "({}(", "){})", "(()"};
    std::string expression;
    std::stack<char> s;
    // Number of test strings.
    int num_expressions = 7;
    int i, turn, limit;
    bool balanced;
    char open_symbol, c;

    for(turn = 0; turn < num_expressions; ++turn)
    {
        expression = expressions[turn];
        balanced = true;
        limit = expression.size();

        for(i = 0; i < limit; ++i)
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
            std::cout << expression << " is balanced\n";
        }

        else
        {
            std::cout << expression << " is not balanced\n";
        }

        // Reset stack for next iteration.
        s = std::stack<char>();
    }

    return 0;
}

// Checks if char is opening bracket.
bool is_open(char symbol)
{
    if(symbol == '(' || symbol == '[' || symbol == '{')
    {
        return true;
    }

    return false;
}

// Checks if char is closing bracket.
bool is_close(char symbol)
{
    if(symbol == ')' || symbol == ']' || symbol == '}')
    {
        return true;
    }

    return false;
}

// Checks if brackets match.
bool matches(char symbol, char open_symbol)
{
    return ((open_symbol == '(' && symbol == ')') || (open_symbol == '{' && symbol == '}') 
        || (open_symbol == '[' && symbol == ']'));
}