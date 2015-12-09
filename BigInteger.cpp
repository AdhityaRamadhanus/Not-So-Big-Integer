/***************************** BEGIN ********************************/

#include <stdlib.h>
#include <stdio.h>
#include "BigInteger.h"

//Implementasi Konstruktor
BigInteger::BigInteger(){
	mpz_init_set_ui(val,0);
	base=10;//Default Base
}
BigInteger::BigInteger(bool Zero,unsigned int bitcount){
    mpz_init2(val,bitcount);
    base=10;
}
BigInteger::BigInteger(int in){
	mpz_init_set_si(val,in);
	base=10;//Default Base
}
BigInteger::BigInteger(unsigned int in){
	mpz_init_set_ui(val, in);
	base=10;//Default Base
}
BigInteger::BigInteger(const BigInteger &in){
	mpz_init_set(val,in.val);
	base=in.base;}
BigInteger::BigInteger(char* a,int base){
	mpz_init_set_str(val,a,base);
	base=base;
}
BigInteger::BigInteger(mpz_t a)	{
	mpz_init_set(val, a);
	base=10;}

//Implementasi Konstruktor
BigInteger::~BigInteger(){
	mpz_clear(val); }	// releases memory

//Method getter setter base
int	BigInteger::getbase()	{ return base; }
void BigInteger::setbase(int b)	{ base = b; }

//
// Casting
//
BigInteger::operator bool(void)	{
	return (bool) (mpz_cmp_ui(val,0))? 1 :0; }
BigInteger::operator int(void)	{
	return (int)  mpz_get_si(val); }
BigInteger::operator unsigned int(void)	{
	return (unsigned int) mpz_get_ui(val); }
BigInteger::operator float(void)	{
	return (float) mpz_get_d(val); }
BigInteger::operator double(void)	{
	return (double) mpz_get_d(val); }

void BigInteger::operator =(BigInteger a)	{
	mpz_set(val, a.val);
	base=a.base;}
void BigInteger::operator =(int a){
	mpz_set_si(val, a);
	base=10;}
void BigInteger::operator =(unsigned int a){
	mpz_set_ui(val, a);
	base=10;}
void BigInteger::operator =(std::string a)	{
	char * cstr = new char [a.length()+1];
  	std::strcpy(cstr, a.c_str());
	mpz_set_str(val, cstr, 10);
	base=10;}
void BigInteger::operator =(const char *a)	{
	mpz_set_str(val, a, 10); base=10;}
void BigInteger::operator =(mpz_t a)	{
	mpz_set(val, a); base=10; }
//Operator unary
BigInteger BigInteger::operator-() {
	BigInteger r;
	mpz_neg(r.val, val); //Negasikan val
	return r; }
bool BigInteger::operator !() {
	return (mpz_cmp_ui(val, 0)==0)? 1 : 0;}
void BigInteger::operator +=(BigInteger a) {
	mpz_add(val, val, a.val); //val=val+a.val
	}
void BigInteger::operator +=(int a) {
	if (a>0) mpz_add_ui(val,val,a);
	else  mpz_sub_ui(val,val,-a);
}
void BigInteger::operator +=(unsigned int a) {
	mpz_add_ui(val, val, a);}
void BigInteger::operator -=(BigInteger a){
	mpz_sub(val, val, a.val);}
void BigInteger::operator -=(int a)		{
	if(a>0) mpz_sub_ui(val, val, a);
	else mpz_add_ui(val, val, -a); }
void BigInteger::operator -=(unsigned int a) {
	 mpz_sub_ui(val, val, a); }
void BigInteger::operator *=(BigInteger a) {
	 mpz_mul(val, val, a.val); }
void BigInteger::operator *=(int a) {
	 mpz_mul_ui(val, val,(a>0)? a :-a);
	 if (a<0) mpz_neg(val,val);}
void BigInteger::operator *=(unsigned int a){
	 mpz_mul_ui(val, val, a); }
