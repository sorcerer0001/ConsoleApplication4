#include<iostream>
using namespace std;

class stu{
private:
	int age, y1, y2, y3, y4;
	char name[20];
	char num[20];
	char k;
public:
	void init();
	void print();
	void average_y();
};

void stu::init(){
	cin.get(name, 20, ',');
	cin >> k >> age >> k;
	cin.get(num, 20, ',');
	cin >> k >> y1 >> k >> y2 >> k >> y3 >> k >> y4;
}
void stu::print(){
	cout << name << "," << age << "," << num << ",";
}
void stu::average_y(){
	cout << (y1 + y2 + y3 + y4) / 4 << endl;
}

int main(){
	stu c;
	c.init();
	c.print();
	c.average_y();
	return 0;
}