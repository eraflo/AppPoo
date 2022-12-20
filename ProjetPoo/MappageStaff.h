#pragma once
#include "MappagePersonne.h"
#include "MappageUser.h"

namespace NS_Composant
{
	ref class MappageStaff : public MappagePersonne
	{
	private:
		int mIdManager;
		String^ mHiringDate;
		int mIdAd;
		MappageUser^ compte;

		int choice;
	public:
		MappageStaff();
		~MappageStaff();
		virtual array<System::Data::SqlClient::SqlCommand^>^ SELECT() override;
		virtual array<System::Data::SqlClient::SqlCommand^>^ DELETE() override;
		virtual array<System::Data::SqlClient::SqlCommand^>^ UPDATE() override;
		virtual array<System::Data::SqlClient::SqlCommand^>^ INSERT() override;
		void SetIdManager(int);
		void SetHiringDate(String^);
		void SetIdAd(int);
		void SetChoice(int);
		int GetIdManager();
		String^ GetHiringDate();
		int GetIdAd();
		MappageUser^ GetMapUser();
		int GetChoice();
	};
}