void BigInteger::operator /=(BigInteger a) { mpz_tdiv_q(val, val, a.val); }
void BigInteger::operator /=(int a)		{ mpz_tdiv_q_ui(val, val,(a>0)? a:-a); if (a<0) mpz_neg(val,val);}
void BigInteger::operator /=(unsigned int a)	{ mpz_tdiv_q_ui(val, val, a); }
void BigInteger::operator %=(BigInteger a)		{ mpz_mod(val, val, a.val); }
void BigInteger::operator %=(int a)		{ mpz_mod_ui(val, val, a); }
void BigInteger::operator ^=(int a)		{ mpz_pow_ui(val, val, a); }

BigInteger	BigInteger::operator ++(void) { mpz_add_ui(val, val, 1); return val;}
BigInteger	BigInteger::operator --(void) { mpz_sub_ui(val, val, 1); return val;}

BigInteger	operator +(BigInteger a, BigInteger b) {BigInteger c;mpz_add(c.val,a.val,b.val);return c;}
BigInteger	operator +(BigInteger a, int b) {BigInteger c; if (b>0) mpz_add_ui(c.val,a.val,b); else mpz_sub_ui(c.val, a.val, -b); return c;}
BigInteger	operator +(int a, BigInteger b) { return b+a; }
BigInteger	operator -(BigInteger a, BigInteger b) {BigInteger c;mpz_sub(c.val,a.val,b.val);return c;}
BigInteger	operator -(BigInteger a, int b) { return a + (-b);}
BigInteger	operator -(int a, BigInteger b) { return -(b-a); }
BigInteger	operator *(BigInteger a, BigInteger b) {BigInteger c; mpz_mul(c.val, a.val, b.val); return c; }
BigInteger	operator *(BigInteger a, int b) {BigInteger c; mpz_mul_ui(c.val, a.val, (b>0)? b:-b); if (b<0) return -c; else return c; }
BigInteger	operator *(int a, BigInteger b) { return b*a; }
BigInteger	operator /(BigInteger a, BigInteger b) {BigInteger c; mpz_tdiv_q(c.val, a.val, b.val); return c; }
BigInteger	operator /(BigInteger a, int b) {BigInteger c; mpz_tdiv_q_ui(c.val, a.val, (b>0)? b:-b); if (b<0) return -c; else return c; }
BigInteger	operator /(int a, BigInteger b) {BigInteger c; c = a; return c/b; }
BigInteger	operator %(BigInteger a, BigInteger b) {BigInteger c; mpz_mod(c.val, a.val, b.val); return c; }
BigInteger	operator %(BigInteger a, int b) {BigInteger c; mpz_mod_ui(c.val, a.val, b); return c; }
BigInteger	operator %(int a, BigInteger b) {BigInteger c; c = a; return c%b; }
BigInteger	operator ^(BigInteger a, BigInteger b) {BigInteger c; mpz_xor(c.val, a.val, b.val); return c; }
BigInteger	operator &(BigInteger a, BigInteger b) {BigInteger c; mpz_and(c.val, a.val, b.val); return c; }
BigInteger	operator |(BigInteger a, BigInteger b) {BigInteger c; mpz_ior(c.val, a.val, b.val); return c; }
bool operator ==(BigInteger a, BigInteger b) {return (mpz_cmp(a.val, b.val)==0)? 1:0;}
bool operator ==(BigInteger a, int b) {return (mpz_cmp_si(a.val, b)==0)? 1:0;}
bool operator ==(int a, BigInteger b) {return (b==a); }
bool operator !=(BigInteger a, BigInteger b) {return (mpz_cmp(a.val, b.val)!=0)? 1:0;}
bool operator !=(BigInteger a, int b) {return (mpz_cmp_si(a.val, b)!=0)? 1:0;}
bool operator !=(int a, BigInteger b) {return (b!=a); }
bool operator <(BigInteger a, BigInteger b) {return (mpz_cmp(a.val, b.val)<0)? 1:0;}
bool operator <(BigInteger a, int b) {return (mpz_cmp_si(a.val, b)<0)? 1 : 0;}
bool operator <(int a, BigInteger b) {return (b>a); }
bool operator <=(BigInteger a,BigInteger b) {return (mpz_cmp(a.val, b.val)>0)? 0:1;}
bool operator <=(BigInteger a, int b) {return (mpz_cmp_si(a.val, b)>0)? 0 : 1;}
bool operator <=(int a, BigInteger b) {return (b>=a); }
bool operator >(BigInteger a, BigInteger b) {return (mpz_cmp(a.val, b.val)>0)? 1:0;}
bool operator >(BigInteger a, int b) {return (mpz_cmp_si(a.val, b)>0)? 1 : 0;}
bool operator >(int a, BigInteger b) {return (b<a); }
bool operator >=(BigInteger a, BigInteger b) {return (mpz_cmp(a.val, b.val)<0)? 0:1;}
bool operator >=(BigInteger a, int b) {return (mpz_cmp_si(a.val, b)<0)? 0 : 1;}
bool operator >=(int a, BigInteger b) {return (b<=a); }
int	BigInteger::Log(unsigned int base){ return mpz_sizeinbase(val,base);}
bool BigInteger::Testbit(unsigned long int i){ return (i == mpz_scan1(val, i))? 1 : 0;}
std::string BigInteger::toString(int base){
	std::string valstr = mpz_get_str (NULL, base, val);
	return valstr;}
