#!/bin/bash
./random.out > random.output
./pre-threadtree.out < random.output > pre-threadtree.output
./binarytree.out < random.output > binarytree.output
diff pre-threadtree.output binarytree.output && echo 'Pre-order: Yeah'
./set-pre-threadtree.out < random.output > set-pre-threadtree.output
diff set-pre-threadtree.output binarytree.output && echo 'Set Pre-order: Yeah'
