#ifndef CALC_EXAMPLE_H
#define CALC_EXAMPLE_H

#ifdef __cplusplus
extern "C" {
#endif	
int fact(int n);
int my_mod(int x, int y);
char *get_time();

struct MyStruct
{
	double x;
	double y;
	double z;
};

struct MyStruct MyStructMake(double the_x, double the_y, double the_z);
struct MyStruct AddStructs(struct MyStruct struct1, struct MyStruct struct2);


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

void multireturn2Double(double* n1, double* n2);
void multireturn2String(const char** n1, const char** n2);

void measure_c_function(void);

#ifdef __cplusplus
}
#endif	
#endif
