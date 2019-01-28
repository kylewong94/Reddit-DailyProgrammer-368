////////////////////////////////////////////
//Name:  Kyle Wong
//Title: Grid Class
//Description:
//Generates a grid of size "n" and fills with 
//a random order of X's and O's.
//Returns a value of 0 1 to show if
//solvable.
////////////////////////////////////////////
#ifndef _GRID_
#define _GRID_

#include <stdlib.h>
#include <stdio.h>
class Grid
{
	private:
	int n;
	int GridNo;
	unsigned char * GridImage;
	int AxisAlignVal = 0; 
	int XValueCheck   = 352;
	int OValueCheck   = 316; 

	public:

	Grid();
	~Grid();

////////////////////////////////////////////
// Main Functions 
////////////////////////////////////////////
	void Generate(int nValue);

////////////////////////////////////////////
// Utilites 
////////////////////////////////////////////
	int RandNum();
	void Print();
	bool SolveX();
	bool SolveO();
	void Solvable();

};

#endif
