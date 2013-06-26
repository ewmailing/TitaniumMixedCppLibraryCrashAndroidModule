 %module example
 %{
 /* Includes the header in the wrapper code */
 #include "example.h"
 %}
 
int fact(int n);
int my_mod(int x, int y);
char *get_time();



void emptyCall(void);
double returnDouble(void);
const char* returnString(void);
void passDouble(double num);
void passString(const char* str);
double passAndReturnDouble(double num);
const char* passAndReturnString(const char* str);
void pass2Double(double n1, double n2);
void pass2String(const char* str1, const char* str2);
double* returnDoubleArray2(void);
const char** returnStringArray2(void);
void measure_c_function(void);

/*
%include "typemaps.i"
%apply double* OUTPUT { double* n1, double* n2 };
%inline %{
void multireturn2Double(double* n1, double* n2);
%}
%clear double* n1;      // Remove all typemaps for double *result
%clear double* n2;      // Remove all typemaps for double *result
*/
