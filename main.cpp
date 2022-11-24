#include<iostream>
#include<Windows.h>
#include<string>
#include"conio.h"
#include <ctime>
#include <cstdlib>
#include<fstream>
using namespace std;

string m_SaveAddress;
string m_Background[30][30];
void forBG(string m_Background[30][30]);
void snakeDead();
void saveGame();			//保存游戏分数
void saveAddress();
int randomNumer_X();
int randomNumer_Y();
int snakeGoOut();
int middleInput();
int playerDoWork();
int SnakeAddSize = 0;				//蛇的长度
string blackBlock = "■";
int snake_X = 0;
int snake_Y = 0;
int m_Fraction = 0;		//得分
int oldSnake_X = 0;
int oldSnake_Y = 0;
bool isHaveAdd = false;

void background()		//初始化地图边界
{

	string m_Background[30][30] = {};
	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 30; j++)
		{
			if (i == 0 || i == 29)
			{
				m_Background[i][j] = "■";
			}
			else
			{
				if (j == 0 || j == 29)
				{
					m_Background[i][j] = "■";
				}
				else
				{
					m_Background[i][j] = "  ";
				}
			}
		}
	}
	forBG(m_Background);
	snake_X = 2;
	snake_Y = 2;
	m_Background[snake_X][snake_Y] = blackBlock;
	forBG(m_Background);

	/*ifstream ifs11;
	ifs11.open(m_SaveAddress, ios::in);
	if (ifs11.is_open() == true)
	{
		ifs11 >> m_Fraction;
	}
	ifs11.close();*/

	int firstFruit_X = randomNumer_X();
	int firstFruit_Y = randomNumer_Y();
	m_Background[firstFruit_Y][firstFruit_X] = blackBlock;		//地图中随机生成一个果实
	system("color 09");
	while (true)
	{

		switch (playerDoWork())
		{
		case 4:
			system("pause");
		D:			while (true)
		{
			int GoOut = 0;
			GoOut = snakeGoOut();
			if (GoOut > 0)
			{
				snakeDead();
				return;
			}

			if (snake_X + 1 == firstFruit_X & snake_Y == firstFruit_Y)		//判断是否吃到果子
			{
				SnakeAddSize += 1;		//蛇的长度加 1
				m_Fraction += 50;		//设置分数增加50
				m_Background[firstFruit_Y][firstFruit_X] = "  ";		//将吃完果实坐标设置为“  ”
				firstFruit_X = randomNumer_X();			//重新创建新果子--X轴
				firstFruit_Y = randomNumer_Y();			//重新创建新果子--Y轴
				m_Background[firstFruit_Y][firstFruit_X] = blackBlock;		//设置新的坐标为黑实心方块
			}


			switch (middleInput())
			{
			case 1:
				m_Background[snake_Y][snake_X - 1] = "  ";
				goto W;
				break;
			case 2:
				m_Background[snake_Y][snake_X - 1] = "  ";
				goto S;
				break;
			case 3:
				m_Background[snake_Y][snake_X - 1] = "  ";
				goto A;
				break;
			case 9:
				system("cls");
				system("color 06");
				cout << "\n\n\n\t\t\t已暂停！ 摁任意键继续\n\n" << endl;
				system("pause");
				system("color 09");
				break;
			case 10:
				saveGame();
				system("cls");
				system("color 06");
				cout << "\n\n\n\t\t\t保存成功！\n\n" << endl;
				system("pause");
				break;
			default:
				m_Background[snake_Y][snake_X - 1] = "  ";
				break;
			}
			m_Background[snake_Y][snake_X] = "  ";
			if (SnakeAddSize != 0)
			{
				oldSnake_X = snake_X;
				oldSnake_Y = snake_Y;
			}

			if (SnakeAddSize != 0)
			{
				m_Background[oldSnake_Y][oldSnake_X] = blackBlock;
				m_Background[oldSnake_Y][oldSnake_X - 1] = "  ";
			}
			snake_X += 1;
			m_Background[snake_Y][snake_X] = blackBlock;
			forBG(m_Background);
			Sleep(50);
		}
		case 3:
		A:			while (true)
		{
			if (snakeGoOut() == 1 || snakeGoOut() == 2)
			{
				snakeDead();
				return;
			}
			if (snake_X - 1 == firstFruit_X & snake_Y == firstFruit_Y)
			{
				m_Fraction += 50;
				m_Background[firstFruit_Y][firstFruit_X] = "  ";
				firstFruit_X = randomNumer_X();
				firstFruit_Y = randomNumer_Y();
				m_Background[firstFruit_Y][firstFruit_X] = blackBlock;
			}
			switch (middleInput())
			{
			case 1:
				m_Background[snake_Y][snake_X + 1] = "  ";
				goto W;
				break;
			case 2:
				m_Background[snake_Y][snake_X + 1] = "  ";
				goto S;
				break;
			case 4:
				m_Background[snake_Y][snake_X + 1] = "  ";
				goto D;
				break;
			case 9:
				system("cls");
				system("color 06");
				cout << "\n\n\n\t\t\t已暂停！ 摁任意键继续\n\n" << endl;
				system("pause");
				system("color 09");
				break;
			case 10:
				saveGame();
				system("cls");
				system("color 06");
				cout << "\n\n\n\t\t\t保存成功！\n\n" << endl;
				system("pause");
				break;
			default:
				break;
			}
			m_Background[snake_Y][snake_X] = "  ";
			if (SnakeAddSize != 0)
			{
				oldSnake_X = snake_X;
				oldSnake_Y = snake_Y;
			}
			if (SnakeAddSize != 0)
			{
				m_Background[oldSnake_Y][oldSnake_X] = blackBlock;
				m_Background[oldSnake_Y][oldSnake_X + 1] = "  ";
			}
			snake_X -= 1;
			m_Background[snake_Y][snake_X] = blackBlock;
			forBG(m_Background);
			Sleep(50);
		}
		case 2:
		S:			while (true)
		{
			if (snakeGoOut() == 1 || snakeGoOut() == 2)
			{
				snakeDead();
				return;
			}
			if (snake_X == firstFruit_X & snake_Y + 1 == firstFruit_Y)
			{
				m_Fraction += 50;
				m_Background[firstFruit_Y][firstFruit_X] = "  ";
				firstFruit_X = randomNumer_X();
				firstFruit_Y = randomNumer_Y();
				m_Background[firstFruit_Y][firstFruit_X] = blackBlock;
			}
			switch (middleInput())
			{
			case 1:
				m_Background[snake_Y - 1][snake_X] = "  ";
				goto W;
				break;
			case 3:
				m_Background[snake_Y - 1][snake_X] = "  ";
				goto A;
				break;
			case 4:
				m_Background[snake_Y - 1][snake_X] = "  ";
				goto D;
				break;
			case 9:
				system("cls");
				system("color 06");
				cout << "\n\n\n\t\t\t已暂停！ 摁任意键继续\n\n" << endl;
				system("pause");
				system("color 09");
				break;
			case 10:
				saveGame();
				system("cls");
				system("color 06");
				cout << "\n\n\n\t\t\t保存成功！\n\n" << endl;
				system("pause");
				break;
			default:
				break;
			}
			m_Background[snake_Y][snake_X] = "  ";
			if (SnakeAddSize != 0)
			{
				oldSnake_X = snake_X;
				oldSnake_Y = snake_Y;
			}
			if (SnakeAddSize != 0)
			{
				m_Background[oldSnake_Y][oldSnake_X] = blackBlock;
				m_Background[oldSnake_Y - 1][oldSnake_X] = "  ";
			}
			snake_Y += 1;
			m_Background[snake_Y][snake_X] = blackBlock;
			forBG(m_Background);
			Sleep(50);
		}
		case 1:
		W:		while (true)
		{
			if (snakeGoOut() == 1 || snakeGoOut() == 2)
			{
				snakeDead();
				return;
			}

			if (snake_X == firstFruit_X & snake_Y - 1 == firstFruit_Y)
			{
				m_Fraction += 50;
				m_Background[firstFruit_Y][firstFruit_X] = "  ";
				firstFruit_X = randomNumer_X();
				firstFruit_Y = randomNumer_Y();
				m_Background[firstFruit_Y][firstFruit_X] = blackBlock;
			}
			switch (middleInput())
			{
			case 2:
				m_Background[snake_Y + 1][snake_X] = "  ";
				goto S;
				break;
			case 3:
				m_Background[snake_Y + 1][snake_X] = "  ";
				goto A;
				break;
			case 4:
				m_Background[snake_Y + 1][snake_X] = "  ";
				goto D;
				break;
			case 9:
				system("cls");
				system("color 06");
				cout << "\n\n\n\t\t\t已暂停！ 摁任意键继续\n\n" << endl;
				system("pause");
				system("color 09");
				break;
			case 10:
				saveGame();
				system("cls");
				system("color 06");
				cout << "\n\n\n\t\t\t保存成功！\n\n" << endl;
				system("pause");
				break;
			default:
				break;
			}
			m_Background[snake_Y][snake_X] = "  ";
			if (SnakeAddSize != 0)
			{
				oldSnake_X = snake_X;
				oldSnake_Y = snake_Y;
			}
			if (SnakeAddSize != 0)
			{
				m_Background[oldSnake_Y][oldSnake_X] = blackBlock;
				m_Background[oldSnake_Y + 1][oldSnake_X] = "  ";
			}
			snake_Y -= 1;
			m_Background[snake_Y][snake_X] = blackBlock;
			forBG(m_Background);
			Sleep(50);
		}

		default:
			break;
		}


	}
}

