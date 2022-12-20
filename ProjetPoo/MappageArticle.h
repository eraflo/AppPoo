#pragma once
#include "Mappage.h"
namespace NS_Composant
{
	typedef ref struct ColorStock
	{
		int mIdStock;
		int mQuantityStock;
		int mReplenishmentThreshold;
		double mProdCost;
		String^ mReferenceProductColor;
		int mIdColor;
		String^ colName;
		int mIdArt;
		ColorStock^ mNext;
	}ColorStock;

	ref class MappageArticle : public Mappage
	{
	private:
		int mIdArticle;
		String^ mReferenceArticle;
		String^ mNameArticle;
		String^ mDesignation;
		double mPriceUHT;
		double mTVA;
		int mIdCategorie;
		ColorStock^ mStockColor;

		int choice;
	public:
		MappageArticle();
		~MappageArticle();
		virtual array<System::Data::SqlClient::SqlCommand^>^ SELECT() override;
		virtual array<System::Data::SqlClient::SqlCommand^>^ DELETE() override;
		virtual array<System::Data::SqlClient::SqlCommand^>^ UPDATE() override;
		virtual array<System::Data::SqlClient::SqlCommand^>^ INSERT() override;
		void SetIdArt(int);
		void SetRefArticle(String^);
		void SetNameArticle(String^);
		void SetDesignation(String^);
		void SetPriceUHT(double);
		void SetTVA(double);
		void SetIdCategorie(int);
		void SetStockColor(ColorStock^);
		void SetChoice(int);
		int GetIdArt();
		String^ GetRefArticle();
		String^ GetNameArticle();
		String^ GetDesignation();
		double GetPriceUHT();
		double GetTVA();
		int GetIdCategorie();
		ColorStock^ GetStockColor();
		int GetChoice();
	};
}

