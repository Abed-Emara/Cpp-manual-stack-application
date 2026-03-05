
#include "st.h"
#include <iostream>
using namespace std;

void to_binary(int num);

int main()
{
    int n;
    cout << "Enter a num: ";
    cin>>n;
    cout<<n<<" => ";
    to_binary(n);
    
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

