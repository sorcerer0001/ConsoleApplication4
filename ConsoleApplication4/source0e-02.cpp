    int &value() {return num;}
    void operator+(const Number &rhs) {
        num += rhs.num;
    }