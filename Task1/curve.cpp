#include <iostream>
#include "curve.h"
#pragma once

Circle::Circle()
{
	r = 0.1f;
}

Circle::Circle(const float _r)
{
	if (_r <= 0) throw - 1;
	r = _r;
}

float Circle::get_radius()
{
	return r;
}

float Circle::get_area()
{
	area = pi * r * r;
	return area;
}

void Circle::accept(Visitor & visitor)
{
	visitor.visit(this);
}

Ellipse::Ellipse()
{
	a = b = 0.1f;
}

Ellipse::Ellipse(const float _a, const float _b)
{
	if (_a <= 0 || _b <= 0)
		throw - 1;
	a = _a; b = _b;
}

float Ellipse::get_major_axis()
{
	return a;
}

float Ellipse::get_minor_axis()
{
	return b;
}

float Ellipse::get_area()
{
	area = pi * a * b;
	return area;
}

void Ellipse::accept(Visitor & visitor)
{
	visitor.visit(this);
}

void RadiusVisitor::visit(Circle* circle) {
	std::cout << "Circle radius = " << circle->get_radius() << std::endl;
}

void RadiusVisitor::visit(Ellipse* ellipse) {
	std::cout << "Ellipse major axis = " << ellipse->get_major_axis() << ", minor axis = " << ellipse->get_minor_axis() << std::endl;
}