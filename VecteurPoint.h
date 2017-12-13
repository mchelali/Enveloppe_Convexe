#pragma once
#include<vector>
#include <algorithm> 
#include "Point.h"
#include"Vecteur.h"

using namespace std;

class VecteurPoint
{
private:
	vector<Point> *points;
public:
	VecteurPoint();
	void addPoint(Point x);
	void modPoint(int pos,float x, float y);
	void deletePoint(int x);
	void triePoint();
	int getPosPoint(Point x);
	vector<int> argSort();
	Point getFirstPoint();
	Point at(int i);
	void afficheVecPoint();
	int getSize();
	VecteurPoint &operator=(VecteurPoint &vecp);
	~VecteurPoint();
};

