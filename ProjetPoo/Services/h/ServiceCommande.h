#pragma once
#include "../h/Service.h"
#include "../../Mappage/h/MappageCommande.h"
namespace NS_Service
{
	ref class ServiceCommande : public Service
	{
	private:
		MappageCommande^ mMap;
	public:
		ServiceCommande();
		~ServiceCommande();
		System::Data::DataSet^ Display(int, array<String^>^);
		System::Data::DataSet^ DisplayAll(array<String^>^);
		void Add(String^, String^, double, String^, int, array<NS_Composant::Basket^>^, array<NS_Composant::Payment^>^);
		void Edit(int, String^, String^, double, String^, array<NS_Composant::Basket^>^, array<NS_Composant::Payment^>^);
		void Invoice(int);
		void Delete(int);
		NS_Composant::Basket^ remplirPanier(array<Basket^>^);
		NS_Composant::Payment^ remplirPaiement(array<Payment^>^);
	};

}

