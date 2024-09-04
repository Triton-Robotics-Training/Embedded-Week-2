// Online C++ compiler to run C++ program online
#include <iostream>

int main() {
    // Write C++ code here
    int16_t thisIs2003 = 2003;
    int16_t thisIsAlso2003 = 0x07D3;
    int16_t whatIts2003 = 0b11111010011;
    int16_t noWayItsNegative2003 = -2003;
    int16_t preposterousNegative2003 = 0xF82D;
    int16_t youreInsaneWithItNegative2003 = 0b1111100000101101;
    printf("Base 10: %d %d %d %d %d %d\n",thisIs2003, thisIsAlso2003, whatIts2003, noWayItsNegative2003, preposterousNegative2003, youreInsaneWithItNegative2003);
    printf("Base 16: 0x%X 0x%X 0x%X 0x%X 0x%X 0x%X",thisIs2003, thisIsAlso2003, whatIts2003, noWayItsNegative2003, preposterousNegative2003, youreInsaneWithItNegative2003);
    // there's no built in function for printing in base 2
    return 0;
}