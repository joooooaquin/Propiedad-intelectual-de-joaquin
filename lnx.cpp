#include <iostream>
#include <cstdlib>
#include <math.h> //later use of π.
#include <ctime>
#include <iomanip> //to give pi the precision i want and know better the accuracy.
using namespace std;

int lnx(){
    int l, i;
    double sum = 0;
    int iterations1 = pow(10, 6);
    int iterations2 = pow(10, 3);
    double points;
    float ln;
    double list[iterations2];
    time_t start, end;
    
    time(&start);
    for (l = 0; l < iterations2; l++){
        points = 0;
        for (i = 0; i < iterations1; i++){
            double x = 1 + static_cast<double>(rand()) / (RAND_MAX/2);
            double y = static_cast<double>(rand()) / (RAND_MAX/log(3));
            //cout<<x<<"\n";
            
            if (y <= log(x))
            {points++;}
        }
        ln = (points/iterations1) * (2*log(3));
        sum += ln;
        list[l] = ln;
    }
    time(&end);
    float time_taken = float (end-start); //calculation of the time.
    float average = sum / iterations2;
    cout<<setprecision(15)<<"average lnx for "<<iterations2<<" iterations is "<<average<<"\n";
    //cout<<points_ln<<"\n";
    
    double sum_squared_dif = 0;
    for (int j=0; j < iterations2; j++){
        sum_squared_dif += pow(list[j] - average, 2);
    }
    double stdev = sqrt(sum_squared_dif/(iterations2 -  1));
    
    double SE = stdev/sqrt(iterations2); //standard error simple calculation
    cout<<"=== STANDARD ERROR IS "<<SE<<" ===\n";
    cout<<setprecision(9)<<"time taken: "<<time_taken<<"s\n";
    cout<<"== aproximation with SE is =="<<average + SE<<" or "<<average - SE<<"\n";
    
    return 0;
}
