// The problem is found here https://csacademy.com/contest/ieeextreme-practice/task/linearly-separable-samples 
// I designed a simple learning algorthim to find the appropriate weights 
// For this problem I was unable to solve most of the test case save for the most basic ones
//Possible reasons could be the learning rate not being optimized and the amount of times the traing loop runs
#include <iostream>

//Structure to store point
using namespace std;
struct point{
    double x1;
    double x2;
    int y;
};

//Calculate the loss of the point 
double calcHingeLoss(point& p, double& w1, double& w2){
    double loss = w1*p.x1 + w2*p.x2;
    if(p.y == 1){
        if(loss>= 0){
            return 0;
        }
        else{
            return loss;
        }
    }
    else{
        if(loss<= 0){
            return 0;
        }
        else{
            return loss;
        }
    }
}

//Calculate the derivations needed for w1 and w2 
void clacDev(point* p, double n, double& w1, double& w2){
    double learning_rate = 0.01;
    for(int j =0; j < 500; j++){
        double dw1 = 0;
        double dw2 = 0;
        for(int i = 0; i <(int)n; i++){
            double loss = calcHingeLoss(p[i], w1,w2);
            if(loss >0){
                dw1 += -p[i].x1*p[i].y;
                dw1 += -p[i].x2*p[i].y;
            }
        }
        dw1 /=n;
        dw2 /=n;
        w1 -= learning_rate*dw1;
        w2 -= learning_rate*dw2;
    }
}

//Test if the line learned satsifies the conditions set 
bool testLine(point* p, int n, double& w1, double& w2){
    for(int i = 0; i < n; i++){
        if((p[i].x1*w1+p[i].x2*w2) < 0 && p[i].y == 1){
            return false;
        }
        else if((p[i].x1*w1+p[i].x2*w2) > 0 && p[i].y == -1){
            return false;
        }
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    for(int i = 0; i <t; i++){
        double n;
        cin >>n;
        point points[(int)n];
        double x1_temp, x2_temp;
        int y_temp;
        for(int j =0; j<(int)n;j++){
            cin >> x1_temp >> x2_temp >>y_temp;
            points[j].x1 = x1_temp;
            points[j].x2 = x2_temp;
            points[j].y = y_temp;
        }
        double w1=1, w2=1;
        clacDev(points, n, w1, w2);
        bool isLine = testLine(points, n, w1, w2);
        if(isLine)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
