#include<cstring>
#include<iostream>
#include<iomanip>
using namespace std;
class base
{
private:
    int m, productable[5], end, ord[5], step, num[5],sum;
    string name;
    static int str[5], time;
    static string monname[5];
public:
    base(int, int, int, int, int, int, const char*);
    static void set();
    void product();
    static void grow(base, base);
    void setname();
};
 
int base::str[5] = {1,1,1,1,1};
int base::time = 0;
string base::monname[5] = {"dragon", "ninja", "iceman", "lion", "wolf"};
 
base::base(int a, int b, int c, int d, int e, int f, const char* g )
{
    m = f;
    sum = 0;
    step = 0;
    name = g;
    for(int i = 0; i < 5; i++) num[i] = 0;
    ord[0] = a;
    ord[1] = b;
    ord[2] = c;
    ord[3] = d;
    ord[4] = e;
    memset(productable, 0, sizeof(productable));
    end = 0;
    return;
}
 
 
void base::set()
{
    for(int i = 0; i < 5; i++)
        cin >> str[i];
    time = 0;
    return;
}
 
void base::product()
{
    if(end) return;
    if(productable[0] + productable[1] + productable[2] + productable[3] + productable[4] == 5)
    {
        cout << setw(3) << setfill('0') << time <<" " << name << " headquarter stops making warriors" << endl;
        end = 1;
        return;
    }
    if(!productable[ord[step]] && m >= str[ord[step]])
    {
        num[ord[step]]++;
        sum++;
        cout << setw(3) << setfill('0') << time << " "<< name <<" " << monname[ord[step]] << " " << sum << " born with strength"<< " "
             << str[ord[step]]<< "," << num[ord[step]] << " " << monname[ord[step]] << " in " << name << " headquarter"<<  endl;
        m -= str[ord[step]];
        return;
    }
    else
    {
        productable[ord[step]] = 1;
        step = (step + 1) % 5;
        product();
        return;
    }
}
 
void base::grow(base a, base b)
{
    while(true)
    {
        a.product();
        a.step = (a.step + 1) % 5;
        b.product();
        b.step = (b.step + 1) % 5;
        time++;
        if(a.end + b.end == 2) break;
    }
    return;
}
 
 
int main()
{
    int n = 0;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cout << "Case:" << i << endl;
        int tep = 0;
        cin >> tep;
        base red(2, 3, 4, 1, 0, tep, "red"), blue(3, 0, 1, 2, 4, tep, "blue");
        base::set();
        base::grow(red, blue);
    }
    return 0;
}