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
	bool X = SolveX();
	bool O = SolveO();

	if (X == true)
	{
		printf("\nGrid is not a valid output, four cells X's or O's formed a square \n");
	}
	else if (O == true)
	{
		printf("\nGrid is not a valid output, four cells X's or O's formed a square\n");
	}
	else
	{
		printf("\nGrid is a valid output no four cells formed a square\n");
	}
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
	//Search by Left-Down Diagonal Gradient
	int BoundMax = n;
	for (int TileNo = 0; TileNo < n-2; TileNo++)
		{
			GridNo = TileNo*n + TileNo;
			for(int GapCheck = 1; GapCheck < BoundMax; GapCheck++)
			{
				AxisAlignVal = 0;
			
				AxisAlignVal += int(GridImage[TileNo*n + (TileNo + GapCheck)]);
		
				AxisAlignVal += int(GridImage[(TileNo + GapCheck)*n + (TileNo + GapCheck)]);

				AxisAlignVal += int(GridImage[(TileNo + GapCheck)*n + TileNo]);

				AxisAlignVal += int(GridImage[GridNo]);

				if (AxisAlignVal == XValueCheck)
				{
					return true;
				}
			}
			BoundMax--;
		}	

	//Search by Right Down Diagonal Gradient
	BoundMax = n;
	for (int TileNo = n - 1; TileNo > 0; TileNo--)
		{
			GridNo = TileNo*n + TileNo;
			for(int GapCheck = 1; GapCheck < BoundMax; GapCheck++)
			{
				AxisAlignVal = 0;
	
				AxisAlignVal += int(GridImage[TileNo*n + (TileNo - GapCheck)]);

				AxisAlignVal += int(GridImage[(TileNo - GapCheck)*n + (TileNo - GapCheck)]);

				AxisAlignVal += int(GridImage[(TileNo - GapCheck)*n + TileNo]);

				AxisAlignVal += int(GridImage[GridNo]);

				if(AxisAlignVal == XValueCheck)
				{
					return true;
				}
			}
			BoundMax--;
		}

	//Search By Column
	for (int ColNo = 0; ColNo < n - 1; ColNo++)
		{
			for(int RowNo = 0; RowNo < n - 1; RowNo++)
			{
				GridNo = RowNo*n + ColNo;
				
				AxisAlignVal = 0;
		
				AxisAlignVal += int(GridImage[RowNo*n + (ColNo + 1)]);

				AxisAlignVal += int(GridImage[(RowNo+1)*n + ColNo]);

				AxisAlignVal += int(GridImage[(RowNo+1)*n + ColNo+1]);
				
				AxisAlignVal += int(GridImage[GridNo]);

				if(AxisAlignVal == XValueCheck)
				{
					return true;
				}
			}
		}
	//Searches Failed
	return false;
}

////////////////////////////////////////////////////////////////////////////
bool Grid::SolveO()
{
	//Search by Left-Down Diagonal Gradient
	int BoundMax = n;
	for (int TileNo = 0; TileNo < n-2; TileNo++)
		{
			GridNo = TileNo*n + TileNo;
			for(int GapCheck = 1; GapCheck < BoundMax; GapCheck++)
			{
				AxisAlignVal = 0;
			
				AxisAlignVal += int(GridImage[TileNo*n + (TileNo + GapCheck)]);
		
				AxisAlignVal += int(GridImage[(TileNo + GapCheck)*n + (TileNo + GapCheck)]);

				AxisAlignVal += int(GridImage[(TileNo + GapCheck)*n + TileNo]);

				AxisAlignVal += int(GridImage[GridNo]);

				if (AxisAlignVal == OValueCheck)
				{
					return true;
				}
			}
			BoundMax--;
		}	

	//Search by Right Down Diagonal Gradient
	BoundMax = n;
	for (int TileNo = n - 1; TileNo > 0; TileNo--)
		{
			GridNo = TileNo*n + TileNo;
			for(int GapCheck = 1; GapCheck < BoundMax; GapCheck++)
			{
				AxisAlignVal = 0;
	
				AxisAlignVal += int(GridImage[TileNo*n + (TileNo - GapCheck)]);

				AxisAlignVal += int(GridImage[(TileNo - GapCheck)*n + (TileNo - GapCheck)]);

				AxisAlignVal += int(GridImage[(TileNo - GapCheck)*n + TileNo]);

				AxisAlignVal += int(GridImage[GridNo]);

				if(AxisAlignVal == OValueCheck)
				{
					return true;
				}
			}
			BoundMax--;
		}

	//Search By Column
	for (int ColNo = 0; ColNo < n - 1; ColNo++)
		{
			for(int RowNo = 0; RowNo < n - 1; RowNo++)
			{
				GridNo = RowNo*n + ColNo;
				
				AxisAlignVal = 0;
		
				AxisAlignVal += int(GridImage[RowNo*n + (ColNo + 1)]);

				AxisAlignVal += int(GridImage[(RowNo+1)*n + ColNo]);

				AxisAlignVal += int(GridImage[(RowNo+1)*n + ColNo+1]);
				
				AxisAlignVal += int(GridImage[GridNo]);

				if(AxisAlignVal == OValueCheck)
				{
					return true;
				}
			}
		}
	//Searches Failed
	return false;
}


