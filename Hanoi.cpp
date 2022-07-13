//
// Hanoi.cpp: определяет точку входа для консольного приложения.
//

/////////////////////////////////////////////
/// Практика
/// 55_Hanoi
/// ИВТ-101 Рябцев Н.П.
/////////////////////////////////////////////


// Ханойские башни

#include "stdafx.h"
#include <iostream> // ввод - вывод
#include <fstream> // файловый ввод-вывод

using namespace std;

struct hanoi_datas {
	int start_peg, destination_peg, buffer_peg, plate_quantity;
	// структура для хранения и считывания данных с файла
};

void read_from_file(hanoi_datas* hanoi) {
	string filename; // переменная строкового типа
	filename = "input.txt"; // название файла
	ifstream is(filename); // инициализирование переменной 
	if (is) // если существует , то 
	{
		cout << "Считываю данные\n";
		for (int i = 0; i < 1; i++) // цикл
		{
			is >> hanoi[i].start_peg;
			is >> hanoi[i].destination_peg;
			is >> hanoi[i].buffer_peg;
			is >> hanoi[i].plate_quantity;
		}
		is.close(); // закрываем файл после выполениня операции
	}
	else // иначе
		cout << "Oшибка открытия файла\n";
}


void hanoi_towers(int quantity, int from, int to, int buf_peg) 
//quantity-число колец, from-начальное положение колец(1-3),
//to-конечное положение колец(1-3)
{//buf_peg - промежуточный колышек(1-3)
	ofstream output;
	// переменная класса ofstream для вывода
	string filename; 
	// переменная строкового типа для хранения файла вывода
	filename = "output.txt"; // название файла
	output.open(filename, ofstream::out | ofstream::app); 
	if (!output.is_open()) { // если не удалось открыть файл
		cout << "Неудалось открыть файл" << endl;
	}
	else { 
		if (quantity != 0)
		{
			hanoi_towers(quantity - 1, from, buf_peg, to);

			output << from << " -> " << to << endl;

			hanoi_towers(quantity - 1, buf_peg, to, from);
		}
	}
}
 
int main()
{
    setlocale(LC_ALL,"rus");
	int quantity, from, to, buf_peg;
	hanoi_datas* hanoi = new hanoi_datas[1];
	read_from_file(hanoi);
	quantity = hanoi->plate_quantity;
	from = hanoi->start_peg;
	to = hanoi->destination_peg;
	buf_peg = hanoi->buffer_peg;
	hanoi_towers(quantity, from, to, buf_peg);
	cout << "Процесс завершен\n";
	return 0;
}