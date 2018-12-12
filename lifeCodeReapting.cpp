#include<iostream>
#include<iomanip>

using namespace std;

int main()
{
  int cellgrid[20][20] = {0};
  int cellgridRead[20][20] = {0};
  int x;
  int y;
  char cellCin = 'y';
  char GOL = 'y';
  bool GameOver = false;
  int days = 0;
  int neighbors = 0;
  int cellSum;

  cout << "Welcome to the Game of Life!" << endl;

  cout << "Please input where you would like to spawn your cells:" << endl;
  while(cellCin == 'Y' || cellCin == 'y')
  {
    cout << "Enter the x coordinate of the cell." << endl;
    cin >> x;

    cout << "Enter the y coordinate of the cell." << endl;
    cin >> y;

    cellgrid[y][x] = 1;

    cout << "Enter more cells? Y/N" << endl;
    cin >> cellCin;
  }

  while((GOL == 'y' || GOL == 'Y') && GameOver == false)
  {
    for (int i = 0; i < 20; i++)
		{
			for(int j = 0; j < 20; j++)
			{
				cout << setw(2) << cellgrid[i][j];
			}
			cout << endl;
		}

    for (int i = 0; i < 20; i++)
    {
			for(int j = 0; j < 20; j++)
      {
      	cellSum = cellSum + cellgrid[i][j];
      }
    }

    if(cellSum == 0)
    {
      cout << "You lost the Game of Life after " << days << " days!" << endl;
      return 1;
    }


    for (int i = 0; i < 20; i++)
    {

			for(int j = 0; j < 20; j++)
			{
          cellgridRead[i][j] = cellgrid[i][j];
      }
    }

    for (int i = 0; i < 20; i++)
    {

			for(int j = 0; j < 20; j++)
      {

        if(i+1 < 20 && cellgridRead[i+1][j] == 1)
          {
            neighbors = neighbors+1;
          }

        if(i+1 < 20 && j+1 < 20 && cellgridRead[i+1][j+1] == 1)
          {
            neighbors = neighbors+1;
          }

        if(j+1 < 20 && cellgridRead[i][j+1] == 1)
          {
            neighbors = neighbors+1;
          }

        if(i-1 > -1 && j+1 < 20 && cellgridRead[i-1][j+1] == 1)
          {
            neighbors = neighbors+1;
          }

        if(i-1 > -1 && cellgridRead[i-1][j] == 1)
          {
            neighbors = neighbors+1;
          }

        if(i-1 > -1 && j-1 > -1 && cellgridRead[i-1][j-1] == 1)
          {
            neighbors = neighbors+1;
          }

        if(j-1 > -1 && cellgridRead[i][j-1] == 1)
          {
            neighbors = neighbors+1;
          }

        if(j-1 > -1 && i+1 < 20 && cellgridRead[i+1][j-1] == 1)
          {
            neighbors = neighbors+1;
          }


				if(neighbors == 3 && cellgridRead[i][j] == 0)
        {
          cellgrid[i][j] = 1;
        }

        else if((neighbors == 2 || neighbors == 3) && cellgridRead[i][j] == 1)
        {
          cellgrid[i][j] = 1;
        }

        else
        {
          cellgrid[i][j] = 0;
        }

        neighbors = 0;
			}

		}

    for(int i = 0; i < 1000000000; i++)
    {
      i = i;
    }
    cellSum = 0;
    days = days + 1;

  }

  cout << "You ended the Game of Life after " << days << " days!" << endl;
  return 0;
}
