#include "omni_wheel.h"
#include <iostream>
#include <cmath>
#define PI 3.1415926535

using namespace std;

wheel::wheel() {}

void wheel::motor_main(float direction, int power, float mod){
    double Motor[4];//PWM value

    double motor_1st = sin((direction-45)*PI/180)*power+mod;
    double motor_2nd = sin((direction-135)*PI/180)*power+mod;
    double motor_3rd = sin((direction-225)*PI/180)*power+mod;
    double motor_4th = sin((direction-315)*PI/180)*power+mod;

    double abs_m1 = abs(motor_1st);
    double abs_m2 = abs(motor_2nd);
    double abs_m3 = abs(motor_3rd);
    double abs_m4 = abs(motor_4th);

    double scope = max(abs_m1,abs_m2);//max power calculate
    scope = max(scope,abs_m3);
    scope = max(scope,abs_m4);

    if(scope == 0){
        Motor[0] = 0;
        Motor[1] = 0;
        Motor[2] = 0;
        Motor[3] = 0;
    }else{
        Motor[0] = motor_1st*255/scope;//final angular velocity
        Motor[1] = motor_2nd*255/scope;
        Motor[2] = motor_3rd*255/scope;
        Motor[3] = motor_4th*255/scope;
    }

    cout << Motor[0] << ","<< Motor[1] << ","<< Motor[2] << ","<< Motor[3] << endl;
}

//test
int main() {
    float direction = 53.8768;
    int power = 87;
    float mod = 32.3657;

    wheel *w;

    w = new wheel();

    w ->motor_main(direction,  power,  mod);

    return 0;
}}