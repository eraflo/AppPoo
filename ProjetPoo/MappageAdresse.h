#pragma once
#include "Mappage.h"
namespace NS_Composant
{
	ref class MappageAdresse
	{
	private:
		int mId;
		int mNumber;
		String^ mComplement;
		String^ mStreet;
		int mPostalCode;
		int mIdCity;


	public:
		MappageAdresse();
		~MappageAdresse();
		virtual array<System::Data::SqlClient::SqlCommand^>^ SELECT();
		virtual array<System::Data::SqlClient::SqlCommand^>^ DELETE();
		virtual array<System::Data::SqlClient::SqlCommand^>^ UPDATE();
		virtual array<System::Data::SqlClient::SqlCommand^>^ INSERT();
		array<System::Data::SqlClient::SqlCommand^>^ GetCity();
		void SetId(int);
		void SetNum(int);
		void SetComp(String^);
		void SetStreet(String^);
		void SetPostalCode(int);
		void SetIdCity(int);
		int GetId();
		int GetNum();
		String^ GetComp();
		String^ GetStreet();
		int GetPostalCode();
		int GetIdCity();
	};
}


