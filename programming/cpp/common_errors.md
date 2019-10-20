# Circular dependency

[Thanks to: [pvigier.github.io](https://pvigier.github.io/2018/02/09/dependency-graph.html#targetText=Its%20goal%20is%20to%20draw,the%20architecture%20of%20a%20project.&targetText=I%20really%20like%20this%20visual,to%20see%20how%20classes%20interact.)]

## What is circular dependancy?

`class A` depends on `class B`, `class B` depends on `class A`.

## How to solve using forward declaration

If file `A.h` has `#include "B.h"`, `B.h` cannot have `#include B.h`.

`A.h`:
```cpp
#include "B.h"

class A {}
```

`B.h`:

```cpp
class A; // this is the forward declaration
class B {
    // for usage using this dependency, define in the `B.cpp
    A *a; 
}
```

`B.cpp`:

```cpp
#include "B.h"

// do not put #include "A.h" in the B.h, but put it here
#include "A.h"
```