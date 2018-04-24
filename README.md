[![Build Status](https://travis-ci.org/maitesin/globalsign.svg?branch=master)](https://travis-ci.org/maitesin/globalsign)

# GlobalSign Code Test
In order to build this project you are going to need to install conan (is a C/C++ dependency manager), CMake and Ninja. It has been used to bring the Google Test dependency is order to do a TDD style development of this project.

## Install conan
Installing conan is really simple:
```
pip install --user conan
```

## Building the package
We are going to build the project, run the test and then use the binary generated.

First, create a build folder and go into it:
```
mkdir build
cd build
```

Then call conan to bring the Google Test dependency. In this step depends on what version of the GCC compiler you have installed. **If the GCC version is less than 5 use this command**:
```
conan install ..
```
**If the GCC version is 5 or more use the following command**:
```
conan install .. -s compiler.libcxx=libstdc++11
```
This missmatch is due to the ABI of the standard library.

Afterwards, use CMake to configure the project:
```
cmake .. -GNinja
```

Finally, run the build of the project using Ninja:
```
ninja
```

To run the unit test you can either use ninja:
```
ninja test
```
or you can call the binary directly:
```
./bin/treap_test
```

Last but not least, the binary that implements the functionality required for this coding test is **top_20**. It can be found in the bin folder. That binary can be called with the following:
```
./top_20 <filename>
```