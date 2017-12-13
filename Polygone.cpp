#include "Polygone.h"

Polygone::Polygone()
{
	
}

void Polygone::addVecPoints(VecteurPoint vecp)
{
	this->vecPoints = vecp;
}

void Polygone::addPoints(Point p)
{
	this->vecPoints.addPoint(p);
}

void Polygone::affichePolygone()
{
	this->vecPoints.afficheVecPoint();
}

void Polygone::afficheConvexe()
{
	this->convexZone.afficheVecPoint();
}

void Polygone::lanchGraham()
{
	// Algorithme de Graham pour calculer l'envelope convexe du polygone
	Point init;//detection du point initial (x_min, y_min)
	this->vecPoints.triePoint();
	this->affichePolygone();
	init = this->vecPoints.getFirstPoint();
	cout << "Point initial selectione : ";
	init.affichePoint();
	vector<Vecteur> coordPolair;
	// calculer les coordonn�es polaires de tous les vecteurs par le point initial
	for (int i = 1; i < this->vecPoints.getSize(); i++) {
		Vecteur vec(init, this->vecPoints.at(i));
		coordPolair.push_back(vec);
	}
	cout << "\ncoordonee polaire : ";
	sort(coordPolair.begin(), coordPolair.end());//trie par rapport au coordone polaire (theta seulement)

	//saisir les point du polygone dans l'ordre du tri polaire
	for (int i = 1; i < this->vecPoints.getSize(); i++) {
		this->vecPoints.modPoint(i, coordPolair.at(i - 1).getx() + init.getX(), coordPolair.at(i - 1).gety() + init.getY());
	}
	this->affichePolygone();//Visualisation des resultats
	cout << "Start Algo of Grahm " << endl;
	this->convexZone = this->vecPoints;
	int k = 0;
	do
	{
		cout << "k = " << k << endl;
		if ( (k+2) < (this->convexZone.getSize()-1)) {
			Vecteur vec(this->convexZone.at(k), this->convexZone.at(k + 2));
			if (vec.puissance(this->convexZone.at(k + 1)) > 0) {
				cout << "k++" << endl;
				k++;
			}
			else {
				this->convexZone.deletePoint(k + 1);
				cout << "k--" << endl;
				k = k - 1;
			}
		}
		else
		{
			k = -1;
		}

	} while (k != -1);
	cout << "k = " << k << endl;
	cout << "les points du polygone :" << endl;
	this->affichePolygone();
	cout << "la zone convexe est :" << endl;
	this->afficheConvexe();
	
}

void Polygone::drawPolygoneConvexe(string path)
{
	int offset = 1;
	string filename = path+"/Points.ps";
	cout << filename.c_str() << endl;
	ofstream output(filename.c_str());
	output << "%!PS-Adobe-3.0" << endl;
	output << endl;

	// deffinir le point de l'origine
	output << 0 << " " << 0 << " 2 0 360 arc" << endl;
	output << "0 setgray" << endl;
	output << "fill" << endl;
	output << 0 + offset << " " << 0 + offset << " moveto" << endl;
	output << "/Courier findfont" << endl << "11 scalefont" << endl << "setfont" << endl;
	output << "( O(0,0) )" << " show" << endl;
	output << "stroke" << endl;
	output << endl;

	//dessiner le polygone entier
	int size = this->vecPoints.getSize();
	for (int i = 0; i < size; i++) {
		int offset = 0, scale = 40;
		float x1 = this->vecPoints.at(i).getX();
		float y1 = this->vecPoints.at(i).getY();
		if (i == 0) {
			output << x1*scale << " " << y1*scale << " 4 0 360 arc" << endl;
			output << "0 setgray" << endl;
			output << "fill" << endl;
			output << (x1 + offset)*scale << " " << y1*scale << " moveto" << endl;
			output << "/Courier findfont" << endl << "11 scalefont" << endl << "setfont" << endl;
			output << "( P(" << x1 <<", " << y1 << ") )" << " show" << endl;
			output << "stroke" << endl;
		}
		else {
			float x = this->vecPoints.at(i-1).getX();
			float y = this->vecPoints.at(i-1).getY();
			
			//on trace le sommet i
			output << x1*scale << " " << y1*scale << " 4 0 360 arc" << endl;
			output << "0 setgray" << endl;
			output << "fill" << endl;
			output << (x1 + offset)*scale << " " << y*scale << " moveto" << endl;
			output << "/Courier findfont" << endl << "11 scalefont" << endl << "setfont" << endl;
			output << "( P(" << x << ", " << y << ") )" << " show" << endl;
			output << "stroke" << endl;

			//on relie le sommet i avec le sommet i-1
			output << x*scale << " " << y*scale << " moveto" << endl;
			output << x1*scale << " " << y1*scale << " lineto" << endl;
			output << "stroke" << endl;

		}
		if (i == this->vecPoints.getSize()-1) {
			//on relie le sommet 0 avec le dernier sommet 
			output << this->vecPoints.at(0).getX() * scale << " " << this->vecPoints.at(0).getY() * scale << " moveto" << endl;
			output << x1 * scale << " " << y1 * scale << " lineto" << endl;
			output << "stroke" << endl;
		}
		
	}


	//Dessiner l'enveloppe convexe
	size = this->convexZone.getSize();
	for (int i = 0; i < size; i++) {
		int offset = 0, scale = 40;
		float x1 = this->convexZone.at(i).getX();
		float y1 = this->convexZone.at(i).getY();
		if (i == 0) {
			output << x1*scale << " " << y1*scale << " 5 0 360 arc" << endl;
			output << "1 0 0 setrgbcolor" << endl;
			output << "fill" << endl;
			output << "stroke" << endl;
		}
		else {
			float x = this->convexZone.at(i - 1).getX();
			float y = this->convexZone.at(i - 1).getY();

			//on trace le sommet i
			output << x1*scale << " " << y1*scale << " 5 0 360 arc" << endl;
			output << "1 0 0 setrgbcolor" << endl;
			output << "fill" << endl;
			output << "stroke" << endl;

			//on relie le sommet i avec le sommet i-1
			output << x*scale << " " << y*scale << " moveto" << endl;
			output << x1*scale << " " << y1*scale << " lineto" << endl;
			output << "1 0 0 setrgbcolor" << endl;
			output << "stroke" << endl;

		}
		if (i == this->vecPoints.getSize() - 1) {
			//on relie le sommet 0 avec le dernier sommet 
			output << this->convexZone.at(0).getX() * scale << " " << this->convexZone.at(0).getY() * scale << " moveto" << endl;
			output << x1 * scale << " " << y1 * scale << " lineto" << endl;
			output << "1 0 0 setrgbcolor" << endl;
			output << "stroke" << endl;
		}

	}

	output << endl;

	output.close();
}

Polygone::~Polygone()
{
}
