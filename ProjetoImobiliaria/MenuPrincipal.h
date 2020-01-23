#pragma once

namespace ProjetoImobiliaria {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Sumário para MenuPrincipal
	/// </summary>
	public ref class MenuPrincipal : public System::Windows::Forms::Form
	{
	public:
		MenuPrincipal(void)
		{
			InitializeComponent();
			//
			//TODO: Adicione o código do construtor aqui
			//
		}

	protected:
		/// <summary>
		/// Limpar os recursos que estão sendo usados.
		/// </summary>
		~MenuPrincipal()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Button^ Cadastrar;
	private: System::Windows::Forms::Button^ Listar;
	private: System::Windows::Forms::Button^ Buscar;
	private: System::Windows::Forms::Button^ Editar;
	private: System::Windows::Forms::Button^ Remover;
	private: System::Windows::Forms::Button^ Sair;
	protected:

	private:
		/// <summary>
		/// Variável de designer necessária.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necessário para suporte ao Designer - não modifique 
		/// o conteúdo deste método com o editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MenuPrincipal::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->Cadastrar = (gcnew System::Windows::Forms::Button());
			this->Listar = (gcnew System::Windows::Forms::Button());
			this->Buscar = (gcnew System::Windows::Forms::Button());
			this->Editar = (gcnew System::Windows::Forms::Button());
			this->Remover = (gcnew System::Windows::Forms::Button());
			this->Sair = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(0, 0);
			this->pictureBox1->MaximumSize = System::Drawing::Size(245, 400);
			this->pictureBox1->MinimumSize = System::Drawing::Size(245, 370);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(245, 370);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// Cadastrar
			// 
			this->Cadastrar->Location = System::Drawing::Point(350, 85);
			this->Cadastrar->Name = L"Cadastrar";
			this->Cadastrar->Size = System::Drawing::Size(84, 33);
			this->Cadastrar->TabIndex = 1;
			this->Cadastrar->Text = L"Cadastrar";
			this->Cadastrar->UseVisualStyleBackColor = true;
			// 
			// Listar
			// 
			this->Listar->Location = System::Drawing::Point(350, 124);
			this->Listar->Name = L"Listar";
			this->Listar->Size = System::Drawing::Size(84, 33);
			this->Listar->TabIndex = 2;
			this->Listar->Text = L"Listar";
			this->Listar->UseVisualStyleBackColor = true;
			// 
			// Buscar
			// 
			this->Buscar->Location = System::Drawing::Point(350, 163);
			this->Buscar->Name = L"Buscar";
			this->Buscar->Size = System::Drawing::Size(84, 33);
			this->Buscar->TabIndex = 3;
			this->Buscar->Text = L"Buscar";
			this->Buscar->UseVisualStyleBackColor = true;
			// 
			// Editar
			// 
			this->Editar->Location = System::Drawing::Point(350, 202);
			this->Editar->Name = L"Editar";
			this->Editar->Size = System::Drawing::Size(84, 33);
			this->Editar->TabIndex = 4;
			this->Editar->Text = L"Editar";
			this->Editar->UseVisualStyleBackColor = true;
			// 
			// Remover
			// 
			this->Remover->Location = System::Drawing::Point(350, 241);
			this->Remover->Name = L"Remover";
			this->Remover->Size = System::Drawing::Size(84, 33);
			this->Remover->TabIndex = 5;
			this->Remover->Text = L"Remover";
			this->Remover->UseVisualStyleBackColor = true;
			// 
			// Sair
			// 
			this->Sair->Location = System::Drawing::Point(350, 280);
			this->Sair->Name = L"Sair";
			this->Sair->Size = System::Drawing::Size(84, 33);
			this->Sair->TabIndex = 6;
			this->Sair->Text = L"Sair";
			this->Sair->UseVisualStyleBackColor = true;
			this->Sair->Click += gcnew System::EventHandler(this, &MenuPrincipal::Sair_Click);
			// 
			// MenuPrincipal
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(514, 371);
			this->Controls->Add(this->Sair);
			this->Controls->Add(this->Remover);
			this->Controls->Add(this->Editar);
			this->Controls->Add(this->Buscar);
			this->Controls->Add(this->Listar);
			this->Controls->Add(this->Cadastrar);
			this->Controls->Add(this->pictureBox1);
			this->MaximumSize = System::Drawing::Size(530, 410);
			this->MinimumSize = System::Drawing::Size(530, 410);
			this->Name = L"MenuPrincipal";
			this->Text = L"LRY Imóveis";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Sair_Click(System::Object^ sender, System::EventArgs^ e) {
		Application::Exit();
	}
};
}
