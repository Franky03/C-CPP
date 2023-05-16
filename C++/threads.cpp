#include <iostream>
#include <thread>

#include <vector>

using namespace std;

void foo() {
    cout << "Hello from thread: "<< this_thread::get_id() << endl;
}

void bar(int x) {
    cout << "Bar: " << x << endl;
}

class TesteClass {
    int i;
    public:
        TesteClass(int n) { i = n; };
        void greeting(string const & message) const {
            cout << message << endl;
            cout << "MyNumber: " << i << endl; 
        };
};

int main(void) {

    TesteClass x = TesteClass(10);
    thread t = thread(&TesteClass::greeting, &x, "Hello! ");
    t.join();
    return 0;

} 