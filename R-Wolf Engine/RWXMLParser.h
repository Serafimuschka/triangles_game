//	������� ������������ ���� ��� �������� XML ��������
//	������������ ���������� TinyXML
//	������ 1.2.1
//	��������� ����������: 20.03.2019
//	�� ��� ���������������; ������������ � ���������� ���������
//	kalterseele, 2018 - 2019

#pragma once
#include <Windows.h>
//#include "tinyxml/tinyxml.h"

class RWScript {
public:
//	TiXmlDocument file;
	LPCSTR docName;
	bool loadFile(LPCSTR);
	void listFile(LPCSTR);
private:

};