# FlowVis
FlowVis is a visual analytic system for unsteady flow. The basic features of the software include Line integral convolution (LIC) texture generation, volume rendering, pathline tracing, local attribute computation, edge-bundling visualization based on time activity curves, attribute volume rendering.

[![Demo Video](https://img.youtube.com/vi/YltJbJSuS5A/0.jpg)](https://www.youtube.com/watch?v=YltJbJSuS5A)



| ![user_interface](https://github.com/duongnb09/FlowVis/blob/master/resources/img/user_interface.png) | 
|:--:| 
| *User interface of FlowVis* |


### Prerequisites

```
QT 5.0 or newer
VTK 6.0 or newer
OpenGL
```
### Build with CMake and GNU Make
Create a build directory inside the FlowVis project directory and configure the
build using [CMake](https://cmake.org) to generate the Makefiles for
[GNU Make](https://www.gnu.org/software/make/):
```
mkdir build && cd build
cmake -D CMAKE_BUILD_TYPE=Release ..
```

Then build the example executable named "FlowVis" using GNU Make:
```
make FlowVis
```



