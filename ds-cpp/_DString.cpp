const int defaultLength = 1024;

class DString {
    private:
        // size of string
        int size;
        // the array to store the chars for string
        char *chars;
    public:
        DString();
        ~DString();
        DString(const DString &srcStr);
        int getLen() const {
            return size;
        }
        bool isEmpty() {
            return size == 0 ? true : false;
        }
        // remove all elements in string
        void empty() {
            size = 0; 
            chars[0] = '0';
        }
        DString getSub(int nPos, int nCount) const;
        char operator [] (int nPos) const;
        DString& operator = (const DString &str);
        DString& operator += (const DString &str);
        bool operator == (const DString &str) const;
        int find(DString &substr) const;
};
