#include "VecteurPoint.h"
#include<vector>
#include <algorithm> 
#include<string>
#include<fstream>

using namespace std;

class Polygone
{
private:
	VecteurPoint vecPoints;
	VecteurPoint convexZone;
public:
	Polygone();
	void addVecPoints(VecteurPoint vecp);
	void addPoints(Point p);
	void affichePolygone();
	void afficheConvexe();
	void lanchGraham();
	void drawPolygoneConvexe(string path);
	~Polygone();
};

