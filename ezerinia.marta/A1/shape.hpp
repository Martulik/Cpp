#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "base-types.hpp"

class Shape
{
public:
	virtual void showCenter() = 0;
	virtual double getArea() = 0;								//���������� �������
	virtual rectangle_t getFrameRect() = 0;						//��������� ��������������� ��������������
	virtual void move(const point_t& point) = 0;				//����������� ������ ������ � ���������� �����
	virtual void move(const double& x, const double& y) = 0;	//����������� ������ ������ � ���� �������� �� ���� ������� � �������
	virtual ~Shape() = default;
};

#endif