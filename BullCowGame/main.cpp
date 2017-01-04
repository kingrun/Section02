#include <iostream> //prideti komandu biblioteka pagal nutylejima
#include <string> //prideti veiksma operatoriui >>
#include "FKartuves.h"

// namespace priskiria pagrindine komanda std, kad nenaudot kartu su std::cout ir std::cin ir t.t.

void SpausdintiPradzia();
void Zaisti();
bool KlaustiArKartoti();
std::string GautSpejima();

FKartuves KZaidimas; // sukurti nauja zaidima

//Programos pradzia
int main() 
{
	std::cout << KZaidimas.TurimiBandymai();
	bool bKartotZaidima = false;
	do {
		SpausdintiPradzia();
		Zaisti();
		bKartotZaidima = KlaustiArKartoti();
	} 
	while (bKartotZaidima);
	return 0;
}

// zaidimo pristatymas
void SpausdintiPradzia() 
{
	constexpr int ZODZIO_ILGIS = 5;
	std::cout << "Kartuves\n";
	std::cout << "Atspek zodi is " << ZODZIO_ILGIS;
	std::cout << " raidziu!\n";
	std::cout << std::endl;
	return;
}

void Zaisti()
{
	KZaidimas.Reset();
	int MaxBandymai = KZaidimas.GautMaxBandymu();

	// kartoti nurodyta kieki kartu
	for (int count = 1; count <= MaxBandymai; count++)
	{
		std::string Spejimas = GautSpejima();
		//rodyt spejima ekrane
		std::cout << "Jusu spejimas: " << Spejimas << std::endl;
		std::cout << std::endl;
	}
}

std::string GautSpejima()
{
	int ManoEsamasBandymas = KZaidimas.TurimiBandymai();
	//gaunam spejima is zaidejo
	std::cout << "Spejimas " << ManoEsamasBandymas << ". Iveskite spejima: "; 
	std::string Spejimas = "";
	std::getline(std::cin, Spejimas);
	return Spejimas;
}

bool KlaustiArKartoti()
{
	std::cout << "Ar norite kartoti zaidima? (T/N)";
	std::string Atsakas = "";
	std::getline(std::cin, Atsakas);

	return (Atsakas[0] == 't') || (Atsakas[0] == 'T');
}