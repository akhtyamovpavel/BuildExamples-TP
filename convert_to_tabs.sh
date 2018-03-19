SCRIPT_FILE=$1
awk -v OFS="\t" '$1=$1' ${SCRIPT_FILE}
