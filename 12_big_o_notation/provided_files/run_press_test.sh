str_len=5
for data_struct_type in {vector,list,bst,priority_queue,hash_table}
do
    for op in {sort,remove_dups}
    do
        for array_len in {1,2,5,10}
        do
            ./a.out $data_struct_type $op random ${array_len}0000 $str_len output.txt
        done
    done
done

