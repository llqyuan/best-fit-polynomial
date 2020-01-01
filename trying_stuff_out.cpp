#include "matrix_vector_operations.h"
#include <new>
#include <iostream>


using namespace std;


class Test {
    public:
        int * arr;
        int len;
        Test(int * al = nullptr, int alen = 0) { 
            arr = al; 
            len = alen;
        }
        ~Test(void) {
            if (arr) {
                delete[] arr;
            }
        }
        void do_stuff_base(void) {
            cout << "Called do_stuff_base" << endl;
            if (arr != nullptr) {
                for (int i = 0; i < len; ++i) {
                    cout << *(arr + i) << " ";
                }
                cout << endl;
            }
        }
};


class TestChild: public Test {
    public:
        int * arr2;
        int len;
        TestChild(int * al = nullptr, int alen = 0) {
            arr2 = al;
            len = alen;
        }
        ~TestChild(void) {
            if(arr2) {
                delete[] arr2;
            }
        }
        void do_stuff_child(void) {
            cout << "Called do_stuff_child" << endl;
            if (this->arr2 != nullptr) {
                for (int i = 0; i < len; ++i) {
                    cout << *(arr2 + i) << " ";
                }
                cout << endl;
            }
        }
};


int main(void) {
    int * a1 = new int[10];
    int * a2 = new int[5];
    for (int i = 0; i < 10; ++i) {
        *(a1 + i) = i;
    }
    for (int i = 0; i < 5; ++i) {
        *(a2 + i) = i + 10;
    }
    Test * base_instance = new Test(a1, 10);
    TestChild * child_instance = new TestChild(a2, 5);
    base_instance->do_stuff_base();
    child_instance->do_stuff_child();
    child_instance->do_stuff_base();
    delete base_instance;
    delete child_instance;

    cout << "Matrix vector operations: " << endl;
    
    Matrix * m = new Matrix(2, 3);
    Vector * v = new Vector(3);
    for (int i = 0; i < 6; ++i) {
        (m->vals)[i] = (float) i + 1;
        if (i < 3) {
            (v->vals)[i] = (float) i + 1;
        }
    }

    m->test_will_remove();
    v->test_will_remove();
    delete m;
    delete v;
    
}

