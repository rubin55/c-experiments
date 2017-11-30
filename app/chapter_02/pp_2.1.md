Practice Problem 2.1
====================
 
Perform the following number conversions:

  * A: 0x39A7F8 to binary
  * B: Binary 1100100101111011 to hexadecimal
  * C: 0xD5E4C to binary
  * D: Binary 1001101110011110110101 to hexadecimal
 

When a value `x` is a power of two, that is, `x = 2^n` for some nonnegative integer `n`, we can readily write `x` in hexadecimal form by remembering that the binary representation of `x` is simply `1` followed by `n` zeros. The hexadecimal digit `0` represents four binary zeros. So, for `n` written in the form `i + 4j`, where `0 ≤ i ≤ 3`, we can write `x` with a leading hex digit of `1` `(i = 0), 2 (i = 1), 4 (i = 2), or 8 (i = 3)`, followed by `j` hexadecimal `0s`. As an example, for `x = 2048 = 2^11`, we have `n 11 = 3 + (4*2)`, giving hexadecimal representation `0x800`.
