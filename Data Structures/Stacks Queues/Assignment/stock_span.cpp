#include <iostream>
using namespace std;
#include <stack>

int* stockSpan(int* price, int N) {
    stack<int> st;
    int* span = new int[N];
    st.push(0);
    span[0] = 1;
    for(int i=1; i<N; i++) {
        while(!st.empty() && price[i] > price[st.top()]) {
            st.pop();
        }
        span[i] = st.empty() ? i+1 : (i-st.top());
        st.push(i);
    }
    return span;
}

int main() {
    int N;
    cin >> N;
    int* price = new int[N];
    int* span = new int[N];
    for(int i=0; i<N; i++) 
        cin >> price[i];
    span = stockSpan(price, N);
    for(int i=0; i<N; i++) 
        cout << span[i] << " ";
}