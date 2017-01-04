/* This is the console executable, that makes use of the FKartuves klase 
This acts as the view in a MVC patttern, and is responsible for all user interaction. 
For game logic see the Fkartus class
*/

#include <iostream> //prideti komandu biblioteka pagal nutylejima
#include <string> //prideti veiksma operatoriui >>
#include "FKartuves.h"

using FText = std::string;
using int32 = int;
// namespace priskiria pagrindine komanda std, kad nenaudot kartu su std::cout ir std::cin ir t.t.

void SpausdintiPradzia();
void Zaisti();
bool KlaustiArKartoti();
FText GautSpejima();

FKartuves KZaidimas; // sukurti nauja zaidima

//Programos pradzia
int main() 
{
	std::cout << KZaidimas.TurimiBandymai();
	bool bKartotZaidima = false;
	do {
		SpausdintiPradzia();
		Zaisti();
		// TODO pridezi zaidima summary
		bKartotZaidima = KlaustiArKartoti();
	} 
	while (bKartotZaidima);
	return 0;
}

// zaidimo pristatymas
void SpausdintiPradzia() 
{
	
	std::cout << "Kartuves\n";
	std::cout << "Atspek zodi is " << KZaidimas.GautiZodzioIlgi();
	std::cout << " raidziu!\n";
	std::cout << std::endl;
	return;
}

void Zaisti()
{
	KZaidimas.Reset();
	int32 MaxBandymai = KZaidimas.GautMaxBandymu();

	// kartoti nurodyta kieki kartu
	for (int32 count = 1; count <= MaxBandymai; count++)
	{
		FText Spejimas = GautSpejima(); //TODO tikrinti teisingus spejimus
		//rodyt spejima ekrane
		FKartuviuSkaicius KartuviuSkaicius = KZaidimas.PateiktSpejima(Spejimas);
		//pateikti teisinga spejima i ekrana, parodyti kiek teisingu ir neteisingu spejimu yra
		std::cout << "Teisingi = " << KartuviuSkaicius.Geras;
		std::cout << ". Neteisingi = " << KartuviuSkaicius.Blogas << std::endl;
		std::cout << "Jusu spejimas: " << Spejimas << std::endl;
		std::cout << std::endl;
	}
}
//TODO padaryti summary

FText GautSpejima()
{
	int32 ManoEsamasBandymas = KZaidimas.TurimiBandymai();
	//gaunam spejima is zaidejo
	std::cout << "Spejimas " << ManoEsamasBandymas << ". Iveskite spejima: "; 
	FText Spejimas = "";
	std::getline(std::cin, Spejimas);
	return Spejimas;
}

bool KlaustiArKartoti()
{
	std::cout << "Ar norite kartoti zaidima? (T/N)";
	FText Atsakas = "";
	std::getline(std::cin, Atsakas);

	return (Atsakas[0] == 't') || (Atsakas[0] == 'T');
}