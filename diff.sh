#!/bin/bash
./random.out > random
./threadtree.out < random > threadtreepre
./binarytree.out < random > binarytreepre
diff threadtreepre binarytreepre && echo 'Yeah'