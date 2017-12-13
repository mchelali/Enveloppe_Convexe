#pragma once
#include<math.h>
#include<iostream>

class Point
{
private:
	float x;
	float y;
public:
	Point();
	Point(float a, float b);
	float getX();
	void setX(float a);
	float getY();
	void setY(float b);
	void modifierPoint(float a, float b);
	float distanceEUC(Point c);
	void affichePoint();
	bool operator <(Point p2);
	bool operator >(Point p2);
	bool operator ==(Point p2);
	Point operator =(Point p2);
	bool operator !=(Point p2);
	~Point();
};

