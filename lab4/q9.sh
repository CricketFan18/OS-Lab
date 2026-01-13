if [ "$#" -ne 2 ]; then
    echo "Usage: $0 <directory_with_files> <max_size_in_MB>"
    exit 1
fi

source_dir=$1
max_size=$2
max_size=$((max_size * 1024 * 1024)) 
if [ ! -d "$source_dir" ]; then
    echo "Error: Source directory '$source_dir' does not exist!"
    exit 1
fi

dir_index=1
current_dir="x_$dir_index"
mkdir -p "$current_dir"
current_size=0
for file in "$source_dir"/*; do
    if [ -f "$file" ]; then
        file_size=$(stat -c%s "$file")
        if (( current_size + file_size > max_size )); then
            ((dir_index++))
            current_dir="x_$dir_index"
            mkdir -p "$current_dir"
            current_size=0
        fi
        mv "$file" "$current_dir/"
        ((current_size += file_size))
    fi
done

echo "Files distributed into x_1, x_2, ... with max size limit of $2 MB."
