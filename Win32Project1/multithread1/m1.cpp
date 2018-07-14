#include<Windows.h>
#include<process.h>
#include<stddef.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>

void Bounce(void* ch);
void CheckKey(void *dummy);


/*获得一个min和max直接的随机数*/

#define GetRandom(min,max) (rand() %(int)(((max) + x) - (min)))+ min))

BOOL repeat = TRUE;

HANDLE hStdOut;

CONSOLE_SCREEN_BUFFER_INFO csbi;


void main()
{
	CHAR ch = 'A';
	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hStdOut, &csbi);

	_beginthread(CheckKey, 0, NULL);

	while (repeat)
	{
		_beginthread(Bounce, 0, (void*)(ch++));

		Sleep(1000);
	}

}


void CheckKey(void* dummy)
{
	_getch();
	repeat = 0;
}

void Bounce(void *ch)
{
	char blankcell = 0x20;
	char blockcell = (char)ch;
	BOOL first = TRUE;

	COORD oldcoord, newcoord;

	DWORD result;

	srand((unsigned)time(NULL));

	newcoord.X = GetRandom(0, csbi.dwSize.X - 1);

	newcoord.Y = GetRandom(0, csbi.dwSize.Y - 1);


}
