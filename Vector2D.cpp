#include "Vector2D.h"


Vector2D::Vector2D()
{
}

Vector2D::Vector2D(float x, float y)
{
}

Vector2D::~Vector2D(void)
{
}

float Vector2D::getX()
{
	return m_x;
}

float Vector2D::getY()
{
	return m_y;
}

void Vector2D::setX(float x)
{
	m_x = x;
}

void Vector2D::setY(float y)
{
	m_y = y;
}

Vector2D Vector2D::operator+(const Vector2D & v2) const
{
	return Vector2D(m_x + v2.m_x, m_y + v2.m_y);
}

Vector2D Vector2D::operator+=(const Vector2D & v2)
{
	m_x += v2.m_x;
	m_y += v2.m_y;
	return *this;
}

Vector2D Vector2D::operator*(float scalar)
{
	return Vector2D(m_x * scalar, m_y * scalar);
}

Vector2D & Vector2D::operator*=(float scalar)
{
	m_x *= scalar;
	m_y *= scalar;
	return *this;
}

Vector2D Vector2D::operator-() const
{
	return Vector2D();
}

Vector2D Vector2D::operator-(const Vector2D & v2) const
{
	return Vector2D(m_x - v2.m_x, m_y - v2.m_y);
}

Vector2D & Vector2D::operator-=(const Vector2D & v2)
{
	m_x -= v2.m_x;
	m_y -= v2.m_y;
	return *this;
}

Vector2D Vector2D::operator/(float scalar)
{
	return Vector2D(m_x / scalar, m_y / scalar);
}

Vector2D & Vector2D::operator/=(float scalar)
{
	m_x /= scalar;
	m_y /= scalar;
	return *this;
}

float Vector2D::length()
{
	return sqrt(m_x * m_x + m_y * m_y);
}

void Vector2D::normalize()
{
	float distancia = length();
	if (distancia > 0)
	{
		(*this) *= 1 / distancia;
	}
}

Vector2D Vector2D::operator=(const Vector2D & v2)
{
	return Vector2D(m_x - v2.m_x, m_y - v2.m_y);
}