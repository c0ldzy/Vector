#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <stack>
#include <map>
#include <iomanip>

using namespace std;

// #define double long double

#define double int

class Vector // or Point
{
    double x, y;

public:

    Vector(double X, double Y);
    Vector();

    double get_x() { return x; }
    double get_y() { return y; }
    void set_x(double X) { x = X; }
    void set_y(double Y) { y = Y; }

    Vector operator+(Vector); // сложение
    Vector operator-(Vector); // вычитание
    Vector operator*(double); // умножение на число
    //Vector operator/(double); // деление на число
    double operator*(Vector); // скалярное
    double operator/(Vector); // косое

    double len2() {return x * x + y * y;}
    double angle(Vector a);

    bool operator==(Vector);
    bool operator!=(Vector);

    friend ostream& operator<<(ostream& out, const Vector& a);

};

Vector::Vector(double X, double Y)
{
    x = X;
    y = Y;
}

Vector::Vector()
{
    x = 0;
    y = 0;
}

Vector Vector::operator+(Vector a)
{
    return Vector(x + a.x, y + a.y);
}

Vector Vector::operator-(Vector a)
{
    return Vector(x - a.x, y - a.y);
}

Vector Vector::operator*(double a)
{
    return Vector(x * a, y * a);
}

/*Vector Vector::operator/(double a)
{
    if(a == 0)
    {
        cout << "error, entered 0" << endl;
        a = 1; // not to have errors with 0, just change nothing
    }

    return Vector(x / a, y / a);
}*/

double Vector::operator*(Vector a)
{
    return x * a.x + y * a.y;
}

double Vector::operator/(Vector a)
{
    return x * a.y - y * a.x;
}

double angle(Vector a)
{

}

bool Vector::operator==(Vector a)
{
    if(x == a.x && y == a.y) return 1;
    return 0;
}

bool Vector::operator!=(Vector a)
{
    if(x == a.x && y == a.y) return 0;
    return 1;
}

ostream& operator<<(ostream& out, const Vector& a)
{
    return out << '(' << a.x << '; ' << a.y << ')' << endl;
}



int main()
{
    cout << "Here u can do some stuff with vectors" << endl;
    cout << "Ur vectors will be A and B" << endl;

    double x, y;

    cout << "Enter A coordinates" << endl;
    cin >> x >> y;
    Vector A(x, y);

    cout << "Enter B coordinates" << endl;
    cin >> x >> y;
    Vector B(x, y);

    int u;
    cout << "Enter a random number from 10 to 20 (preferably 17)" << endl;

    cout << "A" << " ";


    return 0;
}
