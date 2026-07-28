#include <iostream>
#include <stack>
using namespace std;
int prec(char c) {
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}
// Function to check if operator is right-associative
bool isRightAssociative(char c) {
    return c == '^';
}
string infixToPostfix(string &s) {
    stack<char> st;
    string res; // output expression
    for (int i = 0; i < s.length(); i++) {
        char c = s[i]; // dealing with each char separately

        // If operand, add to result
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            res += c; // postfix expression

        // If '(', push to stack
        else if (c == '(')
            st.push('(');

        // If ')', pop until '('
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') { //while stack is not empty and top isn't (
                res += st.top(); // 
                st.pop();
            }
            st.pop(); // pop once more, (the parenthesis "(") 
        }

        // If operator
        else {
            while (!st.empty() && st.top() != '(' && (prec(st.top()) > prec(c) || 
			(prec(st.top()) == prec(c) && !isRightAssociative(c)))){
                res += st.top(); 
                st.pop();
            }
            st.push(c); // onto stack if of lower precedence
        }
    }
    // Pop remaining operators
    while (!st.empty()) {
        res += st.top();
        st.pop();
    }

    return res;
}
int main() {
    string exp = "a*(b+c)/d";
    cout << infixToPostfix(exp);
    return 0;
}