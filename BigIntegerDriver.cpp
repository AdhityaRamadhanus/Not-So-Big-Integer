#include "BigInteger.h"
int main(){
	//Six ways to define a big integer
	BigInteger A,B,C;
	A = "1235678910"; //assignment using string
	B = 123; //assignment using integer
	C = B; //assignment using another big integer
	BigInteger D("12345",10); //constructor using string
	BigInteger E(347); //constructor using int
	BigInteger F(B); //constructor using another big integer
	printf("BigInteger Driver\n");
	printf("A+B = %s \n",(A+B).toCstring(16));
	printf("B-E = %s \n",(B-E).toCstring(10));
	printf("Gcd(A,B) = %s \n",(Gcd(A,B)).toCstring(10));
	printf("Next Prime after %s is %s \n",E.toCstring(10),(NextPrime(E)).toCstring(10));
	return 0;
}