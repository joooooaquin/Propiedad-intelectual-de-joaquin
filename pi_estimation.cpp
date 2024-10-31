#include<iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

int main()
{
    int i, n;
    double x, y, distance;
    double points_circle = 0;
    double points_total = 0;
    double pi = 0;

    cout << "Points: ";
    cin >> n;

    for (i = 0; i < n; i++)
    {
        x = rand();
        y = rand();
        distance = x * x + y * y;

        if (distance <= 1) {
            points_circle++;
        } else {
            points_total++;
        }

        pi = (points_circle / points_total) * 4;
        cout << "\n" << pi;
    }

    return 0;
}
