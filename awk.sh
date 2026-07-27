awk -F ',' '{print $1, $2}' employees.txt

awk -F ',' '$2=="Engineering" {print $0}' employees.txt 

awk -F ',' '{print $1, "gross pay: " $3*$4}' employees.txt 

awk -F, '{print NR, "( " NF " fields): " $0}' employees.txt 

awk -F, 'BEGIN { eng_total = 0 } $2 == "Engineering" { eng_total += ($3 *$4)} END {print "Total Engineering Payroll: $" eng_total}' employees.txt
