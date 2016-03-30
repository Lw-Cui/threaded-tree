#!/bin/bash
SUM=100000
MAX=2000000
./random.out $SUM $MAX > random.output

#Test correctness of postorder thread tree 
./post-threadtree.out < random.output > post-threadtree.output
./binarytree.out post < random.output > binarytree.output
diff post-threadtree.output binarytree.output && echo 'Post-order: Yeah'

#Test correctness of preorder thread tree 
./binarytree.out pre < random.output > binarytree.output
./pre-threadtree.out < random.output > pre-threadtree.output
diff pre-threadtree.output binarytree.output && echo 'Pre-order: Yeah'

#Test correctness of set preorder thread tree 
./set-pre-threadtree.out < random.output > set-pre-threadtree.output
diff set-pre-threadtree.output binarytree.output && echo 'Set Pre-order: Yeah'
