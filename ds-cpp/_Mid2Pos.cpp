#include <iostream>
#include <stack>

class Mid2Pos {
    public:
        int icp(char c) {
            switch(c) {
                case '^': return 4;
                case '*':
                case '/': return 2;
                case '+': 
                case '-': return 1;
            }
        }
        int isp(char c) {
            switch(c) {
                case '^': return 3;
                case '*':
                case '/': return 2;
                case '+':
                case '-': return 1;
                case '(': return 0;
                case '$': return -1;
            }
        }
        int midToPos(char mid[], char pos[]) {
            std::stack<char> s(100); char c; int i, j;
            j = 0; i = 0;
            c = mid[0];
            s.push('$');
        }
};
