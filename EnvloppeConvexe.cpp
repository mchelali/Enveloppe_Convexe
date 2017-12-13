//============================================================================
// Name        : EnvloppeConvexe.cpp
// Author      : Ro0t34
// Version     :
// Copyright   : Au service de la science
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
#include"Point.h"
#include"Vecteur.h"
#include"VecteurPoint.h"
#include"Polygone.h"


using namespace std;

int main() {
	VecteurPoint vecp;
	vecp.addPoint(Point(8, 9));
	vecp.addPoint(Point(8, 7));
	vecp.addPoint(Point(7, 5));
	vecp.addPoint(Point(10, 6));
	vecp.addPoint(Point(11, 3));
	vecp.addPoint(Point(9, 4));
	vecp.addPoint(Point(1, 6));
	vecp.addPoint(Point(3, 1));
	vecp.addPoint(Point(2, 3));
	vecp.addPoint(Point(5, 4));
	vecp.addPoint(Point(6, 8));
	vecp.addPoint(Point(4, 8));
	vecp.afficheVecPoint();

	Polygone poly;
	poly.addVecPoints(vecp);
	poly.affichePolygone();
	poly.lanchGraham();
	poly.drawPolygoneConvexe("/home/ro0t34/Desktop/");//il faut donner le chemin ou on vas sauvegarder le fichier
	return 0;
}
