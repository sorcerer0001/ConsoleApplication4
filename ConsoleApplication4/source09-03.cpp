#include<iostream>
#include<string>
#include<set>
using namespace std;

multiset<int> intSet;
set<int> intSetAll;

void Add() {
    int x;
    cin >> x;
    intSet.insert(x);
    intSetAll.insert(x);
    cout << intSet.count(x) << endl;
}

void Del() {
    int x;
    cin >> x;
    multiset<int>::iterator p;

    int count = 0;
    while (true) {
        p = intSet.find(x);
        if (p != intSet.end()) {
            intSet.erase(p);
            count++;
        }
        else {
            break;
        }
    }
    cout << count << endl;
}

void Ask() {
    int x;
    cin >> x;
    int count = intSet.count(x);
    int countAll = intSetAll.count(x);
    cout << (countAll > 0 ? 1 : 0) << " " << count << endl;
}

int main() {
    int n;
    cin >> n;
    string cmd;
    for (int i = 0; i < n; i++) {
        cin >> cmd;
        if (cmd == "add")
            Add();
        else if (cmd == "del") {
            Del();
        }
        else if (cmd == "ask") {
            Ask();
        }
    }
}