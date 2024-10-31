#include <iostream>
#include <cstdlib>
#include <math.h> //later use of π.
#include <ctime>
#include <iomanip> //to give pi the precision i want and know better the accuracy.
using namespace std;

int sinx(){
    int s, i;
    double sum = 0;
    int iterations1 = pow(10, 6);
    int iterations2 = pow(10, 3);
    double points;
    float sine;
    double list[iterations2];
    time_t start, end;
    
    time(&start);
    for (s = 0; s < iterations2; s++){ //for loop for the u iterations of the pi estimation. U is set previously.
        points = 0; // reset points_circle for each iteration
        
        for (i = 0; i < iterations1; i++) //for loop for the "points" for the estimation of pi. i is defined previously.
        {
            double x = static_cast<double>(rand()) / (RAND_MAX/M_PI);
            //cout<<x<<"x\n";
            double y = 0 + static_cast<double>(rand()) / (RAND_MAX/1); //random generation of the coodinates x and y of the point.
            
            if (y <= sin(x)) {
                points++; //add 1 if the distance is less or equal to 1; it means that the point is within the circumference.
            }
        }
        sine = (points / iterations1) * M_PI; //the formula for the estimation of π.
        sum += sine; //this is the sum of all M πs. each time the loop runs, I add the last π value to the previus sum.
        //cout<<sum_e<<"\n";
        //cout<<points_e<<"\n";
        
        list[s]=sine;
    }
    time(&end);
    float time_taken = float (end-start); //calculation of the time.
    
    float average = sum / iterations2; //calutation of the average for the iterations.
    cout<<setprecision(15)<<"average integral of sinx for "<<iterations2<<" iterations from o to π is\n"<<average<<"\n";
    
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
