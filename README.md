# Modular Healthcare Simulation and Education System - Standard Library

### v1.3.1

This is the MoHSES standard library, intended to be used in the development of [MoHSES-compliant](https://github.com/AdvancedModularManikin/specification) hardware and software modules.

_Software dependencies_:
- [CMake](https://cmake.org/download/) 3.5.1 or higher.
- [Fast-DDS](https://github.com/eProsima/Fast-DDS) 2.01 or higher with FastCDR.
- Boost libraries 1.6.7 or higher (headers only)

Once dependencies have been satisfied, to build and install:
1. Clone this repository
2. Create a build folder. From within it, run `cmake ..`
3. From the build folder, run `cmake --build . --target install` to compile and install the library in your platform specific folder. This step will require an elevated/root command prompt.
```bash
    $ git clone https://github.com/AdvancedModularManikin/amm-library
    $ mkdir amm-library/build && cd amm-library/build
    $ cmake ..
    $ cmake --build . --target install
```

The following example modules are available:

* CORE Module reference implementations
    * Module Manager
    * Simulation Manager
    * Physiology Manager (connection to BioGears)
* Extended CORE module reference implementations
    * TCP Bridge
    * REST Bridge
* Example modules
    * Command line utility
    * "Kitchen Sink" examples
   
