Notes
=====

Table of hexadecimal, decimal and binary
----------------------------------------

|      |      |      |      |      |      |      |      |      |
| ---- |:----:|:----:|:----:|:----:|:----:|:----:|:----:|:----:|
| hex  | 0    | 1    | 2    | 3    | 4    | 5    | 6    | 7    |
| dec  | 0    | 1    | 2    | 3    | 4    | 5    | 6    | 7    |
| bin  | 0000 | 0001 | 0010 | 0011 | 0100 | 0101 | 0110 | 0111 |

|      |      |      |      |      |      |      |      |      |
| ---- |:----:|:----:|:----:|:----:|:----:|:----:|:----:|:----:|
| hex  | 8    | 9    | A    | B    | C    | D    | E    | F    |
| dec  | 8    | 9    | 10   | 11   | 12   | 13   | 14   | 15   |
| bin  | 1000 | 1001 | 1010 | 1011 | 1100 | 1101 | 1110 | 1111 |


Converting from binary to hexadecimal
-------------------------------------

To convert from binary to hexadecimal, split up the number in parts of four. If the number is not a multiple of four, you should prepend the leftmost group with zeroes.


When a value is a power of two
------------------------------

When a value `x` is a power of two, that is, `x = 2^n` for some nonnegative integer `n`, we can readily write `x` in hexadecimal form by remembering that the binary representation of `x` is simply `1` followed by `n` zeros. The hexadecimal digit `0` represents four binary zeros. So, for `n` written in the form `i + 4j`, where `0 ≤ i ≤ 3`, we can write `x` with a leading hex digit of `1` `(i = 0), 2 (i = 1), 4 (i = 2), or 8 (i = 3)`, followed by `j` hexadecimal `0s`. As an example, for `x = 2048 = 2^11`, we have `n 11 = 3 + (4*2)`, giving hexadecimal representation `0x800`.
