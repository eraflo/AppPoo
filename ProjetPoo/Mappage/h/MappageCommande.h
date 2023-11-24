#pragma once
#include "Mappage.h"
namespace NS_Composant
{
	typedef ref struct Basket
	{
		int mIdStock;
		int mPurchaseQuantity;
		double mReductionQuantity;
		Basket^ mNext;
	}Basket;
	typedef ref struct Payment
	{
		int mIdPay;
		String^ mDatePayment;
		String^ mDatePaymentBalance;
		String^ mMeansPayment;
		double mSommePay;
		Payment^ mNext;
	}Payment;
	ref class MappageCommande : public Mappage
	{
	private:
		int mIdCmd;
		String^ mEmissionDate;
		String^ mReferenceCmd;
		double mDiscount;
		String^ mDeliveryDate;
		int mIdCustomer;
		Payment^ mListPayment;
		Basket^ mListArticle;
		int choice;
	public:
		MappageCommande();
		~MappageCommande();
		virtual array<System::Data::SqlClient::SqlCommand^>^ SELECT() override;
		virtual array<System::Data::SqlClient::SqlCommand^>^ DELETE() override;
		virtual array<System::Data::SqlClient::SqlCommand^>^ UPDATE() override;
		virtual array<System::Data::SqlClient::SqlCommand^>^ INSERT() override;
		void SetChoice(int);
		void SetIdCmd(int);
		void SetEmissionDate(String^);
		void SetCmdReference(String^);
		void SetCmdDiscount(double);
		void SetDeliveryDate(String^);
		void SetIdCustomer(int);
		void SetBasket(Basket^);
		void SetPayment(Payment^);
		int GetChoice();
		int GetIdCmd();
		String^ GetEmissionDate();
		String^ GetCmdReference();
		double GetCmdDiscount();
		String^ GetDeliveryDate();
		int GetIdCustomer();
		Basket^ GetBasket();
		Payment^ GetPayment();
	};
}


