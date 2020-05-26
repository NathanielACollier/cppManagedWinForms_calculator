#pragma once
#include <vector>
#include <string>
#include "stack_type.h"
#include <sstream>
#include <vcclr.h>


using namespace std;
using namespace System;

/*
simple way to convert microsofts string to a
std string
*/
string string_convert( System::String^ str )
{
 string buffer;
 for( int i=0; i < str->Length::get(); ++i )
 {
  buffer += str[i];
 }

 return buffer;
}





namespace calculator {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			stack = new vector<stack_type>;
			buffer = new ostringstream;
		}
        ostringstream* buffer;
	private: System::Windows::Forms::Label^  label1;
	public: 
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  dec_output;
	private: System::Windows::Forms::TextBox^  hex_output;
	private: System::Windows::Forms::TextBox^  oct_output;
	private: System::Windows::Forms::TextBox^  bin_output;






	public: 

	public: 
		vector<stack_type>* stack;
		

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  input_text;
	protected: 

	private: System::Windows::Forms::Button^  equal_button;


	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->input_text = (gcnew System::Windows::Forms::TextBox());
			this->equal_button = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->dec_output = (gcnew System::Windows::Forms::TextBox());
			this->hex_output = (gcnew System::Windows::Forms::TextBox());
			this->oct_output = (gcnew System::Windows::Forms::TextBox());
			this->bin_output = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// input_text
			// 
			this->input_text->Location = System::Drawing::Point(1, 139);
			this->input_text->Name = L"input_text";
			this->input_text->Size = System::Drawing::Size(673, 20);
			this->input_text->TabIndex = 0;
			// 
			// equal_button
			// 
			this->equal_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->equal_button->ForeColor = System::Drawing::Color::Red;
			this->equal_button->Location = System::Drawing::Point(680, 136);
			this->equal_button->Name = L"equal_button";
			this->equal_button->Size = System::Drawing::Size(54, 26);
			this->equal_button->TabIndex = 2;
			this->equal_button->Text = L"=";
			this->equal_button->UseVisualStyleBackColor = true;
			this->equal_button->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::equal_button_MouseClick);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(10, 11);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(48, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Decimal:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(10, 42);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(67, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Hexidecimal:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(10, 73);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(35, 13);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Octal:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(10, 104);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(39, 13);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Binary:";
			// 
			// dec_output
			// 
			this->dec_output->Location = System::Drawing::Point(121, 11);
			this->dec_output->Name = L"dec_output";
			this->dec_output->ReadOnly = true;
			this->dec_output->Size = System::Drawing::Size(553, 20);
			this->dec_output->TabIndex = 7;
			this->dec_output->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// hex_output
			// 
			this->hex_output->Location = System::Drawing::Point(121, 39);
			this->hex_output->Name = L"hex_output";
			this->hex_output->ReadOnly = true;
			this->hex_output->Size = System::Drawing::Size(553, 20);
			this->hex_output->TabIndex = 8;
			this->hex_output->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// oct_output
			// 
			this->oct_output->Location = System::Drawing::Point(121, 70);
			this->oct_output->Name = L"oct_output";
			this->oct_output->ReadOnly = true;
			this->oct_output->Size = System::Drawing::Size(553, 20);
			this->oct_output->TabIndex = 9;
			this->oct_output->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// bin_output
			// 
			this->bin_output->Location = System::Drawing::Point(121, 101);
			this->bin_output->Name = L"bin_output";
			this->bin_output->ReadOnly = true;
			this->bin_output->Size = System::Drawing::Size(553, 20);
			this->bin_output->TabIndex = 10;
			this->bin_output->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(739, 174);
			this->Controls->Add(this->bin_output);
			this->Controls->Add(this->oct_output);
			this->Controls->Add(this->hex_output);
			this->Controls->Add(this->dec_output);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->equal_button);
			this->Controls->Add(this->input_text);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
    double pop(vector<double>& stack) 
	{
     if (stack.empty()) { throw  "Stack underflow."; }
     double result = stack.back();
     stack.pop_back();
     return result;
    }//end pop
  
	string reverse_string( string str )
	{ 
	  string new_string("");
	  for( int i=0; i < (int)str.length(); ++i )
	  {
        new_string.push_back(  str.at( (str.length()-1) - i ) );
	  }
	  return new_string;
	}

	string dec_to_hex( double temp )
	{
      string number("");
      int integer = floor( temp );
	  int fp      = temp - integer;
	  
	  int a = integer;
	  int b = 16;
	  div_t division;
	  division.quot = -1;
	  division.rem = -1;
	  
	  while( division.quot != 0 )
	  {
       division = div( a, b );
	   a = division.quot;
	   switch( division.rem )
	   {
	   case 10: number += "A"; break;
	   case 11: number += "B"; break;
	   case 12: number += "C"; break;
	   case 13: number += "D"; break;
	   case 14: number += "E"; break;
	   case 15: number += "F"; break;
	   default:  number += division.rem + 48; break;
	   }
	   
	  }
	  number += "h0"; // write it backwards so it will be reversed properly

	  return reverse_string( number ); // number will be backwards so we need to reverse it !!!!
	}

	string dec_to_bin( double temp )
	{
      string number("");
      int integer = floor( temp );
	  int fp      = temp - integer;
	  
	  int a = integer;
	  int b = 2;
	  div_t division;
	  division.quot = -1;
	  division.rem = -1;
	  while( division.quot != 0 )
	  {
       division = div( a, b );
	   a = division.quot;
	   number += division.rem + 48;
	  }

	  number += "b0";

	  return reverse_string( number ); // number will be backwards so we need to reverse it !!!!
	}

	string dec_to_oct( double temp )
	{
      string number("");
      int integer = floor( temp );
	  int fp      = temp - integer;
	  
	  int a = integer;
	  int b = 8;
	  div_t division;
	  division.quot = -1;
	  division.rem = -1;
	  while( division.quot != 0 )
	  {
       division = div( a, b );
	   a = division.quot;
	   number += division.rem + 48;
	  }

	  number += "o0";

	  return reverse_string( number ); // number will be backwards so we need to reverse it !!!!
	}

	string dec_to_dec( double temp )
	{
      string number("");
      int integer = floor( temp );
	  int fp      = temp - integer;
	  
	  int a = integer;
	  int b = 10;
	  div_t division;
	  division.quot = -1;
	  division.rem = -1;
	  while( division.quot != 0 )
	  {
       division = div( a, b );
	   a = division.quot;
	   number += division.rem + 48;
	  }

	  return reverse_string( number ); // number will be backwards so we need to reverse it !!!!
	}


	void print_result( double result )
	{
	  string temp;
	  temp = dec_to_dec( result );
	  dec_output->Text = gcnew String( temp.c_str() );
	  temp = dec_to_hex( result );
	  hex_output->Text = gcnew String( temp.c_str() );
      temp = dec_to_oct( result );
	  oct_output->Text = gcnew String( temp.c_str() );
	  temp = dec_to_bin( result );
	  bin_output->Text = gcnew String( temp.c_str() );
	  
	}
    
	/////////////////////////////////////////////////////  BUILD STACK //////////////////////////////////////////////////
    void build_stack()
	{
      string temp =  string_convert( input_text->Text );
	  stack_type current;
	  string number;
	  string function;
	  string operation_text;
	  int pos(0);
	  int stack_pos(0);
      
	  // set up the stack
	  for( int i=0; i < (int)temp.length(); ++i )
			   {
			     
			   

                 if( isdigit( temp[i] ) ) // number
				 {
				   // check for what number system the number uses
				   if( temp[i] == '0' && isalpha( temp[i+1] ) )
				   {
				     pos = i;
				     i+= 2; // to get past the 0h 0b 0o etc...
					 while( isalpha( temp[i] ) || isdigit( temp[i] ) )
					 {
					   number += temp[i];
					   ++i;
					 }

					 switch( temp[ pos + 1]  )
					 {
					 case 'h' : current.number.set_hex( number );  break; // hexidecimal
					 case 'o' : current.number.set_oct( number );  break; // octal
					 case 'b' : current.number.set_bin( number );  break; // binary
					 default  : current.number.set_dec( number );  break; // decimal for now figure out something else later
					 }
					 
				   }
				   else // it is a decimal number
				   {
				    while( isdigit( temp[i] ) )
					{
					 number += temp[i];
				     ++i;
					}
					current.number.set_dec( number );
				   }
				   current.set_num();
				  /* stack->at( stack_pos ) = current;
				   ++stack_pos;*/
				   stack->push_back( current ); // adds the number onto the stack
					number = "";
				 }
                 

				 // if it is a alphabetical character it is most likely a function
				 if( isalpha( temp[i] ) )
				 {
                   while( isalpha( temp[i] ) ) // function would usualy end with a (
				   {
				    function += temp[i];
				    ++i;
				   }
				   // do something with the function
				   current.function.set_function( function );
				   current.set_fun();
				  /* stack->at( stack_pos ) = current;
				   ++stack_pos; */
				   stack->push_back( current );
				   function = "";
				    
				 }

				 if( !isalpha( temp[i] ) && !isdigit( temp[i] ) )
				 {
				  bool opp_not_found = false;
                   // it is most likely an operator
                   switch( temp[i] )
				   {
				    case '+': current.op.set_operator( '+' ); break;
					case '-': current.op.set_operator( '-' ); break;
					case '*': current.op.set_operator( '*' ); break;
					case '^': current.op.set_operator( '^' ); break;
					case '/': current.op.set_operator( '/' ); break;
					case '(': current.op.set_operator( '(' ); break;
					case ')': current.op.set_operator( ')' ); break;
					default: opp_not_found = true; break;
				   }

				   if( opp_not_found == false )
				   {
				     current.set_op();
				    /* stack->at( stack_pos ) = current;
					 ++stack_pos; */
					 stack->push_back( current );
				   }
				   current.clear();
				 }
                current.clear();
			   }// done setting up the stack	   

	}// end of build stack

	////////////////////////////////////// RUN STACK FUNCTION ////////////////////////////////////////////
	void run_stack()
	{
     vector<stack_type> output;
	 vector<stack_type> post_fix_stack;
	 vector<double> temp_stack;
	 int  end = -1;
	 
     // now its time to do something with the stack that has been created
	 // we are going to convert the stack to post fix and put it in the post_fix_stack
     for( int i=0; i < (int)stack->size(); ++i )
	 {
	  if( stack->at( i ).check_num() == true )
	  {
	   output.push_back( stack->at( i ) );
	  }
	  else
      if( stack->at( i ).check_op() == true )
	  {
	   if( end >= 0 && post_fix_stack.at(end).op.get_order() >= stack->at(i).op.get_order()  )
	   {
         while( post_fix_stack.at( end ).op.get_order() >= stack->at(i).op.get_order() )
		 {
           output.push_back( post_fix_stack.at( end ) );
		   post_fix_stack.pop_back();
           --end;
		   if( end <= 0 ) break;
		 }
		   post_fix_stack.push_back( stack->at(i) );
	   }
	   else
	   {
         post_fix_stack.push_back( stack->at(i) );
		 ++end;
	   }
	  }
	  else
	  if( stack->at( i ).check_fun() == true )
	  {

	  }
      
	 }
     
	 // write the rest of the operators
	 while( end >= 0 )
	 {
	  output.push_back( post_fix_stack[ end ] );
	  post_fix_stack.pop_back();
	  --end;
	 }
     
	 double result(0);
	 double left(0);
	 double right(0);
	 // now that the stack is converted to rpn format we can use it
	 end = -1;
	 for( int i=0; i < (int)output.size(); ++i )
	 {
       if( output[i].check_num() == true )
	   {
	    temp_stack.push_back( output[i].number.get_decimal() );
	   }
	   else
	   if( output[i].check_op() == true )
	   {
         switch( output[i].op.get_operator() )
		 {
		 case '+':  temp_stack.push_back( pop(temp_stack) + pop(temp_stack) );  break;
		 case '-':  
			        right = pop( temp_stack );
					left = pop( temp_stack );
					temp_stack.push_back( left - right ); break;
			        break;
		 case '*':  temp_stack.push_back( pop( temp_stack ) * pop( temp_stack ) ); break;
		 case '/':
				 right = pop( temp_stack );
				 left = pop( temp_stack );
				 temp_stack.push_back( left / right );
				 break;

		 default:  break;
		 }
	   }

	  
	    
	 }
	  result = pop( temp_stack );
	  print_result( result );
         
	}// end of run stack

	private: System::Void equal_button_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
			 {
			   // output window is update and calculations are done when the = button is clicked
               			   
			   build_stack(); 
			   run_stack();

			 } 
	};
}