int middleInput()		//判断用户中途输入
{
	char m_MiddleInput;
	while (kbhit())
	{
		m_MiddleInput = getch();
		if (m_MiddleInput == 'w')		//返回中途输入的值
		{
			return 1;
		}
		else if (m_MiddleInput == 's')
		{
			return 2;
		}
		else if (m_MiddleInput == 'a')
		{
			return 3;
		}
		else if (m_MiddleInput == 'd')
		{
			return 4;
		}
		else if (m_MiddleInput == 'p')
		{
			cout << "你点击了P" << endl;
			system("pause");
			return 9;
		}
		else if (m_MiddleInput == 'f')
		{
			cout << "你点击了F" << endl;
			system("pause");
			return 10;
		}
		else
		{
			return 200;
			break;
		}
	}
}

int snakeGoOut()			//判断蛇是否出界
{
	if (snake_X == 30 || snake_X == 0)
	{
		return 1;
	}
	else if (snake_Y == 30 || snake_Y == 0)
	{
		return 2;
	}
	else
	{
		return -1;
	}
}

int playerDoWork()		//获取玩家输入
{
	char playerInput;
	playerInput = getch();
	if (playerInput == 'w')
	{
		return 1;
	}
	else if (playerInput == 's')
	{
		return 2;
	}
	else if (playerInput == 'a')
	{
		return 3;
	}
	else if (playerInput == 'd')
	{
		return 4;
	}
}

