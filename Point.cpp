#include "Point.h"


Point::Point()
{
	this->x = 0;
	this->y = 0;
}


Point::Point(float a, float b) {
	this->x = a;
	this->y = b;
}


float Point::getX() {
	return this->x;
}


void Point::setX(float a) {
	this->x = a;
}

float Point::getY() {
	return this->y;
}

void Point::setY(float b) {
	this->y = b;
}

void Point::modifierPoint(float a, float b)
{
	this->x = a;
	this->y = b;
}

float Point::distanceEUC(Point c) {
	float dx = ( (float) c.getY() ) - ( (float) this->getX() );
	float dy = ( (float) c.getY() ) - ( (float) this->getY() );
	return sqrt(dx*dx + dy*dy);
}

void Point::affichePoint()
{
	std::cout << "[" << this->x << " , " << this->y << "]";
}

bool Point::operator<(Point p2)
{
	if (this->x < p2.getX()) {
		if (this->y < p2.getY()) {
			return true;
		}
		else {
			return false;
		}

	}
	else {
		if (this->y < p2.getY()) {
			return true;
		}
		else {
			return false;
		}
	}
}

bool Point::operator>(Point p2)
{
	if (this->x > p2.getX()) {
		if (this->y >= p2.getY()) {
			return true;
		}
		else {
			return false;
		}
		
	}
	else {
		return false;
	}
}

bool Point::operator==(Point p2)
{
	if (this->x == p2.getX() && this->y == p2.getY()) {
		return true;
	}
	else {
		return false;
	}
}

Point Point::operator=(Point p2)
{
	this->x = p2.getX();
	this->y = p2.getY();
	return *this;
}

bool Point::operator!=(Point p2)
{
	if (this->x != p2.getX() && this->y != p2.getY()) {
		return true;
	}
	else {
		return false;
	}
}

Point::~Point()
{
}
