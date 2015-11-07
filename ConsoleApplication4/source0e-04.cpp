class CType {
    friend ostream &operator<<(ostream&, const CType&);
public:
    void setvalue(int __val) {
        val = __val;
    }
    CType operator++(int){
        CType tmp(*this);
        val *= val;
        return tmp;
    }
private:
    int val;
};

ostream &operator<<(ostream &os, const CType &rhs) {
    os << rhs.val;
    return os;
}