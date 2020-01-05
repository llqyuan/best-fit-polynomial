#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>
#include "method_of_least_squares.h"
#include "linear_algebra_objects.h"
#include "within.h"


using namespace std;


struct posn {
    float x;
    float y;
};


// entry_exists(plist, x) returns true if x exists as an
//   x coordinate in plist and false otherwise
bool entry_exists(vector<posn *> * plist, float x) 
{
    for (int i = 0; i < plist->size(); ++i)
    {
        if (within(x, (plist->at(i))->x)) 
        {
            return true;
        }
    }
    return false;
}


Matrix * least_squares_matrix(vector<posn *> * plist, const int degree)
{
    Matrix * m = new Matrix(plist->size(), degree + 1);
    for (int row = 0; row < plist->size(); ++row)
    {
        float x = (plist->at(row))->x;
        for (int col = 0; col < m->num_cols; ++col)
        {
            m->vals[row * m->num_cols + col] = pow(x, col);
        }
    }
    return m;
}


MathVector * least_squares_vector(vector<posn *> * plist)
{
    MathVector * v = new MathVector(plist->size());
    for (int i = 0; i < plist->size(); ++i)
    {
        float y = (plist->at(i))->y;
        v->vals[i] = y;
    }
    return v;
}


void pretty_print_polynomial(MathVector * v)
{
    if (v->len) {
        cout << "f(x) = ";
        bool print_plus = false;
        for (int i = 0; i < v->len; ++i) {
            if (within(v->vals[i], 0)) {
                continue;
            }

            if (print_plus && v->vals[i] > 0) {
                cout << " + ";
            } else if (print_plus && v->vals[i] < 0) {
                cout << " - ";
            }
            print_plus = true;

            if (i == 0) {
                cout << v->vals[0];

            } else if (i == 1 && within(fabs(v->vals[i]), 1)) {
                cout << "x";

            } else if (i == 1) {
                cout << fabs(v->vals[i]) << "x";

            } else if (within(fabs(v->vals[i]), 1)) {
                cout << "x^" << i;

            } else {
                cout << v->vals[i] << "x^" << i;
            }
        }
    } else {
        cout << "f(x) = 0";
    }
    cout << endl;
}


namespace action_statuses 
{
    const unsigned int no_action_occurring = 0;
    const unsigned int adding_x = 1;
    const unsigned int adding_y = 2;
    const unsigned int calculating = 3;
}


int main(void) 
{
    vector<posn *> posn_list;
    const string add_cmd = "add";
    const string remove_cmd = "remove";
    const string calculate_cmd = "calculate";
    const string print_cmd = "view added coordinates";
    const string quit_cmd = "quit";
    string command = "";

    float x;
    float y;
    int status = action_statuses :: no_action_occurring;
    posn * to_add;

    while (getline(cin, command)) {
        if (status) {
            if (status == action_statuses:: adding_x) {
                istringstream sstream(command);
                float convert_to_float_temp;
                if (!(sstream >> convert_to_float_temp)) {
                    cout << "Invalid entry: " << command << endl;
                    cout << "Enter a new x coordinate:" << endl;
                    continue;
                }
                to_add = new posn();
                to_add->x = convert_to_float_temp;
                cout << "x: " << to_add->x << endl;
                cout << "Enter a y coordinate:" << endl;
                status = action_statuses :: adding_y;
            } else if (status == action_statuses :: adding_y) {
                istringstream sstream(command);
                float convert_to_float_temp;
                if (!(sstream >> convert_to_float_temp)) {
                    cout << "Invalid entry: " << command << endl;
                    cout << "Enter a new y coordinate:" << endl;
                    continue;
                }
                to_add->y = convert_to_float_temp;
                cout << "y: " << to_add->y << endl;
                posn_list.push_back(to_add);
                cout << "Added coordinate: " 
                     << to_add->x << ", " << to_add->y << endl;
                status = action_statuses :: no_action_occurring;
            } else if (status == action_statuses :: calculating) {
                cout << "fififdij" << endl;
                status = action_statuses :: no_action_occurring;
            }

        } else if (command.compare(add_cmd) == 0) {
            status = action_statuses :: adding_x;
            cout << "Enter an x coordinate:" << endl;

        } else if (command.compare(remove_cmd) == 0) {
            if (posn_list.size()) {
                delete posn_list.at(posn_list.size() - 1);
                posn_list.pop_back();
                cout << "Removed most recently added coordinate." << endl;
            } else {
                cout << "No coordinates added." << endl;
            }

        } else if (command.compare(calculate_cmd) == 0) {
            status = action_statuses :: calculating;

        } else if (command.compare(print_cmd) == 0) {
            if (posn_list.size()) {
                cout << "List of coordinates stored so far:" << endl;
                for (int i = 0; i < posn_list.size(); ++i) {
                    cout << "(" << posn_list.at(i)->x 
                         << ", " << posn_list.at(i)->y 
                         << ")" << endl;
                }
            } else {
                cout << "None stored." << endl;
            }

        } else if (command.compare(quit_cmd) == 0) {
            break;

        } else {
            cout << "Invalid command: " << command << endl;
        }
    }
    cout << "Quitting." << endl;
    if (status == action_statuses :: adding_y) {
        delete to_add;
    }
    for (int i = 0; i < posn_list.size(); ++i) {
        delete posn_list.at(i);
    }
}
