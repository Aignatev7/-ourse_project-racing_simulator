#include <iostream>

class Transport // класс Транспорт
{
protected:
	int speed;                  // скорость
	std::string name_transport; // наименование транспорта
	double final_time = 0;		// итоговое время
};

class GroundTransport : public Transport // класс Наземный транспорт
{
protected:
	int driving_time_before_rest; // время движения до отдыха
	int duration_of_rest;         // длительность отдыха

public:
	GroundTransport() { name_transport = "Наземный транспорт"; }

	void set_final_time(double distance) {

		double time_to_move = distance / speed; // время затраченное на движение
		int n = time_to_move / driving_time_before_rest; // количество остановок на отдых										
		int time_spent_on_rest = n * duration_of_rest; // время затраченное на отдых
		if (distance > 0) final_time = time_to_move + time_spent_on_rest; // итоговое время 
	}
	double get_final_time() { return final_time; }
};

class Camel : public GroundTransport // класс Верблюд
{
public:
	Camel() {
		name_transport = "Верблюд";
		speed = 10;
		driving_time_before_rest = 30;
		duration_of_rest = 5;
	}
};

class CamelFast : public GroundTransport // класс Верблюд-быстроход
{
public:
	CamelFast() {
		name_transport = "Верблюд-быстроход";
		speed = 40;
		driving_time_before_rest = 10;
		duration_of_rest = 5;
	}
};

class Centaur : public GroundTransport // класс Кентавр
{
public:
	Centaur() {
		name_transport = "Кентавр";
		speed = 15;
		driving_time_before_rest = 8;
		duration_of_rest = 2;
	}
};

class AllTerrainBoots : public GroundTransport // класс Ботинки-вездеходы
{
public:
	AllTerrainBoots() {
		name_transport = "Ботинки-вездеходы";
		speed = 6;
		driving_time_before_rest = 60;
		duration_of_rest = 10;
	}
};

class AirTransport : public Transport // класс Воздушный транспорт
{
protected:
	double distance_reduction_coefficient; // коэффициент сокращения расстояния

public:
	AirTransport() {
		name_transport = "Воздушный транспорт";
	}

	void set_final_time(double distance) {

		if (distance > 0)
			final_time = (distance * (1 - (distance_reduction_coefficient / 100)) / speed); // итоговое время  
	}
	double get_final_time() { return final_time; }
};

class MagicCarpet : public AirTransport // класс Ковер-самолёт
{
public:
	MagicCarpet() {
		name_transport = "Ковер-самолёт";
		speed = 10;
		distance_reduction_coefficient = 3;
	}
};

class Eagle : public AirTransport // класс Орёл
{
public:
	Eagle() {
		name_transport = "Орёл";
		speed = 8;
		distance_reduction_coefficient = 6;
	}
};

class Broomstick : public AirTransport // класс Метла
{
public:
	Broomstick() {
		name_transport = "Метла";
		speed = 20;
		distance_reduction_coefficient = 1;
	}
};

