#pragma once
#include "Mappage.h"

namespace NS_Composant
{
	ref class MappageUser : public Mappage
	{
	private:
		int mIdUser;
		String^ mPwd;
		int mIdP;
	public:
		MappageUser();
		~MappageUser();
		virtual array<System::Data::SqlClient::SqlCommand^>^ SELECT() override;
		virtual array<System::Data::SqlClient::SqlCommand^>^ DELETE() override;
		virtual array<System::Data::SqlClient::SqlCommand^>^ UPDATE() override;
		virtual array<System::Data::SqlClient::SqlCommand^>^ INSERT() override;
		void SetIdUser(int);
		void SetPwd(String^);
		void SetIdP(int);
		int GetIdUser();
		String^ GetPwd();
		int GetIdP();
	};
}


