#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>


FILE* fp;
char* buffer;
int g_size = 0;
int g_count = 0;
int g_time = 10;


void gotoxy(int x, int y)
{
	COORD Cur;
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}


void WARNING()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	system("cls");

	puts("A problem has occurred.\n\n");
	puts("<-- Solution -->");
	puts("Check if there is a Write Here.txt file.");
	puts("If not, create a new one\n\n\n");

	while (1)
	{
		gotoxy(20, 20);

		printf("The system will shut down automatically in %d seconds.", g_time);
		Sleep(1000);
		g_time--;

		if (g_time <= 0)
			exit(0);
	}
}


void Saved_Contents_print ()
{
	fp = fopen("Write Here.txt", "r+");

	if (fp == NULL)
		WARNING();

	fseek(fp, 0, SEEK_END);
	g_size = ftell(fp);

	buffer = malloc(g_size + 1);
	memset(buffer, 0, g_size + 1);

	fseek(fp, 0, SEEK_SET);
	fread(buffer, g_size, 1, fp);

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	printf("%s", buffer);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
}


void SUM_CHARACTERS()
{
	fseek(fp, 0, SEEK_SET);
	while (ftell(fp) != g_size)
	{
		fseek(fp, 1, SEEK_CUR);
		g_count++;
	}
}





int main()
{
	system("title Calculate the Number of Nharacters(CNC) https://github.com/ZENOVERS/");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	printf("<-- Please enter in English as possible as you can -->\n\n\n\n\n");


	Saved_Contents_print();

	SUM_CHARACTERS();

	printf("\n\n\n\n\n\n\nThere are(is) ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
	printf("%d ", g_count);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	printf("characters including a space\n\n\n");

	system("pause");
	return 0;
}