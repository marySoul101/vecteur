#pragma once
#include<iostream>
using namespace std;
namespace mat {
	class Matrice {
	private:
		unsigned int nb_col;
		unsigned int nb_ligne;
		int** matr;
	public:
		Matrice(unsigned int nbl, unsigned int nbc);
		Matrice(Matrice& m) = delete;
		~Matrice();
		void remplissage(int val);
		Matrice& operator=(const Matrice& m)= delete;
		Matrice* operator+(const Matrice& m)const;
		Matrice* operator-(const Matrice& m)const;
		Matrice* operator*(const Matrice& m)const;
		void print() const;
	};
};
