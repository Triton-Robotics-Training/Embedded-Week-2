This is week 2's Binary & Bytes video:

In this video we're going over what bytes and binary are, and how you can use them to create, send, and recieve packets of data.

> TITLE CARD, BYTES AND BINARY ^

Starting off, lets look at the most basic form of number, the integer. An integer is a non-decimal number, like 2, 4, 300, or -80. When we write code, we often use integers. Lets look at a this basic chunk of C++ code that sums an array

```cpp
int arr[5] = {10,42,-23, 123, -7};
int sum = 0;
for(int i = 0; i < 5; i ++){
	sum += arr[i];
}
print(sum);
```

Lets take a closer look at the numbers in the array, we can see that the first number is 10. What does this mean for the code. All data, numbers, code is stored in binary, and this 10 is no different. In C++, the default int size is generally 32 bit, which means that all integer variables are stored in 32 bits (or four bytes, as each byte is 8 bits). 

> USE IMAGE OF ABOVE CODE BLOCK ^

This is how this is stored in binary, as you can see we have 4 bytes, each of which have 8 bits each. A bit is the state of either a 1 or a 0, and with 8 bits we can make a byte, which can store a positive number from 0-255. How does it do this? Binary is a base 2 number system, in the same way that our standard system is base 10. 

> IMAGE OF BINARY REPRESENTATION OF THE NUMBER 10 ^

Base 10 means that our number's digits each go up in magnitudes of 10, so the rightmost digit is * 10^0, which is 1, and the next digit up is * 10^1. If we look at, for example, the number 245, you can substitute n_2 for 2, n_1 for 4, and n_0 for 5.

> IMAGE OF BASE 10 POWER CHART AND EQUATION^
>
> $$
> 10^2*n_2+10^1*n_1+10^0*n_0
> $$

This same thing applies to binary, where each digit is goes up in magnitude, but instead of the magnitude being 10, the magnitude is 2. This also means that there are no digits above 1, the same way in base 10 there is no digit above 9, the next number overflows into the next

> IMAGE OF BASE 2 POWER CHART AND EQUATION^
>
> $$
> 2^2*n_2+2^1*n_1+2^0*n_0
> $$

Now lets look at the same number, 245. We look at 

> BINARY REPRESENTATION OF 245 WITH THE CHART ^

We know that integers can be positive or negative. The way that we can represent whether an integer is postive or negative in binary is using 2s complement. By looking at the binary representation of an integer, if the leftmost bit (or the most signifitcant bit) is 0, then the integer is positive. If the leftmost bit is 1, then the integer is negative. 

For example, the integer 5 has a binary representation of 0101. To make it negative with 2s complement, we first invert all the bits to get 1010, and then add 1 to the end to get 1011.

> 5: 0101 (leftmost bit is 0)
> -5: 1011 (leftmost bit is 1)

FURTHER TOPICS TO DISCUSS:
~~- 2s complement~~
- integers made up of multiple bytes
- every data chunk you get is in a byte
- how to combine bytes (higher and lower order explanation)
- manipulating bytes (shifting, bitwise or, bitwise and, bitwise xor, bitwise not, concatenating bytes (shift + or))
- why this matters (example of constructing a packet with a fake protocol and fake data)
- - (EXAMPLE PROTOCOL: YOU NEED TO DECONSTRUCT A PACKET OF 8 BYTES IN LENGTH, AND HERE ARE THE BYTE COMPOSITIONS: 
[BYTE 1: HIGHER VELOCITY] 
[BYTE 2: LOWER VELOCITY] 
[BYTE 3: CURRENT] 
[BYTE 4: LOWER TEMPERATURE] 
[BYTE 5: MIDDLE TEMPERATURE] 
[BYTE 6: HIGHEST TEMPERATURE] 
[BYTE 7: VOLTAGE])
- assignment should include both constructing and deconstructing a packet