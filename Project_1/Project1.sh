#!/bin/bash

#file Project_1
# Creates an HTML file to create a system readout
# author zachary_schwab
# Project 1
# date 10/5/2020

#functions





#checks to make sure the user running the script is root
function checkroot()
{
if [[ "$UID" -eq "$ROOT_ID" ]]
then
	return $true
else
	return	$false
fi
}

#gives a report on when the script was run
report()
{
	echo "Script was run by $USER on $(date | cut -d ' ' -f1-4) at $(date | cut -d ' ' -f5-7)"
}

#gives the information from the uptime command in a human readable format
uptime1()
{
	echo "Machine has been has been $(uptime -p)" "<br>"
	echo "$(uptime| cut -d ' ' -f7-8 | cut -d ',' -f1) is logged in," "<br>"
	echo "<h4>" "$(uptime| cut -d ' ' -f10-11)"  "</h4>"
	echo "last 1 minute $(uptime| cut -d ' ' -f12)" "<br>"
	echo "last 5 minutes $(uptime| cut -d ' ' -f13)" "<br>"
	echo "last 15 minutes $(uptime| cut -d ' ' -f14)" "<br>"
}

#gives distribution, kernel, and CPU in their own sections
basic()
{
	echo "<h3> Linux Distribution </h3>"
	echo "$(lsb_release -v)" "<br>"
	echo "$(lsb_release -id)" "<br>"
	echo "$(lsb_release -d)" "<br>"
	echo "$(lsb_release -r)" "<br>"
	echo "$(lsb_release -c)" "<br>" "<br>"
	
	echo "<h3> Kernel Version </h3>"
	echo "Linux kernel version:" "$(uname -r)" "<br>"
	
	echo "<h3> CPU Achitecture </h3>"

	CPU=$(lscpu | head -5)
	echo "${CPU//$'\n'/<br />}"
}

#gives RAM memory usage
memory()
{
	MEMORY=$(free)
	echo  "<pre> ${MEMORY//$'\n'/<br />} </pre>"
}

#gives drive information in human readable format
drive()
{
	DRIVE=$(lsblk -f -i| egrep "(sd|crypt|NAME)")
	
	echo " <pre> ${DRIVE//$'\n'/<br />} </pre>"
}

#gives the list of users and what groups they are in
users()
{
	for user in $(cat /etc/passwd | grep bash | cut -d ':' -f1); 
	do
		echo "<h4> $user </h4>"
		echo "$(id $user | cut -d ' ' -f1 | cut -d '(' -f1) <br> "
		echo "$(id $user | cut -d ' ' -f2  | cut -d '(' -f1) <br>"
		echo "$(id $user | cut -d ' ' -f3) <br>"
		echo "<br>"
	done
}

#gives the ip address of the computer
ipaddr()
{
	echo "System ip Address is: $(hostname -I)"
}

#gives a list of all of the usb device
usbdevices()
{
	USB=$(lsusb)
	echo "${USB//$'\n'/<br />}"
}

#calls all the previous functions in order to build out the web page
main()
{
	Header="System Info"
	if checkroot;
	then
	cat<<-  _EOF_
		<html>
		<head>
			<title>
				Project 1
			</title>
		</head>
		<body>
			<h1>
				Report
			</h1>
			<p1>
				$(report)
			</p1>
			
			<h1>
				Uptime
			</h1>
			<p1>
				$(uptime1)
			</p1>
			
			<h1>
				Basic $Header
			</h1>
			<p1>
				$(basic)
			</p1>
			
			<h1>
				Memory $Header
			</h1>
			<p1>
				$(memory)
			</p1>
			
			<h1>
				Drive $Header
			</h1>
			<p1>
				$(drive)
			</p1>
			
			<h1>
				Users $Header
			</h1>
			<p1>
				$(users)
			</p1>
			
			<h1>
				IP Address $Header
			</h1>
			<p1>
				$(ipaddr)
			</p1>
			
			<h1>
				USB devices $Header
			</h1>
			<p1>
				$(usbdevices)
			</p1>
			
		</body>
		</html>
	_EOF_
	else
		echo "Script must be run by root"
	fi
}

#calls main
main
