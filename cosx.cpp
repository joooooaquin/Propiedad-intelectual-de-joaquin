#include <iostream>
#include <cstdlib>
#include <math.h> //later use of π.
#include <ctime>
#include <iomanip> //to give pi the precision i want and know better the accuracy.
using namespace std;

int cosx() { //maybe for running the codes, you'll need to change each function to main manually so each code runs.
    //two functions cannot be called main at the same time, or it will show as "build failed"
    int c, i;
    double sum = 0;
    int iterations1 = pow(10, 6);
    int iterations2 = pow(10, 3);
    double points;
    float cosine;
    double list[iterations2];
    time_t start, end;
    
    time(&start);
    for(c = 0; c < iterations2; c++){
        points = 0;
        
        for (i = 0; i < iterations1; i++)
        {
            double x = static_cast<double>(rand()) / (RAND_MAX/(M_PI/6));
            double y = static_cast<double>(rand()) / (RAND_MAX/1);
            
            if (y <= cos(x))
            {points++;}
        }
        cosine = (points/iterations1) * (M_PI/6);
        sum += cosine;
        list[c] = cosine;
    }
    time(&end);
    float time_taken = float (end-start); //calculation of the time.
    float average = sum / iterations2;
    cout<<setprecision(15)<<"average cosx for "<<iterations2<<" iterations is "<<average<<"\n";
    
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
