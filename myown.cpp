#include <iostream>
#include <cstdlib>
#include <math.h> //later use of π.
#include <ctime>
#include <iomanip> //to give pi the precision i want and know better the accuracy.
using namespace std;

int main(){
    int m, i;
    double sum = 0;
    int iterations1 = pow(10, 6);
    int iterations2 = pow(10, 3);
    double points;
    float myown;
    double list[iterations2];
    time_t start, end;
    
    time(&start);
    
    for(m = 0; m < iterations2; m++){
        points = 0;
        for (i = 0; i < iterations1; i++){
            double x = 0.20276355 + static_cast<double>(rand()) / (RAND_MAX/2.17740618);
            double y = static_cast<double>(rand()) / (RAND_MAX/5);
            
            if (y <= x/(sin(x)*sin(x))){
                points++;
            }
        }
        myown = (points/iterations1) *2.17740618*5;
        sum += myown;
        list[m] = myown;
    }
    time(&end);
    float time_taken = float (end-start); //calculation of the time.
    float average = sum / iterations2;
    cout<<setprecision(15)<<"the integral from 0.203 to 2.38 of x/sin^2(x) for "<<iterations2<<" iterations is equal to\n "<<average<<"\n";
    
    double sum_squared_dif = 0;
    for (int j=0; j< iterations2; j++){
        sum_squared_dif += pow(list[m] - average, 2);
    }
    double stdev = sqrt(sum_squared_dif/(iterations2 - 1));
    
    double SE = stdev/sqrt(iterations2);
    cout<<"=== STANDARD ERROR IS "<<SE<<" ===\n";
    cout<<"== aproximation with SE is =="<<average + SE<<" or "<<average - SE<<"\n";
    cout<<setprecision(9)<<"time taken: "<<time_taken<<"s\n";
    
    
    return 0;
}
