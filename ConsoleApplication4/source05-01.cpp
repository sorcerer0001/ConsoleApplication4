// 在此处补充你的代码
class MyString :public string{
public:
    MyString() :string(){}
    //MyString(char * cs):string(cs){}  
    MyString(const char * cs) :string(cs){}
    MyString & operator +(MyString & op2){
        string s1 = *this;
        string s2 = op2;
        string s = s1 + s2;
        return *new MyString(s.c_str());
    }
    MyString & operator +(const char * cs2){
        string str1 = *this;
        string s = str1 + cs2;
        return *new MyString(s.c_str());
    }
    MyString & operator()(int s, int l){
        string str = substr(s, l);
        return *new MyString(str.c_str());
    }
};

MyString & operator+(const char * cs1, const MyString & myString){
    string str2 = myString;
    string s = cs1 + str2;
    return *new MyString(s.c_str());
}
//代码结束