#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

// Function to evaluate postfix expression
int evaluatePostfix(string exp) {
    stack<int> st;

    for (int i = 0; i < exp.length(); i++) {
        
        // If operand (digit)
        if (isdigit(exp[i])) {
            st.push(exp[i] - '0'); // convert char to int
        }
        else {
            // Operator
            int val2 = st.top(); st.pop();
            int val1 = st.top(); st.pop();

            switch (exp[i]) {
                case '+': st.push(val1 + val2); break;
                case '-': st.push(val1 - val2); break;
                case '*': st.push(val1 * val2); break;
                case '/': st.push(val1 / val2); break;
                case '^': st.push(pow(val1, val2)); break;
            }
        }
    }

    return st.top();
}

int main() {
    string postfix;

    cout << "Input postfix: ";
    cin >> postfix;

    int result = evaluatePostfix(postfix);

    cout << "Output: " << result << endl;

    return 0;
}