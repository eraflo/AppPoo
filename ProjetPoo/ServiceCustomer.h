#pragma once
#include "Service.h"
#include "MappageCustomer.h"
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
		void Delete(int);
		void Edit(int, String^, String^, String^, String^);
		void EditAd(int, int, String^, String^, int, int);
		int* Add(String^, String^, String^, String^);
		int* AddAddress(int, String^, String^, int, int);
		void SetType(int);
		int GetType();
	};
}


