#pragma once
#include "Service.h"
#include "MappageArticle.h"
namespace NS_Service
{
	ref class ServiceStock : public Service
	{
	private:
		MappageArticle^ mMap;
	public:
		ServiceStock();
		~ServiceStock();
		System::Data::DataSet^ Display(int, array<String^>^);
		System::Data::DataSet^ DisplayAll(array<String^>^);
		System::Data::DataSet^ GetIdCol(String^, array<String^>^);
		System::Data::DataSet^ GetAllCat(array<String^>^);
		array<int>^ Add(String^, String^, String^, double, double, int, array<ColorStock^>^);
		array<int>^ AddColor(String^);
		void Edit(int, String^, String^, String^, double, double, int, array<ColorStock^>^);
		void Delete(int);
		NS_Composant::ColorStock^ remplirPanier(array<ColorStock^>^);

	};
}


