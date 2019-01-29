#include <stdlib.h>
#include <stdio.h>
#include "Grid.h"

int main()
{


	Grid	Randomized_Grid;
	//Generates grid size of 5x5 with randomized X and Os
	Randomized_Grid.Generate(6);
	
	//Solves Grid 
	Randomized_Grid.Solvable();
}

