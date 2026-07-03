## Machine Learning

### Overview

Machine Learning implemented in C (with only the standard libraries, such as stdlib.h, math.h, and stdio.h)

The CSV Parser is custom built to load CSV files into memory as a 2 dimensional array in C. 

More information can be found in the README.md files in [src/Linear](https://github.com/developerc76/ml/blob/main/src/Linear/README.md) and [src/Multivariate](https://github.com/developerc76/ml/blob/main/src/Multivariate/README.md).


#### This is licensed under the LGPL v3, so feel free to fork, modify, clone, or use this repository for whatever is needed, as long as your version, if commercialized, is open sourced under a GNU Public License. 

### Prerequisites
GCC (support for at least C11), make, a UNIX-like (Linux, BSD, OS X) or DOS-like (Windows) OS.

### Installation
```bash
$ git clone https://github.com/jasr4j/ml.git
$ cd src
$ make
$ ./ml
```

### Run the project

```bash
$ cd src
$ make
$ ./ml
```

### Notes

You can find the math behind the linear regression in the README.md files in the src/Linear and src/Multivariate directories in the git repository. 


The data in /src/Linear/data/x.txt, /src/Linear/data/y.txt, and /src/Multivariate/data.csv is example data, which can be modified, as long as it stays in the same format. 

The CSV Parser is located in /src/Multivariate/parser.c and can be imported through "parser.h" by copying the parser.c and parser.h files into the directory in which you need those files (for other uses). 

### Thank you