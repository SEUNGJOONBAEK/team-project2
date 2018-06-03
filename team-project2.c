#include <iostream>
#include <Windows.h>
using namespace std;

#define X 9
#define Y 9

// 7x7 �̷� (������ �������� �Ϸ��� 9x9�ؼ� �� ����)
int maze[X][Y] = {
	{ '1','1','1','1','1','1','1','1','1' },
{ '1','e','0','0','0','1','0','1','1' },
{ '1','0','0','0','0','1','0','0','1' },
{ '1','0','1','1','1','0','0','0','1' },
{ '1','0','0','0','1','0','0','1','1' },
{ '1','0','1','0','0','0','0','0','1' },
{ '1','0','0','1','0','0','0','1','1' },
{ '1','0','0','1','x','0','0','0','1' },
{ '1','1','1','1','1','1','1','1','1' }
};

int movement(int * x, int * y)
{
	int x1 = *x;
	int   y1 = *y;

	if (maze[x1][y1] == '1')
	{
		cout << "�̵��� �� �����ϴ�." << endl;
		return -1;
	}
	else if (maze[x1][y1] == 'x')
	{
		cout << "Ż�� ����" << endl;
		maze[x1][y1] = 'e';
		return 1;
	}
	else
	{
		cout << "�̵� ���� " << endl;
		maze[x1][y1] = 'e';
		return 0;
	}
}


int main(void)
{
	char next;
	int x = 1, y = 1;
	int count = 0;
	for (int i = 0; i < X; i++) {
		for (int j = 0; j < Y; j++) {
			if (maze[i][j] == '1') // ��
				cout << "��";
			else if (maze[i][j] == '0')
				cout << "  ";
			else if (maze[i][j] == 'x') // ������
				cout << "��";
			else if (maze[i][j] == 'e') // �����
				cout << "��";
		}
		cout << endl;
	}

	Sleep(3000); // 3�ʰ� �����ݴϴ�
	system("cls"); // �����

	for (int i = 0; i < X; i++) {
		for (int j = 0; j < Y; j++) {
			if (maze[i][j] == '1')
				cout << "  ";
			else if (maze[i][j] == '0')
				cout << "  ";
			else if (maze[i][j] == 'x')
				cout << "��";
			else if (maze[i][j] == 'e')
				cout << "��";
		}
		cout << endl;
	}

	cout << endl;
	cout << "==============\"������ �����մϴ�\"==================\n" << endl;
	char direct;
	cout << "������ �Է��ϼ���(U,D,R,L) : ";
	cin >> direct;

	while (1)
	{
		int win;
		count++;
		switch (direct)
		{
		case 'l':
			y--;
			win = movement(&x, &y);
			if (win == 0 || win == 1)
				maze[x][y + 1] = '0';
			else if (win == -1)
				y++;
			break;
		case 'r':
			y++;
			win = movement(&x, &y);
			if (win == 0 || win == 1)
				maze[x][y - 1] = '0';
			else if (win == -1)
				y--;
			break;
		case 'd':
			x++;
			win = movement(&x, &y);
			if (win == 0 || win == 1)
				maze[x - 1][y] = '0';
			else if (win == -1)
				x--;
			break;
		case 'u':
			x--;
			win = movement(&x, &y);
			if (win == 0 || win == 1)
				maze[x + 1][y] = '0';
			else if (win == -1)
				x++;
			break;
		default:
			break;
		}

		if (win == 1)
		{
			system("cls"); // �����
			for (int i = 0; i < X; i++) {
				for (int j = 0; j < Y; j++) {
					if (maze[i][j] == '1') // ��
						cout << "��";
					else if (maze[i][j] == '0')
						cout << "  ";
					else if (maze[i][j] == 'x') // ������
						cout << "��";
					else if (maze[i][j] == 'e') // �����
						cout << "��";
				}
				cout << endl;
			}
			cout << endl;
			cout << count << "�ϸ��� Ż���ϼ̽��ϴ�." << endl;
			cout << endl;
			break;
		}

		//cout << "���� ���� �����Ϸ��� �ƹ� Ű�� �Է����ּ���.";
		cin >> next;
		system("cls"); // �����

		for (int i = 0; i < X; i++) {
			for (int j = 0; j < Y; j++) {
				if (maze[i][j] == '1')
					cout << "  ";
				else if (maze[i][j] == '0')
					cout << "  ";
				else if (maze[i][j] == 'x')
					cout << "��";
				else if (maze[i][j] == 'e')
					cout << "��";
			}
			cout << endl;
		}
		cout << endl;
		cout << "������ �Է��ϼ���(U,D,R,L) : ";
		cin >> direct;
	}
}