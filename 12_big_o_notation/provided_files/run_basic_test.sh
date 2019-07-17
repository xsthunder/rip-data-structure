build='g++ *.cpp -std=c++11 '
str_len=5
for data_struct_type in {vector,list,bst,priority_queue,hash_table}
do
        for op in {sort,remove_dups}
        do
            ./a.out $data_struct_type $op test_${op}.txt output_test_${op}_${data_struct_type}.txt > /dev/null
            if diff output_test_${op}_${data_struct_type}.txt output_test_${op}_vector.txt
            then
               echo "" >/dev/null
            else
                echo "diff in $data_struct_type $op"
                echo "======"
            fi
        done
done

