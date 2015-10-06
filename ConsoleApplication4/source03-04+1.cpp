#include<iomanip>
#include<iostream>
using namespace std;
class CWorld
{
public:
	CWorld(int m,int *pc,char *sn){
		i_Hou = 0;
		i_M = m;
		memcpy(&ia_ProCos, pc, sizeof(ia_ProCos));
		memcpy(&sa_SmuNam, sn, sizeof(sa_SmuNam));
	};
	int i_M,i_Hou;//总量，时间
	int ia_ProCos[5];//生产成本
	char sa_SmuNam[5][10];//smu名字
private:
};

class CM
{
public:
	CM(const char* name){//构造函数
		memcpy(c_Nam, name, sizeof(c_Nam));
		b_Flag = true;
		i_ProId = 1;
		i_ProKey = 0;
		f_ini();//其他类成员变量初始化
	};
	int i_M;//总M可使用量
	bool b_Flag;//终止生产标志
	int f_getProOrd(int key, int val){ ia_ProOrd[key] = val; return 0; };
	friend class CWorld;
	int f_ProSmu(CWorld cw);//生产
private:
	char c_Nam[10];//名字
	int ia_ProOrd[5], ia_ProNum[5];//生产顺序，生产数量
	int i_ProKey, i_ProId;//生产目标，目标ID
	int f_getProKey(int key);//获取目标
	void f_ini(){for (int i = 0; i < 5; i++){ia_ProNum[i] = 0;}};
};

int CM::f_ProSmu(CWorld cw){
	int tempsetp=0;
	while (tempsetp<6){
		if (i_M>=cw.ia_ProCos[ia_ProOrd[i_ProKey]]){
			i_M -= cw.ia_ProCos[ia_ProOrd[i_ProKey]];
			ia_ProNum[i_ProKey]++;
			cout << c_Nam << " " << cw.sa_SmuNam[ia_ProOrd[i_ProKey]] << " " << i_ProId << " born with strength" << " "
				<< cw.ia_ProCos[ia_ProOrd[i_ProKey]] << "," << ia_ProNum[i_ProKey] << " " << cw.sa_SmuNam[ia_ProOrd[i_ProKey]] << " in " << c_Nam << " headquarter" << endl;
			i_ProId++;
			i_ProKey++;
			i_ProKey %= 5;
			return 1;
		}
		i_ProKey++;
		i_ProKey %= 5;
		tempsetp++;
	}
	cout << c_Nam << " headquarter stops making warriors" << endl;
	b_Flag = false;
	return -1;
}
int main(){
	int i_Time;
	int tempiacost[5], tempM;
	char smuname[5][10] = { "dragon", "ninja", "iceman", "lion", "wolf" };
	cin >> i_Time;
	for (int i_Case = 1; i_Case <i_Time+1 ; i_Case++){
		cin >> tempM;
		cin >> tempiacost[0] >> tempiacost[1] >> tempiacost[2] >> tempiacost[3] >> tempiacost[4];
		int tempredproord[] = { 2, 3, 4, 1, 0 };//获取生产清单
		int tempblueproord[] = { 3, 0, 1, 2, 4 };
		cout << "Case:" << i_Case << endl;
		CWorld e_W1(tempM, tempiacost, *smuname);
		CM e_Mred("red");
		CM e_Mblue("blue");
		e_Mred.i_M = e_W1.i_M;
		e_Mblue.i_M = e_W1.i_M;
		for (int i = 0; i < 5; i++)//初始化生产清单
		{
			e_Mblue.f_getProOrd(i, tempblueproord[i]);
			e_Mred.f_getProOrd(i, tempredproord[i]);
		}
		while (e_Mblue.b_Flag != false || e_Mred.b_Flag != false)//生产循环
		{

			if (e_Mred.b_Flag){
				cout << setw(3) << setfill('0') << e_W1.i_Hou << " ";
				e_Mred.f_ProSmu(e_W1);
			};
			if (e_Mblue.b_Flag){
				cout << setw(3) << setfill('0') << e_W1.i_Hou << " ";
				e_Mblue.f_ProSmu(e_W1);
			};
			e_W1.i_Hou++;
		}
	}
	return 0;
}
