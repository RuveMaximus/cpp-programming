#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

using namespace std;

class Point
{
public:
	float x, y;
	Point(const float& x, const float& y)
	{
		this->x = x; 
		this->y = y;
	}
	Point()
	{
		this->x = 0;
		this->y = 0;
	}
	
	float distanceTo(const Point& p)
	{
		return sqrt(pow((p.x-this->x), 2) + pow((p.y-this->y), 2));
	}
};

class Triangle
{
public:
	Point A, B, C;

	Triangle(const Point& A, const Point& B, const Point& C)
	{
		this->A = A;
		this->B = B;
		this->C = C;	
	}

	float area()
	{
		const float AB = this->A.distanceTo(this->B);
		const float AC = this->A.distanceTo(this->C);
		const float BC = this->B.distanceTo(this->C);
		
		const float p = (AB+AC+BC)/2;
		
		return sqrt(p*(p-AB)*(p-AC)*(p-BC));
	}	
};

int main()
{
	ifstream cin("input.txt");
	
	vector <Point> points;
	float x, y;
	while (!cin.eof())
	{
		cin >> x >> y;
		points.push_back(Point(x, y));
	}
	cout << points[0].x << endl;

	return 0;
}