char* BigInteger::toCstring(int base){
	return mpz_get_str (NULL, base, val);
}
BigInteger Gcd(BigInteger a,BigInteger b){
	BigInteger ret;
	mpz_gcd(ret.val,a.val,b.val);
	return ret;}
BigInteger Lcm(BigInteger a, BigInteger b){
	return (a*b)/Gcd(a,b);}
BigInteger ModExp(BigInteger base, BigInteger exp, BigInteger n){
	BigInteger ret;
	mpz_powm(ret.val,base.val, exp.val, n.val);
	return ret%n;
}
BigInteger ModExp(BigInteger base, int exp, BigInteger n){
	BigInteger ret;
	mpz_powm_ui(ret.val,base.val, exp, n.val);
	return ret%n;
}
BigInteger PowModN(BigInteger a, int b, BigInteger n) {
	BigInteger ret;
	mpz_powm_ui(ret.val, a.val, b, n.val);
	return ret%n;
}
BigInteger PowModN(BigInteger a, BigInteger b, BigInteger n) {
	BigInteger ret;
	mpz_powm(ret.val, a.val, b.val, n.val);
	return ret%n;
}
BigInteger Sqrt(BigInteger a){
	BigInteger ret;
	mpz_sqrt(ret.val, a.val);
	return ret;
}
BigInteger RShift(BigInteger n,unsigned int shift){
	BigInteger ret;
	mpz_tdiv_q_2exp(ret.val, n.val, shift);
	return ret;
}
BigInteger NextPrime(BigInteger a){
	BigInteger ret;
	mpz_nextprime(ret.val,a.val);
	return ret;}
int	Jacobi(BigInteger a, BigInteger b){
    return mpz_jacobi(a.val, b.val);}
int	Legendre(BigInteger a, BigInteger b){
    return mpz_legendre(a.val, b.val);}
void BigInteger::Setbit(unsigned int index){
    mpz_setbit(val,index);
}
 void Swap(BigInteger A, BigInteger B){
    mpz_swap(A.val,B.val);
    int tempbase = A.base;
    A.base = B.base;
    B.base = tempbase;
 }
 BigInteger ModInverse(BigInteger n,BigInteger m){
    BigInteger ret;
    mpz_invert(ret.val,n.val,m.val);
    return ret;
 }



