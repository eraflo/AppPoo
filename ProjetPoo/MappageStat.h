#pragma once
#include "Mappage.h"
namespace NS_Composant
{
	ref class MappageStat : public Mappage
	{
	private:
		int choiceActionNumber;
	public:
		MappageStat();
		~MappageStat();
		virtual array<System::Data::SqlClient::SqlCommand^>^ SELECT() override;
		void SetChoice(int);
		int GetChoice();
	};
}


