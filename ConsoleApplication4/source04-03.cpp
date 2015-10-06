class Array2{
private:
    int *p;
    int r, c;
public:
    Array2(){ p = NULL; }
    Array2(int r_, int c_) :r(r_), c(c_){
        p = new int[r*c];}
    Array2(Array2 &a) :r(a.r), c(a.c){
        p = new int[r*c];
        memcpy(p, a.p, sizeof(int)*r*c);
    }
    Array2& operator=(const Array2 & a){
        if (p)delete[]p;
        r = a.r; c = a.c; p = new int[r*c];
        memcpy(p, a.p, sizeof(int)*r*c);
        return *this;
    }
    ~Array2(){if (p)delete[]p;}
    int *operator[](int i){ return p + i*c; }
    int &operator()(int i, int j){ return p[i*c + j]; }
};