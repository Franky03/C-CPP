#include <iostream>
#include <list>
#include <vector>

using namespace std;

int main(void){
    vector<int> v;
    vector<int> v2;
    int n;

    for(int i = 0; i < 10; i++){
        cin >> n;
        v.push_back(n);
        v2.insert(v2.begin(), n);

    }

    cout << "My vector: ";
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }

    cout << endl;

    cout << "My vector 2: ";
    for(int i = 0; i < v2.size(); i++){
        cout << v2[i] << " ";
    }
    


    return 0;


    list<int> l;
    list<string> names;
    l.push_back(200);
    l.push_back(300);

    cout << "My list: ";
    for(list<int>::iterator it = l.begin(); it != l.end(); it++){
        cout << *it << " ";
    }
    cout << endl;

    cout << "My list: ";
    for(int num: l){
        cout << num << " ";
    }
    cout << endl;

    // sort

    names.push_back("Juan");
    names.push_back("Pedro");
    names.push_back("Maria");
    names.push_back("Ana");

    names.sort();

    cout << "My list: ";
    for(string name: names){
        cout << name << " ";
    }
    cout << endl;
    // reverse
    names.reverse();
    cout << "My list: ";
    for(string name: names){
        cout << name << " ";
    }
    cout << endl;
    
    // remove

    names.remove("Ana");
    cout << "My list: ";
    for(string name: names){
        cout << name << " ";
    }

    cout << endl;

    

    return 0;   
}