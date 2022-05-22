#include <iostream>
#include <string>
using namespace std;
#include <stack>

int minBracketReversal(string str) {
    stack<char> st;
    int count = 0;
    if(str.length() %2 != 0)
        return -1;
    for(int i=0; i<str.length(); i++) {
        if(str[i] == '{') 
            st.push('{');
        else if(!st.empty() && str[i] == '}' && st.top() == '{')
            st.pop();
        else if(!st.empty() && str[i] == '}' && st.top() == '}') 
            st.push('}');
        else if(st.empty() && str[i] == '}') 
            st.push('}');
    }
    while(!st.empty()) {
        char c1 = st.top();
        st.pop();
        char c2 = st.top();
        st.pop();
        if(c1 == c2)
            count++;
        else
            count += 2;
    }
    return count;
}

int main() {
    string str;
    getline(cin, str);
    cout << minBracketReversal(str);
}