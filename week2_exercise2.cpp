//STARTER 
//THIS EXERCISE IS TO BE DONE IN A GENERIC C++ COMPILER
//https://www.programiz.com/cpp-programming/online-compiler/
//IF YOU HAVE ISSUES WITH THE COMPILER, CONTACT EMBEDDED LEAD
const int BUFFER_SIZE = 98;
const int offset = 1;
#include <iostream>

static unsigned char inputString[] = 
{0x84,0x1d,0x3d,0x74,0x1e,0x3d,0x74,0x1e,
0x3c,0x1e,0xbd,0xb4,0x7c,0x1d,0x1e,0xbd,
0xfd,0x54,0xbc,0x1e,0x7c,0xfd,0xbd,0x14,
0x9d,0xbc,0x15,0x1e,0x7c,0x3d,0x14,0x1d,
0xbc,0x54,0x9f,0x1e,0x3d,0x74,0xdd,0x94,
0x1e,0x3d,0x94,0xdf,0x1e,0xad,0xb4,0x7c,
0x1d,0x1e,0xbd,0xfd,0x54,0xbc,0x1e,0xdc,
0xb4,0xdd,0x1e,0x94,0xfd,0x1e,0x9c,0xbc,
0x7c,0xfd,0x9c,0xbc,0x3e,0x1e,0x1d,0x94,
0x94,0x14,0x74,0x57,0xff,0xff,0x14,0x7d,
0xdd,0xbc,0x74,0x74,0xdd,0xbc,0x74,0x74,
0xdf,0xfc,0x3d,0x94,0x1d,0xb4,0x5c,0xdf,
0x3d,0xfd}; //this test string should output something readable

//puts a character into the output buffer
//remember that nothing will show until you print a newline.
void putc(char c){
    printf("%c", c);
}

//puts a character into the output buffer as hexadecimal
//remember that nothing will show until you print a newline.
void putc_hex(char c){
    printf("0x%2x", (unsigned char)c);
}

//puts a character into the output buffer as binary
//remember that nothing will show until you print a newline.
void putc_bin(char c){
    for(int i = 0; i < 8; i ++){
        printf("%c", (c>>(7-i) & 1) ? '1' : '0');
    }
    
}

int main(void)
{
    //CODE GOES HERE 

    putc('\n');
}