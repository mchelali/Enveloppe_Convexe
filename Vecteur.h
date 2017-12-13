#pragma once
#include "Point.h"
#include<iostream>
#include<math.h>

class Vecteur
{
private:
	Point *a;
	Point *b;
	float x;
	float y;
	float theta;//l'angle du vecteur
	float det;//determinant du vecteur
public:
	Vecteur();
	Vecteur(Point A, Point B);
	Vecteur(int x1, int x2, int y1, int y2);
	float getTheta();
	float getDet();
	float getx();
	float gety();
	void afficherVecteur();
	float determinant();
	float angle();
	float produitSclaire(Vecteur A);
	float puissance(Point c);
	bool operator<(Vecteur vec1);
	~Vecteur();
};

/*
ponte
puissance
produit scalaire
*/