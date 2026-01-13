XYZ="$HOME/XYZ"
mkdir -p "$XYZ/MyFile"
mkdir -p "$XYZ/MyDir"
find "$XYZ"/* -type f -exec mv {} "$XYZ/MyFile/" \;
mv "$XYZ"/"!(MyDir|MyFile)" "XYZ/MyDir/"
echo "Files have been moved to $XYZ/MyFile and directories to $XYZ/MyDir."
