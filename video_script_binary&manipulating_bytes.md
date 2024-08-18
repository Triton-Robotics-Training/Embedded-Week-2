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

Another commonly used numeral system is hexadecimal, which is base 16. For hexidecimal, it goes from 0-9 and then 10-15, but 10-15 are represented by characters. A is 10, B is 11, and so on. For 245, its hexadecimal representation is 0xF5 (the 0x just tells us that its using hexadecimal).

> IMAGE OF HEXIDECIMAL TO DECIMAL CHART FOR 0-15.

F is 15 and 5 is just 5, so we have 15*16^1 + 5*16^0, which equals 245.

Each hexidecimal digit has a max value of 15, which takes 4 bits. That means since 0xF5 has 2 digits, it takes up 8 bits, which is also a byte.

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

Now, what if we want a number higher than 255? This is when we start increasing the number of bytes that each integer takes. Let's consider the integer 2003. In binary, this is 11111010011, however we will be padding it out to the next highest multiple of 8, so it is 00000111_11010011, which is 16 bits, or 2 bytes. If you wanted to store a number like this in C or C++, this is the data type int16_t. If we wanted to get -2003, we have 11111000_00101101. It follows the same rules as the 8 bit integer, except its bigger.

> CHART OF 2003, -2003
> SHOW EXAMPLE CREATION OF AN INT16_T

When we obtain data chunks, we commonly obtain them in a byte. Remember that a byte holds 8 bits, which goes up to 255 in binary. We've talked about how we can represent integers, but now we want to represent characters. To do this, we can use ASCII encoding, which maps a specific character to an integer. The ASCII table holds 128 unique characters, so we only need 7 bits to represent them all. The last bit just ends up being set to 0.

For example, the character "q" has an ASCII value of 113. 113 in binary is 01110001. So the byte 01110001 encodes the character "q". In fact, the character data type `char` is just a uint8_t.  They are the same datatype. With this realization also comes the fact that you can have the same byte interpreted and used in different ways, you can have the number 113 stored as a uint8_t, and then cast it and use it as a character, if that suits your needs.

> ASCII TABLE FULL ^

There are other ways that we may want to manipulate bytes. There are bitwise versions of all major operations, like and, or, not, and xor. Lets say we have an int8_t, and we want to select certain bits of it. We can run an and operation to select the bits we want and discard the rest. If I have the `uint8_t x = 01010011`, and I want to select the least significant (rightmost) 4 bits, I can preform an and operation with `x` and the byte 00001111, which will perform the and operation on each bit and return the result, in this case returning 00000011. If I wanted the most significant four bits, I could and `x` with 11110000, resulting in 01010000.

The same applies for all other operations, xor, or, and not. You can see here a few examples of these operations on the byte `x`. All these manipulations can be done with single bytes (uint8_t), but these can also be done with (uint16_t), as well as their signed int variants int8_t and int16_t.

> XOR x with 11111111 and show result, and code
>
> XOR x with 11110000 and show result, and code
>
> NOT x and show result, and code
>
> OR x with 11010001 and show result, and code

There's one more operation that we can talk about, and thats bit shifting. By using one of the shift operators, either shift left or shift right, which is double less than sign or double greater than sign respectively, we can shift bits to the left or the right. Now, what exactly does that mean. That means that if I have the `uint16_t y = 11110100_01010011`, then I can do `y << 8` and what will be returned is `01010011_00000000`, which is the original y shifted to the left by 8 bits. Notice that the bits that were on the left were eliminated. Since this is an int16, it only stores 16 bits and if we try to shift left of that, they are removed. Lets also attempt `y >> 8`, which results in `00000000_11110100`, which is y shifted to the right by 8. Notice again that the bits that were previously on the right were shifted out of existence. This is one major thing to keep in mind with shifting bits, which is that its important to know what type of

Now, lets say I have 2 int8s that I want to combine into an int16, how do I do this? It's important to know which is the higher order byte (the most significant byte), and which one is the lower order byte (the least significant byte). In this case, lets say we have x and y, and x is the higher order and y is the lower order byte.

Next, its important to cast the int8s as int16s, since we need to make sure that we can shift them around without any issue. We can shift x to the left by 8, and then perform the OR operation on both numbers to combine their bits into one. Here is an example. Lets say we want to combine these two bytes, x = 10010100 and y = 00101011. As mentioned before, we shift x 8 to the left, which results us with 10010100_00000000. Then, we can bitwise OR that with y, and that will result us with 10010100_00101011, which is what we want.

> DIAGRAM WITH ABOVE ^

The same way that we can combine bytes to make ints, we can also split an int into its component bytes. Lets say we have an int16 that we want to split into two bytes. See if you can take a minute and think of a way to do that with all the methods we've learned about, using bitwise OR, bit shifting, and bitwise AND.

5 SECOND PAUSE

Lets take the byte z = 10010100_00101011, and split it into its higher and lower order bytes. For the higher order byte, we can perform a bitwise AND operation with the byte 00000000_11111111, which will choose all of the  lower order 8 bits, and ignore the rest. For the higher order 8 bytes, you can shift it rightwards by 8, and then do the same thing, the bitwise AND operation, which will again select only the rightmost 8 bits. 

> DIAGRAM WITH ABOVE ^

FURTHER TOPICS TO DISCUSS:

- ~~-2s complement~~
- ~~-integers made up of multiple bytes~~
- ~~every data chunk you get is in a byte (talk about characters)~~
- ~~how to combine bytes (higher and lower order explanation)~~
- ~~manipulating bytes (shifting, bitwise or, bitwise and, bitwise xor, bitwise not, concatenating bytes (shift + or))~~
- ~~How to split ints into bytes.~~
- hexadecimal (somewhere in middle)
- casting (add it somewhere in the middle)
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
