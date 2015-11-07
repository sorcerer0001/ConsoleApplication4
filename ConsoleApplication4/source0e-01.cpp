public:
    int num;
    Number(int n = 0) : num(n) {}
    int & operator *(Number & x) {
        int * result = new int;
        *result = this->num*x.num;
        return *result;
    }

    operator int() { return this->num; }