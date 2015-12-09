#include "RSA.h"
RSA::RSA(){}
RSA::RSA(BigInteger _p,BigInteger _q){
    p=_p;
    q=_q;
}
RSA::~RSA(){}
//Getter setter
void RSA::SetPQ(BigInteger _p,BigInteger _q){
    p=_p;
    q=_q;
}
//Compute PrivateKey
void RSA::ComputePrivateKey(){
    d=ModInverse(e,(p-1)*(q-1));
}
void RSA::ComputePublicKey(){
    n = p*q;
    e = BigInteger("65537",10);
}

BigInteger RSA::Encrypt(BigInteger Message){
    return ModExp(Message,e,n);
}
BigInteger RSA::Decrypt(BigInteger Message){
    return ModExp(Message,d,n);
}
