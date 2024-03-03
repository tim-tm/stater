# stater
stater (statistic-er) is a useful tool for getting an overview over pieces of data.



https://github.com/tim-tm/stater/assets/43402731/9f4ca7ef-d1b5-42ba-9b8f-43291a1c8b08



https://github.com/tim-tm/stater/assets/43402731/58669aa8-f534-4a7c-8ddb-6eadac2192b8


## Getting started

### Requirements

- git
- gcc, make
- X11 libraries

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
make uninstall
```

## Contribution

If you want to contribute, feel free to open a pull request.

## License

This project is licensed under the [MIT License](https://github.com/tim-tm/stater/blob/main/LICENSE)
