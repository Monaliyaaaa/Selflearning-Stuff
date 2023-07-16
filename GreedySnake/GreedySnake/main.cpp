#include <iostream>;
#include <conio.h>;

using namespace std;

bool gameOver;
const int width = 50;
const int height = 20;
int x, y, fruitX, fruitY, score;
enum Direction {STOP=0,LEFT,RIGHT,UP,DOWN};
Direction dir;
int nTail;
int tailX[100], tailY[100];

void setUp()
{
	gameOver = false;
	x = width / 2;
	y = height / 2;
	fruitX = rand() % width;
	fruitY = rand() % height;
	score = 0;
	dir = STOP;
	nTail = 1;
}

void draw()
{
	system("cls");
	for (int i = 0; i <= width+1; i++)
	{
	   cout << "#";		
	}
	cout << endl;
	for (int i = 0; i < height; i++)
	{   
		cout << "#";
		for (int j = 0; j < width; j++)
		{
			
			if (j == fruitX && i == fruitY)
			{
				cout << "@";
			}
			else if (j == x && i == y)
			{
				cout << "O";
			}
			else
			{
				bool kk = false;
				for (int k = 1; k < nTail; k++)
				{

					if (j == tailX[k] && i == tailY[k])
					{
						cout << "o";
						kk = true;
					}
					
				}
				if (!kk)
				{
                   cout << " ";
				}
				
			}
		}
		cout << "#"<<endl;
		
	}
	for (int i = 0; i <= width+1; i++)
	{
		cout << "#";
	}
	cout << endl;
	cout << "socre= "<<score;
}

void input()
{
	if (_kbhit)
	{
		switch (_getch())
		{
			case 'a':
			     dir = LEFT;
			     break;
			case 'w':
				dir = UP;
				break;
			case 's':
				dir = DOWN;
				break;
			case 'd':
				dir = RIGHT;
				break;
			case 'x':
				gameOver = true;
				break;
		}

		
	}
}

void logic()
{
	 tailX[0] = x;
	tailY[0] = y;
	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X, prev2Y;
    

	for (int i = 1; i < nTail; i++)
	{
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}

	switch (dir)
	{
	case STOP:
		break;
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	}

	if (x<0 || x==width || y<0 || y==height)
		{
			gameOver = true;
		}
	else if (x == fruitX && y == fruitY)
		{
			score += 10;
			fruitX = rand() % width;
			fruitY = rand() % height;
			nTail++;
		}
	for (int i = 0; i < nTail; i++)
	{
		if (x == tailX[i] && y == tailY[i])
		{
			gameOver = true;
		}
	}
}

void play()
{
	setUp();
	while (!gameOver)
	{
		draw();
		input();
		logic();
	}
    cout <<endl<< "GAMEOVER!!!!"<<endl;
	cout << "Type 1 to try again, or press 2 to exit." << endl;
	if (_kbhit)
	{
		switch (_getch())
		{
		case '1':
			play();
			break;
		case '2':
			break;
		default:
			cout << "please press the right button." << endl;
		}
	}
}

int main()
{
	play();	
}