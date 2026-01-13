echo "Enter a char"
read ch
case $ch in 
'a' | 'e' | 'i' | 'o' | 'u' ) echo "It is a vowel";;
* ) echo "It is a consonant";;
esac
