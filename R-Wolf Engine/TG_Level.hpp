#pragma once
#include "RWLevel.h"
#include "RWController.h"

enum colort
{
	rulers
};

class TGLevel : public RWLevel {
public:
	void load() override
	{
		lag = new LAGOMETER();
		typecolors = new RGBA[32];
		typecolors[rulers] = RGBA(0x64, 0x64, 0x64);
		tang_ruler_pos = FVECTOR2(500, 500);
		tang_ruler_rad = 250;
		seg = 24;
	}
	void update() override
	{
		
		lag->setTimeFrom();
	}
	void render() override
	{
		clscr(RGBA(0x10, 0x10, 0x10));
		// Секция UI:
		
		// Шкала ТГ
		ellipse(TWDELLIPSE(tang_ruler_pos, tang_ruler_rad, tang_ruler_rad), typecolors[rulers], 2.0, false);
		ellipse(TWDELLIPSE(tang_ruler_pos, tang_ruler_rad - 10, tang_ruler_rad - 10), typecolors[rulers], 1.5, false);
		for (short i = 0; i < seg * 5; i++)
		{
			// Начало линии
			FVECTOR2 beg = rotation(tang_ruler_pos, i * (360 / (seg * 5)), tang_ruler_rad);
			// Конец линии
			FVECTOR2 end = vecMove(beg, FVECTOR2(-10 * cosf(i * (360 / (seg * 5)) degToRad), -10 * sinf(i * (360 / (seg * 5)) degToRad)));

			// Отрисовка
			line(TWDLINE(beg, end), 1.5, typecolors[rulers]);
		}
		for (short i = 0; i < seg; i++)
		{
			// Начало линии
			FVECTOR2 beg = rotation(tang_ruler_pos, i * (360 / seg), tang_ruler_rad);
			// Конец линии
			FVECTOR2 end = vecMove(beg, FVECTOR2(-0.125f * tang_ruler_rad * cosf(i * (360 / seg) degToRad), -0.125f * tang_ruler_rad * sinf(i * (360 / seg) degToRad)));

			// Отрисовка
			line(TWDLINE(beg, end), 1.5, typecolors[rulers]);
		}

		// Элементы управления:


		// Секция стандартных элементов движка:
		drawLagometer();
		drawCursor();
		lag->setTimeTo();
	}
	void unload() override
	{
		delete lag;
		delete[] typecolors;
	}
private:
	RGBA				*typecolors;					// Цвета разных элементов
	FVECTOR2			tang_ruler_pos;					// Позиция центра шкалы ТГ
	FVECTOR2			tang_ruler_arr;					// Позиция стрелки шкалы ТГ
	float				seg;							// Количество делений шкалы ТГ
	float				tang_ruler_rad;					// Радиус окружности шкалы ТГ
};