#include<stack>
#include<string>
#include<cstdio>

// Determines if char is an opening bracket symbol.
bool is_open(char symbol);
// Determines if char is a closing bracket symbol.
bool is_close(char symbol);
// Determines if char symbols matches.
bool matches(char symbol, char open_symbol);

int main()
{
    // Sample strings to run the program on.
    std::string sample_inputs[] = {"({})", "(()){}()", "()", "{}", "({}(", "){})", "(()"};
    std::string current_input;
    std::stack<char> temp;
    // Number of input strings.
    int num_expressions = 7;
    int i, turn, limit;
    bool is_balanced;
    char open_symbol, c;

    for(turn = 0; turn < num_expressions; ++turn)
    {
        current_input = sample_inputs[turn];
        is_balanced = true;
        // Length of input string.
        limit = current_input.size();

        for(i = 0; i < limit; ++i)
        {
            c = current_input[i];
            // If char is opening bracket symbol.
            if(is_open(c))
            {
                temp.push(c);
            }
            // If char is closing bracket symbol.
            else if(is_close(c))
            {
                // If stack is empty, meaning it doesn't contain the opening bracket symbol.
                if(temp.empty())
                {
                    is_balanced = false;
                    break;
                }
                else
                {
                    // Access the top element of stack, which is also the last item inserted.
                    open_symbol = temp.top();
                    is_balanced = matches(c, open_symbol);

                    if(is_balanced)
                    {
                        // Remove last item from stack.
                        temp.pop();
                    }
                    else
                    {
                        is_balanced = false;
                    }
                }
            }
        }

        if(is_balanced && temp.empty())
        {
            printf("%s is balanced\n", current_input.c_str());
        }
        else
        {
            printf("%s is not balanced\n", current_input.c_str());
        }

        // Reset stack for next iteration.
        temp = std::stack<char>();
    }

    return 0;
}

// Determines if char is an opening bracket symbol.
bool is_open(char symbol)
{
    return (symbol == '(' || symbol == '[' || symbol == '{');
}

// Determines if char is a closing bracket symbol.
bool is_close(char symbol)
{
    return (symbol == ')' || symbol == ']' || symbol == '}');
}

// Determines if char symbols matches.
// Both should belong to the same type of bracket.
// Symbol should be closing bracket while open_symbol is opening bracket.
bool matches(char symbol, char open_symbol)
{
    return ((open_symbol == '(' && symbol == ')') || (open_symbol == '{' && symbol == '}')
        || (open_symbol == '[' && symbol == ']'));
}