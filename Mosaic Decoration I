// Problem description found at https://csacademy.com/contest/ieeextreme-practice/task/mosaic1

#include <iostream>
#include <math.h> 
using namespace std;

int main() {
    int n, cb, cp;
    float b=0, p=0;
    cin >> n >> cb >> cp;
    for(int i = 0; i < n; i++){
        int b_temp, p_temp;
        cin >> b_temp >> p_temp;
        b += b_temp;
        p += p_temp;
    }
    cout << ((int)ceil(b/10)*cb + (int)ceil(p/10)*cp);
    return 0;
}
