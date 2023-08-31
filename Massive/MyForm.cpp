#include "massiv.h"
#include "MyForm.h"
#include "EnterS1_form.h"


using namespace Massiveforms; // Название проекта
using namespace System;
using namespace System::Windows::Forms;
[STAThread]
void main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Massiveforms::MyForm form;
	Application::Run(% form);
	
}
bool f;
System::Void Massiveforms::MyForm::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
	f = 0;
	EnterS1_form^ form = gcnew EnterS1_form;
	form->Del(f);
	this->Hide();
	form->Show();
}

System::Void Massiveforms::MyForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	f = 1;
	EnterS1_form^ form = gcnew EnterS1_form;
	form->Del(f);
	this->Hide();
	form->Show();
}

System::Void Massiveforms::MyForm::button8_Click(System::Object^ sender, System::EventArgs^ e)
{

	Application::Exit();
	
}

System::Void Massiveforms::MyForm::button9_Click(System::Object^ sender, System::EventArgs^ e)
{
	EnterS1_form^ f = gcnew EnterS1_form();
	Array_ S1 = f->Get_S1();
	textBox1->Clear();
	for (int i = 0; i < S1.len();i++) 
	{
		textBox1->Text = textBox1->Text + System::Convert::ToString(S1[i])+" ";
	}
	
}

bool Massiveforms::MyForm::Get_f()
{
	return f;
}

System::Void Massiveforms::MyForm::button10_Click(System::Object^ sender, System::EventArgs^ e)
{
	EnterS1_form^ f = gcnew EnterS1_form();
	Array_ S2 = f->Get_S2();
	textBox2->Clear();
	for (int i = 0; i < S2.len(); i++)
	{
		textBox2->Text = textBox2->Text + System::Convert::ToString(S2[i]) + " ";
	}
}

System::Void Massiveforms::MyForm::button3_Click(System::Object^ sender, System::EventArgs^ e)
{
	EnterS1_form^ f = gcnew EnterS1_form();
	Array_ Sum = f->Get_S1() + f->Get_S2();
	textBox10->Clear();
	for (int i = 0; i < Sum.len(); i++)
	{
		textBox10->Text = textBox10->Text + System::Convert::ToString(Sum[i]) + " ";
	}
}

System::Void Massiveforms::MyForm::button4_Click(System::Object^ sender, System::EventArgs^ e)
{
	EnterS1_form^ f = gcnew EnterS1_form();
	int ans = f->Get_S1().Min();
	textBox11->Clear();
	textBox11->Text = textBox11->Text + System::Convert::ToString(ans);
}

System::Void Massiveforms::MyForm::button5_Click(System::Object^ sender, System::EventArgs^ e)
{
	EnterS1_form^ f = gcnew EnterS1_form();
	int ans = f->Get_S2().Min();
	textBox12->Clear();
	textBox12->Text = textBox12->Text + System::Convert::ToString(ans);
}

System::Void Massiveforms::MyForm::button6_Click(System::Object^ sender, System::EventArgs^ e)
{
	EnterS1_form^ f = gcnew EnterS1_form();
	Array_ temp = f->Get_S1();
	temp.Sorting();
	textBox13->Clear();
	for (int i = 0; i < temp.len(); i++)
	{
		textBox13->Text = textBox13->Text + System::Convert::ToString(temp[i]) + " ";
	}
}

System::Void Massiveforms::MyForm::button7_Click(System::Object^ sender, System::EventArgs^ e)
{
	EnterS1_form^ f = gcnew EnterS1_form();
	bool ans = f->Get_S1() == f->Get_S2() ? 1 : 0;
	textBox14->Clear();
	textBox14->Text = textBox14->Text + System::Convert::ToString(ans);
}
