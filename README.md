## Machine Learning

Machine Learning implemented in C, using only the standard libraries. 

More information can be found on [my website](https://developerc76.github.io/ml) and in the README.md files in [src/Linear](https://github.com/developerc76/ml/blob/main/src/Linear/README.md) and [src/Multivariate](https://github.com/developerc76/ml/blob/main/src/Multivariate/README.md).


#### This is licensed under the LGPL v3, so feel free to fork, modify, clone, or use this repository for whatever is needed, as long as your version, if commercialized, is open sourced under a GNU Public License. 

### Run the project

```bash
$ cd src

$ make

$ ./ml
```

CSV support complete for multivariate regression

### Notes

The data in /src/Linear/data/x.txt, /src/Linear/data/y.txt, and /src/Multivariate/data.csv is example data, which can be modified, as long as it stays in the same format. 

The CSV Parser is located in /src/Multivariate/parser.c and can be imported through "parser.h" by copying the parser.c and parser.h files into the directory in which you need those files (for other uses). 

#### Thank you