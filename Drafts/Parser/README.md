# Purpose

The sensor collects the movement data (YPR) that are later analyzed and a stitch type is assigned (chain, single crochet, double crochet, half double crochet, etc.). This data is sent in a serial communication to this parser, that organizes the data into an interconnected structure of nodes. 

Each stitch is a node, connected with other nodes by edges. A stitch is connected with previous and next stitch by the fact they are made from continous yarn. Then, stitches can be also connected with previous row. 

An interface is to be developed to let the user input the connection points.

# How to run

Mostly, refer to tree-sitter [documentation](https://tree-sitter.github.io/tree-sitter/creating-parsers).

There was lots of difficult setup and installations to be done and I do not remember all of them.

To generate the parser, run:
```
tree-sitter generate
```

I use node, so I generate the bindings and stuff using node-gyp:
```
node-gyp clean
node-gyp configure
node-gyp build
```

To parse a file, I run:
```
tree-sitter parse example-file
```

# Example

For an example-file of:
```
ch ch ch ch
sc @ [0, 1]
```

The result returned is:
```
(source_file [0, 0] - [2, 0]
  (stitch [0, 0] - [0, 2])
  (stitch [0, 3] - [0, 5])
  (stitch [0, 6] - [0, 8])
  (stitch [0, 9] - [0, 11])
  (stitch [1, 0] - [1, 11]
    (coordinate [1, 6] - [1, 7])
    (coordinate [1, 9] - [1, 10])))

```

