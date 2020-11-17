#include <iostream>
#include <stack>

unsigned akm(unsigned m, unsigned n) {
    struct Node {
        unsigned vm ,vn;
    };
    std::stack<Node> st;
    Node w; unsigned v;
    w.vm = m; w.vn = n;
    st.push(w);
    do {
        while(st.top().vm > 0) {
            while(st.top().vn > 0) {
                w.vn--; st.push(w);
            }
            w = st.top(); st.pop();
            w.vm--; w.vn = 1; st.push(w);
        }
        w = st.top(); st.pop(); v = w.vn + 1;
        if (!st.empty()){
            w = st.top(); st.pop();
            w.vm--; w.vn = v; st.push(w);
        }
    } while(!st.empty());
    return v;
}

int main() {
    std::cout << akm(2, 3) << "\n";
    return 0;
}
