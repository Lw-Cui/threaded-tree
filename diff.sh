#!/bin/bash
./random.out > random.output
./threadtree.out < random > threadtree.output
./binarytree.out < random > binarytree.output
diff threadtree.output binarytree.output && echo 'Yeah'