# ogl
ogl is a simple c++ opengl framework using glfw3 and glad for VSCode.

## prerequesites
If not installed yet, install glfw3

## GLFW3 / Ubuntu / Linux
```
$ sudo apt update
$ sudo apt install libglfw3 libglfw3-dev libglfw3-doc
$ sudo apt upgrade
```

## Download the repo
```
$ git clone https://github.com/samuelohterion/ogl.git
```

## VScode
Open the repo in VSCode!  
```
$ cd ogl
$ code .
```

## GLAD
Download glad for your system from [https://glad.dav1d.de](https://glad.dav1d.de) and  
copy it into the root folder of the project.

```
.
├── CMakeLists.txt
├── glad
│   ├── include
│   │   ├── glad
│   │   │   └── glad.h
│   │   └── KHR
│   │       └── khrplatform.h
│   └── src
│       └── glad.c
├── README.md
└── src
    └── main.cpp
```

## Configure and Build the project
Open and enter the repo in VSCode!  

```
$ cd ogl
$ code .
```
then  

### via **build**
- select a compiler in the command palette of VScode **STRG+SHIFT+P**
- press ***Build*** in the bottom menu! 
  
or  
### via CMake  
Generate Makefiles:
  
1. Ubuntu / Linux  
    ```
    $ cmake . -G "Unix Makefiles" 
    ```
  
  or  

2. Windows using mingw propablyA list of options can be found here: [https://coderefinery.github.io/cmake/08-generators/](https://coderefinery.github.io/cmake/08-generators/)  
    ```
    $ cmake . -G "MinGW Makefiles" 
    ```  

## Finally build the project
   ```
   $ make
   ```