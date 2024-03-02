# stater
stater (statistic-er) is a useful tool for getting an overview over pieces of data.

<video src="https://github.com/tim-tm/stater/raw/main/res/float_example.mp4" controls="controls" style="max-width: 730px;">
</video>
<video src="https://github.com/tim-tm/stater/raw/main/res/pacman_example.mp4" controls="controls" style="max-width: 730px;">
</video>

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
