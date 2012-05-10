#include "stdafx.h"
#include "conio.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Menu	{ 
	string element; //Дополнительная позиция основного меню,элемент массива. Что-то типа счетчика.
	string A[100]; //Дополнительная позиция подменю
};

int main()
{	
	Menu point[100]; 
	int N=6; //Количество пунктов меню 
	int M=5; 
	int pos_m=1; //Позиция меню
	int pos_pm=1; //Позиция подменю
//Пункты главного меню
	point[0].element ="Files";
	point[1].element ="Read";
	point[2].element ="Create";
	point[3].element ="Edit";
	point[4].element ="Delete";
	point[5].element ="Exit";
//Вывод основного меню
	for (int i=0;i<N-1;i++)
		if (pos_m==i+1)
			cout << i+1 << " * " << point[i].element << "*" << endl;
		else 
			cout << i+1 << "   " << point[i].element << endl;

	if (pos_m==6)
			cout << 0 << " * " << point[5].element << endl;
		else 
			cout << 0 << "   " << point[5].element << endl;
 
	point [0].A[0]="Return";//Create, Edit, Delete,  

	point [1].A[0]="Return"; //Read, File
//Подменю Create
	point [2].A[0]="First";
	point [2].A[1]="Average";
	point [2].A[2]="Last";
	point [2].A[3]="By key";
	point [2].A[4]="Return";

//Подменю Edit
	point [3].A[0]="First";
	point [3].A[1]="Average";
	point [3].A[2]="Last";
	point [3].A[3]="By key";
	point [3].A[4]="Return";
//Подменю Delete
	point [4].A[0]="First";
	point [4].A[1]="Average";
	point [4].A[2]="Last";
	point [4].A[3]="By key";
	point [4].A[4]="Return";
//Выход
	point [5].A[0]= "Yes";
	point [5].A[1]= "No";
//
	bool F=true;

	int w,x,y,z;

	//Считывание клавишей и привязка функций к ним
	while (1)	{
		x=getch();
		if (x==224) x=getch();
		switch (x) {
			//Цифры
			case 49:
				pos_m=1;
				break;
			case 50: 
				pos_m=2;
				break;
			case 51: 
				pos_m=3;
				break;
			case 52: 
				pos_m=4;
				break;
			case 53: 
				pos_m=5;
				break;
			case 48: 
				pos_m=6;
				break;
			//Стрелочки
			case 80:
				pos_m++;
				break;
			case 72:
				pos_m--;
				break;
			//Ентер
			case 13:
				F=false;
				break;
			//Ескейп
			case 27:
				pos_m=6;
				F=false;
				break;
			default:
				break;
		}

		if (pos_m>N)
			pos_m=1;
		if (pos_m<1)
			pos_m=N;

		if (F==false) {
			system("cls");
			cout << " " << point[pos_m-1].element << "\n";

			if (pos_m==1)
				cout << "1 *" << point[0].A[0] << "*\n";

			if (pos_m==2)
				cout << "1 *" << point[1].A[0] << "*\n";

			if (pos_m==3||pos_m==4||pos_m==5) {
				for (int i=0; i<M-1; i++) 
					if (pos_pm==i+1)
						cout << i+1 << " * " << point[pos_m-1].A[i] << setw(6) << "*\n";
					else 
						cout << i+1 << "   " << point[pos_m-1].A[i] << "\n";
				if (pos_pm==5)
							cout << 0 << " * " << point[pos_m-1].A[4] << setw(6) << "*\n";
						else 
							cout << 0 << "   " << point[pos_m-1].A[4] << "\n";
			}
				pos_pm=1;
//Считывание клавиш в подменю
				do	{
					if (pos_m==3||pos_m==4||pos_m==5) {
						z=getch();
						if (z==224)
							z=getch();
						switch (z) {
							//Цифры
							case 49:
								pos_pm=1;
								break;
							case 50:
								pos_pm=2;
								break;
							case 51:
								pos_pm=3;
								break;
							case 52:
								pos_pm=4;
								break;
							case 48:
								pos_pm=5;
								break;
							//Стрелочки
							case 80:
								pos_pm++;
								break;
							case 72:
								pos_pm--;
								break;
							//Кнопка ескейп
							case 27:
								F=true;
								pos_pm=1;
								break;
							default:
								break;
						}

						if (pos_pm>M)
							pos_pm=5;
						if (pos_pm<1)
							pos_pm=1;

						system ("cls");
						cout << " " << point[pos_m-1].element << "\n";

						for (int i=0; i<M-1; i++)	
							if (pos_pm==i+1) 
								cout << i+1 << " * " << point[pos_m-1].A[i] << "*\n";
							else 
								cout << i+1 << "   " << point[pos_m-1].A[i] << "\n";
							if (pos_pm==5)
								cout << 0 << " * " << point[pos_m-1].A[4] << "*\n";
							else 
								cout << 0 << "   " << point[pos_m-1].A[4] << "\n";
					//Назначение клавиш для подменю
						if (pos_pm==5) 
							switch (z) {
							case 13:
								F=true;
								pos_pm=1;
								break;
							}
					}

					if (pos_m==1||pos_m==2) {
						y=getch();
						if (y==224)
							y=getch();
						switch (y) {
							case 13:
								F=true;
								pos_pm=1;
								break;
							case 27:
								F=true;
								pos_pm=1;
								break;
						}
					}
//Exit
					if (pos_m==6) {
						cout << "\nAre you sure?\n"; 
						for (int i=0; i<2; i++)	{
							if (pos_pm==i+1) 
								cout << "  *" << point[pos_m-1].A[i] << "*";
							else 
								cout << "   " << point[pos_m-1].A[i] << " ";
						}

						w=getch();
						if (w==224)
							w=getch();
						switch (w) {
							case 49:
								pos_pm=1;
								break;
							case 48:
								pos_pm=48;
								break;
							case 50:
								pos_pm=2;
								break;
							case 77: // 80
								pos_pm++;
								break;
							case 75: // 72
								pos_pm--;
								break;
							case 27:
								F=true;
								pos_pm=1;
								break;
						}

						if (pos_pm>2)
							pos_pm=1;
						if (pos_pm<1)
							pos_pm=2;
						
						system ("cls");
						cout << " " << point[pos_m-1].element << "\n";

						if (pos_pm==2) 
							switch (w) {
							case 13:
								F=true;
								pos_pm=1;
								break;
							}
					
						else if (pos_pm==1) 
							switch (w) {
							case 13:
								exit(1);
								break;
							}
					}
				}
				while (F==false);
		}

		if (F==true) {
			system("cls");
			for (int i=0;i<N-1;i++)
				if (pos_m==i+1)
					cout << i+1 << " * " << point[i].element << "*\n";
				else 
					cout << i+1 << "   " << point[i].element << "\n";

			if (pos_m==6)
					cout << 0 << " * " << point[5].element << "*\n";
				else 
					cout << 0 << "   " << point[5].element << "\n";
		}

	}

getch();
return 0;
}