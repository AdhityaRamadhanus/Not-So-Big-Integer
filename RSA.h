#ifndef RSA_H_INCLUDED
#define RSA_H_INCLUDED
#include "BigInteger.h"
class RSA{
    public:
        BigInteger p,q,d;
    public:
        BigInteger e,n;
        RSA();
        RSA(BigInteger p,BigInteger q);
        ~RSA();
        //Getter setter
        void SetPQ(BigInteger _p,BigInteger _q);

        //Compute PrivateKey
        void ComputePrivateKey();
        void ComputePublicKey();

        BigInteger Encrypt(BigInteger Message);
        BigInteger Decrypt(BigInteger Message);
};


#endif // RSA_H_INCLUDED
