file1=$1
file2=$2
output_file=$3

> "$output_file"

paste -d ' ' "$file1" "$file2" > "$output_file"

echo "Concatenation complete. Output stored in '$output_file'."
