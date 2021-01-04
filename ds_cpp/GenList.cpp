#include <iostream>
#include <stack>

class GenList;
class GenListNode;

class GenListNode {
    friend class GenList;
    private:
        int mark;
        // utype = 0/1/2
        int utype;
        GenListNode *tlink;
        union {
            // utype = 0
            char listname; 
            // utype = 1
            char atom;
            GenListNode *hlink;
        } value;
    public:
        GenListNode(int tp, char info): mark(0), utype(tp), tlink(nullptr) {
            if (utype == 0)
                value.listname = info;
            else 
                value.atom = info;
        }
        char info(GenListNode *elem) {
            return (utype == 0) ? elem->value.listname : elem->value.atom;
        }
};

class GenList {
    private:
        GenListNode *first;
        void traverseFrom(GenListNode *ls);
        void remove(GenListNode *ls);
    public:
        GenList(char &value);
        ~GenList();
        void traverse();
};

void GenList::traverse() {
    traverseFrom(first);
}

// recursive
//void GenList::traverseFrom(GenListNode *ls) {
    //if (ls != nullptr) {
        //ls->mark = 1;
        //if (ls->utype == 0) // head
            //std::cout << ls->value.listname << '(';
        //else if (ls->utype == 1) { // atom
            //std::cout << ls->value.atom;
            //if (ls->tlink != nullptr) 
                //std::cout << ',';
        //} else if (ls->utype == 2) { // subGenList
            //if (ls->value.hlink->mark == 0) {
                //traverseFrom(ls->value.hlink);
            //}
            //else {
                //std::cout << ls->value.hlink->value.listname;
            //}
            //if (ls->tlink != nullptr) 
                //std::cout << ',';
        //}
        //traverseFrom(ls->tlink);
    //} else {
        //std::cout << ')';
    //}
//}

// non-recursive
void GenList::traverseFrom(GenListNode *ls) {
    std::stack<GenListNode *> st;
    while (ls != nullptr) {
        ls->mark = 1;
        if (ls->utype == 2) {
            if (ls->value.hlink->mark == 0) {
                st.push(ls->tlink);
                ls = ls->value.hlink;
            } else {
                std::cout << ls->value.hlink->value.listname;
                if (ls->tlink != nullptr) {
                    std::cout << ','; 
                    ls = ls->tlink;
                }
            }
        } else {
            if (ls->utype == 0) {
                std::cout << ls->value.listname << '(';
            } else if (ls->utype == 1) {
                std::cout << ls->value.atom;
                if (ls->tlink != nullptr)
                    std::cout << ',';
            }
        }
    }
}
