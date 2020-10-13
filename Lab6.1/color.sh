#!bin/bash

red='\033[0;31m'
green='\033[0;32m'
yellow='\033[0;33m'
blue='\033[0;34m'
magenta='\033[0;35m'
default='\033[0;0m'

read -p "What is your favorite color (red, green, blue, yellow or magenta)? " color
color=${color^^}

case ${color} in

		"")
	selected_color=$default
	color="No color selected"
	echo "no color"
	;;
	
		"RED")
	selected_color=$red
	;;
	
		"GREEN")
	selected_color=$green
	;;
	
		"BLUE")
	selected_color=$blue
	;;
	
		"YELLOW")
	selected_color=$yellow
	;;
	
		"MAGENTA")
	selected_color=$magenta
	;;
	
		*)
	selected_color=$default
	color="${color} which is not an available option"
	;;
esac	

echo -e "${selected_color}Your selected color is ${color}. ${default}"

if [[ "$selected_color" == "$default" ]]; then
echo $?
fi