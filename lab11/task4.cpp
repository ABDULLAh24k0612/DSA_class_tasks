#include <iostream>
using namespace std;

struct Student {
    int roll;
    string name;
};

class StudentHashTable {
public:
    Student table[15];
    bool occupied[15];

    StudentHashTable() {
        for(int i=0;i<15;i++) occupied[i]=false;
    }

    int hashFunc(int roll) { return roll % 15; }

    void InsertRecord(int roll, string name) {
        int index = hashFunc(roll);
        int i = 0;
        while(occupied[(index + i*i) % 15]) i++;
        int pos = (index + i*i) % 15;
        table[pos].roll = roll;
        table[pos].name = name;
        occupied[pos] = true;
    }

    void SearchRecord(int roll) {
        int index = hashFunc(roll);
        for(int i=0;i<15;i++) {
            int pos = (index + i*i) % 15;
            if(occupied[pos] && table[pos].roll == roll) {
                cout<<table[pos].name<<"\n";
                return;
            }
        }
        cout<<"Record not found\n";
    }
};

int main() {
    StudentHashTable s;
    s.InsertRecord(10,"Ali");
    s.InsertRecord(25,"Hassan");
    s.SearchRecord(10);
}
