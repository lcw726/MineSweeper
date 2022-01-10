#pragma once

namespace Final_Project {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// About 的摘要
	/// </summary>
	public ref class About : public System::Windows::Forms::Form
	{
	public:
		About(void)
		{
			InitializeComponent();
			//
			//TODO: 在此加入建構函式程式碼
			//
		}

	protected:
		/// <summary>
		/// 清除任何使用中的資源。
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
		/// 設計工具所需的變數。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器
		/// 修改這個方法的內容。
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
			this->label1->Text = L"江學明、李佳威、林書緯三人小組(Min2wei)";
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
			this->label4->Text = L"本軟體為國立中興大學100學年度第一學期資工系視窗程式設計課程的期末作業作品，參考自Windows作業系統內建的踩地雷遊戲和BBS踩地雷的code所重製而成。純粹" 
				L"學術用途，和商業無關。";
			// 
			// label5
			// 
			this->label5->Location = System::Drawing::Point(23, 203);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(434, 28);
			this->label5->TabIndex = 5;
			this->label5->Text = L"Mine Sweeper為江學明、李佳威、林書緯三人視窗程式設計課程的學術作品，不對外公開，且無任何商業行為。";
			// 
			// label6
			// 
			this->label6->Location = System::Drawing::Point(23, 248);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(244, 17);
			this->label6->TabIndex = 6;
			this->label6->Text = L"指導老師：黃春融  助理教授";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(23, 265);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(385, 12);
			this->label7->TabIndex = 7;
			this->label7->Text = L"學生：資管三 江學明、資管三 李佳威、歷史二 林書緯 (依筆畫順序排列)";
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
