
template<class T>
class CMyistream_iterator {
private:
    istream *is;
    T inputs[5];
    int now;
public:
    CMyistream_iterator(istream & _is) {
        is = &_is;
        *is >> inputs[0];
        now = 0;
    }
    T & operator*() {
        return this->inputs[this->now];
    }
    CMyistream_iterator & operator++(int k) {
        now++;
        *is >> inputs[now];
        return *this;
    }
};

