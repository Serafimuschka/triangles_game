//	������� �������� ���� "������ ��������" ������
//	������ 1.2.1
//	��������� ����������: 16.03.2019
//	�� ��� ���������������, ������������ � ���������� ���������
//	kalterseele, 2018 - 2019

#include "RWLoading.h"
#include "RWHardwareSync.h"

using namespace RWGraphics;
using namespace RWGraphics::Colors;
using namespace RWGraphics::Fonts;
using namespace RWGraphics::Sprite;
using namespace RWGraphics::Animations;
using namespace RWHardwareSync;

void RWLoading::load()
{
	lag = new LAGOMETER();
	checkVars = new unsigned char[1]{ 0 };
	buff = L"# R-Wolf Engine Evo ver. 1.0.0.0.\n# (�) kalterseele, 2018-2019 \n";
	buff += L"# ����������� ������ ���������������� �������.\n";
	buff += L"# ������������� ������� DirectSound � TCP/IP:\n";
	//if (1) buff += L"# ������ TCP/IP ������� �������.\n";
	//else buff += L"�������� ������ ��� ������� ������ TCP/IP!";
	if (RWDirectSound::initialize()) buff += L"# ������ DirectSound �������...\n";
	else buff += L"�������� ������ ��� ������� ������ DirectSound!";
	if (RWDirectSound::initSecondBuffer(60)) buff += L"# �������� ������ ������� �������.\n";
	else buff += L"�������� ������ ��� ������� ������ DirectSound!";
	buff += L"������ �����.";
}

void RWLoading::update() 
{
	lag->setTimeFrom();
}

void RWLoading::render() 
{
	clscr(RGBA(0x0E, 0x0E, 0x0E));
	picture(logoName,
		FVECTOR2(
			getConfigString(ScreenSize_X) / 2.0f - 256.0f, 
			getConfigString(ScreenSize_Y) / 2.0f - 256.0f
		),
		255.0);
	roundedLoading(
		FVECTOR2(
			getConfigString(ScreenSize_X) / 2.0f, 
			getConfigString(ScreenSize_Y) / 2.0f + (getConfigString(ScreenSize_Y) / 2.0f + 256.0f) / 2.0f
		), 
		32.0f, 
		RGBA(32, 178, 170), 
		true, 
		anim);
	text(buff, FVECTOR2(10.0f, 10.0f), white, consolas);
	//drawCursor();
	lag->setTimeTo();
	catchSignal(signalBuffer, this);
}

void RWLoading::unload() 
{
	delete lag;
	delete[] checkVars;
}