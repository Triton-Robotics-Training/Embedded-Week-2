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

Now lets look at the same number, 245. We can look again at a binary representation of 245, which is 11110101. What does this mean? This means 2^7 * 1 + 2^6 * 1 and so on, as you can see in the chart. Each digit signifies a different power of 2, and with each of these powers you can construct every number. However, this only works for positive numbers, there is a different way that we represent negative numbers.

> BINARY REPRESENTATION OF 245 WITH THE CHART ^

We know that integers can be either positive or negative. The way that we represent whether an integer is postive or negative in binary is using 2s complement. By looking at the binary representation of an integer, there is a simple way to tell if a number is positive or negative. If the leftmost bit (or the most signifitcant bit) is 0, then the integer is positive. If the leftmost bit is 1, then the integer is negative. However, this is actually slightly more complex than it seems

In 2s complement, to implement negative numbers, we split the range of the number into 2. Instead of being able to represent 0-255, $(2^8 - 1)$, we split the range and instead get a range of -128 to 127. The way this is done, is by changing the largest byte to negative. Now, the highest bit is -128 instead of 128. Therefore, adding the highest bit ensures that the entire number is negative.

For example, the integer 5 has a binary representation of 00000101. To make it negative with 2s complement, we first invert all the bits to get 11111010, and then add 1 to the end to get 11111011. As you can see, the math checks out, and the adding 1 offsets the 127 to 128.

> 5: 00000101 (leftmost bit is 0)
> -5: 11111011 (leftmost bit is 1)
>
> ADD CHART SHOW BOTH 5 AND -5 WITH 2S COMPLEMENT ^

Lets also look briefly at another set of numbers, 123 and -123. As you can see, the math checks out.

> CHART OF 123 and -123

Now, what if we want a number higher than 255? This is when we start increasing the number of bytes that each integer takes. Let's consider the integer 2003. In binary, this is 11111010011, however we will be padding it out to the next highest multiple of 8, so it is 0000011111010011, which is 16 bits and 2 bytes. If you wanted to store a number like this in C or C++, this is the data type int16_t. If we wanted to get -2003, we have 1111100000101101. It follows the same rules as the 8 bit integer, except its bigger. 

> CHART OF 2003, -2003
> SHOW EXAMPLE CREATION OF AN INT16_T

When we obtain data chunks, we commonly obtain them in a byte. Remember that a byte holds 8 bits, which goes up to 255 in binary. We've talked about how we can represent integers, but now we want to represent characters. To do this, we can use ASCII encoding, which maps a specific character to an integer. The ASCII table holds 128 unique characters, so we only need 7 bits to represent them all. The last bit just ends up being set to 0. 

For example, the character "q" has an ASCII value of 113. 113 in binary is 01110001. So the byte 01110001 encodes the character "q".


FURTHER TOPICS TO DISCUSS:
- ~~-2s complement~~
- ~~-integers made up of multiple bytes~~
- ~~every data chunk you get is in a byte (talk about characters)~~

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
