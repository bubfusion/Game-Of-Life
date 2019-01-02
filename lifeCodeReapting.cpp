#include<iostream>
#include<iomanip>

using namespace std;

int main()
{
  int cellgrid[20][20] = {0}; //creates the write grid
  int cellgridRead[20][20] = {0}; //creates the read grid
  int x; //user input for X
  int y; //user input for Y
  char cellCin = 'y'; //used for adding more cells
  char GOL = 'y'; //used for the loop that allows the player to stop the game
  bool GameOver = false; // Used if every cell is dead and returns true
  int days = 0; // holds the value of how many game days have passed
  int neighbors = 0; //holds number of neighbors for every cell
  int cellSum; //holds value of how many alive cells there are. If 0 GG

  cout << "Welcome to the Game of Life!" << endl;

  cout << "Please input where you would like to spawn your cells:" << endl;
  while(cellCin == 'Y' || cellCin == 'y') //loop that allows user to input mutliple cells before game start
  {
    cout << "Enter the x coordinate of the cell." << endl;
    cin >> x;

    cout << "Enter the y coordinate of the cell." << endl;
    cin >> y;

    cellgrid[y][x] = 1; //sets the corrosponding coordinate to 1 which represents an alive cell

    cout << "Enter more cells? Y/N" << endl;
    cin >> cellCin;
  }

  while((GOL == 'y' || GOL == 'Y') && GameOver == false) //loop used to end game if either game over returns false or the user no longer wants to play
  {
    for (int i = 0; i < 20; i++)
		{
			for(int j = 0; j < 20; j++)
			{
				cout << setw(2) << cellgrid[i][j]; //loop used to output the starting grid
			}
			cout << endl;
		}
    cout << endl;
    cout << endl; //two cout endls so each unique grid/day is seperated from each other

    for (int i = 0; i < 20; i++)
    {
			for(int j = 0; j < 20; j++)
      {
      	cellSum = cellSum + cellgrid[i][j]; //checks if there is no alive cells left
      }
    }

    if(cellSum == 0)
    {
      cout << "You lost the Game of Life after " << days << " days!" << endl; //if the cellSum is 0 then it ends the game
      return 1;
    }


    for (int i = 0; i < 20; i++)
    {

			for(int j = 0; j < 20; j++)
			{
          cellgridRead[i][j] = cellgrid[i][j]; //clones cellgrid to cellgridRead
      }
    }

    for (int i = 0; i < 20; i++)
    {

			for(int j = 0; j < 20; j++)
      {

        if(i+1 < 20 && cellgridRead[i+1][j] == 1) //checks directly down
          {
            neighbors = neighbors+1;
          }

        if(i+1 < 20 && j+1 < 20 && cellgridRead[i+1][j+1] == 1) //checks down and right
          {
            neighbors = neighbors+1;
          }

        if(j+1 < 20 && cellgridRead[i][j+1] == 1) //checks right
          {
            neighbors = neighbors+1;
          }

        if(i-1 > -1 && j+1 < 20 && cellgridRead[i-1][j+1] == 1) //checks upper right
          {
            neighbors = neighbors+1;
          }

        if(i-1 > -1 && cellgridRead[i-1][j] == 1) //checks directly above
          {
            neighbors = neighbors+1;
          }

        if(i-1 > -1 && j-1 > -1 && cellgridRead[i-1][j-1] == 1) //checks top left
          {
            neighbors = neighbors+1;
          }

        if(j-1 > -1 && cellgridRead[i][j-1] == 1) //checks left
          {
            neighbors = neighbors+1;
          }

        if(j-1 > -1 && i+1 < 20 && cellgridRead[i+1][j-1] == 1) //bottom left
          {
            neighbors = neighbors+1;
          }


				if(neighbors == 3 && cellgridRead[i][j] == 0)
        {
          cellgrid[i][j] = 1; //if a dead cell has 3 neighbors then it becomes alive
        }

        else if((neighbors == 2 || neighbors == 3) && cellgridRead[i][j] == 1)
        {
          cellgrid[i][j] = 1; //if an alive cell has exactly 2 or 3 neighbors then it stays alive
        }

        else
        {
          cellgrid[i][j] = 0; //else then the cell stays dead
        }

        neighbors = 0; //resets neighbors at the end of the loop
			}

		}

    for(int i = 0; i < 500000000; i++)
    {
      i = i; //just one giant loop the stalls a little time to create the animation
    }
    cellSum = 0;
    days = days + 1; //once the loop finishes it means that one successful day has gone so it adds one to the days var

  }

  cout << "You ended the Game of Life after " << days << " days!" << endl; //when the game finishes it outputs that the game ended and how many successful days passed
  return 0;
}
