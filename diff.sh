#!/bin/bash
./random.out > random.output
./threadtree.out < random.output > threadtree.output
./binarytree.out < random.output > binarytree.output
diff threadtree.output binarytree.output && echo 'Yeah'
