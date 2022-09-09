# llvm-pass-template

this repo has been tested against LLVM 15 on OSX and Linux

first, make sure that the LLVM bin dir that you wish to build against
is in your PATH

second, build the template pass like this:

```
mkdir build
cd build
cmake .. -G Ninja
ninja
```

third, test it like this:

```
clang++ -c -emit-llvm ../test/hello.cpp
opt -load template/libtemplate.so -load-pass-plugin template/libtemplate.so -template hello.bc -o /dev/null
```

this template pass is based on documentation
[here](https://llvm.org/docs/WritingAnLLVMPass.html)
and
[here](https://llvm.org/docs/CMake.html#developing-llvm-passes-out-of-source)

