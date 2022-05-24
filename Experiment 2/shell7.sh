echo "Enter the first number : "
read a;
echo "Enter the second number : "
read b;
echo "Enter Choice :"
echo "1. Addition"
echo "2. Subtraction"
echo "3. Multiplication"
echo "4. Division"
read ch
case $ch in
1)res=$(($a + $b))
;;
2)res=$(($a - $b))
;;
3)res=$(($a * $b))
;;
4)res=$(($a / $b))
;;
esac
echo "$res";