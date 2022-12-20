#pragma once
using namespace System;


namespace NS_Composant
{
	ref class Mappage
	{
	private:
		String^ m_email;
		String^ m_pass;
	public:
		Mappage();
		~Mappage();
		virtual array<System::Data::SqlClient::SqlCommand^>^ SELECT();
		virtual array<System::Data::SqlClient::SqlCommand^>^ DELETE();
		virtual array<System::Data::SqlClient::SqlCommand^>^ UPDATE();
		virtual array<System::Data::SqlClient::SqlCommand^>^ INSERT();
		void setEm(String^);
		void setPass(String^);
		String^ getEm(void);
		String^ getPass(void);
	};
}


