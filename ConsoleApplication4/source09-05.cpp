#include <iostream>
#include <map>
using namespace std;

int main() {
    map<int, int> club;
    int n;
    int power, id;
    map<int, int>::iterator it;
    cin >> n;
    club[1000000000] = 1;
    for (int i = 0; i < n; i++)
    {
        cin >> id >> power;
        it = club.lower_bound(power);
        if (it != club.begin()) {
            map<int, int>::iterator it1=it;
            it--;
            if (power - it->first <= it1->first - power) {
                cout << id << ' ' << it->second << endl;
            }
            else {
                cout << id << ' ' << it1->second << endl;
            }
            club[power] = id;
        }
        else {
            cout << id << ' ' << it->second << endl;
            club[power] = id;
        }
    }
    return 0;
}