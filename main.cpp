#include <iostream>

class Transport // ����� ���������
{
protected:
	int speed;                  // ��������
	std::string name_transport; // ������������ ����������
	double final_time = 0;		// �������� �����
};

class GroundTransport : public Transport // ����� �������� ���������
{
protected:
	int driving_time_before_rest; // ����� �������� �� ������
	int duration_of_rest;         // ������������ ������

public:
	GroundTransport() { name_transport = "�������� ���������"; }

	void set_final_time(double distance) {

		double time_to_move = distance / speed; // ����� ����������� �� ��������
		int n = time_to_move / driving_time_before_rest; // ���������� ��������� �� �����										
		int time_spent_on_rest = n * duration_of_rest; // ����� ����������� �� �����
		if (distance > 0) final_time = time_to_move + time_spent_on_rest; // �������� ����� 
	}
	double get_final_time() { return final_time; }
};

class Camel : public GroundTransport // ����� �������
{
public:
	Camel() {
		name_transport = "�������";
		speed = 10;
		driving_time_before_rest = 30;
		duration_of_rest = 5;
	}
};

class CamelFast : public GroundTransport // ����� �������-���������
{
public:
	CamelFast() {
		name_transport = "�������-���������";
		speed = 40;
		driving_time_before_rest = 10;
		duration_of_rest = 5;
	}
};

class Centaur : public GroundTransport // ����� �������
{
public:
	Centaur() {
		name_transport = "�������";
		speed = 15;
		driving_time_before_rest = 8;
		duration_of_rest = 2;
	}
};

class AllTerrainBoots : public GroundTransport // ����� �������-���������
{
public:
	AllTerrainBoots() {
		name_transport = "�������-���������";
		speed = 6;
		driving_time_before_rest = 60;
		duration_of_rest = 10;
	}
};

class AirTransport : public Transport // ����� ��������� ���������
{
protected:
	double distance_reduction_coefficient; // ����������� ���������� ����������

public:
	AirTransport() {
		name_transport = "��������� ���������";
	}

	void set_final_time(double distance) {

		if (distance > 0)
			final_time = (distance * (1 - (distance_reduction_coefficient / 100)) / speed); // �������� �����  
	}
	double get_final_time() { return final_time; }
};

class MagicCarpet : public AirTransport // ����� �����-������
{
public:
	MagicCarpet() {
		name_transport = "�����-������";
		speed = 10;
		distance_reduction_coefficient = 3;
	}
};

class Eagle : public AirTransport // ����� ���
{
public:
	Eagle() {
		name_transport = "���";
		speed = 8;
		distance_reduction_coefficient = 6;
	}
};

class Broomstick : public AirTransport // ����� �����
{
public:
	Broomstick() {
		name_transport = "�����";
		speed = 20;
		distance_reduction_coefficient = 1;
	}
};

