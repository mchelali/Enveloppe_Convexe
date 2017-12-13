#include "Vecteur.h"

Vecteur::Vecteur()
{
	this->a = new Point();
	this->b = new Point();
	this->x = 0;
	this->y = 0;
	this->theta = 0;
	this->det = 0;
}

Vecteur::Vecteur(Point A, Point B)
{
	this->a = new Point();
	this->b = new Point();
	this->a->setX(A.getX());
	this->a->setY(A.getY());
	this->b->setX(B.getX());
	this->b->setY(B.getY());
	this->x = B.getX() - A.getX();
	this->y = B.getY() - A.getY();
	this->theta = this->angle();
	this->det = this->determinant();
}

Vecteur::Vecteur(int x1, int x2, int y1, int y2)
{
	this->a = new Point(x1, y1);
	this->b = new Point(x2, y2);
	this->x = x2 - x1;
	this->y = y2 - y1;
	this->theta = this->angle();
	this->det = this->determinant();
}

float Vecteur::getTheta()
{
	return this->theta;
}

float Vecteur::getDet()
{
	return this->det;
}

float Vecteur::getx()
{
	return this->x;
}

float Vecteur::gety()
{
	return this->y;
}

void Vecteur::afficherVecteur()
{
	std::cout << "Coordonnees du vecteur est [" << this->x << ", " << this->y << "] " << std::endl ;
}

float Vecteur::determinant()
{
	return sqrt(x*x+y*y);
}

float Vecteur::angle()
{	
	if (this->x > 0) {
		if (this->y >= 0) {
			return atan(this->y / this->x);
		}
		else {
			return atan(this->y / this->x) + 2 * 3.14;
		}
	}else if(this->x == 0) {
		if (this->y >= 0) {
			return 3.14/2;
		}
		else {
			return 3*3.14/2;
		}
	}
	else {
		return atan(this->y / this->x) + 3.14;
	}
}

float Vecteur::produitSclaire(Vecteur A)
{
	return (this->x * A.getx() + this->y * A.gety());
}

float Vecteur::puissance(Point c)
{
	//dy(x_p - x_a) - dx(y_p - y_a)
	return (this->y *(c.getX() - this->a->getX())) - ( this->x * (c.getY() - this->a->getY()) );
}

bool Vecteur::operator<(Vecteur vec1)
{
	if ( this->theta < vec1.getTheta() ) {
		return true;
	}
	else if (this->theta == vec1.getTheta()) {
		if (this->det <= vec1.getDet()) {
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

Vecteur::~Vecteur()
{
}
