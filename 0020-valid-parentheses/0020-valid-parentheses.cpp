class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char ch : s) {
            // Opening brackets
            if (ch == '(' || ch == '[' || ch == '{') {
                st.push(ch);
            }
            // Closing bracket
            else {
                // No opening bracket available
                if (st.empty())
                    return false;
                char top = st.top();
                if ((ch == ')' && top != '(') ||
                    (ch == ']' && top != '[') ||
                    (ch == '}' && top != '{')) {
                    return false;
                }
                st.pop();
            }
        }
        // If stack is empty, every bracket was matched
        return st.empty();
    }
};