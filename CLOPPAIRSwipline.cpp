#include <iostream>
#include<bits/stdc++.h>
using namespace std;

struct point
{
	long double x, y;

	int index;
};

point makepoint(int x, int y, int i)
{
	point temp;

	temp.x = x;
	temp.y = y;
	temp.index = i;

	return temp;
}

bool compareX(point a, point b)
{
	return a.x < b.x;
}

double dist(point p1,point p2)
{
    return sqrt((p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y));
}

void fastscan(int &number)
{
	bool negative = false;
	register int c;
	number = 0;
	c = getchar();
	if (c == '-')
	{
		negative = true;
		c = getchar();
	}
	// Keep on extracting characters if they are integers
	// i.e ASCII Value lies from '0'(48) to '9' (57)
	for (; (c > 47 && c < 58); c = getchar())
		number = number * 10 + c - 48;
	if (negative)
		number *= -1;
}
int main()
{
	int n;
	//fastscan(n);
	// added the two lines below 
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
	cin >> n;
	point points[n];
	int x, y;

	for (int i = 0; i < n; i++)
	{
		cin >> x >> y; //fastscan(x);
		//cin >> y; //fastscan(y);
		points[i] = makepoint(x, y, i);
	}
	sort(points, points + n, compareX);

	int min;
	int minX; 
	int minY;
	point temp
	temp.x = 
	min = dist();
	cout << min << "minnn " << endl;
	for (int i = 2; i < n; i++)
	{
		cout<< points[i].x << "," << points[i].y << " ver" << endl;
	}
	return 0;
}
