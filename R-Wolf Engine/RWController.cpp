//	������� �������� ���� ����������� �������� ������
//	������ 1.2.1
//	��������� ����������: 20.03.2019
//	�� ��� ���������������, ������������ � ���������� ���������
//	kalterseele, 2018 - 2019

#include "RWHeaders.h"

RWLevel* RWController::currentLevel;
bool RWController::isLoading;

/// <summary>
/// <para>
/// �������������� ����������
/// </para>
/// <para>
/// -> ���
/// </para>
/// </summary>
void RWController::initialize() 
{
	isLoading = true;
	currentLevel = 0;
}

void RWController::uninitialize()
{
	isLoading = false;
	currentLevel->unload();
}

/// <summary>
/// <para>
/// �������������� � ��������� � ������ ������� 
/// </para>
/// <para>
/// [level] : ��������� �� ����� ������
/// </para>
/// <para>
/// -> ���
/// </para>
/// </sunnary>
void RWController::loadInitialLevel(RWLevel* level) 
{
	isLoading = true;
	currentLevel = level;
	currentLevel->load();
	isLoading = false;
}

/// <summary>
/// <para>
/// ����������� ������� ������� �� ��������
/// </para>
/// <para>
/// [level] : ��������� �� ����� ������
/// </para>
/// <para>
/// -> ���
/// </para>
/// </sunnary>
void RWController::switchLevel(RWLevel* level) 
{
	isLoading = true;
	currentLevel->unload();
	level->load();
	delete currentLevel;
	currentLevel = level;
	isLoading = false;
}

/// <summary>
/// <para>
/// ���������� ����� ������� ���������� ������
/// </para>
/// <para>
/// -> ���
/// </para>
/// </sunnary>
void RWController::render() 
{
	if (isLoading) return;
	currentLevel->render();
}

/// <summary>
/// <para>
/// ���������� ����� ������� ������� ������
/// </para>
/// <para>
/// -> ���
/// </para>
/// </sunnary>
void RWController::update() 
{
	if (isLoading) return;
	currentLevel->update();
}