int main() {
	setlocale(LC_ALL, "Rus");

	int type_of_race;        // тип гонки
	int distance_length;     // расстояние
	int registration = 0;		  // регистрация
	int transport_selection = 0;  // выбор траспорта

	std::cout << "Добро пожаловать на гоночный симулятор!" << std::endl;
	std::cout << "1. Гонка для наземного транспорта" << std::endl;
	std::cout << "2. Гонка для воздушного транспорта" << std::endl;
	std::cout << "3. Гонка для наземного и воздушного транспорта" << std::endl;
	std::cout << "Выберите тип гонки: ";
	std::cin >> type_of_race;
	std::cout << "Укажите длину дистанции (должна быть положительна): ";
	std::cin >> distance_length;
	std::cout << "Должно быть зарегистрировано хотя бы 2 транспортных средства" << std::endl;
	std::cout << "1. Зарегистрировать транспорт" << std::endl;
	std::cout << "Выберите действие: ";
	std::cin >> registration;
	int transport_selection_1 = 0;    // зарегистрпрованный транспорт 1
	int transport_selection_2 = 0;    // зарегистрпрованный транспорт 2

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
				std::cout << "Гонка для наземного транспорта. ";
				break;
			case 2:
				std::cout << "Гонка для воздушного транспорта. ";
				break;
			case 3:
				std::cout << "Гонка для наземного и воздушного транспорта. ";
				break;
			}
		}
		else {
			return 1;
		}
		std::cout << "Расстояние: " << distance_length << std::endl;
		std::cout << "Зарегистрированные транспортные средства: " << static_cast<char>( transport_selection_1) << std::endl;
		std::cout << "1. Верблюд" << std::endl;
		std::cout << "2. Верблюд-быстроход" << std::endl;
		std::cout << "3. Кентавр" << std::endl;
		std::cout << "4. Ботинки-вездеходы" << std::endl;
		std::cout << "5. Ковёр-самолёт" << std::endl;
		std::cout << "6. Орёл" << std::endl;
		std::cout << "7. Метла" << std::endl;
		std::cout << "0. Закончить регистрацию" << std::endl;

		std::cout << "Выберите транспорт или 0 для окончания процесса регистрации: ";
		std::cin >> transport_selection;

		switch (transport_selection) {
		case 1:
			std::cout << "Верблюд";
			break;
		case 2:
			std::cout << "Верблюд-быстроход";
			break;
		case 3:
			std::cout << "Кентавр";
			break;
		case 4:
			std::cout << "Ботинки-вездеходы";
			break;
		case 5:
			std::cout << "Ковёр-самолёт";
			break;
		case 6:
			std::cout << "Орёл";
			break;
		case 7:
			std::cout << "Метла";
			break;
		}
		if (transport_selection != 0) {
			std::cout << " успешно зарегистрирован!" << std::endl;
		}

		if ((transport_selection != 0) && (transport_selection != transport_selection_2)) {
			transport_selection_1 = transport_selection;
		}

		if ((transport_selection != 0) && (transport_selection != transport_selection_1)) {
			transport_selection_2 = transport_selection;
		}

	} while (transport_selection != 0);

	if (transport_selection_1 == 1) {
		std::cout << "Верблюд. Время: " << camel.get_final_time() << std::endl;
	}

	if (transport_selection_1 == 2) {
		std::cout << "Верблюд-быстроход. Время: " << camelFast.get_final_time() << std::endl;
	}

	if (transport_selection_1 == 3) {
		std::cout << "Кентавр. Время: " << centaur.get_final_time() << std::endl;
	}

	if (transport_selection_1 == 4) {
		std::cout << "Ботинки-вездеходы. Время: " << allTerrainBoots.get_final_time() << std::endl;
	}

	if (transport_selection_1 == 5) {
		std::cout << "Ковёр-самолёт. Время: " << magicCarpet.get_final_time() << std::endl;
	}

	if (transport_selection_1 == 6) {
		std::cout << "Орёл. Время: " << eagle.get_final_time() << std::endl;
	}

	if (transport_selection_1 == 7) {
		std::cout << "Метла. Время: " << broomstick.get_final_time() << std::endl;
	}

	/*std::cout << transport_selection_1 << std::endl;
	std::cout << transport_selection_2 << std::endl;*/
}


