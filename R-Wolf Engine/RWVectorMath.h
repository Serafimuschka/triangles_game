//	������� ������������ ���� ��� ��������� ����������
//	������ 1.2 Evo, ������ 2.
//	�������������� 100% ����
//	������ � ������������� ������ DLL
//	��������� ����������: 16.09.2019
//	�� ��� ���������������, ������������ � ���������� ���������
//	kalterseele, 2018 - 2019

#pragma once
#include <cmath>

/// <summary>
/// <para>
/// ������� ���������� ��������������� �������������� �������� ������
/// </para>
/// </summary>
namespace RWMath 
{
	// ����� ��
	constexpr float PI = 3.141592741F;
	// �������� ����������
	constexpr float EXP = 2.718281746F;
	// ����� �������
	constexpr float Epsilon = 1E-7F;
	#define radToDeg * 180 / PI		
	#define degToRad * PI / 180
	/// <summary>
	/// <para>
	/// FVECTOR2: 2D-������ � ������������ ���� float
	/// </para>
	/// </summary>
	struct FVECTOR2 
	{
		/// <summary>
		/// <para>
		/// ������������� �������� ������� � ����� (0; 0)
		/// </para>
		/// </summary>
		FVECTOR2() : x(0.f), y(0.f)
		{

		}
		/// <summary>
		/// <para>
		/// ������������� �������� ������� � ����� (_x; _y)
		/// </para>
		/// </summary>
		FVECTOR2(float _x, float _y) : x(_x), y(_y)
		{

		}
		/// <summary>
		/// <para>
		/// ���������� �������
		/// </para>
		/// </summary>
		~FVECTOR2()
		{
			memset(this, 0, sizeof(*this));
		}
		bool operator ==(const FVECTOR2 &vec) 
		{
			return (&vec == this);
		}
		FVECTOR2 operator +(const FVECTOR2& vec)
		{
			return FVECTOR2(this->x + vec.x, this->y + vec.y);
		}
		FVECTOR2 operator -(const FVECTOR2& vec)
		{
			return FVECTOR2(this->x - vec.x, this->y - vec.y);
		}
		FVECTOR2 operator*(const float lambda)
		{
			return FVECTOR2(this->x * lambda, this->y * lambda);
		}
		float x;
		float y;
	};
	/// <summary>
	/// <para>
	/// IVECTOR2: 2D-������ � ������������ ���� int
	/// </para>
	/// </summary>
	struct IVECTOR2 
	{
		/// <summary>
		/// <para>
		/// ������������� �������� ������� � ����� (0; 0)
		/// </para>
		/// </summary>
		IVECTOR2() : x(0), y(0)
		{
			
		}
		/// <summary>
		/// <para>
		/// ������������� �������� ������� � ����� (_x; _y)
		/// </para>
		/// </summary>
		IVECTOR2(int _x, int _y) : x(_x), y(_y)
		{
			
		}
		/// <summary>
		/// <para>
		/// ���������� �������
		/// </para>
		/// </summary>
		~IVECTOR2()
		{
			memset(this, 0, sizeof(*this));
		}
		bool operator ==(const IVECTOR2& vec)
		{
			return (&vec == this);
		}
		bool operator !=(const IVECTOR2& vec)
		{
			return (&vec == this);
		}
		IVECTOR2 operator +(const IVECTOR2& vec)
		{
			return IVECTOR2(this->x + vec.x, this->y + vec.y);
		}
		IVECTOR2 operator -(const IVECTOR2& vec)
		{
			return IVECTOR2(this->x - vec.x, this->y - vec.y);
		}
		IVECTOR2 operator*(const int lambda)
		{
			return IVECTOR2(this->x * lambda, this->y * lambda);
		}
		int x;
		int y;
	};
	enum ReturnTypes
	{
		AS_RADIANS,
		AS_DEGREES,
		IS_FPOINT = 0,
		IS_SPOINT,
		INV_LOGIC = 0,
		INV_BINARY,
	};

