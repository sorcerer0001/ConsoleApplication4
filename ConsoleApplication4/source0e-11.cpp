template <typename _key, typename _val>
ostream & operator<<(ostream &os, const pair<_key, _val> &rhs) {
    os << "(" << rhs.first << "," << rhs.second << ")";
    return os;
};


template <typename _key, typename _val, typename _compare = greater<_key> >
class MyMultimap : public multimap<_key, _val, _compare> {
public:
//    MyMultimap() : multimap<_key, _val, _compare>() {};
//    MyMultimap(const multimap<_key, _val, _compare> &rhs) : multimap<_key, _val, _compare>(rhs) {};

    void Set(const _key &__key, _val __val) {
        auto begin = this->lower_bound(__key), end = this->upper_bound(__key);
        for (; begin != end; ++begin) {
            begin->second = __val;
        }
    }
};