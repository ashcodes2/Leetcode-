class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (int i = 0; i < s.length(); i++) {
            char currentChar = s[i];

            if (currentChar == '(' || currentChar == '{' || currentChar == '[') {
                st.push(currentChar);
            } 
            else {
                if (st.empty()) {
                    return false;
                }

                char topChar = st.top();

                if (currentChar == ')' && topChar == '(') {
                    st.pop();
                } 
                else if (currentChar == '}' && topChar == '{') {
                    st.pop();
                } 
                else if (currentChar == ']' && topChar == '[') {
                    st.pop();
                } 
                else {
                    return false;
                }
            }
        }

        return st.empty();
    }
};