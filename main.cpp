#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

float potega(float x, int k){
	float pot = 1;
	if (k == 0)return 1;
	for (int l = 1; l <= k; l++)
		pot *= x;
	return pot;
}

float silnia(int m){
	float sil = 1;
	for (int p = 1; p <= m; p++)sil *= p;
	return sil;
}



int main(){
	double eps = 0.0000000000001;
	cout << fixed << setprecision(15);
	double liczba = 2.5;
	float funkcjaf = cos(liczba);
	double funkcjad = cos(liczba);
	cout << "float: " << funkcjaf << endl;
	//cout<< "double: " << funkcjad << endl;
	float fobecna = 0, fsuma = 0, fpot = 0, fsil = 0,ftymcz = 0;
	double dobecna = 0, dsuma = 0, dpot = 0, dsil = 0, dtymcz = 0;
	int wyrazow = 0;

	//////////FLOATY/////////////

	////////ze wzoru p->k
		int i = 0;
		do{
		fpot = potega(liczba, 2*i);
		fsil = silnia(2*i);
		fobecna = fpot / fsil;
		if (i%2 ==1)fsuma -= fobecna;
		if (i % 2 == 0) fsuma += fobecna;
		i++;
		wyrazow++;
		} while (fobecna > eps);
	cout <<endl<< "pocz ->koniec (float):  " << fsuma << endl;

	////////z poprzedniego  p->k 
	 fobecna = 1, ftymcz = 0, fsuma = 1, fpot = 0, fsil = 0;

	for (int i = 1; fobecna>eps; i++){
		fpot = liczba*liczba;
		fsil = ((2 * i)*(2 * i - 1));
		ftymcz = fpot / fsil;
		fobecna = ftymcz*fobecna;
		if (i % 2 == 1)fsuma -= fobecna;
		if (i % 2 == 0) fsuma += fobecna;
	}
	cout << endl << "nastepny(float):  pocz->koniec " << fsuma << endl;


	////////ze wzoru k->p
	fobecna = 0, ftymcz = 0, fsuma = 0, fpot = 0, fsil = 0;

	for(int k=wyrazow-1;k>=0;k--){
		fpot = potega(liczba, 2 * k);
		fsil = silnia(2 * k);
		fobecna = fpot / fsil;
		if (k % 2 == 1)fsuma -= fobecna;
		if (k % 2 == 0) fsuma += fobecna;
		

	} ;
	cout << endl << "koniec->poczatek (float):  " << fsuma << endl;


	////////z poprzedniego  k->p //////////////////////////////////////////////
	fobecna = 1, ftymcz = 0, fsuma = 0, fpot = 0, fsil = 0;
	for (int i = 1; i<wyrazow; i++){
		fpot = liczba*liczba;
		fsil = ((2 * i)*(2 * i - 1));
		ftymcz = fpot / fsil;
		fobecna = ftymcz*fobecna;	
	}
	if (wyrazow % 2 == 1)fsuma = -fobecna;
	if (wyrazow % 2 == 0) fsuma = fobecna;
	for (int i = wyrazow-1; i>0; i--){
		fpot = liczba*liczba;
		fsil = ((2 * i)*(2 * i - 1));

		ftymcz = fpot / fsil;
		fobecna = fobecna/ftymcz;
		if (i % 2 == 0)fsuma -= fobecna;
		if (i % 2 == 1) fsuma += fobecna;
	}
	cout << endl << "poprzedni(float):  koniec->poczatek  " << fsuma << endl;

	////////////DOUBLE//////////////////////////////////////////////////////////
	////////ze wzoru p->k double
		 i = 0;
		do{
		dpot = potega(liczba, 2 * i);
		dsil = silnia(2 * i);
		dobecna = dpot / dsil;
		if (i % 2 == 1)dsuma -= dobecna;
		if (i % 2 == 0) dsuma += dobecna;
		i++;
		} while (dobecna > eps);

	//cout << endl << "pocz ->koniec : (double)  " << dsuma << endl;

	dobecna = 1, dtymcz = 0, dsuma = 1, dpot = 0, dsil = 0;
	////////z poprzedniego  p->k double
	for (int i = 1; dobecna > eps; i++){
		dpot = liczba*liczba;
		dsil = ((2 * i)*(2 * i - 1));
		dtymcz = dpot / dsil;
		dobecna = dtymcz*dobecna;
		if (i % 2 == 1)dsuma -= dobecna;
		if (i % 2 == 0) dsuma += dobecna;
	}

	//cout << endl << "nastepny pocz->koniec (double):  " << dsuma << endl;


	////////ze wzoru k->p (double)
	dobecna = 0, dtymcz = 0, dsuma = 0, dpot = 0, dsil = 0;

	for (int k = wyrazow - 1; k >= 0; k--){
		dpot = potega(liczba, 2 * k);
		dsil = silnia(2 * k);
		dobecna = dpot / dsil;
		if (k % 2 == 1)dsuma -= dobecna;
		if (k % 2 == 0) dsuma += dobecna;


	};
	//cout << endl << "koniec->poczatek (double):  " << dsuma << endl;


	////////z poprzedniego  k->p /////////////////
	dobecna = 1, dtymcz = 0, dsuma = 0, dpot = 0, dsil = 0;
	for (int i = 1; i<wyrazow; i++){
		dpot = liczba*liczba;
		dsil = ((2 * i)*(2 * i - 1));
		dtymcz = dpot / dsil;
		dobecna = dtymcz*dobecna;
	}

	if (wyrazow % 2 == 1)dsuma = -dobecna;
	if (wyrazow % 2 == 0) dsuma = dobecna;
	for (int i = wyrazow - 1; i>0; i--){
		dpot = liczba*liczba;
		dsil = ((2 * i)*(2 * i - 1));
		dtymcz = dpot / dsil;
		dobecna = dobecna / dtymcz;
		if (i % 2 == 0)dsuma -= dobecna;
		if (i % 2 == 1) dsuma += dobecna;
	}
	//cout << endl << "poprzedni(double):  koniec->poczatek  " << dsuma << endl;


	system("pause");
	return 0;
}