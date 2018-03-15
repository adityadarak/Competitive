#include <iostream>
#include <stack>
#include <string>

struct Bracket {
    Bracket(char type, int position):
        type(type),
        position(position)
    {}

    bool Matchc(char c) {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};

int main() {
    std::string text;
    getline(std::cin, text);
    int flag=0;
    std::stack <Bracket> opening_brackets_stack;
    for (int position = 0; position < text.length(); ++position) {
        char next = text[position];
        if (next == '(' || next == '[' || next == '{' && flag==0) {
            // Process opening bracket, write your code here
            opening_brackets_stack.push(Bracket(next,position+1));
        }

        if (next == ')' || next == ']' || next == '}' && flag==0) {
            // Process closing bracket, write your code here
            if(!opening_brackets_stack.empty()){
                Bracket b=opening_brackets_stack.top();
                if(!b.Matchc(next)){
                    std::cout<<position+1;
                    flag=1;
                    break;
                }
                else{
                    opening_brackets_stack.pop();
                }
            }
            else{
                std::cout<<position+1;
                flag=1;
                break;
            }
        }
    }

    // Printing answer, write your code here
    if(opening_brackets_stack.empty() && flag==0){
        std::cout<<"Success";
    }
    else if(flag==0){
        Bracket b=opening_brackets_stack.top();
        std::cout<<b.position;
    }
    return 0;
}
