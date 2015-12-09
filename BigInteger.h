#ifndef BIGINTEGER_H_INCLUDED
#define BIGINTEGER_H_INCLUDED
#include <stdlib.h>
#include <gmp.h>		// GNU MP
#include <iostream>		
#include <ostream>
#include <string>
#include <cstring>
#include <time.h>		

class BigInteger {
	public:
		mpz_t val; // value
		int base; // base
	public:

	//Constructor
    BigInteger();
    BigInteger(int a);
    BigInteger(bool Zero,unsigned int bitcount);
    BigInteger(unsigned int val);
    BigInteger(const BigInteger &val);

    BigInteger(char* strval,int base);
    BigInteger(mpz_t a);

	//Destructor
    ~BigInteger();

    //Getter Setter
    int getbase();
    void setbase(int b);

	//Operator casting
    operator bool();		// (bool) val
    operator int();			// (int)  val
    operator unsigned int();// (unsigned int) val
    operator float();		// (float) val
    operator double();		// (double) val

	//Operator assignment
    void operator=(BigInteger bi);	   // val = (BigInteger) bi;
    void operator=(int i);			   // val = (int) i;
    void operator=(unsigned int ui);	   // val = (unsigned int) ui;
    void operator=(std::string strval);		   // val = strval (a string);
    void operator=(const char *strval);	   // val = "1231231";
    void operator=(mpz_t mpzval);	       // val = mpzval (a mpz number);

    //Operator Unary
    //Negation 
    BigInteger operator -();			// val = -a;
    bool operator !();					// val = (bool) (!a)
    //Addition
    void operator +=(BigInteger x);		// val += x (BigInteger);
    void operator +=(int x);			// val += x (int);
    void operator +=(unsigned int x);	// val += x (unsigned int);
    //Subtraction
    void operator -=(BigInteger x);		// val -= x (BigInteger);
    void operator -=(int x);			// val -= x (int);
    void operator -=(unsigned int x);	// val -= x (unsigned int);
    //Multiplication
    void operator *=(BigInteger x);		// val *= x (BigInteger);
    void operator *=(int x);			// val *= x (int);
    void operator *=(unsigned int x);	// val *= x (unsigned int);
    //Division
    void operator /=(BigInteger x);		// val /= x (BigInteger);
    void operator /=(int x);			// val /= x (int);
    void operator /=(unsigned int x);	// val /= x (unsigned int);
    //Modulo
    void operator %=(BigInteger x);		// val %= x (BigInteger);
    void operator %=(int x);			// val %= x (int);
    //Xor
    void operator ^=(int x);			// val ^= x (int);
	std::string toString(int base);    // Convert val to string in base
    char* toCstring(int base);
    BigInteger operator ++();		 // val = val++;
    BigInteger operator --();		 // val = val--;

	//Operator Binary  (2 operan)
	//Addition
    friend BigInteger operator +(BigInteger x, BigInteger y);	// x + y;
    friend BigInteger operator +(BigInteger x, int y);		// x + y;
    friend BigInteger operator +(int x, BigInteger y);		// x + y;
    //Division
    friend BigInteger operator -(BigInteger x, BigInteger y);	// x - y;
    friend BigInteger operator -(BigInteger x, int y);		// x - y;
    friend BigInteger operator -(int x, BigInteger y);		// x - y;
    //Multiplication
    friend BigInteger operator *(BigInteger x, BigInteger y);	// x * y;
    friend BigInteger operator *(BigInteger x, int y);		// x * y;
    friend BigInteger operator *(int x, BigInteger y);		// x * y;
    //Division
    friend BigInteger operator /(BigInteger x, BigInteger y);	// x / y;
    friend BigInteger operator /(BigInteger x, int y);		// x / y;
    friend BigInteger operator /(int x, BigInteger y);		// x / y;
    //Modulo
    friend BigInteger operator %(BigInteger x, BigInteger y);	// x % y;
    friend BigInteger operator %(BigInteger x, int y);		    // x % y;
    friend BigInteger operator %(int x, BigInteger y);		    // x % y;
    //XOR
    friend BigInteger operator ^(BigInteger x, BigInteger y);	// x ^ y;
    //AND
    friend BigInteger operator &(BigInteger x, BigInteger y);	// x & y;
    //OR
    friend BigInteger operator |(BigInteger x, BigInteger y);	// x | y;

	//operatorp perbandingan
	//Sama dengan
    friend bool operator ==(BigInteger x, BigInteger y);	// (x == y) ? true : false
    friend bool operator ==(BigInteger x, int y);		
    friend bool operator ==(int x, BigInteger y);		
    //Tidak sama dengan
    friend bool operator !=(BigInteger x, BigInteger y);	// (x != y) ? true : false
    friend bool operator !=(BigInteger x, int y);		
    friend bool operator !=(int x, BigInteger y);		
    //Kurang dari
    friend bool operator <(BigInteger x, BigInteger y);	    // (x < a) ? true : false
    friend bool operator <(BigInteger x, int y);		
    friend bool operator <(int x, BigInteger y);		
    //Kurang dari sama dengan
    friend bool operator <=(BigInteger x, BigInteger y);	// (x <= y) ? true : false
    friend bool operator <=(BigInteger x, int y);		
    friend bool operator <=(int x, BigInteger y);		
    //Lebih dari
    friend bool operator >(BigInteger x, BigInteger y);	    // (x > y) ? true : false
    friend bool operator >(BigInteger x, int y);		
    friend bool operator >(int x, BigInteger y);		
    //Lebih dari sama dengan
    friend bool operator >=(BigInteger x, BigInteger y);	// (x >= y) ? true : false
    friend bool operator >=(BigInteger x, int y);		
    friend bool operator >=(int x, BigInteger y);		

    friend BigInteger Gcd(BigInteger x, BigInteger y);//Greatest Common Divisor of x and y
    friend BigInteger ModExp(BigInteger base, BigInteger exp, BigInteger n); //return x = base^exp % n
    friend BigInteger ModExp(BigInteger base, int exp, BigInteger n); //return x = base^exp % n
    friend BigInteger Sqrt(BigInteger x); //Square root of x
    friend BigInteger NextPrime(BigInteger x); //Next Prime after 
    friend BigInteger RShift(BigInteger n,unsigned int shift); //(shift) bit right shift of n
    friend int Jacobi(BigInteger m, BigInteger n);
    friend int Legendre(BigInteger n,BigInteger p);
    friend void Swap(BigInteger A, BigInteger B);
    friend BigInteger ModInverse(BigInteger n,BigInteger m);
    friend BigInteger Lcm(BigInteger a, BigInteger b);

    //Misc
    int Log(unsigned int base);
    bool Testbit(unsigned long int i);
    void Setbit(unsigned int index);
 };
#endif // BIGINTEGER_H_INCLUDED
