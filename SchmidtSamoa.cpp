#include "SchmidtSamoa.h"
#include "stdio.h"
SchmidtSamoa::SchmidtSamoa(){}
SchmidtSamoa::SchmidtSamoa(BigInteger _p, BigInteger _q){
    p=_p;
    q=_q;
}
SchmidtSamoa::~SchmidtSamoa(){}

void SchmidtSamoa::ComputePublicKey(){
    N = p*p*q;
}
void SchmidtSamoa::ComputePrivateKey(){
    d = ModInverse(N,(Lcm(p-1,q-1)));
}
BigInteger SchmidtSamoa::Encrypt(BigInteger Message){
    return ModExp(Message,N,N);
}
BigInteger SchmidtSamoa::Decrypt(BigInteger Message){
    return ModExp(Message,d,(p*q));
}
