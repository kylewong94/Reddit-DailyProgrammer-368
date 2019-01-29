////////////////////////////////////////////
//Name:  Kyle Wong
//Title: Grid Class
//Description:
//Generates a grid of size "n" and fills with 
//a random order of X's and O's.
//Returns a value of 0 1 to show if
//solvable.
///////////////////////////////////////////
#include "Grid.h"
#include <ctime>

////////////////////////////////////////////////////////////////////////////
// MAIN FUNCTIONS
////////////////////////////////////////////////////////////////////////////
Grid::Grid()
{
}

Grid::~Grid()
{
	delete [] GridImage;
}

////////////////////////////////////////////////////////////////////////////
void Grid::Generate(int nValue)
{
	int RandVal;

	n = nValue;

	GridImage = new unsigned char [n*n];

	srand (time(NULL));

	for(int RowNo = 0; RowNo < n; RowNo++)
	{
		for(int ColNo = 0; ColNo < n; ColNo++)
		{
			RandVal = RandNum();
			GridNo = RowNo*n + ColNo;

			if(RandVal == 0)
			{
				GridImage[GridNo] = 'O';
			}

			else if(RandVal == 1)
			{
				GridImage[GridNo] = 'X';
			}

			else
			{
				printf("\n !!!Error found in file Grid.cpp, value is not a 0 or 1, return value: %c !!! \n", RandVal);
				printf("\n Exiting Program \n");
				exit(1);	
			}
		}
	}	
	
	Print();
}
////////////////////////////////////////////////////////////////////////////
void Grid::Solvable()
{
}
////////////////////////////////////////////////////////////////////////////
// UTILITIES
////////////////////////////////////////////////////////////////////////////
int Grid::RandNum()
{
	int RandVal = rand()%2;
	return RandVal;	
	
}
////////////////////////////////////////////////////////////////////////////

void Grid::Print()
{
	for(int RowNo = 0; RowNo < n; RowNo++)
	{
		for(int ColNo = 0; ColNo < n; ColNo++)
		{
			GridNo = RowNo*n + ColNo;
			if(GridNo%n == 0)
			{
				printf("\n%c ", GridImage[GridNo]);
			}
			else
			{
				printf("%c ", GridImage[GridNo]);
			}
		}
	}
	printf("\n");
}

////////////////////////////////////////////////////////////////////////////
bool Grid::SolveX()
{
	
}

////////////////////////////////////////////////////////////////////////////
bool Grid::SolveO()
{

}


