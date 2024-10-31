#include <iostream>
#include <cstdlib>
#include <math.h> //later use of π.
#include <ctime>
#include <iomanip> //to give pi the precision i want and know better the accuracy.
using namespace std;

int ex(){
    int e, i;
    double sum = 0;
    int iterations_1 = pow(10, 6);
    int iterations_2 = pow(10, 3);
    double points;
    float ex;
    double list[iterations_2];
    time_t start, end;
    
    time(&start);
    for(e = 0; e < iterations_2; e++){
        points = 0;
        for (i = 0; i < iterations_1; i++){
            double x1 = 2 - static_cast<double>(rand()) / (RAND_MAX/2);
            //cout<<x<<"\n";
            //double z = -(pow(x, 2)/5.5225) + 1;
            //(1-(pow(x, 2))/2 + (pow(x, 4))/8 - (pow(x, 6))/48 + (pow(x, 8))/384 - (pow(x, 10))/3840 + (pow(x, 12))/46080 - (pow(x, 14))/645120)
            //cout<<z<<"\n";
            double y1 = static_cast<double>(rand()) / (RAND_MAX/1);
            
            if (y1 <= exp(-x1*x1))
            {points++;}
        }
        ex = (points/iterations_1) * 4;
        sum += ex;
        list[e] = ex;
    }
    time(&end);
    float time_taken = float (end-start); //calculation of the time.
    float average = sum / iterations_2;
    cout<<setprecision(15)<<"average ex for "<<iterations_2<<" iterations is "<<average<<"\n";
    
    double sum_squared_dif = 0;
    for (int j=0; j< iterations_2; j++){
        sum_squared_dif += pow(list[e] - average, 2);
    }
    double stdev = sqrt(sum_squared_dif/(iterations_2 - 1));
    
    double SE = stdev/sqrt(iterations_2);
    cout<<"=== STANDARD ERROR IS "<<SE<<" ===\n";
    cout<<"== aproximation with SE is =="<<average + SE<<" or "<<average - SE<<"\n";
    cout<<setprecision(9)<<"time taken: "<<time_taken<<"s\n";
    
    return 0;
}
