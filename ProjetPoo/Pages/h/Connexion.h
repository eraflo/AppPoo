#pragma once
#include "../../Services/h/Service.h"

namespace ProjetPoo {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description résumée de Connexion
	/// </summary>
	public ref class Connexion : public System::Windows::Forms::Form
	{
	public:
		Connexion(void)
		{
			InitializeComponent();
			//
			//TODO: ajoutez ici le code du constructeur
			//
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~Connexion()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ emailLab;
	protected:
	private: System::Windows::Forms::Label^ passLab;
	private: System::Windows::Forms::TextBox^ emailBox;
	private: System::Windows::Forms::TextBox^ passBox;
	private: System::Windows::Forms::Button^ validateBut;

	private: NS_Service::Service^ serviceCon;
	private: System::Data::DataSet^ data;

	private:
		/// <summary>
		/// Variable nécessaire au concepteur.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette méthode avec l'éditeur de code.
		/// </summary>
		void InitializeComponent(void)
		{
			this->emailLab = (gcnew System::Windows::Forms::Label());
			this->passLab = (gcnew System::Windows::Forms::Label());
			this->emailBox = (gcnew System::Windows::Forms::TextBox());
			this->passBox = (gcnew System::Windows::Forms::TextBox());
			this->validateBut = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// emailLab
			// 
			this->emailLab->AutoSize = true;
			this->emailLab->Location = System::Drawing::Point(250, 98);
			this->emailLab->Name = L"emailLab";
			this->emailLab->Size = System::Drawing::Size(41, 16);
			this->emailLab->TabIndex = 0;
			this->emailLab->Text = L"Email";
			// 
			// passLab
			// 
			this->passLab->AutoSize = true;
			this->passLab->Location = System::Drawing::Point(250, 185);
			this->passLab->Name = L"passLab";
			this->passLab->Size = System::Drawing::Size(67, 16);
			this->passLab->TabIndex = 1;
			this->passLab->Text = L"Password";
			// 
			// emailBox
			// 
			this->emailBox->Location = System::Drawing::Point(373, 98);
			this->emailBox->Name = L"emailBox";
			this->emailBox->Size = System::Drawing::Size(100, 22);
			this->emailBox->TabIndex = 2;
			// 
			// passBox
			// 
			this->passBox->Location = System::Drawing::Point(373, 179);
			this->passBox->Name = L"passBox";
			this->passBox->PasswordChar = '*';
			this->passBox->Size = System::Drawing::Size(100, 22);
			this->passBox->TabIndex = 3;
			// 
			// validateBut
			// 
			this->validateBut->Location = System::Drawing::Point(345, 282);
			this->validateBut->Name = L"validateBut";
			this->validateBut->Size = System::Drawing::Size(75, 23);
			this->validateBut->TabIndex = 4;
			this->validateBut->Text = L"Connect";
			this->validateBut->UseVisualStyleBackColor = true;
			this->validateBut->Click += gcnew System::EventHandler(this, &Connexion::validateBut_Click);
			// 
			// Connexion
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1049, 414);
			this->Controls->Add(this->validateBut);
			this->Controls->Add(this->passBox);
			this->Controls->Add(this->emailBox);
			this->Controls->Add(this->passLab);
			this->Controls->Add(this->emailLab);
			this->Name = L"Connexion";
			this->Text = L"Connexion";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Connexion::Connexion_Closed);
			this->Load += gcnew System::EventHandler(this, &Connexion::Connexion_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Connexion_Load(System::Object^ sender, System::EventArgs^ e) {
		this->serviceCon = gcnew NS_Service::Service();
		this->data = gcnew DataSet();
	}
	private: System::Void Connexion_Closed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
		Application::Exit();
	}
	private: System::Void validateBut_Click(System::Object^ sender, System::EventArgs^ e) {
		if (String::IsNullOrEmpty(this->emailBox->Text))
		{
			MessageBox::Show("Email empty");
		}
		else if (String::IsNullOrEmpty(this->passBox->Text))
		{
			MessageBox::Show("Password empty");
		}
		else
		{
			array<String^>^ table = gcnew array<String^>(1);
			table[0] = "Connexion";
			this->data = this->serviceCon->connecter(table, this->emailBox->Text->ToString(), this->passBox->Text->ToString());
			if (this->data->Tables[table[0]]->Rows[0]->ItemArray[0]->ToString() == "1")
			{
				this->Hide();
			}
			else
			{
				MessageBox::Show("Error, this user doesn't exist");
			}
		}
	}
};
}
