#pragma once
#include<iostream>
using namespace std;
namespace geo
{
	class Vector
	{
	private:
		float coor[3];
	public:
		Vector(float x = 0.0, float y = 0.0, float z = 0.0);
		Vector(const Vector&) = delete;
		Vector& operator=(const Vector&) = delete;
		void print() const;
		float at(unsigned int indice) const;
		float& operator[](unsigned int indice);
		bool operator==(const Vector& v)const;
		bool operator!=(const Vector& v)const;
		float module()const;
		float operator*(const Vector& v)const;  //le produit scalaire
		void operator*(float val);				//le produit d'un vecteur et une valeur
		Vector* operator^(const Vector& v)const;//le produit vectoriel
		Vector* operator+(const Vector& v)const;
		Vector* operator-(const Vector& v)const;
		void operator/(float val);
		//friend void afficher(Vector& v);//-5
	};
	void afficher(Vector& v);
};
