#pragma once
#include "../h/Service.h"
#include "../../Mappage/h/MappageCustomer.h"
namespace NS_Service
{
	ref class ServiceCustomer : Service
	{
	private:
		int type_ad;
		MappageCustomer^ mMap;
	public:
		ServiceCustomer();
		~ServiceCustomer();
		System::Data::DataSet^ Display(int, array<String^>^);
		System::Data::DataSet^ DisplayAll(array<String^>^);
		System::Data::DataSet^ DisplayAddr(int, array<String^>^, array<String^>^, array<String^>^);
		System::Data::DataSet^ GetCities(array<String^>^);
		void Delete(int);
		void Edit(int, String^, String^, String^, String^);
		void EditAd(int, int, String^, String^, int, int);
		array<int>^ Add(String^, String^, String^, String^);
		array<int>^ AddAddress(int, String^, String^, int, int, int, int);
		void SetType(int);
		int GetType();
	};
}