	/// <summary>
	/// ������������ ������� ����� �� ���������� � ��������� �������� � ���������� (deg.)
	/// <para>
	/// [center] : ���������� ������ ����������;
	/// </para>
	/// <para>
	/// [arg] : �������� ���� �������� �� ������� ������� �� ��� �������;
	/// </para>
	/// <para>
	/// [radius] : ������ ����������, �� ������� ����� ������ �����;
	/// </para>
	/// <para>
	/// [deg] : ���������� �������� � �������� ��� ��������. True - �������;
	/// </para>
	/// <para>
	/// -> ���������� ����� ����� �������� �� ������� ������� �� ��� �������.
	/// </para>
	/// <para>
	/// --! �������� ���� �������� ����� � ����� (x = radius; y = 0) !--
	/// </para>
	/// </summary>
	inline auto rotation(FVECTOR2 center, float arg, float radius, bool deg = AS_DEGREES)
	{
		if (deg)
		return FVECTOR2
		(
			center.x + radius * cos(arg degToRad),
			center.y + radius * sin(arg degToRad)
		);
		else
		return FVECTOR2
		(
			center.x + radius * cos(arg),
			center.y + radius * sin(arg)
		);
	}

	/// <summary>
	/// ��������� ������ ����� ����������� ����������� �������� ��������
	/// <para>
	/// [pointA] : ���������� ������ ���������� O.1;
	/// </para>
	/// <para>
	/// [pointB] : ���������� ������ ���������� O.2;
	/// </para>
	/// <para>
	/// [a] : ������ ���������� O.1;
	/// </para>
	/// <para>
	/// [b] : ������ ���������� O.2;
	/// </para>
	/// <para>
	/// [point] : ����� ������ ��� ������ ����� �����������;
	/// </para>
	/// <para>
	/// -> ���������� ����� ����������� �����������
	/// </para>
	/// </summary>
	inline auto intersection(FVECTOR2 pointA, FVECTOR2 pointB, float a, float b, bool point = IS_FPOINT)
	{
		float length = sqrt(pow((pointB.x - pointA.x), 2) + pow((pointB.y - pointA.y), 2));

		if (length > a + b) length = a + b;
		if (length < a && a < b) length = b - a;
		else if (length < b && b < a) length = a - b;

		float alpha, beta, gamma, delta;
		alpha = acosf((pow(length, 2) + pow(a, 2) - pow(b, 2)) / (2 * length * a)) radToDeg;
		beta = acosf((pow(a, 2) + pow(b, 2) - pow(length, 2)) / (2 * a * b)) radToDeg;
		gamma = 180.0f - alpha - beta;
		delta = atan2f(pointB.y - pointA.y, pointB.x - pointA.x) radToDeg;

		if (point)
		{
			return rotation(pointA, alpha + delta, a);
		}
		else
		{
			return rotation(pointA, -alpha + delta, a);
		}
	}

	/// <summary>
	/// ��������� ���� ���������� ������� �� ��� �������
	/// <para>
	/// [pointA] : ���������� ������ �������;
	/// </para>
	/// <para>
	/// [pointB] : ���������� ����� �������;
	/// </para>
	/// <para>
	/// -> ���� ���������� ������� � ��������
	/// </para>
	/// </summary>
	inline auto vecAngle(FVECTOR2 pointA, FVECTOR2 pointB)
	{
		return atan2f(pointB.y - pointA.y, pointB.x - pointA.x) radToDeg;
	}

	/// <summary>
	/// ��������� ������ �� �������� ��������
	/// <para>
	/// [root] : ���������� �������;
	/// </para>
	/// <para>
	/// [vec] : ��������, �� ������� ������������ ������;
	/// </para>
	/// <para>
	/// -> ���������� ������� ����� ��������
	/// </para>
	/// </summary>
	inline auto vecMove(FVECTOR2 root, FVECTOR2 vec)
	{
		return FVECTOR2
		(
			root.x + vec.x,
			root.y + vec.y
		);
	}

	/// <summary>
	/// ��������� ����� ��������� �������
	/// <para>
	/// [pointA] : ���������� ������ �������;
	/// </para>
	/// <para>
	/// [pointB] : ���������� ����� �������;
	/// </para>
	/// <para>
	/// -> ����� �������
	/// </para>
	/// </summary>
	inline auto vecLength(FVECTOR2 pointA, FVECTOR2 pointB)
	{
		return sqrt(pow((pointB.x - pointA.x), 2) + pow((pointB.y - pointA.y), 2));
	}

