#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

class number_type
{
private:
  bool is_hex;   // number begins with 0h
  bool is_oct;   // number begins with 0o
  bool is_bin;   // number begins with 0b
  bool is_dec;   // number does not begin with anything
  string number; // number is stored as a string
  double decimal_rep;
public:
  number_type();
  void set_hex( string number_text );
  void set_bin( string number_text );
  void set_oct( string number_text );
  void set_dec( string number_text );
  void convert_dec();
  string get_number() const;
  double get_decimal() const;
  void clear();
};

number_type::number_type()
{
 is_hex = false;
 is_oct = false;
 is_bin = false;
 is_dec = false;
 number = "";
 decimal_rep = 0;
}

void number_type::set_hex( string number_text )
{
 is_hex = true;
 is_oct = false;
 is_bin = false;
 is_dec = false;
 number = number_text;
 convert_dec();
}

void number_type::set_oct( string number_text )
{
 is_hex = false;
 is_oct = true;
 is_bin = false;
 is_dec = false;
 number = number_text;
 convert_dec();
}


void number_type::set_bin( string number_text )
{
 is_hex = false;
 is_oct = false;
 is_bin = true;
 is_dec = false;
 number = number_text;
 convert_dec();
}


void number_type::set_dec( string number_text )
{
 is_hex = false;
 is_oct = false;
 is_bin = false;
 is_dec = true;
 number = number_text;
 convert_dec();
}


void number_type::convert_dec()
{
  string temp;
  double n_temp;
  if( is_hex == true )
  {
   for( int i=0; i < (int)number.length(); ++i )
   {
    temp = "";
	temp += number[i];
	switch( tolower( number[i] ) )
	{
	case 'a': n_temp = 10; break;
	case 'b': n_temp = 11; break;
	case 'c': n_temp = 12; break;
	case 'd': n_temp = 13; break;
	case 'e': n_temp = 14; break;
	case 'f': n_temp = 15; break;
	default: n_temp = atof( temp.c_str() ); break;
	}
    decimal_rep += (  n_temp * ( pow( 16, (double)(  (number.length()-1) - i )) ) );
   }
    
  }
  else
  if( is_oct == true )
  {
      for( int i=0; i <  (int)number.length(); ++i )
   {
	   temp = "";
	temp += number[i];
    decimal_rep += (  atof( temp.c_str() ) * ( pow( 8, (double)(   (number.length()-1)  - i )) ) );
   }
  }
  else
  if( is_bin == true )
  {
     for( int i=0; i <  (int)number.length(); ++i )
   {
	   temp = "";
	temp += number[i];
    decimal_rep += (  atof( temp.c_str() ) * ( pow( 2, (double)(  (number.length()-1) - i )) ) );
   }

  }
  else
  {
   decimal_rep = atoi( number.c_str() );
  }
}


string number_type::get_number() const
{
  string temp;
  if( is_hex == true ) temp = "0h" + number;
  if( is_oct == true ) temp = "0o" + number;
  if( is_bin == true ) temp = "0b" + number;
  if( is_dec == true ) temp = number;
  return temp;
}

double number_type::get_decimal() const
{
  return decimal_rep;
}

void number_type::clear()
{
  is_hex = false;
 is_oct = false;
 is_bin = false;
 is_dec = false;
 number = "";
 decimal_rep = 0;
}



class function_type
{
 private:
  string function_name;
  int number_arguments;
 public:
   function_type();
   void set_function( string name );
   void clear();
};

function_type::function_type()
{
 // constructor
 function_name = "";
 number_arguments = 0;
}

void function_type::set_function( string name )
{
  
}

void function_type::clear()
{
 function_name = "";
 number_arguments = 0;
}


class op_value
{
 private:
	char op_text;     // operator value
	int order;
 public:
   op_value();
   void set_operator( char op );
   void clear();
   char get_operator(){ return op_text; }
   int get_order(){ return order; }
};

op_value::op_value()
{
 // constructor
 op_text = '0';
 order = 0;
}



void op_value::set_operator( char op )
{
 op_text = op;
 switch( op )
 {
 case '+': order = 0; break;
 case '-': order = 0; break;
 case '*': order = 1; break;
 case '/': order = 1; break;
 case '^': order = 2; break;
 case ')': order = 3; break;
 case '(': order = 3; break;
 default: order = 0; break;
 }
}

void op_value::clear()
{
 op_text = '0';
}


// this class is used to create objects to store in the stack
class stack_type
{
private:
 bool is_operator;   // type of datatype stored in this object
 bool is_function;   // ...
 bool is_number;      // ...
 
public:
  number_type number;        // number value
  function_type function;   // function value
  op_value op;
  stack_type();
  void set_op(){ is_operator = true; is_function = false; is_number = false; }
  void set_fun(){ is_function = true; is_operator = false; is_number = false;}
  void set_num(){ is_number = true; is_operator = false; is_function = false; }
  bool check_num() const { return is_number; }
  bool check_op() const { return is_operator; }
  bool check_fun() const { return is_function; }
  void clear();
};

stack_type::stack_type()
{
 // constructor
 is_operator = false;
 is_function = false;
 is_number = false;
}

void stack_type::clear()
{
 number.clear();
 function.clear();
 op.clear();
}



