#pragma once
#ifndef TIMENEW_H_INCLUDED
#define TIMENEW_H_INCLUDED
#include <iostream>
#include <time.h>

class TimeL
{
protected:
	int Hour; // часы
	int Min; // минуты
	int Sec; // секунды
	virtual void printMyself(std::ostream& out) const; // функция формирования потока выводя ОТДЕЛЬНО ДЛЯ ВЫВОДА краткого времени
public:
	TimeL(); // конструтор с текущим временем
	TimeL(int h, int m, int s); // конструктор с врменем, которое присылается в функцию
	TimeL(const TimeL&c); // конструктор копирования
	~TimeL(); // деструктор
	friend std::ostream& operator<< (std::ostream &, const TimeL&); // перегруженный оператор вывода (ОБЩИЙ ДЛЯ КЛАСА И ПОДКЛАССА)
	// принцип работы: из-за того, что этот оператор в принципе нельзя перегрузить, то для него формируются потоки в нужном классе, а потом через перегруженный оператор данный поток выводится
};

class TimeFull : public TimeL
{
protected:
	virtual void printMyself(std::ostream& out) const; // функция формирования потока выводя ОТДЕЛЬНО ДЛЯ ВЫВОДА полного времени
public:
	TimeFull() :TimeL() {}; // конструктор с текущим временем (просто отсылаем данные, чтобы сформировалась в материнском классе, т.е. подкласс и класс СВЯЗАНЫ и подклачч может получать данные из материнского)
	TimeFull(int h, int m, int s) :TimeL(h, m, s) {}; // а теперь отправляем своё время, которое указываем при вызове
};


//////////////////////////////
//////////////////////////////

TimeL::TimeL() // конструктор текущего времени
{
	time_t currentTime; // иннициализируем переменную, в которую получим текущее время
	struct tm *localTime; // структура, в которой распределённо будет храниться отдельно дата и время
	time(&currentTime);                   // Получаем текущее время
	localTime = localtime(&currentTime);  // Конвертируем в структуру Hour = localTime->tm_hour;
	Hour = localTime->tm_hour; // и запоминаем нужные нам данные для класса
	Min = localTime->tm_min;
	Sec = localTime->tm_sec;
}
TimeL::TimeL(int h, int m, int s) // конструктор со своим временем
{
	if (h > 24 || h < 0) Hour = 0; // ну просто проверяем, чтобы не было 28 часов, 140 минут и -6 секунд. Если есть ошибка, то заносим 0
	else Hour = h;
	if (m > 60 || h < 0) Min = 0;
	else Min = m;
	if (m > 60 || h < 0) Sec = 0;
	else Sec = s;
}
TimeL::TimeL(const TimeL&c) // конструктор копирования
{
	Hour = c.Hour; // ну тут просто капитан очевидность
	Min = c.Min;
	Sec = c.Sec;
}
TimeL::~TimeL() // деструктор
{
	Hour = 0; // тут тем более
	Min = 0;
	Sec = 0;
}

void TimeL::printMyself(std::ostream& out) const // формируем вывод краткого времени
{
	out << Hour << ":" << Min << ":" << Sec;
};

// перегрузка оператора <<
std::ostream& operator<< (std::ostream &out, const TimeL&c)
{
	c.printMyself(out); // просто поток берём и получаем из нужного класса
	return out; // и выводим!
}

void TimeFull::printMyself(std::ostream& out) const // вывод расширенной версии времени
{
	out << Hour << ":" << Min << ":" << Sec;
	if (Hour > 5 && Hour <= 9) out << " (ночь)"; // утро - с 5 до 9
	else if (Hour > 9 && Hour <= 17) out << " (утро)";// день - с 9 до 17
	else if (Hour > 17 && Hour <= 22) out << " (день)"; // вечер - с 17 до 22
	else if (Hour > 22 && Hour <= 5) out << " (вечер)"; // ночь - с 22 до 5

};
#endif // TIMENEW_H_INCLUDED