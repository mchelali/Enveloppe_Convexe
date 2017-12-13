#include "VecteurPoint.h"

VecteurPoint::VecteurPoint()
{
	points = new vector<Point>;
}

void VecteurPoint::addPoint(Point x)
{
	this->points->push_back(x);
}

void VecteurPoint::modPoint(int pos, float x, float y)
{
	this->points->at(pos).modifierPoint(x, y);
}

void VecteurPoint::deletePoint(int x)
{
	this->points->erase(this->points->begin() + x );
}

void VecteurPoint::triePoint()
{
	sort(this->points->begin(), this->points->end());
}

int VecteurPoint::getPosPoint(Point x)
{
	int idx = 0;
	int a = x.getX();
	int b = x.getY();
	for (vector<Point>::iterator it = this->points->begin(); it != this->points->end(); ++it) {
		if ((it->getX() == a) && (it->getY() == b)) {
			return idx;
		}
		idx++;
	}
	return idx;
}

vector<int> VecteurPoint::argSort()
{
	int size(this->points->size());
	vector<int> idx;
	for (int i = 0; i < size; i++) {
		idx.push_back(i);
	}
	vector<Point> *points_copi = new vector<Point>();
	points_copi = this->points;
	this->triePoint();
	int i = 0;
	for (vector<Point>::iterator it = points_copi->begin(); it != points_copi->end(); ++it) {
		idx[i] = this->getPosPoint(*it);
		cout << this->getPosPoint(*it) << endl;
	}
	return idx;
}

Point VecteurPoint::getFirstPoint()
{
	return this->points->at(0);
}

Point VecteurPoint::at(int i)
{
	return this->points->at(i);
}

void VecteurPoint::afficheVecPoint()
{
	cout << "[";
	for (vector<Point>::iterator it = points->begin(); it != points->end(); ++it) {
		it->affichePoint();
	}
	cout << "]" << endl;
}

int VecteurPoint::getSize()
{
	return this->points->size();
}

VecteurPoint & VecteurPoint::operator=(VecteurPoint &vecp)
{
	this->points->clear();
	//this->points = new vector<Point>;
	for (int i = 0; i < vecp.getSize(); i++) {
		this->points->push_back(vecp.at(i));
	}
	return *this;
}

VecteurPoint::~VecteurPoint()
{
}
