//	������� ������������ ���� "������ ��������"
//	������ 1.2
//	��������� ����������: 16.03.2019
//	�� ��� ���������������, ������������ � ���������� ���������
//	kalterseele, 2018 - 2019

#pragma once
#include "RWLevel.h"
#include "RWController.h"
#include "RWDirectSound.h"
#include "RWTcpIp.h"

class RWLoading : public RWLevel {
private:
	RWGraphics::Animations::ANIM_ROUNDEDLOAD9_GRADIENT anim;
	// �������� ����� ���������� ������
	wstring buff;
	// ���������� - �����
	bool isSystemReady = true;
	// ���������� � ����������� �� �����:
public:
	void load() override;
	void unload() override;
	void update() override;
	void render() override;
};