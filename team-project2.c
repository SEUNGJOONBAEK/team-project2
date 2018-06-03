#include <iostream>
#include <Windows.h>
using namespace std;

#define X 9
#define Y 9

// 7x7 미로 (밖으로 못나가게 하려고 9x9해서 벽 막음)
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
		cout << "이동할 수 없습니다." << endl;
		return -1;
	}
	else if (maze[x1][y1] == 'x')
	{
		cout << "탈출 성공" << endl;
		maze[x1][y1] = 'e';
		return 1;
	}
	else
	{
		cout << "이동 성공 " << endl;
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
			if (maze[i][j] == '1') // 벽
				cout << "■";
			else if (maze[i][j] == '0')
				cout << "  ";
			else if (maze[i][j] == 'x') // 도착점
				cout << "★";
			else if (maze[i][j] == 'e') // 출발점
				cout << "◎";
		}
		cout << endl;
	}

	Sleep(3000); // 3초간 보여줍니다
	system("cls"); // 지우기

	for (int i = 0; i < X; i++) {
		for (int j = 0; j < Y; j++) {
			if (maze[i][j] == '1')
				cout << "  ";
			else if (maze[i][j] == '0')
				cout << "  ";
			else if (maze[i][j] == 'x')
				cout << "★";
			else if (maze[i][j] == 'e')
				cout << "◎";
		}
		cout << endl;
	}

	cout << endl;
	cout << "==============\"게임을 시작합니다\"==================\n" << endl;
	char direct;
	cout << "방향을 입력하세요(U,D,R,L) : ";
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
			system("cls"); // 지우기
			for (int i = 0; i < X; i++) {
				for (int j = 0; j < Y; j++) {
					if (maze[i][j] == '1') // 벽
						cout << "■";
					else if (maze[i][j] == '0')
						cout << "  ";
					else if (maze[i][j] == 'x') // 도착점
						cout << "★";
					else if (maze[i][j] == 'e') // 출발점
						cout << "◎";
				}
				cout << endl;
			}
			cout << endl;
			cout << count << "턴만에 탈출하셨습니다." << endl;
			cout << endl;
			break;
		}

		//cout << "다음 턴을 진행하려면 아무 키나 입력해주세요.";
		cin >> next;
		system("cls"); // 지우기

		for (int i = 0; i < X; i++) {
			for (int j = 0; j < Y; j++) {
				if (maze[i][j] == '1')
					cout << "  ";
				else if (maze[i][j] == '0')
					cout << "  ";
				else if (maze[i][j] == 'x')
					cout << "★";
				else if (maze[i][j] == 'e')
					cout << "◎";
			}
			cout << endl;
		}
		cout << endl;
		cout << "방향을 입력하세요(U,D,R,L) : ";
		cin >> direct;
	}
}