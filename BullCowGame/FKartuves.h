#pragma once
#include<string>
class FKartuves {
public:
	FKartuves(); //konstruktorius

	int GautMaxBandymu() const;
	int TurimiBandymai() const;
	bool Pergale() const; 

	void Reset(); // sukurti geresni grazinimo atsaka
	bool PatikrintiSpejima(std::string); 


private: //ziureti konstruktoriu inicializacijai
	int ManoEsamasBandymas;
	int ManoMaxBandymas;
};