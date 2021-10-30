#include "pch.h"
#include "matrice.h"
#include<assert.h>
using namespace std;
using namespace mat;

mat::Matrice::Matrice(unsigned int nbl, unsigned int nbc)
{
	this->nb_col = nbc;
	this->nb_ligne = nbl;
	this->matr = new int* [nbl];
	for (int i = 0; i <nbl; i++) this->matr[i] = new int[nbc];
	//assert(nbc > 0 && nbl > 0);
	try 
	{
		if (nbc<= 0 || nbl <=0) throw " Matrice dimension erre";
	}
	catch (char* e)
	{
		cout << e << endl;
	}
	for (int i = 0; i < nbl; i++)
	{
		for (int j = 0; j < nbc; j++) this->matr[i][j] = 0;
	}
}

mat::Matrice::~Matrice()
{
	for (int i = 0; i < this->nb_ligne; i++) delete(this->matr[i]);
	delete(this->matr);
	this->matr = NULL;
}

void mat::Matrice::remplissage(int val)
{
	for (int i = 0; i < this->nb_ligne; i++)
	{
		for (int j = 0; j < this->nb_col; j++) this->matr[i][j] = val;
	}
}


Matrice* mat::Matrice::operator+(const Matrice& m) const
{
	//assert(this->nb_col == m.nb_col && this->nb_ligne == m.nb_ligne);
	try
	{
		if (this->nb_col!=m.nb_col||this->nb_ligne!=m.nb_ligne) throw " impossible d'aditionner 2 matrices qui n'ont pas la meme dimension";
		Matrice* m_addit = new Matrice(this->nb_ligne, this->nb_col);
		for (int i = 0; i < this->nb_ligne; i++)
			for (int j = 0; j < this->nb_ligne; j++)m_addit->matr[i][j] = this->matr[i][j] + m.matr[i][j];
		return m_addit;
	}
	catch (char* e)
	{
		cout << e << endl;
	}
	
	// TODO: insérer une instruction return ici
}

Matrice* mat::Matrice::operator-(const Matrice& m) const
{
	try
	{
		if (this->nb_col != m.nb_col || this->nb_ligne != m.nb_ligne) throw " impossible de soustracter 2 matrices qui n'ont pas la meme dimension";
		Matrice* m_sous = new Matrice(this->nb_ligne, this->nb_col);
		for (int i = 0; i < this->nb_ligne; i++)
			for (int j = 0; j < this->nb_ligne; j++)m_sous->matr[i][j] = this->matr[i][j] - m.matr[i][j];
		return m_sous;
	}
	catch (char* e)
	{
		cout << e << endl;
	}

	// TODO: insérer une instruction return ici
}

Matrice* mat::Matrice::operator*(const Matrice& m) const
{
	try
	{
		if (this->nb_col != m.nb_ligne) throw " impossible de multiplier ces 2 matrices dimension error";
		Matrice* m_mult = new Matrice(this->nb_ligne, m.nb_col);
		for (int i = 0; i < this->nb_ligne; i++)
			for (int j = 0; j < m.nb_col; j++)
				for(int k=0;k<m.nb_ligne;k++)m_mult->matr[i][j] += this->matr[i][k] * m.matr[k][j];
		return m_mult;
	}
	catch (char* e)
	{ 
		cout << e << endl;
	}
	// TODO: insérer une instruction return ici
}



void mat::Matrice::print() const
{
	for (int i = 0; i < this->nb_ligne; i++)
	{
		for (int j = 0; j < this->nb_col; j++) cout << "matrice[" << i << "]" << "[" << j << "]=" << this->matr[i][j] << "\t";
		cout << endl;
	}
}