int main() {
	setlocale(LC_ALL, "Rus");

	int type_of_race;        // ��� �����
	int distance_length;     // ����������
	int registration = 0;		  // �����������
	int transport_selection = 0;  // ����� ���������

	std::cout << "����� ���������� �� �������� ���������!" << std::endl;
	std::cout << "1. ����� ��� ��������� ����������" << std::endl;
	std::cout << "2. ����� ��� ���������� ����������" << std::endl;
	std::cout << "3. ����� ��� ��������� � ���������� ����������" << std::endl;
	std::cout << "�������� ��� �����: ";
	std::cin >> type_of_race;
	std::cout << "������� ����� ��������� (������ ���� ������������): ";
	std::cin >> distance_length;
	std::cout << "������ ���� ���������������� ���� �� 2 ������������ ��������" << std::endl;
	std::cout << "1. ���������������� ���������" << std::endl;
	std::cout << "�������� ��������: ";
	std::cin >> registration;
	int transport_selection_1 = 0;    // ������������������ ��������� 1
	int transport_selection_2 = 0;    // ������������������ ��������� 2

	Camel camel;
	camel.set_final_time(distance_length);

	CamelFast camelFast;
	camelFast.set_final_time(distance_length);

	Centaur centaur;
	centaur.set_final_time(distance_length);

	AllTerrainBoots allTerrainBoots;
	allTerrainBoots.set_final_time(distance_length);

	MagicCarpet magicCarpet;
	magicCarpet.set_final_time(distance_length);

	Eagle eagle;
	eagle.set_final_time(distance_length);

	Broomstick broomstick;
	broomstick.set_final_time(distance_length);

	do {
		if (registration == 1) {
			switch (type_of_race) {
			case 1:
				std::cout << "����� ��� ��������� ����������. ";
				break;
			case 2:
				std::cout << "����� ��� ���������� ����������. ";
				break;
			case 3:
				std::cout << "����� ��� ��������� � ���������� ����������. ";
				break;
			}
		}
		else {
			return 1;
		}
		std::cout << "����������: " << distance_length << std::endl;
		std::cout << "������������������ ������������ ��������: " << static_cast<char>( transport_selection_1) << std::endl;
		std::cout << "1. �������" << std::endl;
		std::cout << "2. �������-���������" << std::endl;
		std::cout << "3. �������" << std::endl;
		std::cout << "4. �������-���������" << std::endl;
		std::cout << "5. ����-������" << std::endl;
		std::cout << "6. ���" << std::endl;
		std::cout << "7. �����" << std::endl;
		std::cout << "0. ��������� �����������" << std::endl;

		std::cout << "�������� ��������� ��� 0 ��� ��������� �������� �����������: ";
		std::cin >> transport_selection;

		switch (transport_selection) {
		case 1:
			std::cout << "�������";
			break;
		case 2:
			std::cout << "�������-���������";
			break;
		case 3:
			std::cout << "�������";
			break;
		case 4:
			std::cout << "�������-���������";
			break;
		case 5:
			std::cout << "����-������";
			break;
		case 6:
			std::cout << "���";
			break;
		case 7:
			std::cout << "�����";
			break;
		}
		if (transport_selection != 0) {
			std::cout << " ������� ���������������!" << std::endl;
		}

		if ((transport_selection != 0) && (transport_selection != transport_selection_2)) {
			transport_selection_1 = transport_selection;
		}

		if ((transport_selection != 0) && (transport_selection != transport_selection_1)) {
			transport_selection_2 = transport_selection;
		}

	} while (transport_selection != 0);

	if (transport_selection_1 == 1) {
		std::cout << "�������. �����: " << camel.get_final_time() << std::endl;
	}

	if (transport_selection_1 == 2) {
		std::cout << "�������-���������. �����: " << camelFast.get_final_time() << std::endl;
	}

	if (transport_selection_1 == 3) {
		std::cout << "�������. �����: " << centaur.get_final_time() << std::endl;
	}

	if (transport_selection_1 == 4) {
		std::cout << "�������-���������. �����: " << allTerrainBoots.get_final_time() << std::endl;
	}

	if (transport_selection_1 == 5) {
		std::cout << "����-������. �����: " << magicCarpet.get_final_time() << std::endl;
	}

	if (transport_selection_1 == 6) {
		std::cout << "���. �����: " << eagle.get_final_time() << std::endl;
	}

	if (transport_selection_1 == 7) {
		std::cout << "�����. �����: " << broomstick.get_final_time() << std::endl;
	}

	/*std::cout << transport_selection_1 << std::endl;
	std::cout << transport_selection_2 << std::endl;*/
}


