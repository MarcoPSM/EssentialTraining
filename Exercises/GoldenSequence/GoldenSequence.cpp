#include <bitset>
#include <cstdint>
#include <iostream>

uint32_t pdschCinit(uint32_t rnti, uint32_t q, uint32_t nID) {
    // C_init = n_RNTI x 2^15 + q x 2^14 + n_ID

    constexpr uint32_t two15 = 1u << 15;
    constexpr uint32_t two14 = 1u << 14;
    uint32_t cinit = (rnti * two15) + (q * two14) + nID;
    return cinit;
}


/// Convert c_init to binary string with fixed 31 bits
inline std::string cinitToBinary(uint32_t cinit)
{
    std::bitset<31> bits(cinit);
    return bits.to_string();
}


int main() {
    std::cout << "Golden Sequence" << std::endl;

    uint32_t rnti = 120;
    uint32_t q = 0;
    uint32_t nID = 17;
    uint32_t cinit = pdschCinit(rnti, q, nID);
    std::cout << "Cinit: " << cinit << " " << cinitToBinary(cinit) << std::endl;

    return 0;
}