#include "ServiceStaff.h"


NS_Service::ServiceStaff::ServiceStaff()
{
	this->mMap = gcnew MappageStaff();
	this->mComDB = gcnew NS_Composant::CommunicationDatabase();
	this->mODs = gcnew System::Data::DataSet();
}

NS_Service::ServiceStaff::~ServiceStaff()
{
	delete this->mComDB;
	delete this->mMap;
	delete this->mODs;
}

System::Data::DataSet^ NS_Service::ServiceStaff::Display(int id_staff, array<String^>^ dataTableName)
{
	this->GetDataSet()->Clear();
	this->mMap->SetChoice(0);
	this->mMap->SetId(id_staff);
	this->SetDataSet(this->GetCom()->GetRows(this->mMap->SELECT(), dataTableName));
	return this->GetDataSet();
}

System::Data::DataSet^ NS_Service::ServiceStaff::DisplayAll(array<String^>^ dataTableName)
{
	this->GetDataSet()->Clear();
	this->mMap->SetChoice(1);
	this->SetDataSet(this->GetCom()->GetRows(this->mMap->SELECT(), dataTableName));
	return this->GetDataSet();
}

System::Data::DataSet^ NS_Service::ServiceStaff::DisplayAddr(int _indexAddr, array<String^>^ dataTableName)
{
	int length = dataTableName->Length;
	int i = 0;
	while (i < length)
	{
		if (this->GetDataSet()->Tables->Contains(dataTableName[i]))
		{
			this->GetDataSet()->Tables->Remove(dataTableName[i]);
		}
		i++;
	}
	
	this->mMap->GetMapAd()->SetId(_indexAddr);
	this->SetDataSet(this->GetCom()->GetRows(this->mMap->GetMapAd()->SELECT(), dataTableName));
	return this->GetDataSet();
}

int* NS_Service::ServiceStaff::Add(String^ fname, String^ lname, String^ email, String^ hdate, int sup, int num, String^ comp, String^ street, int pcode, int city)
{
	int* id_p = new int();

	this->mMap->SetChoice(0);
	this->mMap->SetFirstName(fname);
	this->mMap->SetLastName(lname);
	this->mMap->SetEmail(email);
	this->mMap->SetHiringDate(hdate);
	this->mMap->SetIdManager(sup);

	this->mMap->GetMapAd()->SetNum(num);
	this->mMap->GetMapAd()->SetComp(comp);
	this->mMap->GetMapAd()->SetStreet(street);
	this->mMap->GetMapAd()->SetPostalCode(pcode);
	this->mMap->GetMapAd()->SetIdCity(city);

	int* id_ad = new int();
	id_ad = this->GetCom()->ActionRowsId(this->mMap->GetMapAd()->INSERT());

	this->mMap->SetIdAd(id_ad[0]);
	id_p = this->GetCom()->ActionRowsId(this->mMap->INSERT());

	this->mMap->SetChoice(1);

	int i = 0;
	while (i < sizeof(id_p))
	{
		this->mMap->SetId(id_p[i]);
		this->GetCom()->ActionRows(this->mMap->INSERT());
		i++;
	}
	return id_p;
}

int* NS_Service::ServiceStaff::AddUser(String^ pwd, int id)
{
	int* id_p = new int();

	this->mMap->GetMapUser()->SetPwd(pwd);
	this->mMap->GetMapUser()->SetIdP(id);

	id_p = this->GetCom()->ActionRowsId(this->mMap->GetMapUser()->INSERT());

	return id_p;
}

void NS_Service::ServiceStaff::Edit(int id_cust, String^ fname, String^ lname, String^ email, String^ hdate, int sup)
{
	this->mMap->SetId(id_cust);
	this->mMap->SetFirstName(fname);
	this->mMap->SetLastName(lname);
	this->mMap->SetEmail(email);
	this->mMap->SetHiringDate(hdate);

	this->GetCom()->ActionRows(this->mMap->UPDATE());
}

void NS_Service::ServiceStaff::EditAd(int id, int num, String^ comp, String^ street, int pcode, int city)
{
	this->mMap->GetMapAd()->SetId(id);
	this->mMap->GetMapAd()->SetNum(num);
	this->mMap->GetMapAd()->SetComp(comp);
	this->mMap->GetMapAd()->SetStreet(street);
	this->mMap->GetMapAd()->SetPostalCode(pcode);
	this->mMap->GetMapAd()->SetIdCity(city);

	this->GetCom()->ActionRows(this->mMap->GetMapAd()->UPDATE());
}

void NS_Service::ServiceStaff::Delete(int _id)
{
	int* id = new int();
	int i = 0;
	this->mMap->SetChoice(0);
	this->mMap->SetId(_id);
	id = this->GetCom()->ActionRowsId(this->mMap->DELETE());

	this->mMap->SetChoice(3);

	while (i < sizeof(id))
	{
		this->mMap->GetMapAd()->SetId(id[i]);
		this->GetCom()->ActionRows(this->mMap->DELETE());
		i++;
	}

	i = 0;
	id = new int();

	this->mMap->SetChoice(1);
	this->mMap->SetId(_id);
	id = this->GetCom()->ActionRowsId(this->mMap->DELETE());

	this->mMap->SetChoice(4);

	while (i < sizeof(id))
	{
		this->mMap->GetMapUser()->SetIdUser(id[i]);
		this->GetCom()->ActionRows(this->mMap->DELETE());
		i++;
	}
	this->mMap->SetChoice(2);
	this->mMap->SetId(_id);
	id = this->GetCom()->ActionRowsId(this->mMap->DELETE());

}