/*
Курсовой проект «Симулятор гонок»

Курсовой проект — простейшая реализация симулятора гонок для фэнтезийных
транспортных средств (ТС). Содержание
1. Правила игры

Все ТС делятся на два типа:

	наземные;
	воздушные.

В симуляторе есть несколько видов ТС:

	верблюд (наземное);
	верблюд-быстроход (наземное);
	кентавр (наземное);
	ботинки-вездеходы (наземное);
	ковёр-самолёт (воздушное);
	орёл (воздушное);
	метла (воздушное).

У всех ТС есть заранее заданная скорость.

В симуляторе есть несколько видов гонок:

	только для наземных ТС;
	только для воздушных ТС;
	для наземных и воздушных ТС.

Наземные ТС

Наземные ТС не могут двигаться непрерывно: после определённого времени им нужно
отдыхать. У каждого вида наземного ТС время движения своё. Время отдыха у
каждого наземного ТС также различается и зависит от того, какая по счёту эта
остановка. Пример

Скорость ТС равна 100 км/ч, дистанция равна 1000 км, время движения до отдыха
равно 6 ч, длительность отдыха равна 3 ч. В таком случае ТС пройдёт дистанцию за
1000 / 100 = 10 ч. Так как время движения до отдыха равно 6 часов, то по пути ТС
нужно будет отдохнуть 1 раз. Итоговое время составит: 10 + 3 = 13 ч.

Сводная таблица характеристик для каждого наземного ТС:
Вид ТС 	Скорость 	Время движения
до отдыха 	Длительность отдыха
Верблюд 	10 	30 	Первый раз: 5
Все последующие разы: 8
Верблюд-быстроход 	40 	10 	Первый раз: 5
Второй раз: 6.5
Все последующие разы: 8
Кентавр 	15 	8 	Всегда 2
Ботинки-вездеходы 	6 	60 	Первый раз: 10
Все последующие разы: 5
Воздушные ТС

Воздушные ТС двигаются непрерывно. Так как они могут облетать препятствия,
каждое воздушное ТС имеет собственный коэффициент сокращения расстояния: то есть
для каждого воздушного ТС дистанция, которую нужно пройти, уменьшается.
Коэффициент сокращения расстояния может зависеть от дистанции. Пример

Если у воздушного ТС коэффициент сокращения расстояния равен 5%, то вместо
дистанции в 1000 км ему нужно пройти дистанцию в 1000 * 0.95 = 950 км.

Сводная таблица характеристик для каждого воздушного ТС:
Вид ТС 	Скорость 	Коэффициент сокращения расстояния
Ковёр-самолёт 	10 	Если расстояние меньше 1000 — без сокращения
Если расстояние меньше 5000 — 3%
Если расстояние меньше 10000 — 10%
Если расстояние больше или равно 10000 — 5%
Орёл 	8 	Всегда 6%
Метла 	20 	Увеличивается на 1% за каждую 1000 у.е. расстояния
Например, для расстояния 5600 коэффициент будет 5%
2. Требования к решению

Требования по функционированию программы:

	При старте программы пользователю должен быть предложен выбор типа гонки.
	После выбора типа гонки пользователь должен указать расстояние для этой
гонки. Пользователю должна быть предоставлена возможность зарегистрировать ТС на
гонку. Можно регистрировать не более одного экземпляра для каждого вида ТС. На
гонку должно быть зарегистрировано хотя бы два вида ТС. Нельзя зарегистрировать
на наземную гонку воздушное ТС, а на воздушную гонку наземное ТС. После
завершения регистрации пользователь может либо зарегистрировать ещё ТС, либо
начать гонку. Сама гонка происходит мгновенно. Пользователю выводится результат
гонки — ТС-участники гонки и их время. Результаты участников должны выводиться
по возрастанию времени: самый быстрый оказывается вверху списка, самый медленный
— внизу. Вместе с результатами гонки пользователю должен быть предложен выбор:
провести ещё одну гонку (программа стартует заново) или выйти из программы.

Требования к структуре и реализации программы:

	Для реализации ТС и гонок должны быть использованы иерархии классов.
	Для каждого класса должна быть создана пара «заголовочный файл + файл
исходного кода». Классы ТС, гонок и другие вспомогательные классы должны
находиться в отдельной динамической библиотеке (DLL). В основном проекте (.exe)
должен находиться код для взаимодействия с пользователем и использование классов
из вашей библиотеки в ответ на действия пользователя. Классы библиотеки не
должны самостоятельно выводить данные на консоль.

3. Пример пошаговой работы программы

выбор типа гонки наземная

ввод расстояния

выбор действия 1 регистрация

регистрация 1 верблюд

регистрация 1 кентавр

регистрация 1 выход

выбор действия 2 регистрация

регистрация 2 верблюд

регистрация 2 метла

регистрация 2 ботинки-скороходы

регистрация 2 выход

выбор действия старт

результаты и выбор действия ещё раз

выбор типа гонки воздушная

ввод расстояния

выбор действия 1 регистрация

регистрация 1 верблюд-быстроход

регистрация 1 выход

выбор действия 2 регистрация

регистрация 2 метла

регистрация 2 орёл

регистрация 2 ковёр-самолёт

регистрация 2 выход

выбор действия старт

результаты и выбор действия выход
*/