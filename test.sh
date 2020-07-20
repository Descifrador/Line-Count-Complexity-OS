#! /bin/bash
function count_lines2() {
    find "$1" | while read FILE; do
        echo $(grep -c ^ <"$FILE") >> comparefile.txt
    done
}
count_lines2 $1