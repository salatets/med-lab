# info
![project build](https://github.com/salatets/med-lab/actions/workflows/qt-build.yml/badge.svg)
![project release](https://github.com/salatets/med-lab/actions/workflows/qt-deploy.yml/badge.svg)
test project
tested on MSVC2019 with Ninja generator

# build
```
export BUILDDIR=#you building directory 
cmake -S . -B $BUILDDIR
cmake --build $BUILDDIR
```
