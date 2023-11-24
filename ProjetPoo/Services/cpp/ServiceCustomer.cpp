#include "../h/ServiceCustomer.h"



NS_Service::ServiceCustomer::ServiceCustomer()
{
	this->mMap = gcnew MappageCustomer();
	this->mComDB = gcnew NS_Composant::CommunicationDatabase();
	this->mODs = gcnew System::Data::DataSet();
}

NS_Service::ServiceCustomer::~ServiceCustomer()
{
	delete this->mComDB;
	delete this->mMap;
	delete this->mODs;
}

System::Data::DataSet^ NS_Service::ServiceCustomer::Display(int id_cust, array<String^>^ dataTableName)
{
	this->GetDataSet()->Clear();
	this->mMap->SetChoice(0);
	this->mMap->SetId(id_cust);
	this->SetDataSet(this->GetCom()->GetRows(this->mMap->SELECT(), dataTableName));
	return this->GetDataSet();
}

System::Data::DataSet^ NS_Service::ServiceCustomer::DisplayAll(array<String^>^ dataTableName)
{
	this->GetDataSet()->Clear();
	this->mMap->SetChoice(1);
	this->mODs = this->GetCom()->GetRows(this->mMap->SELECT(), dataTableName);
	return this->mODs;
}

System::Data::DataSet^ NS_Service::ServiceCustomer::DisplayAddr(int _indexP, array<String^>^ dataTableName, array<String^>^ tmp_del, array<String^>^ tmp_bill)
{
	this->mMap->SetId(_indexP);
	this->mMap->SetChoice(2);
	this->SetDataSet(this->GetCom()->GetRows(this->mMap->SELECT(), dataTableName));

	int lengthAddr = this->GetDataSet()->Tables[dataTableName[0]]->Rows->Count;
	System::Data::DataSet^ data_del = gcnew System::Data::DataSet();
	System::Data::DataSet^ data_bill = gcnew System::Data::DataSet();

	for (int i = 0; i < lengthAddr; i++)
	{
		this->mMap->GetMapAd()->SetId(Convert::ToInt32(this->GetDataSet()->Tables[dataTableName[0]]->Rows[i]->ItemArray[0]));

		if (this->GetDataSet()->Tables[dataTableName[0]]->Rows[i]->ItemArray[1]->ToString() == "deliver")
		{
			data_del->Merge(this->GetCom()->GetRows(this->mMap->GetMapAd()->SELECT(), tmp_del));
		}
		else if (this->GetDataSet()->Tables[dataTableName[0]]->Rows[i]->ItemArray[1]->ToString() == "bill")
		{
			data_bill->Merge(this->GetCom()->GetRows(this->mMap->GetMapAd()->SELECT(), tmp_bill));
		}
	}

	this->GetDataSet()->Merge(data_del);
	this->GetDataSet()->Merge(data_bill);

	return this->GetDataSet();
}

System::Data::DataSet^ NS_Service::ServiceCustomer::GetCities(array<String^>^ dataTableName)
{
	this->GetDataSet()->Clear();
	this->mODs = this->GetCom()->GetRows(this->mMap->GetMapAd()->GetCity(), dataTableName);
	return this->mODs;
}

void NS_Service::ServiceCustomer::Delete(int id)
{
	this->mMap->SetChoice(0);
	this->mMap->SetId(id);
	array<String^>^ table_ad = gcnew array<String^>(1);
	table_ad[0] = "ad";
	System::Data::DataSet^ id_ad = this->GetCom()->GetRows(this->mMap->DELETE(), table_ad);

	
	this->mMap->SetChoice(1);
	this->GetCom()->ActionRows(this->mMap->DELETE());

	this->mMap->SetChoice(2);
	int i = 0;
	int length = id_ad->Tables[table_ad[0]]->Rows->Count;
	
	while (i < length)
	{
		this->mMap->GetMapAd()->SetId(Convert::ToInt32(id_ad->Tables[table_ad[0]]->Rows[i]->ItemArray[0]));
		this->GetCom()->ActionRows(this->mMap->DELETE());
		i++;
	}
}

void NS_Service::ServiceCustomer::Edit(int id_cust, String^ fname, String^ lname, String^ email, String^ bdate)
{
	this->mMap->SetId(id_cust);
	this->mMap->SetFirstName(fname);
	this->mMap->SetLastName(lname);
	this->mMap->SetEmail(email);
	this->mMap->SetBirthDate(bdate);

	this->GetCom()->ActionRows(this->mMap->UPDATE());
}

void NS_Service::ServiceCustomer::EditAd(int id, int num, String^ comp, String^ street, int pcode, int city)
{
	this->mMap->GetMapAd()->SetId(id);
	this->mMap->GetMapAd()->SetNum(num);
	this->mMap->GetMapAd()->SetComp(comp);
	this->mMap->GetMapAd()->SetStreet(street);
	this->mMap->GetMapAd()->SetPostalCode(pcode);
	this->mMap->GetMapAd()->SetIdCity(city);

	this->GetCom()->ActionRows(this->mMap->GetMapAd()->UPDATE());
}

array<int>^ NS_Service::ServiceCustomer::Add(String^ fname, String^ lname, String^ email, String^ bdate)
{
	this->mMap->SetChoice(0);
	this->mMap->SetFirstName(fname);
	this->mMap->SetLastName(lname);
	this->mMap->SetEmail(email);
	this->mMap->SetBirthDate(bdate);
	array<int>^ id_p = this->GetCom()->ActionRowsId(this->mMap->INSERT());

	this->mMap->SetChoice(1);

	this->mMap->SetId(id_p[0]);
	this->GetCom()->ActionRows(this->mMap->INSERT());

	return id_p;
}

array<int>^ NS_Service::ServiceCustomer::AddAddress(int num, String^ comp, String^ street, int pcode, int city, int id_p, int type)
{
	this->mMap->GetMapAd()->SetNum(num);
	this->mMap->GetMapAd()->SetComp(comp);
	this->mMap->GetMapAd()->SetStreet(street);
	this->mMap->GetMapAd()->SetPostalCode(pcode);
	this->mMap->GetMapAd()->SetIdCity(city);
	this->SetType(type);

	array<int>^ id_ad = this->GetCom()->ActionRowsId(this->mMap->GetMapAd()->INSERT());

	if (this->GetType() == 0)
	{
		this->mMap->SetChoice(2);
	}
	else
	{
		this->mMap->SetChoice(3);
	}

	this->mMap->SetId(id_p);

	this->mMap->GetMapAd()->SetId(id_ad[0]);
	this->GetCom()->ActionRows(this->mMap->INSERT());
	
	return id_ad;
}

void NS_Service::ServiceCustomer::SetType(int t)
{
	this->type_ad = t;
}

int NS_Service::ServiceCustomer::GetType()
{
	return this->type_ad;
}
