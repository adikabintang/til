# goto is considered harmful. or it depends on the context.
Apparently `goto` is not that [*haram*](https://en.wikipedia.org/wiki/Haram).

At least in C.

Linus said himself: https://koblents.com/Ches/Links/Month-Mar-2013/20-Using-Goto-in-Linux-Kernel-Code/

According to Suhu Erik, this is super fine and it's good to use `goto` like this:
```C
void foo()
{
    int *x = malloc(sizeof(int));
    bool ok;

    // do one thing
    ok = do_one_thing();
    if (!ok)
        goto err_handling_point;
    
    // do one other thing
    ok = do_re_mi();
    if (!ok)
        goto err_handling_point;

err_handling_point:
    free(x);
}
```

Suhu said that `goto` is a poor man's exception handling: we can handle error without stack unwinding.

This note was taken from a conversation in a not-so-useful-but-sometimes-very-useful whatsapp group.