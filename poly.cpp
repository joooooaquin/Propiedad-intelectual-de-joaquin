#include <iostream>
#include <cstdlib>
#include <math.h> //later use of π.
#include <ctime>
#include <iomanip> //to give pi the precision i want and know better the accuracy.
using namespace std;

int poly() {
    
    int i, p;
    //double distance;
    double sum_poly = 0;
    int iterations1 = pow(10, 6);
    int iterations2 = pow(10, 3);
    double points_poly;
    float poly;
    //time_t start, end;
    double list[iterations2];  //defining important variables that i'll use later.
    
    //float A = 0;
    //float n = 0;
    float z;
    //float min = 0;
    //float max = 0;
    //cout<<"Enter a value for A for a polynomial in the form Ax^n\n";
    //cin>>A;
    //cout<<"Now, enter a value for n for a polynomial in the form ax^n\n";
    //cin>>n;
    //cout<<"Give a value for the low boundary of the integral\n";
    //cin>>min;
    //cout<<"Give a value for the upper boundary of the integral\n";
    //cin>>max;
    z = 0.125*abs(pow(2, 6));

    for (p = 0; p < iterations2; p++){
        points_poly = 0;
        for (i = 0; i < iterations1; i++){
            double x = static_cast<double>(rand()) / (RAND_MAX/2);
            double y = static_cast<double>(rand()) / (RAND_MAX/8);
            //cout<<y<<"\n";
            
            if (y <= 0.125*pow(x, 6))
            {points_poly++;}
        }
        poly = ((points_poly/iterations1) * 16);
        sum_poly += poly;
        list[p] = poly;
    }
    float averageP = sum_poly / iterations2;
    cout<<setprecision(15)<<"average Ax^n for "<<iterations2<<" iterations is "<<averageP<<"\n";
    
    double sum_squared_difP = 0;
    for (int j=0; j < iterations2; j++){
        sum_squared_difP += pow(list[j] - averageP, 2);
    }
    double stdevP = sqrt(sum_squared_difP/(iterations2 -  1));
    
    double SEp = stdevP/sqrt(iterations2); //standard error simple calculation
    cout<<"=== STANDARD ERROR IS "<<SEp<<" ===\n";
    //cout<<setprecision(9)<<"time taken: "<<time_taken<<"s\n";
    cout<<"== aproximation with SE is =="<<averageP + SEp<<" or "<<averageP - SEp<<"\n";
    
        return 0;
}
