class A {
public:
    A(int __age) : age(__age) {}
    friend bool operator<(const A &lhs, const A &rhs) {
        return lhs.age < rhs.age;
    }
    virtual void print() const {
        cout << "A " << age;
    }

protected:
    int age;
};

class B : public A {
public:
    B(int __age) : A(__age) {};
    void print() const {
        cout << "B " << age;
    }
};

class Comp {
public:
    bool operator()(const A *lhs, const A *rhs) const {
        const A l = *lhs;
        const A r = *rhs;
        return l < r;
    }
};

void Print(const A *lhs) {
    lhs->print();
    cout << endl;
}
