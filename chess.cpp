#include<iostream>
#include <Windows.h>

using namespace std;
int main() {
	setlocale(0, "");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int v1, g1, v2, g2;

	cout << "Первое поле шахмотной доски (размер 8х8)\n";
	cout << "Введите пару чисел через Enter: первое число — номер вертикали (при счете слева направо)\n";
	cin >> v1;
	cout << "Второе число — номер горизонтали (при счете снизу вверх)\n";
	cin >> g1;

	cout << "Второе поле шахмотной доски (размер 8х8)\n";
	cout << "Введите пару чисел через Enter: первое число — номер вертикали (при счете слева направо)\n";
	cin >> v2;
	cout << "Второе число — номер горизонтали (при счете снизу вверх)\n";
	cin >> g2;

	// проверка ввода
	if (v1 > 8 || g1 > 8 || v2 > 8 || g2 > 8 || v1 < 0 || g1 < 0 || v2 < 0 || g2 < 0) {
		cout << "Вы ввели некорректные данные, закройте программу и попробуйте еще раз!";
	}

	else {
		if (((v1 % 2 == g1 % 2) & (v2 % 2 == g2 % 2)) || ((v1 % 2 != g1 % 2) & (v2 % 2 != g2 % 2))) {
			cout << "Поля являются полями одного цвета";
		}
		else { cout << "Поля являются полями разных цветов"; }
		int figura;
		cout << "Вы можете выбрать фигуру, которая стоит на первом поле: ферзь, ладья, слон или конь. Введите цифру, соответствующую названию выбранной вами фигуры: " << endl;
		cout << "1 - ферзь" << endl;
		cout << "2 - ладья" << endl;
		cout << "3 - слон" << endl;
		cout << "4 - конь" << endl;
		cin >> figura;
		//Ферзь:
		if (figura == 1) {
			if ((v1 - v2) * (v1 - v2) == (g1 - g2) * (g1 - g2)) {
				cout << "Ферзь угрожает второму полю" << endl;
			}
			else if (v1 == v2 || g1 == g2) {
				cout << "Ферзь угрожает второму полю" << endl;
			}
			else { cout << "Ферзь не угрожает второму полю" << endl; }
		}
		//Ладья:
		else if (figura == 2) {
			if (g1 == g2 || v1 == v2) {
				cout << "Ладья угрожает второму полю" << endl;
			}
			else { cout << "Ладья не угрожает второму полю" << endl; }
		}
		//Слон:
		else if (figura == 3) {
			if ((v1 - v2) * (v1 - v2) == (g1 - g2) * (g1 - g2)) {
				cout << "Слон угрожает второму полю" << endl;
			}
			else { cout << "Слон не угрожает второму полю" << endl; }
		}
		//Конь:
		else if (figura == 3) {
			if (((v1 - v2) * (v1 - v2) == 4 && (g1 - g2) * (g1 - g2) == 1) || ((g1 - g2) * (g1 - g2) == 4 && (v1 - v2) * (v1 - v2) == 1)) {
				cout << "Конь угрожает второму полю" << endl;
			}
			else { cout << "Конь не угрожает второму полю" << endl; }
		}
		//Ошибка:
		else {
			cout << "Вы ввели некорректные данные, закройте программу и попробуйте еще раз!" << endl;
		}

		//Выяснить, можно ли из первого поля одним ходом ладьи, ферзя или слона попасть на второе поле 
		cout << "Вы можете выбрать фигуру, которая стоит на первом поле: ладья, ферзь или слон. Введите цифру, соответствующую названию выбранной вами фигуры: " << endl;
		cout << "1 - ладья" << endl;
		cout << "2 - ферзь" << endl;
		cout << "3 - слон" << endl;
		int f;
		cin >> f;
		//Ладья
		if (f == 1) {
			if (g1 == g2 || v1 == v2) {
				cout << "Ладья может попасть из первого поля на второе за один ход" << endl;
			}
			else {
				int m = 0;
				int vp, gp;//промежуточное поле
				for (int i = 1; i < 8; i++) {
					for (int j = 1; j < 8; j++) {
						vp = i; gp = j;
						if ((gp == g2 || vp == v2) & (g1 == gp || v1 == vp)) {
							cout << "Ладья может попасть из первого поля на второе за два хода, первый ход приведет на поле (" << vp << ";" << gp << ")" << endl;
							m++;
						}
						if (m != 0) { break; }
					}
					if (m != 0) { break; }
				}
				if (m == 0) { cout << "Ладья не сможет попасть из первого поля на второе даже за два хода"; }
			}
		}
		//Ферзь
		if (f == 2) {
			if (((v1 - v2) * (v1 - v2) == (g1 - g2) * (g1 - g2)) || (v1 == v2 || g1 == g2)) {
				cout << "Ферзь может попасть из первого поля на второе за один ход" << endl;
			}
			else {
				int m = 0;
				int vp, gp;//промежуточное поле
				for (int i = 1; i < 8; i++) {
					for (int j = 1; j < 8; j++) {
						vp = i; gp = j;
						if ((((v1 - vp) * (v1 - vp) == (g1 - gp) * (g1 - gp)) || (v1 == vp || g1 == gp)) & (((vp - v2) * (vp - v2) == (gp - g2) * (gp - g2)) || (vp == v2 || gp == g2))) {
							cout << "Ферзь может попасть из первого поля на второе за два хода, первый ход приведет на поле (" << vp << ";" << gp << ")" << endl;
							m++;
						}
						if (m != 0) { break; }
					}
					if (m != 0) { break; }
				}
				if (m == 0) { cout << "Ферзь не сможет попасть из первого поля на второе даже за два хода"; }
			}

		}
		//Слон
		if (f == 3) {
			if ((v1 - v2) * (v1 - v2) == (g1 - g2) * (g1 - g2)) {
				cout << "Слон может попасть из первого поля на второе за один ход" << endl;
			}
			else {
				int m = 0;
				int vp, gp;//промежуточное поле
				for (int i = 1; i < 8; i++) {
					for (int j = 1; j < 8; j++) {
						vp = i; gp = j;
						if (((v1 - vp) * (v1 - vp) == (g1 - gp) * (g1 - gp)) & ((vp - v2) * (vp - v2) == (gp - g2) * (gp - g2))) {
							cout << "Слон может попасть из первого поля на второе за два хода, первый ход приведет на поле (" << vp << ";" << gp << ")" << endl;
							m++;
						}
						if (m != 0) { break; }
					}
					if (m != 0) { break; }
				}
				if (m == 0) { cout << "Слон не сможет попасть из первого поля на второе даже за два хода"; }
			}
		}
	}
}