/*
�������� ������ ���������� �����

�������� ������ � ���������� ���������� ���������� ����� ��� �����������
������������ ������� (��). ����������
1. ������� ����

��� �� ������� �� ��� ����:

	��������;
	���������.

� ���������� ���� ��������� ����� ��:

	������� (��������);
	�������-��������� (��������);
	������� (��������);
	�������-��������� (��������);
	����-������ (���������);
	��� (���������);
	����� (���������).

� ���� �� ���� ������� �������� ��������.

� ���������� ���� ��������� ����� �����:

	������ ��� �������� ��;
	������ ��� ��������� ��;
	��� �������� � ��������� ��.

�������� ��

�������� �� �� ����� ��������� ����������: ����� ������������ ������� �� �����
��������. � ������� ���� ��������� �� ����� �������� ���. ����� ������ �
������� ��������� �� ����� ����������� � ������� �� ����, ����� �� ����� ���
���������. ������

�������� �� ����� 100 ��/�, ��������� ����� 1000 ��, ����� �������� �� ������
����� 6 �, ������������ ������ ����� 3 �. � ����� ������ �� ������ ��������� ��
1000 / 100 = 10 �. ��� ��� ����� �������� �� ������ ����� 6 �����, �� �� ���� ��
����� ����� ��������� 1 ���. �������� ����� ��������: 10 + 3 = 13 �.

������� ������� ������������� ��� ������� ��������� ��:
��� �� 	�������� 	����� ��������
�� ������ 	������������ ������
������� 	10 	30 	������ ���: 5
��� ����������� ����: 8
�������-��������� 	40 	10 	������ ���: 5
������ ���: 6.5
��� ����������� ����: 8
������� 	15 	8 	������ 2
�������-��������� 	6 	60 	������ ���: 10
��� ����������� ����: 5
��������� ��

��������� �� ��������� ����������. ��� ��� ��� ����� �������� �����������,
������ ��������� �� ����� ����������� ����������� ���������� ����������: �� ����
��� ������� ���������� �� ���������, ������� ����� ������, �����������.
����������� ���������� ���������� ����� �������� �� ���������. ������

���� � ���������� �� ����������� ���������� ���������� ����� 5%, �� ������
��������� � 1000 �� ��� ����� ������ ��������� � 1000 * 0.95 = 950 ��.

������� ������� ������������� ��� ������� ���������� ��:
��� �� 	�������� 	����������� ���������� ����������
����-������ 	10 	���� ���������� ������ 1000 � ��� ����������
���� ���������� ������ 5000 � 3%
���� ���������� ������ 10000 � 10%
���� ���������� ������ ��� ����� 10000 � 5%
��� 	8 	������ 6%
����� 	20 	������������� �� 1% �� ������ 1000 �.�. ����������
��������, ��� ���������� 5600 ����������� ����� 5%
2. ���������� � �������

���������� �� ���������������� ���������:

	��� ������ ��������� ������������ ������ ���� ��������� ����� ���� �����.
	����� ������ ���� ����� ������������ ������ ������� ���������� ��� ����
�����. ������������ ������ ���� ������������� ����������� ���������������� �� ��
�����. ����� �������������� �� ����� ������ ���������� ��� ������� ���� ��. ��
����� ������ ���� ���������������� ���� �� ��� ���� ��. ������ ����������������
�� �������� ����� ��������� ��, � �� ��������� ����� �������� ��. �����
���������� ����������� ������������ ����� ���� ���������������� ��� ��, ����
������ �����. ���� ����� ���������� ���������. ������������ ��������� ���������
����� � ��-��������� ����� � �� �����. ���������� ���������� ������ ����������
�� ����������� �������: ����� ������� ����������� ������ ������, ����� ���������
� �����. ������ � ������������ ����� ������������ ������ ���� ��������� �����:
�������� ��� ���� ����� (��������� �������� ������) ��� ����� �� ���������.

���������� � ��������� � ���������� ���������:

	��� ���������� �� � ����� ������ ���� ������������ �������� �������.
	��� ������� ������ ������ ���� ������� ���� ������������� ���� + ����
��������� ����. ������ ��, ����� � ������ ��������������� ������ ������
���������� � ��������� ������������ ���������� (DLL). � �������� ������� (.exe)
������ ���������� ��� ��� �������������� � ������������� � ������������� �������
�� ����� ���������� � ����� �� �������� ������������. ������ ���������� ��
������ �������������� �������� ������ �� �������.

3. ������ ��������� ������ ���������

����� ���� ����� ��������

���� ����������

����� �������� 1 �����������

����������� 1 �������

����������� 1 �������

����������� 1 �����

����� �������� 2 �����������

����������� 2 �������

����������� 2 �����

����������� 2 �������-���������

����������� 2 �����

����� �������� �����

���������� � ����� �������� ��� ���

����� ���� ����� ���������

���� ����������

����� �������� 1 �����������

����������� 1 �������-���������

����������� 1 �����

����� �������� 2 �����������

����������� 2 �����

����������� 2 ���

����������� 2 ����-������

����������� 2 �����

����� �������� �����

���������� � ����� �������� �����
*/