//Problem found at https://csacademy.com/contest/ieeextreme-practice/task/hotel-wiring

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    int temp;
    cin >> t;
    for(int i=0; i<t; i++){
        long int m, n, k;
        cin >> m >> n >>k;
        vector<long int> rooms;
        for(long int j =0; j<m; j++){
            cin>>temp;
            rooms.push_back(temp);
        }
        long int max_rooms = 0;
        //sort rooms in descending order
        sort(rooms.begin(), rooms.end());
        long int j = 0;
        //Turn off master switch for k rooms 
        for(; j <k; j++){
            max_rooms += (n - rooms.at(j));
        }
        //The rest must have the master switch on 
        for(;j<m;j++){
            max_rooms += rooms.at(j);
        }
        cout<< max_rooms<<endl;
    }
    return 0;
}
