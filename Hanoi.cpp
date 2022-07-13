//
// Hanoi.cpp: ���������� ����� ����� ��� ����������� ����������.
//

/////////////////////////////////////////////
/// ��������
/// 55_Hanoi
/// ���-101 ������ �.�.
/////////////////////////////////////////////


// ��������� �����

#include "stdafx.h"
#include <iostream> // ���� - �����
#include <fstream> // �������� ����-�����

using namespace std;

struct hanoi_datas {
	int start_peg, destination_peg, buffer_peg, plate_quantity;
	// ��������� ��� �������� � ���������� ������ � �����
};

void read_from_file(hanoi_datas* hanoi) {
	string filename; // ���������� ���������� ����
	filename = "input.txt"; // �������� �����
	ifstream is(filename); // ����������������� ���������� 
	if (is) // ���� ���������� , �� 
	{
		cout << "�������� ������\n";
		for (int i = 0; i < 1; i++) // ����
		{
			is >> hanoi[i].start_peg;
			is >> hanoi[i].destination_peg;
			is >> hanoi[i].buffer_peg;
			is >> hanoi[i].plate_quantity;
		}
		is.close(); // ��������� ���� ����� ���������� ��������
	}
	else // �����
		cout << "O����� �������� �����\n";
}


void hanoi_towers(int quantity, int from, int to, int buf_peg) 
//quantity-����� �����, from-��������� ��������� �����(1-3),
//to-�������� ��������� �����(1-3)
{//buf_peg - ������������� �������(1-3)
	ofstream output;
	// ���������� ������ ofstream ��� ������
	string filename; 
	// ���������� ���������� ���� ��� �������� ����� ������
	filename = "output.txt"; // �������� �����
	output.open(filename, ofstream::out | ofstream::app); 
	if (!output.is_open()) { // ���� �� ������� ������� ����
		cout << "��������� ������� ����" << endl;
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
	cout << "������� ��������\n";
	return 0;
}