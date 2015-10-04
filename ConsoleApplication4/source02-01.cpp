#include "stdafx.h"
#include<iostream>
#include<string.h>
using namespace std;
class s
{
private:
	char name[100], id[10];
	int age, s1, s2, s3, s4, avg;

public:
	s(char name[], int age, char id[], int s1, int s2, int s3, int s4){
		strcpy_s(this->name,name);
		this->age = age;
		strcpy_s(this->id,id);
		this->s1 = s1;
		this->s2 = s2;
		this->s3 = s3;
		this->s4 = s4;
	};
/*	~s();*/
	int getAvg(){
		return int((s1 + s2 + s3 + s4) / 4);
	}
	char *getName(){
		return name;
	}
	char *getId(){
		return id;
	}
	int getAge(){
		return age;
	}

};
int main() {
	char name[100], comm, id[100];
	int age, s1, s2, s3, s4;
	cin.getline(name, 100, ',');
	cin >> age;
	comm = getchar();
	cin.getline(id, 100, ',');
	cin >> s1 >> comm >> s2 >> comm >> s3 >> comm >> s4;
	s std1(name, age, id, s1, s2, s3, s4);
	cout << std1.getName() << ',' << std1.getAge() << ',' << std1.getId() << ',' << std1.getAvg();
	return 0;
}
