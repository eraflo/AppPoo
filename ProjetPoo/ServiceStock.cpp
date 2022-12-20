#include "ServiceStock.h"


NS_Service::ServiceStock::ServiceStock()
{
	this->mMap = gcnew MappageArticle();
	this->mComDB = gcnew NS_Composant::CommunicationDatabase();
	this->mODs = gcnew System::Data::DataSet();
}

NS_Service::ServiceStock::~ServiceStock()
{
	delete this->mComDB;
	delete this->mMap;
	delete this->mODs;
}

System::Data::DataSet^ NS_Service::ServiceStock::Display(int id, array<String^>^ dataTableName)
{
	this->GetDataSet()->Clear();
	this->mMap->SetChoice(0);
	this->mMap->SetIdArt(id);
	this->SetDataSet(this->GetCom()->GetRows(this->mMap->SELECT(), dataTableName));
	return this->GetDataSet();
}

System::Data::DataSet^ NS_Service::ServiceStock::DisplayAll(array<String^>^ dataTableName)
{
	this->GetDataSet()->Clear();
	this->mMap->SetChoice(1);
	this->SetDataSet(this->GetCom()->GetRows(this->mMap->SELECT(), dataTableName));
	return this->GetDataSet();
}

System::Data::DataSet^ NS_Service::ServiceStock::GetIdCol(String^ name, array<String^>^ dataTableName)
{
	this->GetDataSet()->Clear();
	this->mMap->SetChoice(2);
	this->SetDataSet(this->GetCom()->GetRows(this->mMap->SELECT(), dataTableName));
	this->mMap->SetChoice(0);
	return this->GetDataSet();
}

System::Data::DataSet^ NS_Service::ServiceStock::GetAllCat(array<String^>^ dataTableName)
{
	this->GetDataSet()->Clear();
	this->mMap->SetChoice(3);
	this->SetDataSet(this->GetCom()->GetRows(this->mMap->SELECT(), dataTableName));
	this->mMap->SetChoice(0);
	return this->GetDataSet();
}

int* NS_Service::ServiceStock::Add(String^ ref, String^ name, String^ design, double price, double vat, int cat, array<ColorStock^>^ stocks)
{
	int* id;

	this->mMap->SetRefArticle(ref);
	this->mMap->SetNameArticle(name);
	this->mMap->SetDesignation(design);
	this->mMap->SetPriceUHT(price);
	this->mMap->SetTVA(vat);
	this->mMap->SetIdCategorie(cat);

	ColorStock^ stock = this->remplirPanier(stocks);

	this->mMap->SetStockColor(stock);
	id = this->GetCom()->ActionRowsId(this->mMap->INSERT());
	return id;
}

void NS_Service::ServiceStock::Edit(int id, String^ ref, String^ name, String^ design, double price, double vat, int cat, array<ColorStock^>^ stocks)
{
	this->mMap->SetRefArticle(ref);
	this->mMap->SetNameArticle(name);
	this->mMap->SetDesignation(design);
	this->mMap->SetPriceUHT(price);
	this->mMap->SetTVA(vat);
	this->mMap->SetIdCategorie(cat);

	ColorStock^ stock = this->remplirPanier(stocks);

	this->mMap->SetStockColor(stock);
	this->GetCom()->ActionRows(this->mMap->UPDATE());
}

void NS_Service::ServiceStock::Delete(int _id)
{
	this->mMap->SetIdArt(_id);
	this->GetCom()->ActionRows(this->mMap->DELETE());
}

NS_Composant::ColorStock^ NS_Service::ServiceStock::remplirPanier(array<ColorStock^>^ _stock)
{
	int i = 1;
	NS_Composant::ColorStock^ new_stock = gcnew ColorStock();
	new_stock = _stock[0];
	NS_Composant::ColorStock^ tmp = gcnew ColorStock();
	tmp = new_stock;
	while (i < _stock->Length)
	{
		tmp->mNext = _stock[i];
		tmp = tmp->mNext;
		i++;
	}
	return new_stock;
}
