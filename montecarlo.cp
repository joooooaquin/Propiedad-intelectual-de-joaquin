#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <iomanip> //to give pi the precision i want and know better the accuracy.
using namespace std;

int main() {
    
    srand(static_cast<unsigned>(time(0))); //seed for the generation of random x and y.
    
    int i, u;
    double distance;
    double sum_pi = 0;
    double points_circle;
    int iterations1 = pow(10, 5);
    int iterations2 = pow(10, 3); //this are the iterations for N and M.
    float pi;
    time_t start, end;
    double list[iterations2];  //defining important variables that i'll use later.
    
    time(&start); // for fun, I want to check how much time the code takes to run.
    for (u = 0; u < iterations2; u++){ //for loop for the u iterations of the pi estimation. U is set previously.
       
        points_circle = 0; // reset points_circle for each iteration
        
        for (i = 0; i < iterations1; i++) //for loop for the "points" for the estimation of pi. i is defined previously.
        {
            double x = static_cast<double>(rand()) / RAND_MAX;
            double y = static_cast<double>(rand()) / RAND_MAX; //random generation of the coodinates x and y of the point.
            distance = sqrt(x*x + y*y); //calculation of the distance from the origin created by x and y, which is the hypotenuse.
            
            if (distance <= 1) {
                points_circle++; //add 1 if the distance is less or equal to 1; it means that the point is within the circumference.
            }
        }
        pi = (points_circle / iterations1) * 4; //the formula for the estimation of π.
        sum_pi += pi; //this is the sum of all M πs. each time the loop runs, I add the last π value to the previus sum.
        //cout<<pi<<"\n";
        
        list[u] = pi;
        //cout<<setprecision(10)<<list[u]<<"\n";
    }
    time(&end);
    float time_taken = float (end-start); //calculation of the time.
    
    float average = sum_pi / iterations2; //calutation of the average for the iterations.
    cout<<setprecision(15)<<"average π for "<<iterations2<<" iterations is "<<average<<"\n";
    
    //calculation of sample standard deviation:
    double sum_squared_dif = 0; //I define the summatory of the sample minus the average all squared.
    
    for (int j = 0; j < iterations2; j++){ //for loop to append all te values of pi into the list to then calculate the sum of the squared difference.
        sum_squared_dif += pow(list[j] - average, 2); //calculation of the summatory of the squared difference.
    }
    double stdev = sqrt(sum_squared_dif/(iterations2 -  1)); //putting all the parts of the sample standard deviation formula together.
    
    //cout<<"s = "<<stdev<<"\n";
    
    double SE = stdev/sqrt(iterations2); //standard error simple calculation
    cout<<"=== STANDARD ERROR IS "<<SE<<" ===\n";
    cout<<setprecision(9)<<"time taken: "<<time_taken<<"s\n"; //printing the standard error value for π and the time taken to run the code.
    
    
    //circle calculation with given r and previously estimated π.
    int r;//=2; //For personally running the code, I set r equal to 2 to avoid an imput so everything runs fluently.
    double area, volume;
    float SEa, SEv; //defining the radius fo the circle and sphere, which are the same.
    
    cout<<"Enter a value for the radius:\n"; //asking the user to enter a value for the radius of the circle and the sphere.
    cin>>r;
    area = average*r*r; //calculation of the area with given r and the π i got.
    SEa = SE*4*r*r; //calculation of the standard error of the area of the circle, using SEπ*r^2*4.
    cout<<setprecision(15)<<"The area of a circle with given radius r = "<<r<<" is "<<area<<" u^2.\n===STANDARD ERROR OF THE AREA IS "<<SEa<<"===\n\n";
    volume = average*(4/3)*r*r*r; //using the formula for the volume that I got after working with the algebra on paper; instead of working in 2-d I did it in 3-d.
    SEv = SE*8*r*r*r; //the same with the standard error of the volume of the circle, using SEπ*r^3*8.
    cout<<setprecision(15)<<"The volume of a sphere with given radius r = "<<r<<" is "<<volume<<" u^3.\n=== STANDARD ERROR OF THE VOLUME IS "<<SEv<<"===\n";
    
    
    return 0;
}
 
