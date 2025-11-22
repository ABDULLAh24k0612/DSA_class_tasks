

#include <iostream>
using namespace std;

struct Node {
    string word;
    Node* next;
    Node(string w){word=w;next=NULL;}
};

class Dictionary {
public:
    Node* table[100];

    Dictionary() {
        for(int i=0;i<100;i++) table[i]=NULL;
    }

    int hashFunc(string s) {
        int sum=0;
        for(char c:s) sum+=c;
        return sum%100;
    }

    void Add_Record(string s) {
        int index = hashFunc(s);
        Node* n = new Node(s);
        n->next = table[index];
        table[index] = n;
    }

    void Word_Search(string s) {
        int index = hashFunc(s);
        Node* temp = table[index];
        while(temp) {
            if(temp->word == s) {
                cout<<"Word found\n";
                return;
            }
            temp=temp->next;
        }
        cout<<"Error: Word not found\n";
    }

    void Print_Dictionary() {
        for(int i=0;i<100;i++) {
            cout<<i<<" : ";
            Node* temp = table[i];
            while(temp){
                cout<<temp->word<<" -> ";
                temp=temp->next;
            }
            cout<<"NULL\n";
        }
    }
};

int main() {
    Dictionary d;
    d.Add_Record("apple");
    d.Add_Record("ball");
    d.Word_Search("apple");
    d.Print_Dictionary();
}
