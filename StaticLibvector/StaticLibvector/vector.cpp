#include "pch.h"
#include "vector.h"
#include<assert.h>
#include<math.h>
using namespace geo;
using namespace std;
Vector:: Vector(float x, float y, float z)
{
	this->coor[0] = x;
	this->coor[1] = y;
	this->coor[2] = z;
}

float Vector::at(unsigned int indice) const
{
	assert(indice >= 0 && indice < 3);//debug
	try //release
	{
		if (indice < 0 || indice >= 3) throw "rang erre";
		return this->coor[indice];
	}
	catch (char* e)
	{
		cout << e << endl;
	}
}

void Vector::print() const
{
	for (int i = 0; i < 3; i++)
	{
		cout << "coor[" << i << "]=" << this->at(i) << endl;
	}
	//cout << "x=" << this->at(0)  << "\ty=" << this->at(1) << "\tz=" << this->at(2);
}

float& Vector::operator[](unsigned int indice)
{
	assert(indice >= 0 && indice < 3);//debug
	try //release
	{
		if (indice < 0 || indice >= 3) throw "rang erre";
		return this->coor[indice];
	}
	catch (char* e)
	{
		cout << e << endl;
	}
}

bool Vector::operator==(const Vector& v) const
{
	bool res = true;
	for (int i = 0; i < 3; i++)
	{
		res = res && (this->at(i) == v.at(i));
	}
	return res;
}

bool Vector::operator!=(const Vector& v) const
{
	bool res = !(*this == v);
	return res;
}

float geo::Vector::module() const
{
	return(sqrt(pow(this->at(0), 2) + pow(this->at(1), 2) + pow(this->at(2), 2)));
}

float geo::Vector::operator*(const Vector& v) const
{
	return(this->at(0) * v.at(0) + this->at(1) * v.at(1) + this ->at(2) * v.at(2));
}

void geo::Vector::operator*(float val)
{
	this->coor[0] *= val;
	this->coor[1] *= val;
	this->coor[2] *= val;
}

Vector* geo::Vector::operator^(const Vector& v) const
{
	Vector* prod = new Vector();
	prod->coor[0] = this->at(1) * v.at(2) - this->at(2) * v.at(1);
	prod->coor[1] = this->at(0) * v.at(2) - this->at(2) * v.at(0);
	prod->coor[2] = this->at(0) * v.at(1) - this->at(1) * v.at(0);
	return prod;
}

Vector* geo::Vector::operator+(const Vector& v) const
{
	Vector* add = new Vector();
	add->coor[0] = this->at(0) + v.at(0);
	add->coor[1] = this->at(1) + v.at(1);
	add->coor[2] = this->at(2) + v.at(2);
	return add;
}

Vector* geo::Vector::operator-(const Vector& v) const
{
	Vector* sous = new Vector();
	sous->coor[0] = this->at(0) - v.at(0);
	sous->coor[1] = this->at(1) - v.at(1);
	sous->coor[2] = this->at(2) - v.at(2);
	return sous;
}

void geo::Vector::operator/(float val) 
{
	this->coor[0] /=val;
	this->coor[1] /= val;
	this->coor[2] /= val;
}

void geo::afficher(Vector& v)
{

	for (int i = 0; i < 3; i++)
	{
		cout << "coor[" << i << "]=" << v.at(i) << endl;
	}
}