void forBG(string m_Background[30][30])
{
	system("cls");
	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 30; j++)
		{
			cout << m_Background[i][j];
		}
		cout << "\n";
	}

	cout << "\n┍-----------------------得分如下-------------------------┑" << endl;
	cout << "\n\t\t\t" << "分数：" << m_Fraction << "\t\t\t\t \n" << endl;
	cout << "\t\t>>> 点击 p 键来暂停游戏！<<<" << endl;
	cout << "\t\t>>> 点击 f 键来保存游戏！<<<" << endl;
}

int randomNumer_X()			//设置X轴的随机数
{
	srand(time(0));
	return (rand() % (25 - 5 + 1)) + 5;
}

int randomNumer_Y()			//设置Y轴的随机数
{
	srand(time(0));
	return (rand() % (25 - 4 + 1)) + 4;
}

void snakeDead()			//蛇死了
{
	system("cls");
	system("color 04");
	cout << "\n\n\t\t你死了!\n\n\n" << endl;
	system("pause");
	return;
}

int menu()
{
	int num;
	cout << "\t\t蛇皮走位之闪烁的窗口" << endl;
	cout << "\t\t版权由WAT所有" << endl;
	cout << "\n\n\t\t1.开始游戏" << endl;
	cout << "\n\n\t\t2.编辑保存地址" << endl;
	cout << "\n\n\t\t0.退出游戏" << endl;
	cin >> num;
	if (num == 0)
	{
		return 0;
	}
	else if (num == 2)
	{
		return 2;
	}
	else if (num == 1)
	{
		system("cls");
		cout << "\n\n\t\t玩法说明：W:向上移动  S:向下移动 A:向左移动 D:向右移动\n\n\t\t[输入任意摁键开始游戏]\n" << endl;
		system("pause");
		return 1;
	}
}

void saveGame()			//保存游戏分数
{
	ofstream ofs;
	ofs.open(m_SaveAddress, ios::out);
	ofs << m_Fraction << endl;
	ofs.close();
}

void saveAddress()
{
	string addre;
	system("cls");
	cout << "\n\n\t\t请输入保存地址(回车即可保存)：";
	cin >> addre;
	m_SaveAddress = addre + "tcsGameSave.txt";
	isHaveAdd = true;
}

int main()
{
	while (true)
	{
		int myNum = menu();
		if (myNum == 0)
		{
			return 0;
		}
		else if (myNum == 1)
		{
			if (isHaveAdd)
			{
				background();
			}
			saveAddress();
			system("cls");
			continue;
		}
		else if (myNum == 2)
		{
			saveAddress();
		}
		system("cls");
	}

	cout << "\n" << endl;
	system("pause");
	return 0;
}
