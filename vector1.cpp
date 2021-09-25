//OLE4KA
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
#define ld long double

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

    float angle(Vector a) // float bcz doubles were defined to be int and I'm kinda lazy
    {
        float v1 = sqrt(float(x * x + y * y));
        float v2 = sqrt(float(a.x * a.x + a.y * a.y));
        return acos(float(x * a.x + y * a.y) / (v1 * v2));
    }

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
    return out << '(' << a.x << "; " << a.y << ')';
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
    cin >> u;

    cout << "A is " << A << endl;
    cout << "B is " << B << endl;

    cout << "A + B is " << A + B << endl;
    cout << "A - B is " << A - B << endl;

    cout << "A * 17 (yep ur number didnt matter, I'll use 17 anyway) is " << A * 17 << endl;

    cout << "scalar product is " << A * B << endl;
    cout << "pseudoscalar product is " << A / B << endl;

    cout << "A length squared is " << A.len2() << endl;
    cout << "B length squared is " << B.len2() << endl;

    cout << "Angle between A and B is " << A.angle(B) << " rad" << endl;

    cout << "A == B ?   ";
    if(A == B) cout << "yes" << endl;
    else cout << "no" << endl;




    return 0;
}
