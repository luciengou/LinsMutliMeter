#include <MPC82G516.h>
#include <intrins.h>
#include <MCP4011.h>

sbit  EVR_UD	= P4^3;
sbit  EVR_CS	= P4^2;
//======================================
void Increment_R(unsigned char value_up)
{
	unsigned char i;

	EVR_CS = 1;
	EVR_UD = 1;
	_nop_();    //110us
	_nop_();
	EVR_CS = 0;
	_nop_();

     for (i=0; i<value_up; i++)
	{
		EVR_UD = 0;
		_nop_();
		_nop_();
		EVR_UD = 1;
		_nop_();
	}
	EVR_CS = 1;
	_nop_(); 
}
//========================================
void Decrement_R(unsigned char value_down)
{
	unsigned char i;

	EVR_CS = 1;
	EVR_UD = 0;				
	_nop_();    //110us
	_nop_();
	EVR_CS = 0;
	_nop_();
   
     for (i=0; i<value_down; i++)
	{
		EVR_UD = 1;
		_nop_();
		_nop_();
		EVR_UD = 0;
		_nop_();
	}
	EVR_CS = 1;
	_nop_(); 
} 
