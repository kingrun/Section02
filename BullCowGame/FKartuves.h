#pragma once
#include<string>

using FString = std::string;
using int32 = int;

// visi inicializuoti i 0
struct FKartuviuSkaicius 
{
	int32 Blogas = 0;
	int32 Geras = 0;
};

class FKartuves {
public:
	FKartuves(); //konstruktorius

	int32 GautMaxBandymu() const;
	int32 TurimiBandymai() const;
	int32 GautiZodzioIlgi() const;

	bool Pergale() const; 
	bool PatikrintiSpejima(FString) const;

	void Reset(); // sukurti geresni grazinimo atsaka

	// suteikti metoda suskaiciuoti teisingus ir neteisingus atsakymus ir didint spejimu skaiciu, zinant kad tai teisingas spejimas
	FKartuviuSkaicius PateiktSpejima(FString);


private: //ziureti konstruktoriu inicializacijai
	int32 ManoEsamasBandymas;
	int32 ManoMaxBandymas;
	FString ManoPasleptasZodis;
};