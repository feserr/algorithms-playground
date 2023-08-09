# Decompressor

Given a compressed string, decompress it following the next rules:

- Letters are threated as they are.
- A number will multiply what is at the right side.
- Paranthesis surround the scope of a number multiplication if any.

## Example 1

```text
A = (2(3AB)A)

1. (3AB) = ABABAB
2. 2(3AB)A = ABABABAABABAB
3. (2(3AB)A) = ABABABAABABAB

Solution = ABABABAABABABA
```
