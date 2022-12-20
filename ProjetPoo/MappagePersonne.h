#pragma once
#include "Mappage.h"
#include "MappageAdresse.h"
namespace NS_Composant
{
	ref class MappagePersonne : public Mappage
	{
	private:
		int mId_personne;
		String^ mLastName;
		String^ mFirstName;
		String^ email;
		MappageAdresse^ mMapAd;

		int choice;
	public:
		MappagePersonne();
		~MappagePersonne();
		virtual array<System::Data::SqlClient::SqlCommand^>^ SELECT() override;
		virtual array<System::Data::SqlClient::SqlCommand^>^ DELETE() override;
		virtual array<System::Data::SqlClient::SqlCommand^>^ UPDATE() override;
		virtual array<System::Data::SqlClient::SqlCommand^>^ INSERT() override;
		void SetId(int);
		void SetLastName(String^);
		void SetFirstName(String^);
		void SetEmail(String^);
		void SetChoice(int);
		int GetId();
		String^ GetLastName();
		String^ GetFirstName();
		String^ GetEmail();
		MappageAdresse^ GetMapAd();
		int GetChoice();
	};
}