	/// <summary>
	/// ��������� ����� ����� �������
	/// <para>
	/// [from] : ������ �������;
	/// </para>
	/// <para>
	/// [to] : ����� �������;
	/// </para>
	/// <para>
	/// [stepDistance] : ����� ����;
	/// </para>
	/// <para>
	/// -> ���
	/// </para>
	/// </summary>
	inline auto moveAlongTo(FVECTOR2 &from, FVECTOR2 to, float stepDistance)
	{
		float angle = vecAngle(from, to);
		from.x += stepDistance * cos(angle degToRad);
		from.y += stepDistance * sin(angle degToRad);
	}

	// ����� �������
	inline bool inRange(FVECTOR2 vec, FVECTOR2 x_range, FVECTOR2 y_range)
	{
		return (vec.x >= x_range.x && vec.x <= x_range.y) && 
			(vec.y >= y_range.x && vec.y <= y_range.y);
	}

	/// <summary>
	/// ���������� ��������� ��� ���������� �������� ����������.
	/// <para>
	/// [in] : ������� ������;
	/// </para>
	/// <para>
	/// [invmode] : ���������� ��� ��������� ��������. �� ��������� ����������;
	/// </para>
	/// <para>
	/// -> ���
	/// </para>
	/// </summary>
	template<class Any> auto invert(Any& in, bool invmode = INV_LOGIC)
	{
		if (invmode) in = ~in;
		else in = !(static_cast<bool>(in));
	}

	inline bool isEqual(float x, float y)
	{
		return (abs(x - y) < Epsilon);
	}
}

/// <summary>
/// <para>
/// ������� ���������� ��������� ��������������� �������� ������
/// </para>
/// </summary>
namespace RWBinaryOp
{
	enum BinaryOperations
	{
		OP_READ,
		OP_WRITE
	};
#define READ (bool)OP_READ
#define WRITE (bool)OP_WRITE
	/// <summary>
	/// <para>
	/// ���������� �������� ��� �������
	/// </para>
	/// <para>
	/// [cell] : ������, ����� ����������
	/// </para>
	/// <para>
	/// [op] : ��� ��������, READ ��� WRITE
	/// </para>
	/// <para>
	/// [reg] : ����� �������� �� 0 �� 8 * sizeof - 1. ���� �������� ����� ���������� �� ���������� �����������
	/// </para>
	/// <para>
	/// -> �������� �������� � ������
	/// </para>
	/// <para>
	/// �������� WRITE ����������� ��� ����������� �����. ����������� ������������� ������ �������
	/// </para>
	/// <para>
	/// �������� WRITE ����������� �������� ��������� �������� ������
	/// </para>
	/// </summary>
	template<class In> inline bool cellOperation(In cell, bool op, unsigned short reg)
	{
		// ������������� ������ ������ ��� �������� READ:
		In bc(cell);
		// ���������� ������ �������� � �����������:
		if (reg > (8 * sizeof(In) - 1)) reg = 8 * sizeof(In) - 1;
		// ������������� ������������ ��������:
		In point = 1 << reg;
		if (op)	// �������� WRITE
		{
			cell = (bc xor point);
			return true;
		}
		else	// �������� READ
		{
			if ((bc xor point) > cell) return false;
			else return true;
			// (bc xor point) �� ����� ���� ����� cell � ���� ������������ �������� xor
		}
	}

	template<class In> inline bool cellOperation(const In cell, unsigned short reg)
	{
		In bc(cell);
		In point = 1 << reg;
		if ((bc xor point) > cell) return false;
		else return true;
	}
}

namespace RWPhysics 
{
	struct PHYSOBJ 
	{
		PHYSOBJ() :
			weight(0.f),
			vSpeed(0.f),
			gSpeed(0.f),
			velocity(0.f, 0.f),
			gravity(0.f, 0.f)
		{

		}
		PHYSOBJ(
			float _w,
			float _vS,
			float _gS,
			RWMath::FVECTOR2 v,
			RWMath::FVECTOR2 g
		) :
			weight(_w),
			vSpeed(_vS),
			gSpeed(_gS * _w),
			velocity(v),
			gravity(g)
		{
			
		}
		~PHYSOBJ()
		{
			memset(this, 0, sizeof(*this));
		}
		RWMath::FVECTOR2 velocity;
		RWMath::FVECTOR2 gravity;
		float weight;
		float vSpeed;
		float gSpeed;
	};
}