#include "hex.h"
#include<iomanip>
#include<sstream>
/***************************************************************
hex8
Use: This function will return a std::string with exactly 2 hex digits representing the 8 bits of
the i argument.
Parameters: uint8_t i 
Returns: a string representing a 2 hex digits 
*************************************************************/ 
string hex8 ( uint8_t i ){
    std::ostringstream os;
    os << std::hex << std::setfill('0') << std::setw(2) << static_cast<uint16_t>(i);
    return os.str();
}

/***************************************************************
hex32
Use: This function will return a std::string with 8 hex digits representing the 32 bits of the i
argument.
Parameters: uint32_t number 
Returns: a string representing a 8 hex digits 
*************************************************************/ 
string hex32 ( uint32_t i ){
    std::ostringstream os;
    os << std::hex << std::setfill('0') << std::setw(8) << static_cast<uint32_t>(i);
    return os.str();
}

/***************************************************************
hex0x32
Use: This function will return a std::string beginning with 0x, followed by the 8 hex digits
representing the 32 bits of the i argumentIt must be implemented by creating a string by
concatenating a 0x to the output of your hex32() function like this
Parameters: uint32_t number
Returns: a string representing a 8 hex digits starting with the 0x
*************************************************************/ 
string hex0x32 ( uint32_t i ){
    //calls the hex32 function to convert it to hex.... we then add "0x" plus the function return 
    return std::string("0x")+hex32(i);
}