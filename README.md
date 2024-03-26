# Genetic algorithms example - Academic

This project is a simple implementation of genetic algorithms in C++.

> [!NOTE]
> The exe file is built using the Makefile, so you will need to have make installed in your system.
> To install make in Windows, you can install it directly from [GNUWin32](https://gnuwin32.sourceforge.net/packages/make.htm).
> Or you can use the [Chocolatey](https://chocolatey.org/) package manager to install it by running the following command:
>
> ```shell
> choco install make
> ```
>
> In Linux, you can install it using the package manager of your distribution.

```shell
cd "genetic algorithms"
```

Then you can run the following command to build the project:

```shell
make
```

If you don't have make installed, you can compile the project using the following command:

```shell
g++ -Wall main.cpp src/alea.cpp src/gene.cpp src/chromosome.cpp src/crossover.cpp src/fichier.cpp src/fonc.cpp src/population.cpp src/utils.cpp -o main
```

Then you can run the generated executable:

```shell
./main
```

# TODO

- [x] class random
- [x] class chromosome (code)
- [x] class population
- [x] selection
