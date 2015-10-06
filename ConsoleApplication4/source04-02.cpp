
MyInt & operator - ( int k) {
	nVal -= k;
	return *this;
}
MyInt operator = (const MyInt &obj) {
	return MyInt(obj.nVal);}
