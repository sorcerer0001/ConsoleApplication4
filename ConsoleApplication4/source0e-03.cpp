template<typename _Tp, typename _Binary_Op>
_Tp sum(_Tp *arr, _Tp sz, _Binary_Op func) {
    _Tp total = 0;
    for (_Tp i = 0; i < sz; ++i) {
        total += func(arr[i]);
    }
    return total;
}