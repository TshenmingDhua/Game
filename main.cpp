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
void saveGame();			//������Ϸ����
void saveAddress();
int randomNumer_X();
int randomNumer_Y();
int snakeGoOut();
int middleInput();
int playerDoWork();
int SnakeAddSize = 0;				//�ߵĳ���
string blackBlock = "��";
int snake_X = 0;
int snake_Y = 0;
int m_Fraction = 0;		//�÷�
int oldSnake_X = 0;
int oldSnake_Y = 0;
bool isHaveAdd = false;

void background()		//��ʼ����ͼ�߽�
{

	string m_Background[30][30] = {};
	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 30; j++)
		{
			if (i == 0 || i == 29)
			{
				m_Background[i][j] = "��";
			}
			else
			{
				if (j == 0 || j == 29)
				{
					m_Background[i][j] = "��";
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
	m_Background[firstFruit_Y][firstFruit_X] = blackBlock;		//��ͼ���������һ����ʵ
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

			if (snake_X + 1 == firstFruit_X & snake_Y == firstFruit_Y)		//�ж��Ƿ�Ե�����
			{
				SnakeAddSize += 1;		//�ߵĳ��ȼ� 1
				m_Fraction += 50;		//���÷�������50
				m_Background[firstFruit_Y][firstFruit_X] = "  ";		//�������ʵ��������Ϊ��  ��
				firstFruit_X = randomNumer_X();			//���´����¹���--X��
				firstFruit_Y = randomNumer_Y();			//���´����¹���--Y��
				m_Background[firstFruit_Y][firstFruit_X] = blackBlock;		//�����µ�����Ϊ��ʵ�ķ���
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
				cout << "\n\n\n\t\t\t����ͣ�� �����������\n\n" << endl;
				system("pause");
				system("color 09");
				break;
			case 10:
				saveGame();
				system("cls");
				system("color 06");
				cout << "\n\n\n\t\t\t����ɹ���\n\n" << endl;
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
				cout << "\n\n\n\t\t\t����ͣ�� �����������\n\n" << endl;
				system("pause");
				system("color 09");
				break;
			case 10:
				saveGame();
				system("cls");
				system("color 06");
				cout << "\n\n\n\t\t\t����ɹ���\n\n" << endl;
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
				cout << "\n\n\n\t\t\t����ͣ�� �����������\n\n" << endl;
				system("pause");
				system("color 09");
				break;
			case 10:
				saveGame();
				system("cls");
				system("color 06");
				cout << "\n\n\n\t\t\t����ɹ���\n\n" << endl;
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
				cout << "\n\n\n\t\t\t����ͣ�� �����������\n\n" << endl;
				system("pause");
				system("color 09");
				break;
			case 10:
				saveGame();
				system("cls");
				system("color 06");
				cout << "\n\n\n\t\t\t����ɹ���\n\n" << endl;
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

int middleInput()		//�ж��û���;����
{
	char m_MiddleInput;
	while (kbhit())
	{
		m_MiddleInput = getch();
		if (m_MiddleInput == 'w')		//������;�����ֵ
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
			cout << "������P" << endl;
			system("pause");
			return 9;
		}
		else if (m_MiddleInput == 'f')
		{
			cout << "������F" << endl;
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

int snakeGoOut()			//�ж����Ƿ����
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

int playerDoWork()		//��ȡ�������
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

	cout << "\n��-----------------------�÷�����-------------------------��" << endl;
	cout << "\n\t\t\t" << "������" << m_Fraction << "\t\t\t\t \n" << endl;
	cout << "\t\t>>> ��� p ������ͣ��Ϸ��<<<" << endl;
	cout << "\t\t>>> ��� f ����������Ϸ��<<<" << endl;
}

int randomNumer_X()			//����X��������
{
	srand(time(0));
	return (rand() % (25 - 5 + 1)) + 5;
}

int randomNumer_Y()			//����Y��������
{
	srand(time(0));
	return (rand() % (25 - 4 + 1)) + 4;
}

void snakeDead()			//������
{
	system("cls");
	system("color 04");
	cout << "\n\n\t\t������!\n\n\n" << endl;
	system("pause");
	return;
}

int menu()
{
	int num;
	cout << "\t\t��Ƥ��λ֮��˸�Ĵ���" << endl;
	cout << "\t\t��Ȩ��WAT����" << endl;
	cout << "\n\n\t\t1.��ʼ��Ϸ" << endl;
	cout << "\n\n\t\t2.�༭�����ַ" << endl;
	cout << "\n\n\t\t0.�˳���Ϸ" << endl;
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
		cout << "\n\n\t\t�淨˵����W:�����ƶ�  S:�����ƶ� A:�����ƶ� D:�����ƶ�\n\n\t\t[��������������ʼ��Ϸ]\n" << endl;
		system("pause");
		return 1;
	}
}

void saveGame()			//������Ϸ����
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
	cout << "\n\n\t\t�����뱣���ַ(�س����ɱ���)��";
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
