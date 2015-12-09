#include "BigInteger.h"
#include "RSA.h"
int main(){
	BigInteger P(61),Q(53);
    RSA rsa = RSA(P,Q);
    rsa.ComputePublicKey();
    rsa.ComputePrivateKey();
    printf("Testing\n");
    BigInteger Encrypted = rsa.Encrypt(BigInteger("65",10));
    printf("ENcrypted : %s\n",Encrypted.toCstring(10));
    printf("Decrypted : %s\n",rsa.Decrypt(Encrypted).toCstring(10));
    printf("\n");
}