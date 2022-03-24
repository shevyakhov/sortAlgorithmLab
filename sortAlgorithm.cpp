

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
		if (resultX == 0) {
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
		if (resultX == 0) {
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
		if (resultX == 0) {
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
		if (resultX == 0) {
			int resultY = p1.y - p2.y;
			return resultY <= 0;
		}
		else
			return false;
}

template <class T> class Sort
{
public:
	void checkIfSortedAsc(T** Array, int* ia, int size, string name) {
		bool flag = true;
		for (int i = 0; i < size-1; i++)
		{
			if (*Array[ia[i]] < *Array[ia[i + 1]]) {
				flag = false;
				break;
			}
		}
		if (flag) {
			cout << name + " Array sorted right" << endl;
		}
		else {
			cout << name + "Array sorted wrond" << endl;
		}
		
	}
	void checkIfSortedDesc(T** Array, int* ia, int size, string name) {
		bool flag = true;
		for (int i = 0; i < size-1; i++)
		{
			if (*Array[ia[i]] > *Array[ia[i + 1]]) {
				flag = false;
				break;
			}
		}
		if (flag) {
			cout << name +" Array sorted right" << endl;
		}
		else {
			cout << name + "Array sorted wrond" << endl;
		}
	}
	void SortByShell(T** Array, int* ia, int size)
	{
		int distance;
		for (distance = 0; distance <= size / 9; distance = distance * 3 + 1);
		while (distance >=1 )
		{
			for (int i = distance; i < size; i++) {
				for (int j = i - distance; j >= 0 && *Array[ia[j]] > *Array[ia[j + distance]]; j -= distance) {
					swap(ia[j], ia[j + distance]);
				}
			}
			distance = (distance - 1) / 3;
		}
	}
	void PyramidSort(T** Array, int* ia, int size)
	{
		int i, newSizeEnd, start=0;
		for (i = size / 2; i >= 0; i--) // all rows except last one
		{
			doHeaping(Array,ia, i, size - 1);
		}
		for (newSizeEnd = size - 1; newSizeEnd >= 1; newSizeEnd--)
		{
			swap(ia[start], ia[newSizeEnd]);
			doHeaping(Array,ia, start, newSizeEnd - 1);
		}
	}
	
	

private:
	void doHeaping(T** Array,int*ia, int i, int size)
	{
		int top = i, sonInd = i * 2 + 1; // first son
		while (sonInd <= size)
		{
			if (sonInd < size && *Array[ia[sonInd + 1]] > *Array[ia[sonInd]] ) {
				sonInd++; // choose biggest son
			} 
			if (*Array[ia[sonInd]] > *Array[ia[top]] )
			{
				swap(ia[top], ia[sonInd]); 
				top = sonInd; 
				sonInd = sonInd * 2 + 1;
			}
			else break;
		}

	}
};

void pointPyramid(int n) {
	Point* p = new Point[n];
	int* ia = new int[n];
	for (int i = 0; i < n; i++)
	{
		Point point;
		p[i] = point;
		ia[i] = i;
	}
	Point** arr = new Point * [n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = &p[i];
	}
	srand(time(0));
	Sort<Point> sort;
	sort.PyramidSort(arr, ia, n);
	cout << "Piramid sort of point array done in: " << clock() / 1000.0 << " seconds" << endl;
	srand(time(0));
	sort.checkIfSortedDesc(arr, ia, n, "Pyramid sort of point");
}
void pointShell(int n) {
	Point* p = new Point[n];
	int* ia = new int[n];
	for (int i = 0; i < n; i++)
	{
		Point point;
		p[i] = point;
		ia[i] = i;
	}
	Point** arr = new Point * [n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = &p[i];
	}
	srand(time(0));
	Sort<Point> sort;
	sort.SortByShell(arr, ia, n);
	cout << "Shell sort of point array done in: " << clock() / 1000.0 << " seconds" << endl;
	srand(time(0));
	sort.checkIfSortedDesc(arr, ia, n, "Shell sort of point");
}
void intAscPyramid(int n) {
	//// ASC ARRAY
	int* p = new int[n];
	int* ia = new int[n];
	for (int i = 0; i < n; i++)
	{
		p[i] = i;
		ia[i] = i;
	}
	int** arr = new int * [n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = &p[i];
	}
	srand(time(0));
	Sort<int> sort;
	sort.PyramidSort(arr,ia, n);
	cout << "Pyramid sort of asc array done in: " << clock() / 1000.0 << " seconds" << endl;
	srand(time(0));
	sort.checkIfSortedDesc(arr, ia, n, "Pyramid sort of asc");
	//////

}
void intAscShell(int n) {
	//// ASC ARRAY
	int* p = new int[n];
	int* ia = new int[n];
	for (int i = 0; i < n; i++)
	{
		p[i] = i;
		ia[i] = i;
	}
	int** arr = new int * [n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = &p[i];
	}
	srand(time(0));
	Sort<int> sort;
	sort.SortByShell(arr,ia, n);
	cout << "Shell sort of asc array done in: " << clock() / 1000.0 << " seconds" << endl;
	srand(time(0));
	sort.checkIfSortedDesc(arr,ia,n, "Shell sort of asc");
	//////
	

}

void intDescPyramid(int n) {
	//// Desc ARRAY
	int* p = new int[n];
	int* ia = new int[n];
	for (int i = 0; i < n; i++)
	{
		p[i] = n - 1 - i;
		ia[i] = i;
	}
	int** arr = new int* [n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = &p[i];
	}
	srand(time(0));
	Sort<int> sort;
	sort.PyramidSort(arr, ia, n);
	cout << "Pyramid sort of desc array done in: " << clock() / 1000.0 << " seconds" << endl;
	srand(time(0));
	//////
	sort.checkIfSortedDesc(arr, ia, n, "Pyramid sort of Desc");

}
void intDescShell(int n) {
	//// Desc ARRAY
	int* p = new int[n];
	int* ia = new int[n];
	for (int i = 0; i < n; i++)
	{
		p[i] = n-1-i;
		ia[i] = i;
	}
	int** arr = new int * [n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = &p[i];
	}
	srand(time(0));
	Sort<int> sort;
	sort.SortByShell(arr,ia, n);
	cout << "Shell sort of desc array done in: " << clock() / 1000.0 << " seconds" << endl;
	srand(time(0));
	//////
	sort.checkIfSortedDesc(arr, ia, n, "Shell sort of Desc");

}

void intRandPyramid(int n) {
	//// random ARRAY
	int* p = new int[n];
	int* ia = new int[n];
	for (int i = 0; i < n; i++)
	{
		p[i] = rand() / ((RAND_MAX + 1u) / 100);
		ia[i] = i;
	}
	int** arr = new int* [n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = &p[i];
	}
	srand(time(0));
	Sort<int> sort;
	sort.PyramidSort(arr, ia, n);
	cout << "Pyramid sort of random array done in: " << clock() / 1000.0 << " seconds" << endl;
	srand(time(0));
	//////
	sort.checkIfSortedDesc(arr, ia, n, "Pyramid sort of random");

}
void intRandShell(int n) {
	//// random ARRAY
	int* p = new int[n];
	int* ia = new int[n];
	for (int i = 0; i < n; i++)
	{
		p[i] = rand() / ((RAND_MAX + 1u) / 100);
		ia[i] = i;
	}
	int** arr = new int * [n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = &p[i];
	}
	srand(time(0));
	Sort<int> sort;
	sort.SortByShell(arr,ia, n);
	cout << "Shell sort of random array done in: " << clock() / 1000.0 << " seconds" << endl;
	srand(time(0));
	//////
	sort.checkIfSortedDesc(arr, ia, n, "Shell sort of random");

}
int main()
{
	srand((unsigned)time(NULL));
	int n = 1000000;

	pointPyramid(n);
	pointShell(n);
	cout << endl;
	intAscPyramid(n);
	intAscShell(n);
	cout << endl;
	intDescPyramid(n);
	intDescShell(n);
	cout << endl;
	intRandPyramid(n);
	intRandShell(n);
	cout << endl;


}

// for printing
//for (int i = 0; i < n; i++)
//{
//	cout << *arr[ia[i]] << " ";
//}
