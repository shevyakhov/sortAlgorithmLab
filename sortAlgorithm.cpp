

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Point
{
private:
	int x, y;

public:

	Point() {
		rand();
		x = 10 - (rand() / ((RAND_MAX + 1u) / 20));
		y = 10 - (rand() / ((RAND_MAX + 1u) / 20));
	}

	~Point() {

	}
	void print() {
		cout << this->x<< " "<< this->y << endl;
	}
	friend bool operator > (const Point& d1, const Point& d2);
	friend bool operator <= (const Point& d1, const Point& d2);

	friend bool operator < (const Point& d1, const Point& d2);
	friend bool operator >= (const Point& d1, const Point& d2);
};

bool operator> (const Point& p1, const Point& p2)
{
	int resultX = p1.x - p2.x;
	if (resultX > 0) {
		return true;
	} else
		if (resultX = 0) {
			int resultY = p1.y - p2.y;
			return resultY > 0;
		}
		else
			return false;
}

bool operator>= (const Point& p1, const Point& p2)
{

	int resultX = p1.x - p2.x;
	if (resultX > 0) {
		return true;
	}
	else
		if (resultX = 0) {
			int resultY = p1.y - p2.y;
			return resultY >= 0;
		}
		else
			return false;
}

bool operator< (const Point& p1, const Point& p2)
{
	int resultX = p1.x - p2.x;
	if (resultX < 0) {
		return true;
	}
	else
		if (resultX = 0) {
			int resultY = p1.y - p2.y;
			return resultY < 0;
		}
		else
			return false;
}

bool operator<= (const Point& p1, const Point& p2)
{
	int resultX = p1.x - p2.x;
	if (resultX < 0) {
		return true;
	}
	else
		if (resultX = 0) {
			int resultY = p1.y - p2.y;
			return resultY <= 0;
		}
		else
			return false;
}
int main()
{
	srand((unsigned)time(NULL));
	Point* point1, *point2, *point3, *point4, *point5;
	point1 = new Point;
	point2 = new Point;
	point3 = new Point;
	point4 = new Point;
	point5 = new Point;

	Point* array[5] = {point1,point2,point3,point4, point5};
	for (int i = 0; i < 5; i++)
	{
		array[i]->print();
	}
}

