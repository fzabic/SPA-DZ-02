#include "game_of_life.h"

game_of_life::game_of_life()
{
	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++)
		{
			if (i==0||i==REDAKA-1|| j == 0 || j == STUPACA - 1)
			{
				_sljedeca_generacija[i][j] = false;
			}
			else
			{
				_sljedeca_generacija[i][j] = slucajna_vrijednost();
			}
		}
	}
}

bool game_of_life::slucajna_vrijednost()
{
	if (rand() % 4 == 0)
	{
		return true;
	}

    return false;
}

bool game_of_life::celija_zauzeta(int i, int j)
{
	if (_generacija[i][j])
	{
		return true;
	}
    return false;
}


void game_of_life::sljedeca_generacija()
{
	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++)
		{
			int counter = 0;
			
			if (_generacija[i-1][j] && i!=0)
			{
				counter++;
			}
			if (_generacija[i-1][j+1] && i!=0 && j!=STUPACA-1)
			{
				counter++;
			}
			if (_generacija[i-1][j-1] && i!=0 && j!=0)
			{
				counter++;
			}
			if (_generacija[i][j+1] && j!=STUPACA-1)
			{
				counter++;
			}
			if (_generacija[i][j-1] && j!=0)
			{
				counter++;
			}
			if (_generacija[i+1][j] && i!=REDAKA-1)
			{
				counter++;
			}
			if (_generacija[i+1][j+1] && i!= REDAKA-1 && j!= STUPACA-1)
			{
				counter++;
			}
			if (_generacija[i+1][j-1] && i!=REDAKA && j!=0)
			{
				counter++;
			}
			
			if (!celija_zauzeta(i, j))
			{
				if (counter == 3)
				{
					_sljedeca_generacija[i][j] = true;
				}
				else
				{
					_sljedeca_generacija[i][j] = false;
				}
			}

			if(celija_zauzeta(i, j))
			{
				if (counter < 2 || counter > 3)
				{
					_sljedeca_generacija[i][j] = false;
				}
				else
				{
					_sljedeca_generacija[i][j] = true;
				}
			}
		}
	}
}

void game_of_life::iscrtaj()
{
	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++)
		{
			_generacija[i][j] = _sljedeca_generacija[i][j];
		}
	}

	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++)
		{
			if (_generacija[i][j])
			{
				cout << "*";
			}
			else
			{
				cout << "-";
			}
		}
		cout << endl;
	}
}
