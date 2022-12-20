#pragma once

namespace ProjetPoo {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description résumée de Add
	/// </summary>
	public ref class Add : public System::Windows::Forms::Form
	{
	public:
		Add(void)
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
		~Add()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TabControl^ tabControl1;
	private: System::Windows::Forms::TabPage^ tabHomeAdd;
	private: System::Windows::Forms::TabPage^ tabArtAdd;
	protected:


	private: System::Windows::Forms::Button^ butBackAdd;
	private: System::Windows::Forms::TabPage^ tabCmdAdd;
	private: System::Windows::Forms::TabPage^ tabCustAdd;
	private: System::Windows::Forms::TabPage^ tabStaffAdd;




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
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabHomeAdd = (gcnew System::Windows::Forms::TabPage());
			this->butBackAdd = (gcnew System::Windows::Forms::Button());
			this->tabArtAdd = (gcnew System::Windows::Forms::TabPage());
			this->tabCmdAdd = (gcnew System::Windows::Forms::TabPage());
			this->tabCustAdd = (gcnew System::Windows::Forms::TabPage());
			this->tabStaffAdd = (gcnew System::Windows::Forms::TabPage());
			this->tabControl1->SuspendLayout();
			this->tabHomeAdd->SuspendLayout();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabHomeAdd);
			this->tabControl1->Controls->Add(this->tabArtAdd);
			this->tabControl1->Controls->Add(this->tabCmdAdd);
			this->tabControl1->Controls->Add(this->tabCustAdd);
			this->tabControl1->Controls->Add(this->tabStaffAdd);
			this->tabControl1->Location = System::Drawing::Point(1, 0);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(1073, 482);
			this->tabControl1->TabIndex = 0;
			// 
			// tabHomeAdd
			// 
			this->tabHomeAdd->Controls->Add(this->butBackAdd);
			this->tabHomeAdd->Location = System::Drawing::Point(4, 25);
			this->tabHomeAdd->Name = L"tabHomeAdd";
			this->tabHomeAdd->Padding = System::Windows::Forms::Padding(3);
			this->tabHomeAdd->Size = System::Drawing::Size(1065, 453);
			this->tabHomeAdd->TabIndex = 0;
			this->tabHomeAdd->Text = L"Home";
			this->tabHomeAdd->UseVisualStyleBackColor = true;
			// 
			// butBackAdd
			// 
			this->butBackAdd->Location = System::Drawing::Point(350, 33);
			this->butBackAdd->Name = L"butBackAdd";
			this->butBackAdd->Size = System::Drawing::Size(194, 53);
			this->butBackAdd->TabIndex = 0;
			this->butBackAdd->Text = L"Back";
			this->butBackAdd->UseVisualStyleBackColor = true;
			this->butBackAdd->Click += gcnew System::EventHandler(this, &Add::button1_Click);
			// 
			// tabArtAdd
			// 
			this->tabArtAdd->Location = System::Drawing::Point(4, 25);
			this->tabArtAdd->Name = L"tabArtAdd";
			this->tabArtAdd->Padding = System::Windows::Forms::Padding(3);
			this->tabArtAdd->Size = System::Drawing::Size(1065, 453);
			this->tabArtAdd->TabIndex = 1;
			this->tabArtAdd->Text = L"Article";
			this->tabArtAdd->UseVisualStyleBackColor = true;
			// 
			// tabCmdAdd
			// 
			this->tabCmdAdd->Location = System::Drawing::Point(4, 25);
			this->tabCmdAdd->Name = L"tabCmdAdd";
			this->tabCmdAdd->Padding = System::Windows::Forms::Padding(3);
			this->tabCmdAdd->Size = System::Drawing::Size(1065, 453);
			this->tabCmdAdd->TabIndex = 2;
			this->tabCmdAdd->Text = L"Commande";
			this->tabCmdAdd->UseVisualStyleBackColor = true;
			// 
			// tabCustAdd
			// 
			this->tabCustAdd->Location = System::Drawing::Point(5, 25);
			this->tabCustAdd->Name = L"tabCustAdd";
			this->tabCustAdd->Padding = System::Windows::Forms::Padding(3);
			this->tabCustAdd->Size = System::Drawing::Size(1065, 453);
			this->tabCustAdd->TabIndex = 3;
			this->tabCustAdd->Text = L"Customer";
			this->tabCustAdd->UseVisualStyleBackColor = true;
			// 
			// tabStaffAdd
			// 
			this->tabStaffAdd->Location = System::Drawing::Point(5, 25);
			this->tabStaffAdd->Name = L"tabStaffAdd";
			this->tabStaffAdd->Padding = System::Windows::Forms::Padding(3);
			this->tabStaffAdd->Size = System::Drawing::Size(1065, 453);
			this->tabStaffAdd->TabIndex = 4;
			this->tabStaffAdd->Text = L"Staff";
			this->tabStaffAdd->UseVisualStyleBackColor = true;
			// 
			// Add
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1071, 481);
			this->Controls->Add(this->tabControl1);
			this->Name = L"Add";
			this->Text = L"Add";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Add::Add_Closed);
			this->tabControl1->ResumeLayout(false);
			this->tabHomeAdd->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Add_Closed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
		Application::Exit();
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
	}
};
}
