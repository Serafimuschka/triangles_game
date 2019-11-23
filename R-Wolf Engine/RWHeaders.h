//	������� ������������ ���� �� ����� �������� ����������� � ������ ��������� ������
//	������ 1.2
//	��������� ����������: 16.03.2019
//	�� ��� ���������������, ������������ � ���������� ���������
//	kalterseele, 2018 - 2019

#pragma once

//	��������� WinAPI � Process Status API
#include <Windows.h>
#include <Psapi.h>

//	�������� DirectX, Direct2D, DirectWrite � DXGI
//	������ ������������� ������� ������������ D2D1
#include <D2D1.h>
#include <DXGI.h>
#include <DWrite.h>
#include <DirectxMath.h>
using namespace DirectX;
using namespace D2D1;

//	����������� ��������� C++
//	������ ������������� ������� ������������ STD
#include <wchar.h>
#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <typeinfo>
#include <thread>
#include <mutex>
using namespace std;

//	��������� ������
#include "RWGlobalDefinitions.h"
#include "RWPhysicsConstants.h"
#include "RWStringsParser.h"
#include "RWVectorMath.h"
#include "RWGraphics.h"
#include "RWController.h"
#include "RWLevel.h"
#include "resource.h"