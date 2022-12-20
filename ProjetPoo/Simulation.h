#pragma once

namespace NS_Composant
{
	typedef double(*variation) (double);
	private delegate double tVariation(double);

	ref class Simulation
	{
	private:
		array<tVariation^>^ mCombiPossible;
		array<tVariation^>^ mCombiChoose;
	public:
		Simulation();
		~Simulation();
		void AddPossibilities(tVariation^);
		double CalculTVA(double);
		double CalculMarge(double);
		double CalculDiscount(double);
		double CalculBrand(double);
	};
}


