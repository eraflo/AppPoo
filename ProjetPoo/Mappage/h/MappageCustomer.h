#pragma once
#include "MappagePersonne.h"
namespace NS_Composant
{
	ref class MappageCustomer : public MappagePersonne
	{
	private:
		System::String^ mBirthDate;
	public:
		MappageCustomer();
		~MappageCustomer();
		virtual array<System::Data::SqlClient::SqlCommand^>^ SELECT() override;
		virtual array<System::Data::SqlClient::SqlCommand^>^ DELETE() override;
		virtual array<System::Data::SqlClient::SqlCommand^>^ UPDATE() override;
		virtual array<System::Data::SqlClient::SqlCommand^>^ INSERT() override;
		void SetBirthDate(System::String^);
		System::String^ GetBirthdate();

	};
}


