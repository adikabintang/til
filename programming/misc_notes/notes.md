# Static, dynamic, strong, weak typing

Reference: https://www.sitepoint.com/typing-versus-dynamic-typing/

## Static typing

- Variables need explicit declaration
- Checked at compile time
- Example: C, C++, Java

```C
int x;
int y = 1;
x = 9;
x += y;
```

## Dynamic typing

- Variables do not need explicit declaration
- Checked at runtime
- Example: python, php

```python
num = 10
```

## Strong typing

- Languages in which variables have specific data types are strong typed
- Variables are bound to a particular data type
- Static typed != strong typed
- Example: Java, Python

```python
foo = "x"
foo = foo + 2 # TypeError: cannot concatenate 'str' and 'int' objects
```

## Weak typing

- Variables are NOT bund to a particular data type
- Example: C, php

```php
$foo = "x";
$foo = $foo + 2; // not error
```

```c
int x;
char y;
void *p;

p = &x; // not error
p = &y; // not error
```
