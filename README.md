# Genepy

Genepy is a C++ API which provides reusable components to build console or interactive applications.

## Installation

Genepy is a [Qt 5](https://www.qt.io/) library which has been developped and tested on Linux Debian
Stretch (Debian 9). [CMake](https://cmake.org/) 3.7 or higher and a C++14 compiler are required to
build this project.

```bash
cd external
mkdir build && cd build
cmake -D EXTERNAL_BUILD_TYPE=Release ..
make
cd ../..
mkdir build && cd build
cmake -D CMAKE_BUILD_TYPE=Release ..
sudo make install
```

## Usage

Once installed, Genepy can be consumed by a client project with CMake. The given [example](example)
can be compiled as follows:

```bash
cd example
mkdir build && cd build
cmake ..
make
```

## Support

If you have any questions, please send an email to <erwan.grace@outlook.fr>.

## Contributing

Pull requests are welcome. For major changes, please open an issue first to discuss what you would
like to change.

Please make sure to update the tests as appropriate.

## License

[GNU GPL v3.0](https://choosealicense.com/licenses/gpl-3.0/)
