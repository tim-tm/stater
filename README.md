# stater
stater (statistic-er) is a useful tool for getting an overview over pieces of data.

![](https://github.com/tim-tm/stater/blob/fe09bc39b8cfa0a997c0b1dd17fa12eb2d1cf774/res/float_example.png)
![](https://github.com/tim-tm/stater/blob/d0938a8e1e6d45db3b27c396f27a8210f61a5e45/res/pacman_example.png)

## Getting started

Cloning the repository
```sh
git clone https://github.com/tim-tm/stater && cd stater
```

Configuring stater
```sh
cmake -B build
```

Building stater
```sh
cmake --build build
```
or
```sh
make -C build
```

Running an example
```sh
./build/stater examples/pacman.state
```

## Contribution

If you want to contribute, feel free to open a pull request.

## License

This project is licensed under the [MIT License](https://github.com/tim-tm/stater/blob/main/LICENSE)
