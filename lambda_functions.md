### Lambda function

```c++
/*

[capture_list](params_list) -> return_type { function_body }; -> values by copy
[=](&params_list) -> return_type { function_body }; -> capture all the values above by ref

[&capture_list](&params_list) -> return_type { function_body }; -> values by ref
[&](&params_list) -> return_type { function_body }; -> capture all the values above by ref

*/

```

> NOTE: Lambda captures are resolved lexically at the lambda expression location, not dynamically at invocation time.

* [&] --> capture used vars by reference
* [=] --> capture used vars by value
* [&x] --> capture x by reference
* [x] --> capture x by value
* [&, x] --> all by ref, except x by value
* [=, &x] --> all by value, except x by ref
* [const&] --> does not exist

#### Example
```c++

int x = 5;
auto f = [=]() {
    x++; // error
};

// because lambda call operator is const by default.
// To modify the copied values:

auto f = [=]() mutable {
    x++;
};

```

### TODO
1. lvalue & rvalue
