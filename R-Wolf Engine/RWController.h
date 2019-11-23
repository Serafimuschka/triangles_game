//	������� ������������ ���� ����������� ������
//	������ 1.2.1
//	��������� ����������: 20.03.2019
//	�� ��� ���������������, ������������ � ���������� ���������
//	kalterseele, 2018 - 2019

#pragma once

#include "RWLevel.h"

class RWController {
private:
	RWController();
	~RWController()
	{
		memset(this, 0, sizeof(*this));
	}
	static RWLevel* currentLevel;
	static bool isLoading;
public:
	static void initialize();
	static void uninitialize();
	static void loadInitialLevel(RWLevel* level);
	static void switchLevel(RWLevel* level);
	static void render();
	static void update();
	static auto getLevel() 
	{
		return currentLevel;
	}
};