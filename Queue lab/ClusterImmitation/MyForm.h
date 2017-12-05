#pragma once
#include "Structs.h"
#include "..\Queue lab\TQueue.h"

namespace ClusterImmitation {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	private:

		Graphics^ gr;
		TQueue<Task> *qTask;
		TQueue<Processor> *qProc;
		Processor *ProcWithTask;
		int TactsCount;




	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Button^  button3;
			





	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

			gr = CreateGraphics();
			qTask = new TQueue<Task>(10);


			/*int ProcCount = Convert::ToInt32(textBox1->Text);
			qProc = new TQueue<Processor>(ProcCount);
			for (int i = 0; i < qProc->getMaxsize(); i++) {
				//qProc[i].push(Processor());

				Processor tmp;
				tmp.free = true;
				tmp.ActiveTaskID = 0;
				tmp.CurrentStepCount = 0;
				tmp.MaxStepCount = 0;
				tmp.InactiveTactsCount = 0;
				tmp.id = qProc->getMaxsize() - 1 - i;

				qProc[i].push(tmp);
				
			}*/

		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  textBox1;
	protected:
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(170, 17);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(66, 22);
			this->textBox1->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 17);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(142, 17);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Кол-во процессоров";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 55);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(119, 17);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Вероятность (%)";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(170, 55);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(66, 22);
			this->textBox2->TabIndex = 2;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox2_TextChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 138);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(122, 17);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Максимум тактов";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(170, 135);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(66, 22);
			this->textBox3->TabIndex = 4;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(12, 95);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(115, 17);
			this->label4->TabIndex = 7;
			this->label4->Text = L"Максимум узлов";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(170, 95);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(66, 22);
			this->textBox4->TabIndex = 6;
			// 
			// timer1
			// 
			this->timer1->Interval = 1000;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(89, 179);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 8;
			this->button1->Text = L"Готово";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(15, 224);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 9;
			this->button2->Text = L"Старт";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(160, 224);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 10;
			this->button3->Text = L"Стоп";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(12, 302);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(99, 17);
			this->label5->TabIndex = 12;
			this->label5->Text = L"Текущий такт";
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(170, 299);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(66, 22);
			this->textBox5->TabIndex = 11;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(33, 360);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(90, 17);
			this->label6->TabIndex = 13;
			this->label6->Text = L"Исключение";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1315, 612);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Name = L"MyForm";
			this->Text = L" ";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void textBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		int ProcCount = Convert::ToInt32(textBox1->Text);

		qProc = new TQueue<Processor>(ProcCount);
		for (int i = 0; i < qProc->getMaxsize(); i++) {
			//qProc[i].push(Processor());

			Processor tmp;
			tmp.free = true;
			tmp.ActiveTaskID = -1;
			tmp.CurrentStepCount = 0;
			tmp.MaxStepCount = 0;
			tmp.InactiveTactsCount = 0;
			tmp.id = qProc->getMaxsize() - 1 - i;

			qProc->push(tmp);
			
		}

		ProcWithTask = new Processor[ProcCount];

		TactsCount = 0;

		int x = 300, y = 10, width = 90, height = 65;
		int dx = 100, dy = 75;
		for (int i = 0; i < ProcCount; i++) {
			qProc->ring[i].X = x;
			qProc->ring[i].Y = y;

			gr->FillRectangle(Brushes::Gray, x, y, width, height);

			if (i % 8 == 7) {
				y += dy;
				x = 300;
			}
			else {
				x += dx;
			}
		}
		
	}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	timer1->Enabled = true;
}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	timer1->Enabled = false;
}
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
	try {

		int CountOfProc = Convert::ToInt32(textBox1->Text);
		int probability = Convert::ToInt32(textBox2->Text);
		int MaxTaskProc = Convert::ToInt32(textBox4->Text);
		int MaxTaskTact = Convert::ToInt32(textBox3->Text);

		int chance = rand() % 101;
		if ((chance >= probability) && ((qTask->isfull()) != 1)) {
			Task temp;
			temp.ID = qTask->getSize();
			temp.ProcCount = rand() % (MaxTaskProc - 1) + 1;
			temp.StepCount = rand() % (MaxTaskTact - 1) + 1;
			qTask->push(temp);
		}
		if ((qTask->isempty()) != 1) {
			while (((qProc->getSize()) >= (qTask->top().ProcCount)) && ((qTask->isempty()) != 1)) {
				Task CurrentTask = qTask->pop();
				for (int i = 0; i < CurrentTask.ProcCount; i++) {
					int CurrentID = qProc->top().id;
					qProc->ring[CurrentID].free = false;
					qProc->ring[CurrentID].ActiveTaskID = CurrentTask.ID;
					qProc->ring[CurrentID].CurrentStepCount = CurrentTask.StepCount;
					qProc->ring[CurrentID].MaxStepCount = CurrentTask.StepCount;

					int color = rand() % 7;
					switch (color) {
					case 0: gr->FillRectangle(Brushes::Red, qProc->top().X, qProc->top().Y, 90, 65); break;
					case 1: gr->FillRectangle(Brushes::Orange, qProc->top().X, qProc->top().Y, 90, 65); break;
					case 2: gr->FillRectangle(Brushes::Yellow, qProc->top().X, qProc->top().Y, 90, 65); break;
					case 3: gr->FillRectangle(Brushes::Green, qProc->top().X, qProc->top().Y, 90, 65); break;
					case 4: gr->FillRectangle(Brushes::Blue, qProc->top().X, qProc->top().Y, 90, 65); break;
					case 5: gr->FillRectangle(Brushes::DarkBlue, qProc->top().X, qProc->top().Y, 90, 65); break;
					case 6: gr->FillRectangle(Brushes::Purple, qProc->top().X, qProc->top().Y, 90, 65); break;
					default: break;
					}

					//ProcWithTask[(qProc->getMaxsize()) - (qProc->getSize())] = (qProc->pop());

					Processor tmp = (qProc->pop());
					ProcWithTask[(qProc->getMaxsize()) - (qProc->getSize()) - 1] = tmp;
				}
			}
		}

		for (int i = 0; i < (qProc->getMaxsize()) - (qProc->getSize()); i++) {
			ProcWithTask[i].CurrentStepCount--;
			if ((ProcWithTask[i].CurrentStepCount) == 0) {
				ProcWithTask[i].free = true;
				ProcWithTask[i].ActiveTaskID = -1;
				ProcWithTask[i].MaxStepCount = 0;

				gr->FillRectangle(Brushes::Gray, ProcWithTask[i].X, ProcWithTask[i].Y, 90, 65);

				qProc->push(ProcWithTask[i]);

				for (int j = i; j < (qProc->getMaxsize()) - (qProc->getSize()) - 1; j++) {
					ProcWithTask[j] = ProcWithTask[j + 1];
				}

				i--;
			}
		}

		for (int i = 0; i < qProc->getMaxsize(); i++) {
			qProc->ring[i].InactiveTactsCount++;
		}

		TactsCount++;
		textBox5->Text = System::Convert::ToString(TactsCount);
	}
	catch (int str) {
		//textBox5->Text = System::Convert::ToString(str);
		label6->Text = System::Convert::ToString(str);
		timer1->Enabled = false;
	}
}
};
}
