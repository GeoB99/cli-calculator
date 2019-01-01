# Terminal Calculator
## What's this?
cli-calculator is a simplistic calculator written in C programming language for console terminals. It does all the four operations including the square root. 

## How can I compile it?
In order to compile the program you must shall have `gcc` installed on your Linux system. Depending on your Linux distribution, each one of those have their own package manager.

Debian/Ubuntu:

```sudo apt-get install gcc```

Fedora:

```sudo yum install gcc```

Arch:

```sudo pacman -Syu gcc```

Once GCC is successfully installed, you have to type the following command line below:

```gcc -o <programname> main.c -lm```

`<programnane>` can be of any name that you wish. Keep in mind to preserve the `-lm` flag as the code uses `math.h` header which it'll link against the C math library.

## How can I contribute?
If you wish to contribute to this piece of program, drop a PR here with your fixes or improvements. That'd be great!
