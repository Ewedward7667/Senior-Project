#include "globals.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>"
void one_row();
void deposite();
void wall();
void forward(int speed);
void reverse(int speed ,int interval);
void pivot_right(int speed, int interval);
void pivot_left(int speed, int interval);
void swing_right(int speed, int interval);
void swing_left(int speed, int interval);
void swing_right_r(int speed, int interval);
void swing_left_r(int speed, int interval);
void stop();
void orientate();



int main(void) {
  initialize();
int prog=0, bool_=1;
  led_on();
  delay_ms(200);
  led_off();
  delay_ms(200);
  led_on();
  delay_ms(200);
  led_off();
  delay_ms(200);
  print_string("Start Up");
  next_line();
  print_string("Select a Prog");
  delay_ms(1500);
  clear_screen();
  while(bool_){
	print_string("prog " );
	print_int(prog);
	delay_ms(500);
	if(get_sw1()==257)
	{
	    prog++;
		//if(prog>10);
		  // prog=0;
	}
	else
	   bool_=0;
	clear_screen();
  }
  clear_screen();
  print_string("Ready" );
  next_line();  
  print_string("Prog " );
  print_int(prog);
  print_string(" Selected");
  delay_ms(2000);
  clear_screen();
  if(prog==1)
  {
   
       orientate();
	
    /* print_string("Collection");
     one_row();
     deposite();
     clear_screen();
	 print_string("DONE");
	 forward(0);*/
	 
  }
  else if(prog==0)
  {
     print_string("sensor test");
     delay_ms(500);
     clear_screen();
     while(1)
     {
	    forward(100);
        if(digital(0)==1)
	    {  
		   break;
	    }  
	 }
	
     clear_screen();
     
	 print_string("DONE");
     reverse(0, 1000);
	 //stop();
	
  }
  else if(prog==2)
  {
     print_string("ATTACK");
	 forward(100);
	 //swing_left(100,250);
	 clear_screen();
	 print_string("DONE");
	 return 0;
	 //return code?
  }
  return 0;
}
void deposite()
{
	forward(100);
	reverse(100, 800);
	pivot_left(100,700);
    forward(100);
    pivot_left(100, 900); 
	
}
void one_row()
{
  forward(100);
  wall();
 // pivot_right(100,700);
//  forward(100, 1000);
 // pivot_right(100, 1200); 
  forward(100);  
}
void wall()
{
   swing_left_r(-100, 1000);
   forward(100);
   swing_left_r(-100, 750);
   forward(100);
   swing_left_r(-100, 1000);
   forward(100);
   swing_left_r(-100, 2000);
   
   
   
}
void forward(int speed)
{  
   int speed2=speed;
   int right=set_motor_power(0, speed-5);
   int left =set_motor_power(1, speed);
   delay_ms(100);
   
   
}
void stop()
{
   set_motor_power(0, 0);
   set_motor_power(1, 0);
}
void reverse(int speed ,int interval)
{
   set_motor_power(1, -speed);
   set_motor_power(0, -speed);
   delay_ms(interval);
   set_motor_power(0, 0);
   set_motor_power(1, 0);
}
void pivot_right(int speed, int interval)
{
   set_motor_power(0, speed);
   set_motor_power(1, -speed);
   delay_ms(interval);
   set_motor_power(0, 0);
   set_motor_power(1, 0);    
}
void pivot_left(int speed, int interval)
{
   set_motor_power(0, -speed);
   set_motor_power(1, speed);
   delay_ms(interval);
   set_motor_power(0, 0);
   set_motor_power(1, 0);    
}
void swing_right(int speed, int interval)
{
   set_motor_power(1, -speed);
   delay_ms(interval);
   set_motor_power(0, 0);
   set_motor_power(1, 0);    
}
void swing_left(int speed, int interval)
{
   set_motor_power(0, -speed);
   delay_ms(interval);
   set_motor_power(0, 0);
   set_motor_power(1, 0);
}
void swing_right_r(int speed, int interval)
{
   set_motor_power(0, -speed+75);
   set_motor_power(1, -speed);
   delay_ms(interval);
   set_motor_power(0, 0);
   set_motor_power(1, 0);    
}
void swing_left_r(int speed, int interval)
{
   set_motor_power(1, speed);
   set_motor_power(0, speed+75);
   delay_ms(interval);
   set_motor_power(0, 0);
   set_motor_power(1, 0);    
}
void orientate()
{
//sensor left=0 right=1
 //wheels left=1 right=0
 
int bool1=0;
int bool2=0;
set_motor_power(0, 100);
 set_motor_power(1,100);
 delay_ms(100);
while(1){ 
 
 
 
 if(digital(1)==1)
 {
  set_motor_power(0,0);
  delay_ms(100);
  print_string("left det");
  bool1++;
 }
 if(digital(0)==1)
 {
  set_motor_power(1,0);
  delay_ms(100);
  print_string("right det");
  bool2++;
 }
 if(bool1>=1 && bool2>=1)
    break;
	
	
  }
   set_motor_power(0,0);
  set_motor_power(1,0);
  delay_ms(100);
  clear_screen();
  print_string("done");
}
