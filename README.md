# stater
stater (statistic-er) is a useful tool for getting an overview over pieces of data.



https://github.com/tim-tm/stater/assets/43402731/9f4ca7ef-d1b5-42ba-9b8f-43291a1c8b08



https://github.com/tim-tm/stater/assets/43402731/58669aa8-f534-4a7c-8ddb-6eadac2192b8


## Getting started

[![Packaging status](https://repology.org/badge/vertical-allrepos/stater.svg)](https://repology.org/project/stater/versions)

### Linux

Arch-Linux (AUR)
```sh
yay -S stater-git
```
or
```sh
git clone https://aur.archlinux.org/stater-git.git && cd stater && makepkg -si
```

If you are not using Arch, you may want to take a look at the [latest release](https://github.com/tim-tm/stater/releases/latest), which contains install instructions.
You can also build stater manually.

#### Builing stater

#### Requirements

- git
- gcc, make
- alsa-lib, mesa, libx11, libxrandr, libxi, libxcursor, libxinerama

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

There is no installer for Windows, go ahead and build stater manually.

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

Cleaning the build directory without destroying it
```sh
make clean
```

Destroying the build directory and cleaning the raylib build
```sh
make destroy
```

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
