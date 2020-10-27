//Program description found at https://csacademy.com/contest/ieeextreme-practice/task/mosaic2

#include <iostream>
#include <math.h>
using namespace std;

int main() {
    long int w, h, m, c;
    float a,b;
    cin >> w >> h >> a >> b >> m >>c;
    long int amount_tiles = (long int)ceil(w/a) *(long int)ceil(h/b); 
    long int amount_cut = 0;
    //if width is not able to divided by tile width need to make a cut of height size
    if((long int)ceil(w/a) != (long int)w/a){
        amount_cut += h;
    }
    //if height is not able to divided by tile width need to make a cut of width size
    if((long int)ceil(h/b) != (long int)h/b){
        amount_cut += w;
    }
    cout<< (long int)(amount_cut*c + (long int)ceil((long double)amount_tiles/10)*m);
    return 0;
}
