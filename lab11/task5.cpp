#include <iostream>
using namespace std;

class EmployeeTable {
public:
    string table[50];
    bool used[50];

    EmployeeTable() {
        for(int i=0;i<50;i++){
            table[i]="";
            used[i]=false;
        }
    }

    int h1(string s) {
        int sum=0;
        for(char c:s) sum+=c;
        return sum%50;
    }

    int h2(string s) {
        int sum=0;
        for(char c:s) sum+=c;
        return 7 - (sum % 7);
    }

    void Add_Employee(string name) {
        int a = h1(name);
        int b = h2(name);
        int i = 0;
        while(used[(a + i*b) % 50]) i++;
        int pos = (a + i*b) % 50;
        table[pos] = name;
        used[pos] = true;
    }

    void Search_Employee(string name) {
        int a = h1(name);
        int b = h2(name);
        for(int i=0;i<50;i++) {
            int pos = (a + i*b) % 50;
            if(used[pos] && table[pos] == name) {
                cout<<"Employee found at index "<<pos<<"\n";
                return;
            }
        }
        cout<<"Employee not found in the directory.\n";
    }

    void Display_Table() {
        for(int i=0;i<50;i++)
            cout<<i<<" : "<<table[i]<<"\n";
    }
};

int main() {
    EmployeeTable e;
    e.Add_Employee("Ali");
    e.Add_Employee("Usman");
    e.Search_Employee("Ali");
    e.Display_Table();
}
