## `file`

To show the properties of a file. For an executable binary filename, the endiannes, architecture, OS are also displayed. Example:

```
$ file main
main: ELF 64-bit LSB executable, x86-64, version 1 (SYSV), dynamically linked, interpreter /lib64/ld-linux-x86-64.so.2, for GNU/Linux 3.2.0, BuildID[sha1]=18b332441153673cdb491c8e74884c3c1130ec44, not stripped
```

## `objdump`

...

## `xxd`

Show a binary/hex representation of a file. Example:

```
$ xxd picture.jpg
```

## `printf`

Print a string of a repeated characters of n length

```
$ printf '%*s' 100 ''|tr ' ' 'x'
```

This will print a string of 'x' characters with length of 100
https://stackoverflow.com/questions/5799303/print-a-character-repeatedly-in-bash
