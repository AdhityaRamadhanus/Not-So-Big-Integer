#ifndef SCHMIDTSAMOA_H_INCLUDED
#define SCHMIDTSAMOA_H_INCLUDED
#include "BigInteger.h"
class SchmidtSamoa{
    private:
        BigInteger p,q,d;
    public:
        BigInteger N;

        SchmidtSamoa();
        SchmidtSamoa(BigInteger p,BigInteger q);
        ~SchmidtSamoa();

        void ComputePublicKey();
        void ComputePrivateKey();
        BigInteger Encrypt(BigInteger Message);
        BigInteger Decrypt(BigInteger Message);
};


#endif // SCHMIDTSAMOA_H_INCLUDED
