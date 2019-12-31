# Lambda expression

The term lambda function borrows from the term _[lambda calculus](https://en.wikipedia.org/wiki/Lambda_calculus)_.

Quoting from [wikipedia](https://en.wikipedia.org/wiki/Lambda_calculus): "lambda calculus is a formal system for expressing computation based on function abstraction using variable binding and substitution".

Other terms for lambda expression is _anonymous function_, _lambda abstraction_, _function literal_ [[wikipedia](https://en.wikipedia.org/wiki/Anonymous_function)].

## Lamda in Python

Normal function:

```python
def sum(x, y):
    return x + y
```

Lambda expression equal to the above function:

```python
sum = lambda x, y: x + y
```

Both forms can be called with the normal, such as `sum(3, 6)`.

## Lambda in Java

Good reading material : [tothenew.com](http://www.tothenew.com/blog/functional-programming-in-java8-using-lambda-expressions/) and [developer.com](https://www.developer.com/java/data/what-is-functional-programming-in-java.html)



## Lambda in C++

Normal fuction:

```cpp
int sum(int x, int y) {
    return x + y;
}
```

Lambda expression of the above:

```cpp
#include <functional> // don't forget this one

std::function<int(int, int)> 
    lambda_sum = [](int x, int y){ return x + y; };
```

We can also use `auto`, by the way:

```cpp
auto lambda_sum = [](int x, int y){ return x + y; };
```

# Map and Filter

- Map: executes function for each item in an iterable
- Filter: Filter out (= don't choose) element of an iterable that will triger `true` in the given function (_ind: "buang yang kayak gini"_)

## Python

Read more: https://www.python-course.eu/python3_lambda.php

```python
arr = [1, 2, 3, 4, 5, 6]
r = map(lambda x: x * 2, arr)
print(list(r))

# filter out arr element if that element % 2 == true
r = filter(lambda x: x % 2, arr)
print(list(r)) # [1, 3, 5]
```

## C++

Read more: https://stackoverflow.com/questions/40901615/how-to-replicate-map-filter-and-reduce-behaviors-in-c-using-stl

```cpp
std::vector<int> nums{1, 2, 3, 4, 5, 6};
std::vector<int> result;

// std::transform = map
// if you want the result to be in "nums" too,
// put nums.begin() instead of std::back_inserter(result) as 
// the 3rd parameter
std::transform(nums.begin(), nums.end(), std::back_inserter(result),
    [](int x) {return x * 2; });

for (int i = 0; i < nums.size(); i++) {
    std::cout << result.at(i) << std::endl;
}

std::vector<int> result_copy;

// std::copy_if = filter
std::copy_if(nums.begin(), nums.end(), std::back_inserter(result_copy),
    [](int x){ return x % 2; });

for (int i = 0; i < result_copy.size(); i++) {
    std::cout << result_copy.at(i) << std::endl;
}
```

## Java

Read more: http://web.mit.edu/6.031/www/fa17/classes/26-map-filter-reduce/ 

```java
List<Integer> myList = Arrays.asList(1, 2, 3, 4, 5, 6);

// map
List<Integer> res = myList.stream().map(x -> x * 2)
    .collect(Collectors.toList());

System.out.println(res);

// filter
List<Integer> filterRes = myList.stream()
    .filter(x -> (x % 2 == 1 ? true : false))
    .collect(Collectors.toList());

System.out.println(filterRes);
```

