
#include "st.h"
#include <iostream>
using namespace std;

void to_binary(int num);

int main()
{
    cout << "12 in binary is "; 
    to_binary(73);
}


void to_binary(int num) {
    stack<int> binary(0,10);
    while (num > 0) {
        binary.push(num % 2);
        num /= 2;
    }
    int i = 0;
    while (binary.getElements() > 0) {
        cout << binary.pop();
    }
}
