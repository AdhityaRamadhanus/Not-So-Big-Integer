#include "SchmidtSamoa.h"
int main(){
	BigInteger P(7),Q(11);
    SchmidtSamoa SS = SchmidtSamoa(P,Q);
    SS.ComputePublicKey();
    SS.ComputePrivateKey();
    BigInteger Encrypted = SS.Encrypt(BigInteger("65",10));
    printf("Encrypted : %s\n",Encrypted.toCstring(10));
    printf("Decrypted : %s\n",SS.Decrypt(Encrypted).toCstring(10));
}