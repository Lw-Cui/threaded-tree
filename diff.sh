#!/bin/bash
./random.out > random.output
./pre-threadtree.out < random.output > pre-threadtree.output
./binarytree.out < random.output > binarytree.output
diff pre-threadtree.output binarytree.output && echo 'Pre-order: Yeah'
