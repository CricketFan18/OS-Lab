echo "enter a name of a fruit"
read a
case $a in
"apple" ) echo "This is a fruit" ;;
"orange" ) echo "This is a fruit" ;;
"banana" ) echo "This is a fruit" ;;
"cherry" ) echo "This is a fruit" ;;
"mango" ) echo "This is a fruit" ;;
* ) echo "This is not a fruit" ;;
esac
