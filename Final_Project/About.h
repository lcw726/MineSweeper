#pragma once

namespace Final_Project {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// About ���K�n
	/// </summary>
	public ref class About : public System::Windows::Forms::Form
	{
	public:
		About(void)
		{
			InitializeComponent();
			//
			//TODO: �b���[�J�غc�禡�{���X
			//
		}

	protected:
		/// <summary>
		/// �M������ϥΤ����귽�C
		/// </summary>
		~About()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;

	protected: 

	private:
		/// <summary>
		/// �]�p�u��һݪ��ܼơC
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// �����]�p�u��䴩�һݪ���k - �ФŨϥε{���X�s�边
		/// �ק�o�Ӥ�k�����e�C
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(About::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->Location = System::Drawing::Point(12, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(445, 81);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &About::pictureBox1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label1->Location = System::Drawing::Point(23, 103);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(234, 12);
			this->label1->TabIndex = 1;
			this->label1->Text = L"���ǩ��B���Ϋ¡B�L�ѽn�T�H�p��(Min2wei)";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(23, 115);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(126, 12);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Mine Sweeper version 2.7";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(23, 127);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(209, 12);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Copyright (C) 2011 Min2wei Corporation. ";
			// 
			// label4
			// 
			this->label4->Location = System::Drawing::Point(23, 151);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(434, 80);
			this->label4->TabIndex = 4;
			this->label4->Text = L"���n�鬰��ߤ����j��100�Ǧ~�ײĤ@�Ǵ���u�t�����{���]�p�ҵ{�������@�~�@�~�A�ѦҦ�Windows�@�~�t�Τ��ت���a�p�C���MBBS��a�p��code�ҭ��s�Ӧ��C�º�" 
				L"�ǳN�γ~�A�M�ӷ~�L���C";
			// 
			// label5
			// 
			this->label5->Location = System::Drawing::Point(23, 203);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(434, 28);
			this->label5->TabIndex = 5;
			this->label5->Text = L"Mine Sweeper�����ǩ��B���Ϋ¡B�L�ѽn�T�H�����{���]�p�ҵ{���ǳN�@�~�A����~���}�A�B�L����ӷ~�欰�C";
			// 
			// label6
			// 
			this->label6->Location = System::Drawing::Point(23, 248);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(244, 17);
			this->label6->TabIndex = 6;
			this->label6->Text = L"���ɦѮv�G���K��  �U�z�б�";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(23, 265);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(385, 12);
			this->label7->TabIndex = 7;
			this->label7->Text = L"�ǥ͡G��ޤT ���ǩ��B��ޤT ���Ϋ¡B���v�G �L�ѽn (�̵��e���ǱƦC)";
			// 
			// About
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(469, 303);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"About";
			this->Text = L"About";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void richTextBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 }
	};
}
