class CMy_add {
public:
    CMy_add(int &__total) : total(__total) {}
    void operator()(int val) {
        total += val & ((1 << 3) - 1);
    }

private:
    int &total;
};