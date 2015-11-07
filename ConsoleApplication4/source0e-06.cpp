class MyString : public string {
public:
    MyString() : string() {};
    MyString(const char *rhs) : string(rhs) { };
    MyString(const string &rhs) : string(rhs) {};

    MyString operator()(int start, int length) {
        string s = substr(start, length);
        MyString tmp(s);
        return tmp;
    }
};