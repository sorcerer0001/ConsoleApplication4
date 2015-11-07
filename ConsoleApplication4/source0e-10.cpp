class A {
public:
    static int count;
    A(int __val = 0) : val(__val){
        ++count;
    }
    virtual ~A() {
        cout << "A::destructor" << endl;
        --count;
    }
protected:
    int val;
};

class B : public A{
public:
    B(int __val = 0) : A(__val) {};
    B(const B &rhs) : B(rhs.val) {};
    ~B() {
        cout << "B::destructor" << endl;
    }
};