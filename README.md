# stater
stater (statistic-er) is a useful tool for getting an overview over pieces of data.



https://github.com/tim-tm/stater/assets/43402731/9f4ca7ef-d1b5-42ba-9b8f-43291a1c8b08



https://github.com/tim-tm/stater/assets/43402731/58669aa8-f534-4a7c-8ddb-6eadac2192b8


## Getting started

### Linux

For now, stater cannot be installed using any package manager, you need to build it on your own.

#### Requirements

- git
- gcc, make
- X11 libraries

#### Builing stater

Cloning the repository
```sh
git clone https://github.com/tim-tm/stater && cd stater
```

Setting up libraries and the project
```sh
make setup
```

Building stater
```sh
make
```

Running an example
```sh
./build/stater examples/pacman.state
```

Installing stater system-wide
```sh
sudo make install
```

### Windows

#### Requirements

- git
- [w64devkit](https://github.com/skeeto/w64devkit/releases/latest)

#### w64devkit setup

1. Download the latest zip from the [w64devkit releases page](https://github.com/skeeto/w64devkit/releases/latest)
2. Unzip w64devkit to a place you like (preferably C:/)
3. Add (path-to-w64devkit)/bin to your PATH environment variable

#### Builing stater

Cloning the repository
```sh
git clone https://github.com/tim-tm/stater && cd stater
```

Setting up libraries and the project
```sh
make setup
```

Building stater
```sh
make
```

Running an example
```sh
./build/stater examples/pacman.state
```

Installing stater system-wide (this needs admin privileges because it copies stater to your System32 folder)
```sh
make install
```

## More Makefile options

### Linux-only

Cleaning the build directory without destroying it
```sh
make clean
```

Destroying the build directory and cleaning the raylib build
```sh
make destroy
```

### Windows and Linux

Uninstalling stater from your system
```sh
sudo make uninstall
```
for Windows users in a admin terminal
```sh
make uninstall
```

Building stater with debug info
```sh
make BUILD_TYPE=DEBUG
```

## Contribution

If you want to contribute, feel free to open a pull request.

## License

This project is licensed under the [MIT License](https://github.com/tim-tm/stater/blob/main/LICENSE)
