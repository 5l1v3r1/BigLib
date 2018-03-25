#include "include/big_p.h"



BigPol::BigPol(std::string str) {
    /* Initializer. Takes string representation of big num */

    //Get digits from string and add to vector
    int size;
    for (int i = str.length() - 1; i >= 0; i-=(size + 2)){

        size = 0;

        std::string s = "";

        while(str[i - size] != ' '){
            s += str[i - size];
            size++;
        }

        BigInt denom(s);

        s = "";
        while(i - size - 1 >= 0 && str[i - size - 1] != ' '){
            s += str[i - size - 1];
            size++;
        }
        BigInt num(s);

        coefs.push_back(BigFra(num, denom));
    }
}

BigPol ADD_PP_P(BigPol lhs, BigPol rhs) {
    BigPol result = lhs;
    int max_len = std::max(result.coefs.size(), rhs.coefs.size());
    for(int i = 0; i < max_len; i++){
        result.coefs[i] = result.coefs[i] + (i < rhs.coefs.size() ? rhs.coefs[i] : BigFra(BigInt("0"), BigInt("1")));
    }
    return result;
}

BigPol MUL_PQ_P(BigPol lhs, BigFra rhs) {
    for(int i = 0; i < lhs.coefs.size(); i++){
        lhs.coefs[i] = lhs.coefs[i] * rhs;
    }

    return lhs;
}

BigPol SUB_PP_P(BigPol lhs, BigPol rhs) {
    BigFra temp(BigInt("-1"), BigInt("1"));
    rhs = rhs * temp;
    return ADD_PP_P(lhs, rhs);
}

BigPol BigPol::operator+(const BigPol &rhs) {
    return ADD_PP_P(*this, rhs);
}

BigPol BigPol::operator-(const BigPol &rhs) {
    return SUB_PP_P(*this, rhs);
}

BigPol BigPol::operator*(const BigFra &rhs) {
    return MUL_PQ_P(*this, rhs);
}

int DEG_P_N(BigPol lhs) {
    return lhs.coefs.size();
}

std::ostream &operator<<(std::ostream &stream, const BigPol &pol) {
    for (int i = pol.coefs.size() - 1; i >= 0; --i) {
        stream << pol.coefs[i] << "*X^" << i;
    }

    return stream;
}

BigFra LED_P_Q(BigPol lhs) {
    return (lhs.coefs[lhs.coefs.size()]);
}

BigPol DER_P_P(BigPol lhs) {

    for(int i = 1; i < lhs.coefs.size(); i++){
        lhs.coefs[i-1] = lhs.coefs[i];
        lhs.coefs[i-1] = lhs.coefs[i-1] * lhs.coefs[i];
    }
    return lhs;
}

BigFra FAC_P_Q(BigPol lhs) {
    BigFra temp(BigInt("0"),BigInt("1"));
    BigInt result1 = BigInt("0");
    BigInt result2 = BigInt("0");
    int i = 0;

    while(i != lhs.coefs.size()){

    }

}
